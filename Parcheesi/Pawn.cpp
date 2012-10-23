#include "Pawn.h"

Pawn::Pawn(int position, int startPosition, Color color) {
    this->startPosition = startPosition;
    this->position = position;
    this->color = color;
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
