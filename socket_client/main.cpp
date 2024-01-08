#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main() {
    //Pripojenie na server
    WSADATA wsaData;
    std::string hostName = "frios2.fri.uniza.sk";
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

    // Resolve the server address and port
    iResult = getaddrinfo(hostName.c_str(), std::to_string(port).c_str(), &hints, &result);
    if (iResult != 0) {
        WSACleanup();
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(iResult) + "\n");
    }

    // Create a SOCKET for connecting to server
    SOCKET connectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (connectSocket == INVALID_SOCKET) {
        WSACleanup();
        throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()) + "\n");
    }

    // Connect to server
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

    while (true) {

        // prijimanie zo server vysledok hodu kocky
        int hod;
        recv(connectSocket, reinterpret_cast<char*>(&hod), sizeof(hod), 0);
        std::cout << "Na kocke padla " << hod << std::endl;
        char buffer[256];
        int vybranaFigurka;
        recv(connectSocket, reinterpret_cast<char*>(&buffer), sizeof(buffer), 0);
        std::cout << "Figurky hraca, ktorymi sa moze hrac pohnut: " << std::endl;
        std::cout << "Zadajte cislo figurky: ";
        std::cin >> vybranaFigurka;
        int bytesSent = send(connectSocket, reinterpret_cast<char*>(&vybranaFigurka), sizeof(vybranaFigurka), 0);

        if (bytesSent == SOCKET_ERROR) {
            // Handle error
            std::cerr << "send failed with error: " << WSAGetLastError() << std::endl;
        }


        // Poslanie čísla na server
        //send(connectSocket, reinterpret_cast<char*>(&vybranaFigurka), sizeof(vybranaFigurka), 0);
        Sleep(1000);  // Čakáme na simuláciu ďalšieho kola
    }

    closesocket(connectSocket);
    WSACleanup();
    return 0;
}
