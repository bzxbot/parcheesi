#include "Board.h"
#include "PawnList.h"

class Parcheesi {
    private:
        Board* board;
        Player* firstPlayer;
        Player* humanPlayer;
        Player* currentPlayer;
        int previousRoll = 2 ;
        void turn();
        bool isGameOver();
        void gameOver();
        int diceRoll();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
    public:
        Parcheesi();
        void run();
};