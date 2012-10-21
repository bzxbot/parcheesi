#ifndef Pawn_Header
#define Pawn_Header

#include "Parcheesi.h"
#include "GlPawnRenderer.h"

class Pawn {
    public:
        Pawn(int position);
        void setNextPawn(Pawn* pawn);
        Pawn* getNextPawn();
        int getPosition();
        void setPosition(int position);
    private:
        int position;
        Pawn* nextPawn;
};

#endif