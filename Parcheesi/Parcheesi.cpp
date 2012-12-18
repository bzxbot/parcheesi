#include "Parcheesi.h"

Parcheesi* Parcheesi::instance = new Parcheesi();

PawnList* Parcheesi::prepareTurn() {
    
    if (lastTurn->IsPawnCapture()) {
        this->diceRoll = 20;
    } else {
        this->diceRoll = this->rollDice();
    }
    
    return this->getPlayablePawns(diceRoll);
}

Pawn* Parcheesi::selectFirstPawn(PawnList* pawnList) {
    
    if(pawnList->getFirst() == 0) {
        return 0;
    }
    
    return pawnList->getFirst()->getPawn();
}

Pawn* Parcheesi::selectPawn(PawnType type) {
    PawnNode *pawnNode = this->playablePawns->getFirst();
	
	while (pawnNode != 0) {
		if (pawnNode->getPawn()->getType() == type) {
            return pawnNode->getPawn();
        }
		pawnNode = pawnNode->getNext();
	}
    
    return 0;
}

TurnResult* Parcheesi::turn(Pawn* pawn) {
    
    bool capture = false;

    if (pawn != 0) {
        capture = board->movePawn(diceRoll, this->currentPlayer, pawn);
    }
    
    if (!capture) {
        this->currentPlayer = this->currentPlayer->getNextPlayer();
    }
    
    return new TurnResult(capture, false);
}

Parcheesi* Parcheesi::getInstance() {
    return instance;
}

PawnList* Parcheesi::getPlayablePawns(int diceRoll) {
    PawnList* pawnList = new PawnList();
    Pawn* pawn;
    
    // Find a pawn in nest and add to the pawn list.
    
    if (diceRoll == Parcheesi::NewPawnDiceRoll &&
        this->board->canAddNewPawn(this->currentPlayer->getStartingPosition())) {
        
        pawn = this->currentPlayer->getFirstPawn();
        
        while(pawn != 0) {
            if (pawn->getPosition() == Board::Nest){
                pawnList->add(new PawnNode(pawn));
                break;
            }
            
            pawn = pawn->getNextPawn();
        }
    }
    
    if (pawnList->getFirst() != 0)
        return pawnList;
    
    // Find all pawns in positions not in nest or end and add to pawn list.
    
    pawn = this->currentPlayer->getFirstPawn();
    
    while(pawn != 0) {
        if (pawn->getPosition() != Board::Nest && pawn->getPosition() != Board::End) {
            pawnList->add(new PawnNode(pawn));
        }
        
        pawn = pawn->getNextPawn();
    }
    
    return pawnList;
}

void Parcheesi::display() {
    instance->renderer->render();
}

void Parcheesi::enqueueAnimation()
{
    this->animations++;
}

void Parcheesi::dequeueAnimation()
{
    this->animations--;
    
    if (this->animations < 0) {
        this->animations = 0;
    }
}

bool Parcheesi::isAnimating() {
    return animations != 0;
}

void Parcheesi::timer() {
    instance->window->redisplay();
    
    if (instance->isGameOver()) {
        instance->gameOver();
    }
    
    switch (instance->state) {
        case State::PrepareTurn:
            instance->pawnType = PawnType::None;
            instance->selectedPawn = 0;
            instance->playablePawns = instance->prepareTurn();
            if (instance->currentPlayer->getPlayerType() == Player::Type::Human && instance->playablePawns->getFirst() != 0) {
                instance->state = State::PlayerInput;
			}
            else {
                instance->state = State::RobotInput;
            }
            break;
        case State::PlayerInput:
            instance->updatePawnSelectors(instance->playablePawns);
            if (instance->isInputReady()) {
                instance->selectedPawn = instance->selectPawn(instance->pawnType);
                instance->state = State::Turn;
            }
            break;
        case State::RobotInput:
            instance->selectedPawn = instance->selectFirstPawn(instance->playablePawns);
            instance->state = State::Turn;
            break;
        case State::Turn:
            instance->lastTurn = instance->turn(instance->selectedPawn);
            instance->state = State::PrepareTurn;
            break;
    }
}

void Parcheesi::updatePawnSelectors(PawnList* pawnList) {
    PawnSelector* pawnSelector = this->pawnSelector;
    
    while(pawnSelector != 0) {
        pawnSelector->deactivate();
        
        pawnSelector = pawnSelector->getNext();
    }
    
    PawnNode* pawnNode = pawnList->getFirst();
    
    while(pawnNode != 0) {
        
        Pawn* pawn = pawnNode->getPawn();
        
        pawnSelector = this->pawnSelector;

        while(pawnSelector != 0) {
            if (pawnSelector->getType() == pawn->getType()){
                pawnSelector->activate();
            }
            
            pawnSelector = pawnSelector->getNext();
        }
        
        pawnNode = pawnNode->getNext();
    }
}

