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
        int specialSpaces[12] = { 6, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63, 68 };
        AnimationQueue* animationQueue = new AnimationQueue();
    public:
        static const int Size = 68;
        static const int End = -8;
        static const int Nest = 0;
        Board();
        void movePawn(int diceRoll, Player* player, Pawn* pawn);
        bool checkCapture(int position);
        int nextPawnPosition(int diceRoll, int currentPosition, int startingPosition, int endingPosition);
};

#endif