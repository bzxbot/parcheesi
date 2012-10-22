#include "Pawn.h"

Pawn::Pawn(int position, Color color) {
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

Color Pawn::getColor() {
    return this->color;
}