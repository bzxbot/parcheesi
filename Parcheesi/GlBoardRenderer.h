#ifndef Parcheesi_BoardRenderer
#define Parcheesi_BoardRenderer

#include "Board.h"
#include "IObjectRenderer.h"

class Board;

class GlBoardRenderer : public IObjectRenderer {
    private:
        Board* board;
    public:
        GlBoardRenderer(Board* board);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* renderer);
        virtual void render();
};

#endif
