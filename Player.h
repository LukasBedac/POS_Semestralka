//
// Created by Lukas on 30. 12. 2023.
//

#ifndef POS_SEMESTRALKA_PLAYER_H
#define POS_SEMESTRALKA_PLAYER_H


class Player {
private:
    int currentPos = 0;
    bool playerTurn = false;
    bool inHome[4] = {false, false, false, false};
    bool win = false;
public:
    void movePlayer(int count, Player player);
    bool winCondition(Player player);
};


#endif //POS_SEMESTRALKA_PLAYER_H
