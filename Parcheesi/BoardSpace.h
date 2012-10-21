#ifndef BoardSpace_Header
#define BoardSpace_Header

class PawnList;

#include "PawnList.h"

class BoardSpace {
    public:
        BoardSpace();
        PawnList* pawnList;
};

#endif