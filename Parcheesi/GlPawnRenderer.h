#ifndef Parcheesi_GlPawnRenderer
#define Parcheesi_GlPawnRenderer

#include "Pawn.h"
#include "IObjectRenderer.h"
#include "Color.h"
#include "Board.h"
#include <math.h>
#include "Canvas.h"

class Pawn;

class GlPawnRenderer : public IObjectRenderer {
    private:
        static const int speed = 3;
        Pawn* pawn;
        int boardSpacePositions[68][4]; //TODO - change
        int startPositions[4][4][2];
        int getColorIndex(Color color);
        void calculatePawnPosition();
		void initialize();
		int pawnOnly, pawnL, pawnMinus, pawnPlus;
		Canvas cvs;
    public:
        GlPawnRenderer(Pawn* pawn);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* next);
        virtual void render();
};

#endif
