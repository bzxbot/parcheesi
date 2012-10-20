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
        enum Type {
            Human,
            AI
        };
        Player(Type type, Color color, int startingPosition, int endingPosition);
        Player* getNextPlayer();
        Pawn* getFirstPawn();
        void setNextPlayer(Player* nextPlayer);
        int getStartingPosition();
        int getEndingPosition();
        Type getPlayerType();
    private:
        Player* nextPlayer;
        Pawn* firstPawn;
        Color color;
        Type type;
        int startingPosition;
        int endingPosition;
};

#endif