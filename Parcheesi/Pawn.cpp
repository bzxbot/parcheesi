#include "Pawn.h"

Pawn::Pawn(int position, int startPosition, Color color, Player* player, PawnType type) {
    this->startPosition = startPosition;
    this->position = position;
    this->color = color;
    this->player = player;
    this->type = type;
}

void Pawn::setNextPawn(Pawn* nextPawn) {
    this->nextPawn = nextPawn;
}

Pawn* Pawn::getNextPawn() {
    return this->nextPawn;
}

int Pawn::getPosition() {
    return this->position;
}

void Pawn::setPosition(int position) {
    this->position = position;
    Parcheesi::getInstance()->enqueueAnimation();
}

int Pawn::getStartPosition() {
    return this->startPosition;
}

void Pawn::setStartPosition(int position) {
    this->startPosition = position;
}

Color Pawn::getColor() {
    return this->color;
}

void Pawn::setCoordinates(float x, float y) {
    this->coordinates[0] = x;
    this->coordinates[1] = y;
}

float Pawn::getXCoordinate() {
    return this->coordinates[0];
}

float Pawn::getYCoordinate() {
    return this->coordinates[1];
}

Player* Pawn::getPlayer() {
    return this->player;
}

PawnType Pawn::getType() {
    return this->type;
}
