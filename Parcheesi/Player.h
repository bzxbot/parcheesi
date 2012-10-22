#ifndef Parcheesi_Player
#define Parcheesi_Player

#include "Pawn.h"
#include "Color.h"

class Pawn;

class Player {
    public:
        enum Type {
            Human,
            Robot
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
        Type type;
        int startingPosition;
        int endingPosition;
};

#endif