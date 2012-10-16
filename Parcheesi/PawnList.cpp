#include "PawnList.h"

void PawnList::add(PawnNode* pawnNode) {
    
    if (this->first == 0) {
        this->first = pawnNode;
    } else {
        PawnNode* previous = this->first;
        PawnNode* current = previous;
        while(current->getNext() != 0) {
            previous = current;
            current = current->getNext();
        }
        previous->setNext(pawnNode);
    }
}

void PawnList::remove(PawnNode* node) {
    
    if (this->first == node) {
        this->first = this->first->getNext();
    } else {
        PawnNode* previous = this->first;
        PawnNode* current = this->first->getNext();
        while(current != 0) {
            if (current == node) {
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