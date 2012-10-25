#include "PawnSelector.h"
#include "Parcheesi.h"
#include "Pawn.h"
#include "PawnNode.h"
#include "PawnList.h"

PawnSelector::PawnSelector(int x, int y, PawnType type) {
    this->x = x;
    this->y = y;
    this->radius = 25;
    this->type = type;
    this->active = false;
}

void PawnSelector::setNext(PawnSelector* next) {
    this->next = next;
}

PawnSelector* PawnSelector::getNext() {
    return this->next;
}

int PawnSelector::getX() {
    return this->x;
}

int PawnSelector::getY() {
   return this->y;
}

int PawnSelector::getRadius() {
    return this->radius;
}

PawnType PawnSelector::getType() {
    return this->type;
}

bool PawnSelector::isActive() {
	PawnList *pawnList = Parcheesi::getInstance()->getPlayablePawns(0);
	PawnNode *pawnNode = pawnList->getFirst();
	
	if (!Parcheesi::getInstance()->isCurrentPlayerHuman())
		return false;
	
	while (pawnNode != 0) {
		if (pawnNode->getPawn()->getType() == this->getType())
			return true;
		pawnNode = pawnNode->getNext();
	}
	
	return false;
    //return this->active;
}

void PawnSelector::activate() {
    this->active = true;
}

void PawnSelector::deactivate() {
    this->active = false;
}