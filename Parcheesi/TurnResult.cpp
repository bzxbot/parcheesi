#include "TurnResult.h"

TurnResult::TurnResult(bool pawnCapture, bool sixRoll) {
    this->pawnCapture = pawnCapture;
    this->sixRoll = sixRoll;
}

bool TurnResult::IsPawnCapture() {
    return this->pawnCapture;
}

bool TurnResult::IsSixRoll() {
    return this->sixRoll;
}