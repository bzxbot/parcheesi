#include "PawnList.h"

PawnList::PawnList() {
    this->first = 0;
}

void PawnList::add(PawnNode* pawnNode) {
    
    if (this->first == 0) {
        this->first = pawnNode;
    } else {
        PawnNode* current = this->first;
        while(current->getNext() != 0) {
            current = current->getNext();
        }
        current->setNext(pawnNode);
    }
}

void PawnList::remove(PawnNode* node) {
    
    if (this->first->getPawn() == node->getPawn()) {
        this->first = this->first->getNext();
    } else {
        PawnNode* previous = this->first;
        PawnNode* current = this->first->getNext();
        while(current != 0) {
            if (current->getPawn() == node->getPawn()) {
                previous->setNext(current->getNext());
                break;
            }
            previous = current;
            current = current->getNext();
        }
    }
}

PawnNode* PawnList::getFirst() {
    return this->first;
}