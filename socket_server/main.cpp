#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <condition_variable>
#include "../Game/Game.h"
#include "../Game/Player.h"

//Player* hraci;
std::vector<Player*> hraci;
Kocka kocka;
std::vector<std::thread> clientThreads;
std::vector<int> clientSockets;
std::mutex gameMutex;
Player hrac0;
Player hrac1;
Player hrac2;
Player hrac3;

struct LocalInfo{
    int playerID=-1;
}; //TODO mozeme vymazat

struct Hra{
    game hra;
    std::mutex mtx; // Globálny mutex
    std::condition_variable cv[4]; // Pole podmienkových premenných pre každého hráča
    int aktualnyHrac = 0;

};

void posliHodKockou(int hodKockou, int clientSocket) {
    std::string hodStr = std::to_string(hodKockou);
    const char *data = hodStr.c_str();
    size_t remainingBytes = hodStr.size();

    while (remainingBytes > 0) {
        ssize_t result = send(clientSocket, data, remainingBytes, 0);

        if (result == -1) {
            std::cerr << "Chyba při odesílání dat na socket. Chybový kód: " << errno << std::endl;

            break;
        }

        remainingBytes -= result;
        data += result;
    }
}

int vyberFigurkyPriPosuneServer(Player *hrac) {
    std::string moznosti = "";
    for(int i = 0; i < 4; i++) {
        if(!hrac->getFigurka(i).getVDomceku()) {
            moznosti += std::to_string(i) + " ";
        }
    }
    //std::cout << std::endl;

    std::string cisloFigurkyStr = "";
    std::cout << ">> S ktorou figurkou chcete pohnut? - figurky na hracej ploche -> " << moznosti << std::endl;
    std::cin >> cisloFigurkyStr;
    std::cout << std::endl;
    int cisloFigurky = std::stoi(cisloFigurkyStr);

    return cisloFigurky;
}

void getMapaPreVsetkych(Hra &hra) {
    char buf[182];
    int riadok = 0;
    int stlpec = 0;
    for (int i = 0; i < sizeof (buf) / sizeof (buf[0]); ++i) {
        buf[i] = hra.hra.vypisPlochuPreKlienta(stlpec, riadok);
        stlpec++;

        if (stlpec % 14 == 0 && stlpec != 0) {
            buf[i] = '\n';
            riadok++;
            stlpec = 0;
        }

    }
    gameMutex.lock();
    int sprava = 3;
    for (auto& client : clientSockets) {
        send(client, reinterpret_cast<char*>(&hra.aktualnyHrac), sizeof(hra.aktualnyHrac), 0);
        send(client, reinterpret_cast<char*>(&sprava), sizeof(sprava), 0);
        send(client, reinterpret_cast<char*>(&buf), sizeof(buf), 0);
    }
    gameMutex.unlock();
    /*kontrola vypisu
    for (int i = 0; i < sizeof (buf) / sizeof (buf[0]); ++i) {
        std::cout << ' ' << buf[i] ;
    } */



}

int getCisloVyberanejFigurky(int clientSocket, game hra) {
    gameMutex.lock();
    for (int i = 0; i < 4; i++) {
        if(i == hra.getHracNaTahu().getCisloHraca()) {
            int cisloVyberanejFigurky;
            recv(clientSocket, reinterpret_cast<char*>(&cisloVyberanejFigurky), sizeof(cisloVyberanejFigurky), 0);
            if (cisloVyberanejFigurky == -1) {
                std::cerr << "recv failed with error: " << strerror(errno) << std::endl;
            } else {
                std::cout << "Hrac " << i << " si vybral figurku " << cisloVyberanejFigurky << std::endl;
                gameMutex.unlock();
                return cisloVyberanejFigurky;
            }
        }
    }
    gameMutex.unlock();
    return -1;  // vráti -1, ak žiadny hráč nie je na rade

}

