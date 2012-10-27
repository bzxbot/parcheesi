#ifndef Parcheesi_Board
#define Parcheesi_Board

#include "Player.h"
#include "BoardSpace.h"
#include "AnimationQueue.h"
#include "Parcheesi.h"

class BoardSpace;
class Player;

class Board {
    private:
        Player* player;
        BoardSpace* board;
        int specialSpaces[12] = { 2, 7, 14, 19, 24, 31, 36, 41, 48, 53, 58, 65};
        AnimationQueue* animationQueue = new AnimationQueue();
    public:
        static const int Size = 68;
        static const int End = -8;
        static const int Nest = 0;
        Board(Player* player);
        bool movePawn(int diceRoll, Player* player, Pawn* pawn);
        bool checkCapture(int position, Pawn* pawn, Player* currentPlayer);
        bool canAddNewPawn(int startingPosition);
        int nextPawnPosition(int diceRoll, int currentPosition, int startingPosition, int endingPosition);
		bool hasPawnAtIndex(int index);
};

#endif