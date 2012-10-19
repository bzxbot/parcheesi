#ifndef Parcheesi_Header
#define Parcheesi_Header

#include "Board.h"
#include "PawnList.h"
#include "GlutWindow.h"

class Parcheesi {
    private:
        Board* board;
        Player* firstPlayer;
        Player* humanPlayer;
        Player* currentPlayer;
        GlutWindow* window;

        static int test;
        int previousRoll = 2 ;
        void turn();
        bool isGameOver();
        void gameOver();
        int diceRoll();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
    public:
        Parcheesi();
        void run();
        void animation();
        static Parcheesi* game;
        static void run2();
        static void animation2();
};

#endif