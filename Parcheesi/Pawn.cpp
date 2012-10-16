#include "Pawn.h"

Pawn::Pawn(int position) {
    this->position = position;
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

void Pawn::incrementPositionBy(int value) {
    this->position = this->position + value;
}