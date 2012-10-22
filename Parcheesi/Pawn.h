#ifndef Pawn_Header
#define Pawn_Header

#include "Parcheesi.h"
#include "GlPawnRenderer.h"
#include "Color.h"

class Pawn {
    public:
        Pawn(int position, int startPosition, Color color);
        void setNextPawn(Pawn* pawn);
        Pawn* getNextPawn();
        int getPosition();
        int getStartPosition();
        Color getColor();
        void setPosition(int position);
        void setStartPosition(int position);
    private:
        int position;
        int startPosition;
        Pawn* nextPawn;
        Color color;
};

#endif