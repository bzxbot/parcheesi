#include "Player.h"

Player::Player(Type type, Color color, int startingPosition, int endingPosition) {
    Pawn* firstPawn = new Pawn(startingPosition, 0, color);
    Pawn* secondPawn = new Pawn(Board::Nest, 1, color);
    Pawn* thirdPawn = new Pawn(Board::Nest, 2, color);
    Pawn* forthPawn = new Pawn(Board::Nest, 3, color);
    
    firstPawn->setNextPawn(secondPawn);
    secondPawn->setNextPawn(thirdPawn);
    thirdPawn->setNextPawn(forthPawn);
    forthPawn->setNextPawn(0);
    
    this->firstPawn = firstPawn;
    this->type = type;
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