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