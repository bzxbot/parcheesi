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
#include "GlDiceRenderer.h"

#include "iostream"
#include <time.h>
#include <stdio.h>

class Board;
class GlRenderer;
class Player;
class PawnList;
class GlutWindow;

enum State {
	PrepareTurn,
	PlayerInput,
	RobotInput,
	Turn
};

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
    
		int nTurns = 0;
        int diceRoll;
        int animations = 0;
        PawnType pawnType;
    
        static const int NewPawnDiceRoll = 5;
    
		State state = State::PrepareTurn;
    
        bool isAnimating();
        PawnList* prepareTurn();
        Pawn* selectFirstPawn(PawnList* pawnList);
        Pawn* selectPawn(PawnType type);
        TurnResult* turn(Pawn* pawn);
        bool isGameOver();
        void gameOver();
        int rollDice();
        int nextPawnPosition(int currentPosition, int diceRoll, int endingPosition);
        void updatePawnSelectors(PawnList* pawnList);
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
		int lastDiceRoll();
		State getState();
		bool isCurrentPlayerHuman();
		Color getColorOfCurrentPlayer();
		PawnList* getPlayablePawns(int diceRoll);
		bool hasPawnInPosition(int position);
};



#endif