#ifndef Parcheesi_GlPawnRenderer
#define Parcheesi_GlPawnRenderer

#include "Pawn.h"
#include "IObjectRenderer.h"
#include "Color.h"
#include "Board.h"

class Pawn;

class GlPawnRenderer : public IObjectRenderer {
    private:
        Pawn* pawn;
        int boardSpacePositions[68][4]; //TODO - change
        int startPositions[4][4][2];
        int getColorIndex(Color color);
    
    public:
        GlPawnRenderer(Pawn* pawn);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* next);
        virtual void render();
};

#endif
