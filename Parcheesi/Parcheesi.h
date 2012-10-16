#include "Board.h"
#include "PawnList.h"

class Parcheesi {
    private:
        Board* board;
        Player* firstPlayer;
        Player* humanPlayer;
        Player* currentPlayer;
        void turn();
        bool isGameOver();
        void gameOver();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
        int checkCapture(int position);
    public:
        Parcheesi();
        void run();
};