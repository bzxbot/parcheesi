#ifndef PawnNode_Header
#define PawnNode_Header

#include "Pawn.h"

class PawnNode {
    private:
        PawnNode* next;
    Pawn* pawn;
    public:
        PawnNode(Pawn* pawn);
        PawnNode* getNext();
        void setNext(PawnNode* pawnNode);
        Pawn* getPawn();
};

#endif