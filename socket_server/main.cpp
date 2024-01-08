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
#include "../Game/game.h"
#include "../Game/Player.h"

//Player* hraci;
std::vector<Player*> hraci;
Kocka kocka;
std::vector<std::thread> clientThreads;
std::vector<int> clientSockets;
std::mutex gameMutex;
Player hrac1;
Player hrac2;
Player hrac3;
Player hrac4;

struct LocalInfo{
    int playerID=-1;
}; //TODO mozeme vymazat

struct Hra{
    game hra;
    std::mutex mtx; // Globálny mutex
    std::condition_variable cv[4]; // Pole podmienkových premenných pre každého hráča
    int aktualnyHrac = 1;

};

void posliHodKockou(int hodKockou, int clientSocket) {
    std::string hodStr = std::to_string(hodKockou);
    const char *data = hodStr.c_str();
    size_t remainingBytes = hodStr.size();

    while (remainingBytes > 0) {
        ssize_t result = send(clientSocket, data, remainingBytes, 0);

        if (result == -1) {
            std::cerr << "Chyba při odesílání dat na socket. Chybový kód: " << errno << std::endl;
            // Případně můžete provést další ošetření chyb nebo program ukončit.
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

    // Převod řetězce na integer
    int cisloFigurky = std::stoi(cisloFigurkyStr);

    return cisloFigurky;
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
    //gameMutex.unlock();
    return -1;  // vráti -1, ak žiadny hráč nie je na rade

}

void handleClient(int clientSocket, int playerId, Hra &hra) {

    //LocalInfo localInfo;
    //localInfo.playerID=playerId;
    int cisloVyberanejFigurky = 0;
    bool chcemNovehohraca = false;

    int hracNaTahu = 0; // Globálna premenná pre sledovanie, ktorý hráč je na ťahu

    while (hra.hra.getSpustenaHra()) {
        //hra.aktualnyHrac = hra.hra.getHracNaTahu().getCisloHraca();
        // Prijatie akcie od klienta (hod kockou)
        //char buffer[256];
        //ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        //if (bytesRead <= 0) {
        //    std::cerr << "Chyba pri čítaní zo soketu pre hráča " << playerId << std::endl;
        //     break;
        // }
        //int cisloFigurky = std::stoi(buffer);

        //while (hra.hra->getSpustenaHra()) {
        //std::cout << "NA RADE JE HRAC " << hrac2.getCisloHraca() << std::endl;
        std::unique_lock<std::mutex> lock(hra.mtx); // Zamkneme mutex


        while (hra.hra.getHracNaTahu().getCisloHraca() != hra.aktualnyHrac) {
            hra.cv[playerId].wait(lock); // Odemkneme mutex a čekáme na notifikaci
        }

        std::cerr << "Na rade je hrac " << hra.hra.getHracNaTahu().getCisloHraca() << std::endl;
        if (hra.hra.getHracNaTahu().getPocetFigurokNaCeste() == 0) {

            if (hra.hra.getHracNaTahu().getCisloHraca() != 0) {
                //posliHodKockou(hodKockou, clientSockets[hra.hra.getHracNaTahu().getCisloHraca()]);

                if (hra.hra.vybratieZDomceka(&hra.hra.getHracNaTahu())) { //true, ak hodi 6 a de z domceka
                    /*if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                        std::cout << "HOD KOCKOU JE " << hra.hra.getHracNaTahu().getHodKockou() << std::endl;
                        send(clientSocket, reinterpret_cast<char*>(hra.hra.getHracNaTahu().getHodKockou()), sizeof(hra.hra.getHracNaTahu().getHodKockou()), 0);
                        //cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu());
                        int hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);
                        hra.hra.getHracNaTahu().setHodKockou(hodKockou);
                        send(clientSocket, reinterpret_cast<char*>(&hodKockou), sizeof(hodKockou), 0);
                        hra.hra.daniePanacikaNaZaciatok(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                        hra.hra.prvyPosunPanacika(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                    } else {*/
                        int hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);
                        hra.hra.getHracNaTahu().setHodKockou(hodKockou);
                        send(clientSocket, reinterpret_cast<char*>(&hodKockou), sizeof(hodKockou), 0);

                        cisloVyberanejFigurky = getCisloVyberanejFigurky(clientSocket, hra.hra);
                        hra.hra.daniePanacikaNaZaciatok(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                        hra.hra.prvyPosunPanacika(&hra.hra.getHracNaTahu(), hodKockou, cisloVyberanejFigurky);
                    //}
                } else {
                    hra.hra.zmenaHracaNaTahu();
                }
            } else {
                int hodHraca = hra.hra.getHracNaTahu().hodKockou(kocka);
                if (hra.hra.getHracNaTahu().getCisloHraca() != 0) {
                    int hodKockou = hra.hra.getHracNaTahu().hodKockou(kocka);
                    hra.hra.getHracNaTahu().setHodKockou(hodKockou);
                    send(clientSocket, reinterpret_cast<char*>(&hodKockou), sizeof(hodKockou), 0);
                    //posliHodKockou(hodHraca, clientSockets[hra.hra.getHracNaTahu().getCisloHraca()]);
                }
                std::cout << ">> hrac " << hra.hra.getHracNaTahu().getZnak() << " hodil " << hodHraca << std::endl;
                if (hra.hra.getHracNaTahu().getFigurka(cisloVyberanejFigurky).getVKoncovomDomceku()) {
                    if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                        cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu());
                    } else {
                        cisloVyberanejFigurky = getCisloVyberanejFigurky(clientSocket, hra.hra);
                    }
                    hra.hra.posunVKoncovomDomceku(&hra.hra.getHracNaTahu(), hodHraca, cisloVyberanejFigurky);
                } else {
                    if (hra.hra.getHracNaTahu().getFigurka(cisloVyberanejFigurky).getPrejdenaVzdialenost() + hodHraca >=
                        40) {
                        hra.hra.figurkaDoKoncovehoDomceka(&hra.hra.getHracNaTahu(), hodHraca, cisloVyberanejFigurky);
                    } else {
                        if (hodHraca == 6) {
                            chcemNovehohraca = hra.hra.vyberAkcie();
                            if (chcemNovehohraca) {
                                if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                                    cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu());
                                } else {
                                    cisloVyberanejFigurky = getCisloVyberanejFigurky(clientSocket, hra.hra);
                                }
                                hra.hra.novyHracZDomceka(cisloVyberanejFigurky, hodHraca);
                                hra.hra.zmenaHracaNaTahu();
                            } else {
                                if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                                    cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu());
                                } else {
                                    cisloVyberanejFigurky = getCisloVyberanejFigurky(clientSocket, hra.hra);
                                }
                                hra.hra.posunFigurkyPoHracejPloche(&hra.hra.getHracNaTahu(), hodHraca,
                                                                   cisloVyberanejFigurky);
                                hra.hra.zmenaHracaNaTahu();
                            }
                        } else {
                            if (hra.hra.getHracNaTahu().getCisloHraca() == 0) {
                                cisloVyberanejFigurky = vyberFigurkyPriPosuneServer(&hra.hra.getHracNaTahu());
                            } else {
                                cisloVyberanejFigurky = getCisloVyberanejFigurky(clientSocket, hra.hra);
                            }
                            hra.hra.posunFigurkyPoHracejPloche(&hra.hra.getHracNaTahu(), hodHraca,
                                                               cisloVyberanejFigurky);
                            hra.hra.zmenaHracaNaTahu();
                        }
                    }
                }
            }
        } else {
            if (hra.aktualnyHrac == 0) {
                int hodHraca = hra.hra.getHracNaTahu().hodKockou(kocka);
                hra.hra.getHracNaTahu().setHodKockou(hodHraca);
                hra.hra.vybratieFigurkyZDomceku(false);
                hra.hra.posunFigurkyPoHracejPloche(&hra.hra.getHracNaTahu(), hodHraca,
                                                   cisloVyberanejFigurky);
                hra.hra.zmenaHracaNaTahu();
            } else {
                int hodHraca = hra.hra.getHracNaTahu().hodKockou(kocka);
                //hra.hra.vybratieFigurkyZDomceku(false);
                hra.hra.getHracNaTahu().setHodKockou(hodHraca);
                send(clientSocket, reinterpret_cast<char*>(&hodHraca), sizeof(hodHraca), 0);
                cisloVyberanejFigurky = getCisloVyberanejFigurky(clientSocket, hra.hra);
                hra.hra.posunFigurkyPoHracejPloche(&hra.hra.getHracNaTahu(), hodHraca,
                                                   cisloVyberanejFigurky);
                hra.hra.zmenaHracaNaTahu();
            }

        }
            lock.unlock(); // Odomkneme mutex
            hra.aktualnyHrac = hra.hra.getHracNaTahu().getCisloHraca();
            clientSocket = clientSockets.at(hra.aktualnyHrac);
            playerId = hra.aktualnyHrac;
            hra.cv[hra.aktualnyHrac].notify_one();
            // Odošleme klientovi výsledek hodu
            //send(clientSocket, reinterpret_cast<char*>(&diceResult), sizeof(diceResult), 0);
            //std::cout << "Hráč " << playerId << " hodil kockou a získal: " << diceResult << std::endl;



    }

    close(clientSocket);
}

