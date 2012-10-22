#ifndef Pawn_Header
#define Pawn_Header

#include "Parcheesi.h"
#include "GlPawnRenderer.h"
#include "Color.h"

class Pawn {
    public:
        Pawn(int position, Color color);
        void setNextPawn(Pawn* pawn);
        Pawn* getNextPawn();
        int getPosition();
        Color getColor();
        void setPosition(int position);
    private:
        int position;
        Pawn* nextPawn;
        Color color;
};

#endif