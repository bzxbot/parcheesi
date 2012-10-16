#ifndef PawnList_Header
#define PawnList_Header

#include "PawnNode.h"

class PawnList {
    private:
        PawnNode* first;
    public:
        PawnNode* getFirst();
        void add(PawnNode* node);
    
};

#endif