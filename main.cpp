#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <condition_variable>
#include "my_socket.h"

struct Point {
    double x;
    double y;
    static Point generate();
};

Point Point::generate() {
    static std::default_random_engine rnd;
    static std::uniform_real_distribution<double> dist(-1.0, 1.0);
    double x = dist(rnd);
    double y = dist(rnd);
    Point point = {x, y};
    return point;
}

class PiEstimation {
public:
    PiEstimation();
    void addPoint(const Point& point);
    std::string& serialize(std::string& output);
private:
    long long totalCount;
    long long insideCount;
};

void PiEstimation::addPoint(const Point& point) {
    ++this->totalCount;
    if (point.x * point.x + point.y * point.y <= 1) {
        ++this->insideCount;
    }
    std::cout << "Odhad pi: " << 4 * (double)this->insideCount / (double)this->totalCount << std::endl;
}

PiEstimation::PiEstimation() :
        totalCount(0),
        insideCount(0) {
}

std::string &PiEstimation::serialize(std::string &output) {
    output += std::to_string(this->totalCount) + ";" + std::to_string(this->insideCount) + ";";
    return output;
}


class ThreadData {
public:
    ThreadData(long long replicationsCount, int bufferCapacity, MySocket* serverSocket);
    void produce();
    void consume();
private:
    const long long replicationsCount;
    const int bufferCapacity;
    std::queue<Point> buffer;
    std::mutex mutex;
    std::condition_variable isFull;
    std::condition_variable isEmpty;
    MySocket* serverSocket;
};

//hrthr

ThreadData::ThreadData(long long replicationsCount, int bufferCapacity, MySocket* serverSocket) :
        replicationsCount(replicationsCount),
        bufferCapacity(bufferCapacity),
        buffer(),
        mutex(),
        isFull(),
        isEmpty(),
        serverSocket(serverSocket) {
}

void ThreadData::produce() {
    for (long long i = 1; i <= this->replicationsCount; ++i) {
        Point item = Point::generate();
        {
            std::unique_lock<std::mutex> lock(this->mutex);
            while (static_cast<long long>(this->buffer.size()) >= bufferCapacity) {
                this->isEmpty.wait(lock);
            }
            this->buffer.push(item);
            this->isFull.notify_one();
        }
    }
}

void ThreadData::consume() {
    PiEstimation piEstimaton;
    for (long long i = 1; i <= this->replicationsCount; ++i) {
        Point item;

        {
            std::unique_lock<std::mutex> lock(this->mutex);
            while (this->buffer.size() <= 0) {
                this->isFull.wait(lock);
            }
            item = this->buffer.front();
            this->buffer.pop();
            this->isEmpty.notify_one();
        }
        std::cout << i << ": ";
        piEstimaton.addPoint(item);
        if (i % 1000 == 0 && this->serverSocket != nullptr) {
            std::string input;
            this->serverSocket->sendData(piEstimaton.serialize(input)); //na server poslem spravu kde poslem odhad
        }
    }
    if (this->serverSocket != nullptr) {
        std::string input;
        this->serverSocket->sendData(piEstimaton.serialize(input));
        this->serverSocket->sendEndMessage();
    }
}

void produce(ThreadData& data) {
    data.produce();
}

void consume(ThreadData& data) {
    data.consume();
}

int main() {

    MySocket* mySocket = MySocket::createConnection("frios2.fri.uniza.sk", 12345);

    ThreadData data(3000, 10, mySocket);
    std::thread thProduce(produce, std::ref(data));

    consume(data);
    thProduce.join();

    delete mySocket;
    mySocket = nullptr;

    return 0;
}
