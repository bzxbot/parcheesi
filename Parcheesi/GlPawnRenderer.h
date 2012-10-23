#ifndef Parcheesi_GlPawnRenderer
#define Parcheesi_GlPawnRenderer

#include "Pawn.h"
#include "IObjectRenderer.h"
#include "Color.h"
#include "Board.h"
#include <math.h>

class Pawn;

class GlPawnRenderer : public IObjectRenderer {
    private:
        static const int speed = 2;
        Pawn* pawn;
        int boardSpacePositions[68][4]; //TODO - change
        int startPositions[4][4][2];
        int getColorIndex(Color color);
        void calculatePawnPosition();
    public:
        GlPawnRenderer(Pawn* pawn);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* next);
        virtual void render();
};

#endif
