#include "Parcheesi.h"
#include "iostream"

Parcheesi* Parcheesi::instance = new Parcheesi();

void Parcheesi::turn() {
    int diceRoll = this->diceRoll();
    
    PawnList* pawnList = this->getPlayablePawns(diceRoll);
    
    // Highlight possible play pawns.
    
    // User selects pawn.
    
    // For now, always selects the first pawn in the PawnList.
    
    if (pawnList->getFirst() != 0) {

        Pawn* pawnToPlay = pawnList->getFirst()->getPawn();
    
        board->movePawn(diceRoll, this->currentPlayer, pawnToPlay);
        
        std::cout << pawnToPlay->getPosition() << "\n";

    }
    
    this->currentPlayer = this->currentPlayer->getNextPlayer();
}

Parcheesi* Parcheesi::getInstance() {
    return instance;
}

PawnList* Parcheesi::getPlayablePawns(int diceRoll) {
    PawnList* pawnList = new PawnList();
    Pawn* pawn;
    int canAddNewPawn = 5;
    
    // Find a pawn in nest and add to the pawn list.
    
    if (diceRoll == canAddNewPawn) {
        
        pawn = this->currentPlayer->getFirstPawn();
        
        while(pawn != 0) {
            if (pawn->getPosition() == Board::Nest){
                pawnList->add(new PawnNode(pawn));
                break;
            }
            
            pawn = pawn->getNextPawn();
        }
    }
    
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

//void Parcheesi::run() {
//    
//    while (!instance->isGameOver()) {
//        
//        instance->board->draw();
//        
//        // Drawing test.
//        glBegin(GL_QUADS);
//        
//        srand((int)time(0));
//        
//        glColor3f((float)rand()/(RAND_MAX), (float)rand()/(RAND_MAX), (float)rand()/(RAND_MAX));
//        
//        int x1 = rand() % 500;
//        int y1 = rand() % 300;
//        int x2 = rand() % 500;
//        int y2 = rand() % 300;
//        
//        glVertex2d(x1, y1);
//        glVertex2d(x1, y2);
//        glVertex2d(x2, y2);
//        glVertex2d(x2, y1);
//        
//        glEnd();
//        glFlush();
//
//        instance->turn();
//    }
//    
//    instance->gameOver();
//}

void Parcheesi::run() {
//    glBegin(GL_QUADS);
//    
//    srand((int)time(0));
//    
//    glColor3f((float)rand()/(RAND_MAX), (float)rand()/(RAND_MAX), (float)rand()/(RAND_MAX));
//    
//    int x1 = rand() % 500;
//    int y1 = rand() % 300;
//    int x2 = rand() % 500;
//    int y2 = rand() % 300;
//    
//    glVertex2d(x1, y1);
//    glVertex2d(x1, y2);
//    glVertex2d(x2, y2);
//    glVertex2d(x2, y1);
//    
//    glEnd();
//    glFlush();
}

void Parcheesi::animation() {
    while (!instance->isGameOver()) {
        
        instance->glRenderer->render();
        
        instance->turn();
    }
    
    instance->gameOver();

}

bool Parcheesi::isGameOver() {
    return false;
}

void Parcheesi::gameOver() {
    
}

int Parcheesi::diceRoll() {
    if (previousRoll == 2) {
        previousRoll = 4;
    } else {
        previousRoll = 2;
    }
    
    return previousRoll;
}

void Parcheesi::start() {
    window->show();
}

Parcheesi::Parcheesi() {
    window = new GlutWindow(&Parcheesi::run, &Parcheesi::animation);
    board = new Board();
    glRenderer = new GlRenderer(new GlBoardRenderer(board));
    
    // TODO: Randomize the players.
    //    Player* firstPlayer = new Player(new PlayerColor(PlayerColor::Color::Blue, 22, 17));
    //    Player* secondPlayer = new Player(new PlayerColor(PlayerColor::Color::Red, 39, 34));
    //    Player* thirdPlayer = new Player(new PlayerColor(PlayerColor::Color::Yellow, 5, 68));
    //    Player* forthPlayer = new Player(new PlayerColor(PlayerColor::Color::Green, 56, 51));
    
    Player* firstPlayer = new Player(Player::Type::AI, Player::Color::Blue, 20, 15);
    Player* secondPlayer = new Player(Player::Type::AI, Player::Color::Red, 26, 15);
    
    firstPlayer->setNextPlayer(secondPlayer);
    //    secondPlayer->setNextPlayer(thirdPlayer);
    //    thirdPlayer->setNextPlayer(forthPlayer);
    //    forthPlayer->setNextPlayer(firstPlayer);
    secondPlayer->setNextPlayer(firstPlayer);
    
    
    this->firstPlayer = firstPlayer;
    this->currentPlayer = this->firstPlayer;
}