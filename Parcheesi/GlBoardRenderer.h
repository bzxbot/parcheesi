#ifndef Parcheesi_BoardRenderer
#define Parcheesi_BoardRenderer

#include "Board.h"
#include "IObjectRenderer.h"

class Board;

class GlBoardRenderer : public IObjectRenderer {
    private:
        Board* board;
        void drawTable();
        void drawCentral();
        void drawSafeSpots();
        void drawVertical(float r, float g, float b);
        void drawHorizontal(float r, float g, float b);
        void drawSingleSpot(float r, float g, float b);
    public:
        GlBoardRenderer(Board* board);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* renderer);
        virtual void render();
};

#endif
