#include "PawnSelector.h"

PawnSelector::PawnSelector(int x, int y, PawnType type) {
    this->x = x;
    this->y = y;
    this->type = type;
}

void PawnSelector::setNext(PawnSelector* next) {
    this->next = next;
}

PawnSelector* PawnSelector::getNext() {
    return this->next;
}

int PawnSelector::getX() {
    this->x;
}

int PawnSelector::getY() {
    this->y;
}

int PawnSelector::getRadius() {
    this->radius;
}

PawnType PawnSelector::getType() {
    this->type;
}