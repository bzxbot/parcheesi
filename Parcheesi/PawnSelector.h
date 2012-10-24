#ifndef Parcheesi_PawnSelector
#define Parcheesi_PawnSelector

#include "PawnType.h"

class PawnSelector {
    public:
        PawnSelector(int x, int y, PawnType type);
        void setNext(PawnSelector* next);
        PawnSelector* getNext();
        int getX();
        int getY();
        int getRadius();
        PawnType getType();
    private:
        int x, y, radius;
        PawnSelector* next;
        PawnType type;
};

#endif
