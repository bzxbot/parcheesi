#include "PawnSelector.h"

PawnSelector::PawnSelector(int x, int y, PawnType type) {
    this->x = x;
    this->y = y;
    this->radius = 50;
    this->type = type;
    this->active = false;
}

void PawnSelector::setNext(PawnSelector* next) {
    this->next = next;
}

PawnSelector* PawnSelector::getNext() {
    return this->next;
}

int PawnSelector::getX() {
    return this->x;
}

int PawnSelector::getY() {
   return this->y;
}

int PawnSelector::getRadius() {
    return this->radius;
}

PawnType PawnSelector::getType() {
    return this->type;
}

bool PawnSelector::isActive() {
    return this->active;
}

void PawnSelector::activate() {
    this->active = true;
}

void PawnSelector::deactivate() {
    this->active = false;
}