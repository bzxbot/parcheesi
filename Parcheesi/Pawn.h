#ifndef Pawn_Header
#define Pawn_Header

#include "Parcheesi.h"
#include "GlPawnRenderer.h"
#include "Color.h"
#include "Player.h"

class Player;

class Pawn {
    public:
        Pawn(int position, int startPosition, Color color, Player* player);
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
    private:
        int position;
        int startPosition;
        Pawn* nextPawn;
        Color color;
        float coordinates[2] = {0, 0};
        Player* player;
};

#endif