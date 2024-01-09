#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <string>
#include <mutex>

void prijatieMapy(SOCKET socket);

#pragma comment(lib, "ws2_32.lib")


void vyberanieFigurky(SOCKET connectSocket) {
    char moznosti[5];
    recv(connectSocket, moznosti, sizeof(moznosti), 0);

    std::cerr << ">> Ktore figurky si chcete vybrat ? -> ";
    std::cerr << ' ';
    for (int i = 0; i < 4; i++) {
        if (moznosti[i] != '\0') {
            std::cerr << moznosti[i] << " ";
        }
    }
    std::cout << std::endl;

    int vybranaFigurka;
    std::cin >> vybranaFigurka;
    std::cerr << std::endl;
    send(connectSocket, reinterpret_cast<char*>(&vybranaFigurka), sizeof(vybranaFigurka), 0);
}

void prijatieHodKockou(SOCKET connectSocket) {
    int hod;
    recv(connectSocket, reinterpret_cast<char*>(&hod), sizeof(hod), 0);
    std::cout << ">> Hrac hodil: " << hod << std::endl;
}

void prijatieMapy(SOCKET socket) {
    char buffer[182];
    recv(socket, reinterpret_cast<char*>(&buffer), sizeof(buffer), 0);
    for (int i = 0; i < sizeof (buffer) / sizeof (buffer[0]); ++i) {
        std::cout << ' ' << buffer[i];
    }
    std::cout << std::endl;
}


int main() {
    //Pripojenie na server
    WSADATA wsaData;
    std::string hostName = "frios2.fri.uniza.sk";
    std::mutex read;
    short port = 19520;

    struct addrinfo *result = NULL;
    struct addrinfo hints;
    int iResult;



    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        throw std::runtime_error("WSAStartup failed with error: " + std::to_string(iResult) + "\n");
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;


    iResult = getaddrinfo(hostName.c_str(), std::to_string(port).c_str(), &hints, &result);
    if (iResult != 0) {
        WSACleanup();
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(iResult) + "\n");
    }


    SOCKET connectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (connectSocket == INVALID_SOCKET) {
        WSACleanup();
        throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()) + "\n");
    }

    iResult = connect(connectSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        closesocket(connectSocket);
        connectSocket = INVALID_SOCKET;
    }

    freeaddrinfo(result);

    if (connectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        throw std::runtime_error("Unable to connect to server.\n");
    }
    std::cout << "Pripojenie na server bolo uspesne." << std::endl;

    std::string plocha;
    int hod;
    int cisloHraca;
    recv(connectSocket, reinterpret_cast<char*>(&cisloHraca), sizeof(cisloHraca), 0);

    while (true) {

        int hracNaTahuServer;
        recv(connectSocket, reinterpret_cast<char*>(&hracNaTahuServer), sizeof(hracNaTahuServer), 0);

        while(hracNaTahuServer == -1 && hracNaTahuServer != cisloHraca) {
            recv(connectSocket, reinterpret_cast<char*>(&hracNaTahuServer), sizeof(hracNaTahuServer), 0);
            Sleep(1000);
        }

        int cisloSpravy = 0;
        recv(connectSocket, reinterpret_cast<char*>(&cisloSpravy), sizeof(cisloSpravy), 0);

        if ((cisloSpravy == 1 || cisloSpravy == 2 || cisloSpravy == 3 || cisloSpravy == 4)) {
            switch (cisloSpravy) {
                case 1:
                    vyberanieFigurky(connectSocket);
                    continue;
                case 2:
                    prijatieHodKockou(connectSocket);
                    continue;
                case 3:
                    prijatieMapy(connectSocket);
                    continue;
            }
        }
    }
}


