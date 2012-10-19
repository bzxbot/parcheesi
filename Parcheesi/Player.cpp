#include "Player.h"

Player::Player(Color color, int startingPosition, int endingPosition) {
    int nest = 0;
    
    Pawn* firstPawn = new Pawn(startingPosition);
    Pawn* secondPawn = new Pawn(nest);
    Pawn* thirdPawn = new Pawn(nest);
    Pawn* forthPawn = new Pawn(nest);
    
    firstPawn->setNextPawn(secondPawn);
    secondPawn->setNextPawn(thirdPawn);
    thirdPawn->setNextPawn(forthPawn);
    
    this->firstPawn = firstPawn;
    this->color = color;
    this->startingPosition = startingPosition;
    this->endingPosition = endingPosition;
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

int Player::getStartingPosition() {
    return this->startingPosition;
}

int Player::getEndingPosition() {
    return this->endingPosition;
}