int vyberFigurkyPriPosuneServer(Player *hrac, int clientSocket) {
    char moznosti[4];
    if (hrac->getPocetFigurokNaCeste() == 0) {
        moznosti[0] = '0';
        moznosti[1] = '1';
        moznosti[2] = '2';
        moznosti[3] = '3';
    } else {
        for(int i = 0; i < 4; i++) {
            if(!hrac->getFigurka(i).getVDomceku() && i == 0) {
                moznosti[i] = '0';
            } else if (!hrac->getFigurka(i).getVDomceku() && i == 1){
                moznosti[i] = '1';
            } else if (!hrac->getFigurka(i).getVDomceku() && i == 2){
                moznosti[i] = '2';
            } else if (!hrac->getFigurka(i).getVDomceku() && i == 3){
                moznosti[i] = '3';
            } else {
                moznosti[i] = ' ';
            }
        }
    }
    send(clientSocket, &moznosti, sizeof(moznosti), 0);
    int vybranaFigurka;
    recv(clientSocket, reinterpret_cast<char*>(&vybranaFigurka), sizeof(vybranaFigurka), 0);
    return vybranaFigurka;
}


void handleClient(int clientSocket, int playerId, Hra &hra) {
    int cisloVyberanejFigurky = 0;
    bool chcemNovehohraca = false;
    int hodKockou;
    int hracNaTahu = 0; // Globálna premenná pre sledovanie, ktorý hráč je na ťahu
    int cisloSpravy;
    while (hra.hra.getSpustenaHra()) {
        std::unique_lock<std::mutex> lock(hra.mtx); // Zamkneme mutex

        while (hra.hra.getHracNaTahu().getCisloHraca() != hra.aktualnyHrac) {
            hra.cv[hra.aktualnyHrac].wait(lock);
        }
        send(clientSocket, reinterpret_cast<char*>(&hra.aktualnyHrac), sizeof(hra.aktualnyHrac), 0);
        std::cerr << "Na rade je hrac " << hra.hra.getHracNaTahu().getCisloHraca() << std::endl;
        // HOD KOCKOU KED PRVY KRAT IDES DO DOMCEKA

        if(hra.hra.getHracNaTahu().getPocetFigurokNaCeste() == 0) {

            hra.hra.vybratieZDomceka(&hra.hra.getHracNaTahu());
            if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                int hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);
                std::cout << "Hrac hodil" << hodKockou << std::endl;
                cisloVyberanejFigurky = hra.hra.vyberFigurkyPriPosune(&hra.hra.getHracNaTahu());
                hra.hra.daniePanacikaNaZaciatok(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                hra.hra.prvyPosunPanacika(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);

            } else {
                cisloSpravy = 2;
                send(clientSocket, reinterpret_cast<char*>(&cisloSpravy), sizeof(cisloSpravy), 0);
                send(clientSocket, reinterpret_cast<char*>(&hra.hra.getHracNaTahu().getHodKockou()), sizeof(&hra.hra.getHracNaTahu().getHodKockou()), 0); // POSLE SA TA 6
                send(clientSocket, reinterpret_cast<char*>(&hra.aktualnyHrac), sizeof(hra.aktualnyHrac), 0);

                cisloSpravy = 1;
                send(clientSocket, reinterpret_cast<char*>(&cisloSpravy), sizeof(cisloSpravy), 0);

                cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu(), clientSocket);
                int hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);

                hra.hra.daniePanacikaNaZaciatok(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                hra.hra.prvyPosunPanacika(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
            }

        } else {
            if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                int hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);
                std::cout << "Hrac hodil " << hodKockou << std::endl;
                cisloVyberanejFigurky = hra.hra.vyberFigurkyPriPosune(&hra.hra.getHracNaTahu());
            } else {
                hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);
                cisloSpravy = 2;
                send(clientSocket, reinterpret_cast<char*>(&cisloSpravy), sizeof(cisloSpravy), 0);
                send(clientSocket, reinterpret_cast<char*>(&hodKockou), sizeof(hodKockou), 0);
                send(clientSocket, reinterpret_cast<char*>(&hra.aktualnyHrac), sizeof(hra.aktualnyHrac), 0);

                cisloSpravy = 1;
                send(clientSocket, reinterpret_cast<char*>(&cisloSpravy), sizeof(cisloSpravy), 0);
                cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu(), clientSocket);
            }

            if(hra.hra.getHracNaTahu().getFigurka(cisloVyberanejFigurky).getVKoncovomDomceku()) {
                hra.hra.posunVKoncovomDomceku(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
            } else {
                if(hra.hra.getHracNaTahu().getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodKockou >= 40) {
                    hra.hra.figurkaDoKoncovehoDomceka(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                } else {
                    hra.hra.posunFigurkyPoHracejPloche(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                }
            }
        }
        hra.aktualnyHrac = hra.hra.getHracNaTahu().getCisloHraca();
        getMapaPreVsetkych(hra);
        clientSocket = clientSockets.at(hra.aktualnyHrac);
        playerId = hra.aktualnyHrac;
        lock.unlock();
        hra.cv[hra.aktualnyHrac].notify_one();
    }

    close(clientSocket);
}

