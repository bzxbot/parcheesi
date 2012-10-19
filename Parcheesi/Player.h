#ifndef Player_Header
#define Player_Header

#include "Pawn.h"

class Player {
    public:
        enum Color {
            Blue,
            Red,
            Green,
            Yellow
        };
        Player(Color color, int startingPosition, int endingPosition);
        Player* getNextPlayer();
        Pawn* getFirstPawn();
        void setNextPlayer(Player* nextPlayer);
        int getStartingPosition();
        int getEndingPosition();
    private:
        Player* nextPlayer;
        Pawn* firstPawn;
        Color color;
        int startingPosition;
        int endingPosition;
};

#endif