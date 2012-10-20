#include "Board.h"
#include "iostream"

Board::Board() {
    
}

void Board::draw() {
    
    this->animate();
    
    // Drawing code.
}

void Board::animate() {
    Animation* animation = animationQueue->dequeue();
    
    while(animation != 0) {
        // Do animation.
        animation = animationQueue->dequeue();
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
    
    return this->board[position].pawnList->getFirst()->getNext() != 0;
}

int Board::nextPawnPosition(int diceRoll, int currentPosition, int startingPosition, int endingPosition) {
    if (currentPosition == Board::Nest) {
        return startingPosition;
    } else if (currentPosition > Board::Nest) {
        bool end = false;
        
        for(int i = 1; i <= diceRoll; i++) {
            if (currentPosition + i > endingPosition) {
                end = true;
                break;
            }
        }
        
        if (end) {
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