#include "Player.h"

Player::Player(Type type, Color color, int startingPosition, int endingPosition) {
    Pawn* firstPawn = new Pawn(startingPosition, 0, color, this, PawnType::Plus);
    Pawn* secondPawn = new Pawn(Board::Nest, 1, color, this, PawnType::Minus);
    Pawn* thirdPawn = new Pawn(Board::Nest, 2, color, this, PawnType::Pipe);
    Pawn* forthPawn = new Pawn(Board::Nest, 3, color, this, PawnType::Blank);
    
    firstPawn->setNextPawn(secondPawn);
    secondPawn->setNextPawn(thirdPawn);
    thirdPawn->setNextPawn(forthPawn);
    forthPawn->setNextPawn(0);
    
    this->firstPawn = firstPawn;
    this->type = type;
    this->startingPosition = startingPosition;
    this->endingPosition = endingPosition;
    this->color = color;
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

Color Player::getColor() {
    return this->color;
}

void Player::capture() {
    this->captured = true;
}

void Player::useCapture(Pawn* pawn) {
    this->captured = false;
    pawn->setPosition(pawn->getPosition()+20);
}

bool Player::hasCaptured() {
    return this->captured;
}

bool Player::isHuman() {
	return this->type == Type::Human;
}

Player::Type Player::getPlayerType() {
    return this->type;
}