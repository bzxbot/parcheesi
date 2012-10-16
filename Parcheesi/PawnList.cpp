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

PawnNode* PawnList::getFirst() {
    return this->first;
}