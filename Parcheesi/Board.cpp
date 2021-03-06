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

bool Board::movePawn(int diceRoll, Player* player, Pawn *pawn) {
    int currentPosition = pawn->getPosition();
    int newPosition = this->nextPawnPosition(diceRoll, currentPosition, player->getStartingPosition(), player->getEndingPosition());
    int currentIndex = currentPosition - 1;
    int newIndex = newPosition - 1;
    
    pawn->setPosition(newPosition);
    
    if (newPosition > Board::Nest) {
    
        this->board[newIndex].pawnList->add(new PawnNode(pawn));
        
        if (currentPosition != 0) {
            this->board[currentIndex].pawnList->remove(new PawnNode(pawn));
        }
    
        if (checkCapture(newPosition, pawn, player)) {
            
            PawnNode* captured = this->board[newIndex].pawnList->getFirst();
            
            captured->getPawn()->setPosition(Board::Nest);
            
            this->board[newIndex].pawnList->remove(this->board[newIndex].pawnList->getFirst());
            
            return true;
        }
    } else if (newPosition < Board::Nest && currentPosition > Board::Nest) {
		this->board[currentIndex].pawnList->remove(new PawnNode(pawn));
	}
    
    return false;
}

bool Board::checkCapture(int position, Pawn* pawn, Player* currentPlayer) {
    // In special spaces, we can have more than one pawn in a space.
    for (int i = 0; i < 12; i++) {
        if (position == specialSpaces[i])
            return false;
    }
    
    int index = position - 1;
    
    if (this->board[index].pawnList->getFirst()) {
        PawnNode* node = this->board[index].pawnList->getFirst();

        if (node == 0 || node->getPawn()->getPlayer() == currentPlayer) {
            return false;
        } else {
            return true;
        }
    }

    return false;
}

bool Board::hasPawnAtIndex(int index) {
	if (this->board[index].pawnList->getFirst())
		return true;
	return false;
}

int Board::nextPawnPosition(int diceRoll, int currentPosition, int startingPosition, int endingPosition) {
    if (currentPosition == Board::Nest) {
        return startingPosition;
    } else if (currentPosition > Board::Nest) {
        bool end = false;
        int i;
        int p = currentPosition;
        
		if (p == endingPosition)
			end = true;
		else
			for(i = 1; i <= diceRoll; i++) {
				p = p + 1 > Board::Size ? p + 1 - Board::Size : p + 1;
				if (p == endingPosition) {
					end = true;
					break;
				}
			}
        
        if (end && i == diceRoll) {
            return endingPosition;
        } else if (end) {
			if (currentPosition > endingPosition)
				currentPosition = currentPosition - Board::Size;
            int remaining = endingPosition - currentPosition;
            int finalPosition = remaining - diceRoll;
            if (finalPosition < Board::End)
                return currentPosition;
            else
                return finalPosition;
        } else {
            int position = currentPosition + diceRoll;
            
            return position > Board::Size ? position - Board::Size : position ;
        }
        
    } else {        
        int position = currentPosition - diceRoll;
        
        return position < Board::End ? Board::End : position;
    }
}

bool Board::canAddNewPawn(int startingPosition) {
    PawnNode* node = this->board[startingPosition - 1].pawnList->getFirst();
    
    if (node != 0) {
        return this->board[startingPosition - 1].pawnList->getFirst()->getNext() == 0;
    }
    
    return true;
}