void pripojenieHracov(int serverSocket, int cisloHraca, Hra &hra) {
    //int clientSocket = accept(serverSocket, NULL, NULL);
    ;
    if(serverSocket == -1) {
        std::cerr << "Pripojenie hraca sa nepodarilo" << std::endl;
        //continue;
    } else {
        std::cerr << "Pripojil sa novy hrac" << std::endl;
    }
    std::string hrac = "hrac" + std::to_string(cisloHraca);
    hraci.push_back((Player*) &hrac);
    clientSockets.push_back(serverSocket);
    send(serverSocket, &cisloHraca, sizeof(cisloHraca),0);
    handleClient(clientSockets.at(cisloHraca), cisloHraca, hra);

    if(hraci.size() == 4) {
        std::cerr << "Pripojeny su 4 hraci - hra sa moze zacat" << std::endl;
        cisloHraca = 0;
    }
}

int main() {
    //hraci = new Player[4];
    srand(static_cast<unsigned>(time(0)));

    // DEFINOVANIE PORTU A VYTVORENIE SOCKETOV PRE HRACOV
    short port = 19520;
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;             // Internetove sokety
    serverAddress.sin_port = htons(port);           // Nastavenie portu
    serverAddress.sin_addr.s_addr = INADDR_ANY;     // Prijimam sokety z celeho internetu

    // aby sa predišlo tomu, že port bude stále obsadený, pri znovupoužiteľnosťi adresy
    int enable = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&enable), sizeof(int)) < 0)
        std::cerr << "setsockopt(SO_REUSEADDR) failed" << std::endl;

    // Pasivny soket je len na strane servera
    bind(serverSocket, reinterpret_cast<struct sockaddr *>(&serverAddress), sizeof(serverAddress));
    listen(serverSocket, 3);    // Pasivny soket - nesluzi na komunikaciu, ale len aby sa k nemu niekto pripojil; 3 - najviac 3 ludi pripojit v jednom okamziku

    std::cout << "Server je spusteny aw pocuva na porte " << port << std::endl;

    Hra hra;
    hra.hra.pridelHracov(hrac0, hrac1, hrac2, hrac3);
    hra.hra.setHracNaTahu(&hrac0);
    hraci.push_back(&hrac0);
    int cisloHraca = 0;

    while (true) {
        for (int i = 0; i < 4; ++i) {
            int clientSocket = accept(serverSocket, nullptr, nullptr);
            clientThreads.push_back(std::thread(pripojenieHracov, clientSocket, cisloHraca, std::ref(hra)));
            cisloHraca++;
            if (cisloHraca > 4) {
                cisloHraca = 0;
            }
        }

    }
    close(serverSocket);
    return 0;
}
