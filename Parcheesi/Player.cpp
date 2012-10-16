#include "Player.h"

Player::Player(PlayerColor *playerColor) {
    this->playerColor = playerColor;
    
    int nest = 0;
    
    Pawn* firstPawn = new Pawn(playerColor->getStartingPosition());
    Pawn* secondPawn = new Pawn(nest);
    Pawn* thirdPawn = new Pawn(nest);
    Pawn* forthPawn = new Pawn(nest);
    
    firstPawn->setNextPawn(secondPawn);
    secondPawn->setNextPawn(thirdPawn);
    thirdPawn->setNextPawn(forthPawn);
    
    this->firstPawn = firstPawn;
}

Player* Player::getNextPlayer() {
    return this->nextPlayer;
}

void Player::setNextPlayer(Player *nextPlayer) {
    this->nextPlayer = nextPlayer;
}

Pawn* Player::getFirstPawn() {
    return this->firstPawn;
}

PlayerColor* Player::getPlayerColor() {
    return this->playerColor;
}