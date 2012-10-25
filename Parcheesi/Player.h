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
        Color getColor();
        void capture();
        void useCapture(Pawn* pawn);
        bool hasCaptured();
		bool isHuman();
    private:
        Player* nextPlayer;
        Pawn* firstPawn;
        Type type;
        Color color;
        int startingPosition;
        int endingPosition;
        bool captured;
};

#endif