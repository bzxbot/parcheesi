#ifndef PawnList_Header
#define PawnList_Header

#include "PawnNode.h"

class PawnNode;

class PawnList {
    private:
        PawnNode* first;
    public:
        PawnNode* getFirst();
        void add(PawnNode* node);
        void remove(PawnNode* node);
    
};

#endif