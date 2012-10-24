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

Pawn* Parcheesi::selectPawn(PawnList* pawnList) {
    
    if(pawnList->getFirst() == 0) {
        return 0;
    }
    
    return pawnList->getFirst()->getPawn();
}

//void Parcheesi::turn() {
//    int diceRoll;
//    
//    if (lastTurn->IsPawnCapture()) {
//        diceRoll = 20;
//    } else {
//        diceRoll = this->rollDice();
//    }
//    
//    PawnList* pawnList = this->getPlayablePawns(diceRoll);
//    
//    // Highlight possible play pawns.
//    
//    // User selects pawn.
//    
//    // For now, always selects the first pawn in the PawnList.
//    
//    bool capture = false;
//    
//    if (pawnList->getFirst() != 0) {
//
//        Pawn* pawnToPlay = pawnList->getFirst()->getPawn();
//    
//        capture = board->movePawn(diceRoll, this->currentPlayer, pawnToPlay);
//        
//        std::cout << "Player: " << this->currentPlayer->getColor() << " Dice roll: " << diceRoll << " New position: " << pawnToPlay->getPosition() << "\n";
//    }
//    
//    if (!capture)
//        this->currentPlayer = this->currentPlayer->getNextPlayer();
//    
//    lastTurn = new TurnResult(capture, false);
//}

void Parcheesi::turn(Pawn* pawn) {
        
    bool capture = board->movePawn(diceRoll, this->currentPlayer, pawn);
        
    std::cout << "Player: " << this->currentPlayer->getColor() << " Dice roll: " << diceRoll << " New position: " << pawn->getPosition() << "\n";

    
    if (!capture)
        this->currentPlayer = this->currentPlayer->getNextPlayer();
    
    lastTurn = new TurnResult(capture, false);

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

//void Parcheesi::timer() {
//    instance->prepareTurn();
//    
//    if (!instance->isAnimating())
//        instance->turn();
//    
//    instance->window->redisplay();
//    
//    if (instance->isGameOver())
//        instance->gameOver();
//}

void Parcheesi::timer() {
    instance->window->redisplay();
    
    if (instance->isAnimating()) {
        return;
    }
    
    switch (instance->state) {
        case State::PrepareTurn:
            instance->input = false;
            instance->playablePawns = instance->prepareTurn();
            if (instance->currentPlayer->getPlayerType() == Player::Type::Human)
                instance->state = State::PlayerInput;
            else
                instance->state = State::RobotInput;
            break;
        case State::PlayerInput:
            // Show available inputs in screen.
            if (instance->isInputAvailable()) {
                if (instance->input) {
                    instance->selectedPawn = instance->selectPawn(instance->playablePawns);
                    instance->state = State::Turn;
                }
            }
            break;
        case State::RobotInput:
            instance->selectedPawn = instance->selectPawn(instance->playablePawns);
            instance->state = State::Turn;
            break;
        case State::Turn:
            instance->turn(instance->selectedPawn);
            instance->state = State::PrepareTurn;
            break;
    }
    
    if (instance->isGameOver())
        instance->gameOver();
}

bool Parcheesi::isGameOver() {
    return false;
}

bool Parcheesi::isInputAvailable() {
    return this->input;
}

void Parcheesi::setInput(bool input) {
    instance->input = input;
}

void Parcheesi::gameOver() {
}

int Parcheesi::rollDice() {
    if (previousRoll == 1) {
        previousRoll = 3;
    } else {
        previousRoll = 1;
    }
    
    return previousRoll;
//    return rand()%6+1;
//    return 5;
}

void Parcheesi::start() {
    window->show();
}

Parcheesi::Parcheesi() {
    srand((unsigned int)time(NULL));
    
    window = new GlutWindow(&Parcheesi::display, &Parcheesi::timer);
    renderer = new GlRenderer();
    
    // TODO: Randomize the players.
    //    Player* firstPlayer = new Player(new PlayerColor(PlayerColor::Color::Blue, 22, 17));
    //    Player* secondPlayer = new Player(new PlayerColor(PlayerColor::Color::Red, 39, 34));
    //    Player* thirdPlayer = new Player(new PlayerColor(PlayerColor::Color::Yellow, 5, 68));
    //    Player* forthPlayer = new Player(new PlayerColor(PlayerColor::Color::Green, 56, 51));
    
    Player* firstPlayer = new Player(Player::Type::Human, Color::Blue, 24, 15);
    Player* secondPlayer = new Player(Player::Type::Robot, Color::Red, 41, 15);
    
    firstPlayer->setNextPlayer(secondPlayer);
    //    secondPlayer->setNextPlayer(thirdPlayer);
    //    thirdPlayer->setNextPlayer(forthPlayer);
    //    forthPlayer->setNextPlayer(firstPlayer);
    secondPlayer->setNextPlayer(firstPlayer);
    
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
}