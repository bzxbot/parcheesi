#include "GlutMouseInput.h"

GlutMouseInput::GlutMouseInput(PawnSelector *pawnSelector, void (*inputCallbackFunction)(PawnType type)) {
    this->first = pawnSelector;
    this->inputCallbackFunction = inputCallbackFunction;
}

bool GlutMouseInput::setInput(int x, int y) {
    // (x-center_x)^2 + (y - center_y)^2 <= radius^2

    // Check if x and y are inside any of the pawn selectors;
    
    PawnSelector* pawnSelector = this->first;
    
    while (pawnSelector != 0) {
        int px = pawnSelector->getX();
        int py = pawnSelector->getY();
        int radius = pawnSelector->getRadius();
        
        if (pow((x - px), 2) + pow((y - py), 2) <= pow(radius, 2)) {
            inputCallbackFunction(pawnSelector->getType());
        }
        
        pawnSelector = pawnSelector->getNext();
    }
    
    return false;
}