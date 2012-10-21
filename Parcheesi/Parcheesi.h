#ifndef Parcheesi_Header
#define Parcheesi_Header

#include "Board.h"
#include "PawnList.h"
#include "GlutWindow.h"
#include "GlRenderer.h"

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
        GlutWindow* glutWindow;

        static GlRenderer* renderer;
        static Parcheesi* instance;
    
        int previousRoll = 2 ;
    
        void turn();
        bool isGameOver();
        void gameOver();
        int diceRoll();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
        PawnList* getPlayablePawns(int diceRoll);
        static void render();
        static void animation();
    public:
        void start();
        static Parcheesi* getInstance();
        static GlRenderer* getRenderer();
};



#endif