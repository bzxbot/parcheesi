#include "Board.h"

class Parcheesi {
    private:
        Board *board;
        void playerTurn();
        void nextTurn();
    public:
        void run();
};