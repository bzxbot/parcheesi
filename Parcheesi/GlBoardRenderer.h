#ifndef Parcheesi_BoardRenderer
#define Parcheesi_BoardRenderer

#include "Board.h"

class GlBoardRenderer {
    private:
        Board* board;
    public:
        GlBoardRenderer(Board* board);
        void render();
};

#endif
