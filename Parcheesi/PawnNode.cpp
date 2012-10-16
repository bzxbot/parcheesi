#include "PawnNode.h"

PawnNode::PawnNode(Pawn* pawn) {
    this->pawn = pawn;
}

void PawnNode::setNext(PawnNode* pawnNode) {
    this->next = pawnNode;
}

PawnNode* PawnNode::getNext() {
    return this->next;
}

Pawn* PawnNode::getPawn() {
    return this->pawn;
}