bool Parcheesi::isGameOver() {
    Player* player = this->firstPlayer;
    bool gameOver = true;
    bool first = true;
    
    while (player != this->firstPlayer || first) {
        Pawn* pawn = player->getFirstPawn();
        
        while(pawn != 0) {
            if (pawn->getPosition() != Board::End)
                gameOver = false;
            pawn = pawn->getNextPawn();
        }
        
        player = player->getNextPlayer();
        first = false;
    }
    
    return gameOver;
}

bool Parcheesi::isInputReady() {
    return this->pawnType != PawnType::None;
}

void Parcheesi::setSelectedPawn(PawnType type) {
    instance->pawnType = type;
}

void Parcheesi::gameOver() {
    window->stopTimer();
    
    std::cout << "Game Over!";
}

int Parcheesi::rollDice() {
	this->nTurns++;
    
    return rand()%6+1;
}

int Parcheesi::getNumberOfTurns() {
	return this->nTurns;
}

Color Parcheesi::getColorOfCurrentPlayer() {
	return this->currentPlayer->getColor();
}

int Parcheesi::lastDiceRoll() {
	return diceRoll;
}

State Parcheesi::getState() {
	return this->state;
}

bool Parcheesi::isCurrentPlayerHuman() {
	return this->currentPlayer->isHuman();
}

bool Parcheesi::hasPawnInPosition(int position) {
	return this->board->hasPawnAtIndex(position-1);
}

void Parcheesi::start() {
    window->show();
}

Parcheesi::Parcheesi() {
    srand((unsigned int)time(0));

    renderer = new GlRenderer();
    
    PawnSelector* selectorPlus = new PawnSelector(10 + 25, 230 + 25, PawnType::Plus);
    PawnSelector* selectorMinus = new PawnSelector(80 + 25, 230 + 25, PawnType::Minus);
    PawnSelector* selectorPipe = new PawnSelector(80 + 25, 300 + 25, PawnType::Pipe);
    PawnSelector* selectorBlank = new PawnSelector(10 + 25, 300 + 25, PawnType::Blank);
    
    selectorPlus->setNext(selectorMinus);
    selectorMinus->setNext(selectorPipe);
    selectorPipe->setNext(selectorBlank);
    selectorBlank->setNext(0);
    
    this->mouseInput = new GlutMouseInput(selectorPlus, &Parcheesi::setSelectedPawn);
    
    window = new GlutWindow(this->mouseInput, &Parcheesi::display, &Parcheesi::timer);

    renderer->registerRender(new GlPawnSelectorRenderer(selectorPlus));
    renderer->registerRender(new GlPawnSelectorRenderer(selectorMinus));
    renderer->registerRender(new GlPawnSelectorRenderer(selectorPipe));
    renderer->registerRender(new GlPawnSelectorRenderer(selectorBlank));
	
	renderer->registerRender(new GlDiceRenderer(1));
	renderer->registerRender(new GlDiceRenderer(2));
	renderer->registerRender(new GlDiceRenderer(3));
	renderer->registerRender(new GlDiceRenderer(4));
	renderer->registerRender(new GlDiceRenderer(5));
	renderer->registerRender(new GlDiceRenderer(6));
    
    Player* firstPlayer = new Player(Player::Type::Human, Color::Blue, 24, 19);
    Player* secondPlayer = new Player(Player::Type::Human, Color::Red, 41, 36);
	Player* thirdPlayer = new Player(Player::Type::Human, Color::Green, 58, 53);
	Player* fourthPlayer = new Player(Player::Type::Human, Color::Yellow, 7, 2);
    
    firstPlayer->setNextPlayer(secondPlayer);
    secondPlayer->setNextPlayer(thirdPlayer);
	thirdPlayer->setNextPlayer(fourthPlayer);
	fourthPlayer->setNextPlayer(firstPlayer);
    
    board = new Board(firstPlayer);
    
    renderer->registerRender(new GlBoardRenderer(board));
    
    Player* player = firstPlayer;
    bool first = true;
    
    while (player != firstPlayer || first) {
        first = false;
        Pawn* pawn = player->getFirstPawn();
        
        while(pawn != 0) {
            renderer->registerRender(new GlPawnRenderer(pawn));
            
            pawn = pawn->getNextPawn();
        }
        
        player = player->getNextPlayer();
    }

    this->firstPlayer = firstPlayer;
    this->currentPlayer = this->firstPlayer;
    this->lastPlayer = this->firstPlayer;
    this->lastTurn = new TurnResult(false, false);
    this->pawnSelector = selectorPlus;
}