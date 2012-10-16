#include "Board.h"

Board::Board() {
}

void Board::draw() {
    
}

void Board::movePawn(int position, Pawn *pawn) {
    int oldPosition = pawn->getPosition();
    int newPosition = 0;//this->nextPawnPosition();

    this->board[position].pawnList->add(new PawnNode(pawn));
    pawn->setPosition(newPosition);
    
    if (checkCapture(newPosition)) {
        // new position.
        this->movePawn(position, pawn);
    }
}

//bool Board::checkCapture(int position) {
  //  return 0;
//}