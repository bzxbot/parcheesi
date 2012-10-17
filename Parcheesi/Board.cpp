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

void Board::movePawn(int diceRoll, int endingPosition, Pawn *pawn) {
    int oldPosition = pawn->getPosition();
    int newPosition = this->nextPawnPosition(diceRoll, oldPosition, endingPosition);
    
    pawn->setPosition(newPosition);
    
    if (newPosition > 0) {
    
        this->board[newPosition].pawnList->add(new PawnNode(pawn));
        
        animationQueue->enqueue(new Animation(oldPosition, newPosition));
    
        if (checkCapture(newPosition)) {
            this->movePawn(20, endingPosition, pawn);
            PawnNode* captured = this->board[newPosition].pawnList->getFirst();
            captured->getPawn()->setPosition(Nest);
            animationQueue->enqueue(new Animation(newPosition, Nest));
            this->board[newPosition].pawnList->remove(this->board[newPosition].pawnList->getFirst());
        }
    }
}

bool Board::checkCapture(int position) {

    // In special spaces, we can have more than one pawn.
    for (int i = 0; i < 12; i++) {
        if (position == specialSpaces[i])
            return false;
    }
    
    return this->board[position].pawnList->getFirst()->getNext() != 0;
}

int Board::nextPawnPosition(int diceRoll, int currentPosition, int endingPosition) {
    int nest = 0;
    int end = -8;
    int boardEnd = 68;
    
    if (currentPosition > nest) {
        
        bool end = false;
        
        for(int i = 1; i <= diceRoll; i++) {
            if (currentPosition + i == endingPosition) {
                end = true;
                break;
            }
        }
        
        if (end) {
            int remaining = endingPosition - currentPosition;
            return remaining - diceRoll;
        } else {
            int position = currentPosition + diceRoll;
            
            if (position > boardEnd)
                position = position - boardEnd;
            
            return position;
        }
        
    } else {
        
        int position = currentPosition - diceRoll;
        
        if (position < end)
            position = end;
        
        return position;
    }
}