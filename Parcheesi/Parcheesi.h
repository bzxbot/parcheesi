#ifndef Parcheesi_Header
#define Parcheesi_Header

#include "Board.h"
#include "PawnList.h"
#include "GlutWindow.h"
#include "GlRenderer.h"
#include "Color.h"

#include "iostream"

class Board;
class GlRenderer;
class Player;
class PawnList;

class Parcheesi {
    private:
        Parcheesi();
    
        Board* board;
        Player* firstPlayer;
        Player* currentPlayer;
        GlutWindow* window;
        GlRenderer* renderer;
    
        static Parcheesi* instance;
    
        int previousRoll = 2;
        int animations = 0;
    
        bool canRollTheDice();
        void turn();
        bool isGameOver();
        void gameOver();
        int diceRoll();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
        PawnList* getPlayablePawns(int diceRoll);
        static void display();
        static void timer();
    public:
        void start();
        static Parcheesi* getInstance();
        void enqueueAnimation();
        void dequeueAnimation();
};



#endif