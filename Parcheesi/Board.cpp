#include "Board.h"

Board::Board(Player* player) {
    board = new BoardSpace[Board::Size];

    Player* p = player;
    bool first = true;
    
    while (p != player || first) {
        first = false;
        
        this->board[p->getFirstPawn()->getPosition() - 1].pawnList->add(new PawnNode(p->getFirstPawn()));
        
        p = p->getNextPlayer();
    }
}

void Board::movePawn(int diceRoll, Player* player, Pawn *pawn) {
    int currentPosition = pawn->getPosition();
    int newPosition = this->nextPawnPosition(diceRoll, currentPosition, player->getStartingPosition(), player->getEndingPosition());
    int currentIndex = currentPosition - 1;
    int newIndex = newPosition - 1;
    
    pawn->setPosition(newPosition);
    
    if (newPosition > Board::Nest) {
    
        this->board[newIndex].pawnList->add(new PawnNode(pawn));
        
        if (currentPosition != 0)
            this->board[currentIndex].pawnList->remove(new PawnNode(pawn));
    
        if (checkCapture(newPosition)) {
            
            this->movePawn(20, player, pawn);
            
            PawnNode* captured = this->board[newIndex].pawnList->getFirst();
            
            captured->getPawn()->setPosition(Board::Nest);
            
            this->board[newIndex].pawnList->remove(this->board[newIndex].pawnList->getFirst());
        }
    }
}

bool Board::checkCapture(int position) {
    // In special spaces, we can have more than one pawn in a space.
    for (int i = 0; i < 12; i++) {
        if (position == specialSpaces[i])
            return false;
    }
    
    int index = position - 1;
    
    if (this->board[index].pawnList->getFirst())
        return this->board[index].pawnList->getFirst()->getNext() != 0;
    return false;
}

int Board::nextPawnPosition(int diceRoll, int currentPosition, int startingPosition, int endingPosition) {
    if (currentPosition == Board::Nest) {
        return startingPosition;
    } else if (currentPosition > Board::Nest) {
        bool end = false;
        int i;
        for(i = 1; i <= diceRoll; i++) {
            if (currentPosition + i == endingPosition) {
                end = true;
                break;
            }
        }
        
        if (end && i == diceRoll) {
            return endingPosition;
        } else if (end) {
            int remaining = endingPosition - currentPosition;
            
            return remaining - diceRoll;
        } else {
            int position = currentPosition + diceRoll;
            
            return position > Board::Size ? position - Board::Size : position ;
        }
        
    } else {        
        int position = currentPosition - diceRoll;
        
        return position < Board::End ? Board::End : position;
    }
}