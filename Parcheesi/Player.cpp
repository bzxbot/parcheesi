#include "Player.h"

Player::Player(Type type, Color color, int startingPosition, int endingPosition) {
    Pawn* firstPawn = new Pawn(startingPosition);
    Pawn* secondPawn = new Pawn(Board::Nest);
    Pawn* thirdPawn = new Pawn(Board::Nest);
    Pawn* forthPawn = new Pawn(Board::Nest);
    
    firstPawn->setNextPawn(secondPawn);
    secondPawn->setNextPawn(thirdPawn);
    thirdPawn->setNextPawn(forthPawn);
    forthPawn->setNextPawn(0);
    
    this->firstPawn = firstPawn;
    this->type = type;
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

Player::Type Player::getPlayerType() {
    return this->type;
}