void pripojenieHracov(int serverSocket, int cisloHraca, Hra &hra) {
    //int clientSocket = accept(serverSocket, NULL, NULL);
    if(serverSocket == -1) {
        std::cerr << "Pripojenie hraca sa nepodarilo" << std::endl;
        //continue;
    } else {
        std::cerr << "Pripojil sa novy hrac" << std::endl;
    }
    std::string hrac = "hrac" + std::to_string(cisloHraca);
    hraci.push_back((Player*) &hrac);
    //clientThreads.push_back(std::thread(handleClient, clientSocket, i, std::ref(hra))); // Použitie globálnej premennej
    clientSockets.push_back(serverSocket);

    if(hraci.size() == 4) {
        std::cerr << "Pripojeny su 4 hraci - hra sa moze zacat" << std::endl;
        cisloHraca = 1;
        for (auto& thread : clientThreads) {
            thread.join();
        }
        handleClient(clientSockets.at(cisloHraca - 1), cisloHraca, hra);
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
    listen(serverSocket,
           3);    // Pasivny soket - nesluzi na komunikaciu, ale len aby sa k nemu niekto pripojil; 3 - najviac 3 ludi pripojit v jednom okamziku

    std::cout << "Server je spusteny a pocuva na porte " << port << std::endl;

    Hra hra;
    hra.hra.pridelHracov(hrac1, hrac2, hrac3, hrac4);
    hra.hra.setHracNaTahu(&hrac2);

    /*while(hra.getPocetHracov() != 4) {
        std::cout << "nie su pripojeny vsetci hraci " << std::endl;
        sleep(100000);
    }*/
    int cisloHraca = 1;

    while (true) {
        for (int i = 0; i < 3; ++i) {
            int clientSocket = accept(serverSocket, nullptr, nullptr);

            std::thread(pripojenieHracov, clientSocket, cisloHraca, std::ref(hra)).detach();
            cisloHraca++;
            if (cisloHraca > 4) {
                cisloHraca = 1;
            }
        }

    }

    for (auto& thread : clientThreads) {
        thread.join();
    }

    close(serverSocket);

    return 0;
}
