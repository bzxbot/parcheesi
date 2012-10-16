#include "Player.h"
#include "BoardSpace.h"

class Board {
    private:
        Player* player;
        BoardSpace* board = new BoardSpace[BoardSize];
        int specialPositions[12] = { 6, 12, 17, 22, 29, 34, 39, 46, 51, 56, 63, 68 };
    public:
        static const int BoardSize = 69;
        static const int BoardEndPosition = -8;
        static const int Nest = 0;
        void movePawn(int position, int endingPosition, Pawn* pawn);
        bool checkCapture(int position);
        int nextPawnPosition(int diceRoll, int currentPosition, int endingPosition);
        Board();
        void draw();
};