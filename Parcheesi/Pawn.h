#ifndef Pawn_Header
#define Pawn_Header

class Pawn {
    public:
        Pawn(int position);
        void setNextPawn(Pawn* pawn);
        Pawn* getNextPawn();
        int getPosition();
        void setPosition(int position);
        void incrementPositionBy(int value);
    private:
        int position;
        Pawn* nextPawn;
};

#endif