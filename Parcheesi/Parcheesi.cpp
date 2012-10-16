#include "Parcheesi.h"
#include "iostream"

Parcheesi::Parcheesi() {
    board = new Board();
    
    // TODO: Randomize the players.
    Player* firstPlayer = new Player(new PlayerColor(PlayerColor::Color::Blue, 22, 17));
    Player* secondPlayer = new Player(new PlayerColor(PlayerColor::Color::Red, 39, 34));
    Player* thirdPlayer = new Player(new PlayerColor(PlayerColor::Color::Yellow, 5, 68));
    Player* forthPlayer = new Player(new PlayerColor(PlayerColor::Color::Green, 56, 51));
    
    firstPlayer->setNextPlayer(secondPlayer);
    secondPlayer->setNextPlayer(thirdPlayer);
    thirdPlayer->setNextPlayer(forthPlayer);
    forthPlayer->setNextPlayer(firstPlayer);
    
    this->firstPlayer = firstPlayer;
    this->currentPlayer = this->firstPlayer;
    
    // TODO: For now, the human player is always the first player.
    this->humanPlayer = this->firstPlayer;
}

void Parcheesi::turn() {
    int diceRoll = 5; // Roll dice.
    int canAddNewPawn = 5;
    int nest = 0;
    int end = -8;
    PawnList* pawnList = new PawnList();
    Pawn* pawn = this->currentPlayer->getFirstPawn();
    
    if (diceRoll == canAddNewPawn) {

        // Find a pawn in nest and add to can play list.
        
        pawn = this->currentPlayer->getFirstPawn();

        while(pawn != 0) {
            if (pawn->getPosition() == nest){
                pawnList->add(new PawnNode(pawn));
                break;
            }
            
            pawn = pawn->getNextPawn();
        }
    }
    
    // Find all pawns in positions not in nest or end and add to possible play list.
    
    pawn = this->currentPlayer->getFirstPawn();
    
    while(pawn != 0) {
        if (pawn->getPosition() != nest && pawn->getPosition() != end) {
            pawnList->add(new PawnNode(pawn));
        }
        
        pawn = pawn->getNextPawn();
    }
    
    // Highlight possible play pawns.
    
    // User selects pawn.
    
    // For now, always selects the first pawn in the PawnList.
    
    Pawn* pawnToPlay = pawnList->getFirst()->getPawn();
    
    if (pawnToPlay->getPosition() == nest) {
        pawnToPlay->setPosition(this->currentPlayer->getPlayerColor()->getStartingPosition());
    } else {
        int position = this->nextPawnPosition(pawnToPlay->getPosition(), diceRoll, this->currentPlayer->getPlayerColor()->getEndingPosition());
        position = this->checkCapture(position);
        pawnToPlay->setPosition(position);
        board->movePawn(position, pawnToPlay);
    }
    
    this->currentPlayer = this->currentPlayer->getNextPlayer();
    
    std::cout << pawnToPlay->getPosition() << "\n";
}

void Parcheesi::run() {
    
    while (!isGameOver()) {
        
        board->draw();
    
        this->turn();
    }
    
    gameOver();
}

bool Parcheesi::isGameOver() {
    return false;
}

void Parcheesi::gameOver() {
    
}

int Parcheesi::nextPawnPosition(int currentPosition, int diceRoll, int endingPosition) {
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