#ifndef Parcheesi_Header
#define Parcheesi_Header

#include "Board.h"
#include "PawnList.h"
#include "GlutWindow.h"
#include "GlRenderer.h"
#include "Color.h"
#include "TurnResult.h"
#include "GlutMouseInput.h"
#include "PawnSelector.h"
#include "GlPawnSelectorRenderer.h"

#include "iostream"
#include <time.h>
#include <stdio.h>

class Board;
class GlRenderer;
class Player;
class PawnList;
class GlutWindow;

class Parcheesi {
    private:
        Parcheesi();
    
        Board* board;
        Player* firstPlayer;
        Player* lastPlayer;
        Player* currentPlayer;
        GlutWindow* window;
        GlRenderer* renderer;
        GlutMouseInput* mouseInput;
        TurnResult* lastTurn;
        PawnList* playablePawns;
        Pawn* selectedPawn;
        PawnSelector* pawnSelector;
    
        static Parcheesi* instance;
    
        int previousRoll = 1;
		int nTurns = 0;
        int diceRoll;
        int animations = 0;
        PawnType pawnType;
    
        static const int NewPawnDiceRoll = 5;
    
        enum State {
            PrepareTurn,
            PlayerInput,
            RobotInput,
            Turn
        };
    
        State state = State::PrepareTurn;
    
        bool isAnimating();
        PawnList* prepareTurn();
        Pawn* selectPawn(PawnList* pawnList);
        void turn(Pawn* pawn);
        bool isGameOver();
        void gameOver();
        int rollDice();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
        void updatePawnSelectors(PawnList* pawnList);
        PawnList* getPlayablePawns(int diceRoll);
        bool isInputReady();
        static void display();
        static void timer();
        static void setSelectedPawn(PawnType type);
    public:
        void start();
        static Parcheesi* getInstance();
        void enqueueAnimation();
        void dequeueAnimation();
		int getNumberOfTurns();
};



#endif