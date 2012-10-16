#include "PlayerColor.h"
#include "Pawn.h"

class Player {
    public:
        Player(PlayerColor* playerColor);
        Player* getNextPlayer();
        void setNextPlayer(Player* nextPlayer);
        Pawn* getFirstPawn();
        PlayerColor* getPlayerColor();
    private:
        PlayerColor* playerColor;
        Player* nextPlayer;
        Pawn* firstPawn;
};