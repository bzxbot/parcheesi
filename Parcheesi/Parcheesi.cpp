#include "Parcheesi.h"

void Parcheesi::playerTurn() {
    
}

void Parcheesi::nextTurn() {
    
}

void Parcheesi::run() {
    bool running = true;
    
    while (running) {
        
        // Get player input.
        
        this->playerTurn();
        
        // Draw board.
        
        board->draw();
        
        // Player's turn.
    
        this->nextTurn();
    }
}