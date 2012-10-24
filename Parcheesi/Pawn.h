#ifndef Pawn_Header
#define Pawn_Header

#include "Parcheesi.h"
#include "GlPawnRenderer.h"
#include "Color.h"
#include "PawnType.h"
#include "Player.h"

class Player;

class Pawn {
    public:
        Pawn(int position, int startPosition, Color color, Player* player, PawnType type);
        void setNextPawn(Pawn* pawn);
        Pawn* getNextPawn();
        int getPosition();
        int getStartPosition();
        Color getColor();
        void setPosition(int position);
        void setStartPosition(int position);
        void setCoordinates(float x, float y);
        float getXCoordinate();
        float getYCoordinate();
        Player* getPlayer();
        PawnType getType();
    private:
        Pawn* nextPawn;
        Player* player;
        Color color;
        PawnType type;
        int position;
        int startPosition;
        float coordinates[2] = {0, 0};

};

#endif