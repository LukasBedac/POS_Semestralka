//
// Created by Lukas on 30. 12. 2023.
//

#include "Player.h"

bool Player::winCondition(Player player) { //kontrola domceka pre jednotliveho hraca

    int count = 0;
    for (bool home : player.inHome) {
        if (home) {
            count++;
        }
    }
    if (count == 4) {
        return true;
    }
    return false;
}

void Player::movePlayer(int count, Player player) {
    if (player.currentPos + count <= 40) {
        player.currentPos += count; //posun na ploche, normalnych policok je 40, ptm 4 domceky
    }
    //posun v hre podla logiky ako urobime + zmena typu returnu neskor

    if (player.currentPos > 40 && (player.currentPos + count) < 45) { //kontrola ak je vyse 40 aby si skontroloval ci moze ist do domceka
        int tmpPosHome = currentPos + count - 40;
        if  (!player.inHome[tmpPosHome]) {
            player.inHome[tmpPosHome] = true;
        }
    }

    player.playerTurn = false;
    player.win = player.winCondition(player); //po tom co sa skontroluje sa v hre moze urcit vitaz
                                              //hned po dohrani tahu ifom a vie sa skoncit hra
}