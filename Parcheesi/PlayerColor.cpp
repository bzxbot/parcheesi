#include "PlayerColor.h"

PlayerColor::PlayerColor(Color color, int startingPosition, int endingPosition) {
    this->color = color;
    this->startingPosition = startingPosition;
    this->endingPosition = endingPosition;
}

int PlayerColor::getStartingPosition() {
    return this->startingPosition;
}

int PlayerColor::getEndingPosition() {
    return this->endingPosition;
}