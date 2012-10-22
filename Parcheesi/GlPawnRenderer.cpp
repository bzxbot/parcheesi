#include "GlPawnRenderer.h"
#include <GLUT/GLUT.h>

GlPawnRenderer::GlPawnRenderer(Pawn* pawn) {
    int posXBoard = 597, posYBoard = 571;
    
    this->pawn = pawn;
    this->next = 0;
    
    //Filling up the board spaces
    for (int i = 0; i < 3; i++) {
        posXBoard -= 64;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard - 29;
        boardSpacePositions[i][3] = posYBoard;
    }
    
    for (int i = 3; i < 10; i++) {
        posYBoard -= 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard - 29;
        boardSpacePositions[i][3] = posYBoard;
    }
    
    posXBoard = 407;
    posYBoard = 344;
    
    for (int i = 10; i < 18; i++) {
        posXBoard -= 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard;
        boardSpacePositions[i][3] = posYBoard + 29;
    }
    
    for (int i = 18; i < 20; i++) {
        posYBoard -= 64;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard;
        boardSpacePositions[i][3] = posYBoard + 29;
    }
    
    for (int i = 20; i < 27; i++) {
        posXBoard += 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard;
        boardSpacePositions[i][3] = posYBoard + 29;
    }
    
    posXBoard = 408;
    posYBoard = 217;
    
    for (int i = 27; i < 35; i++) {
        posYBoard -= 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard + 29;
        boardSpacePositions[i][3] = posYBoard;
    }
    
    for (int i = 35; i < 37; i++) {
        posXBoard += 64;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard + 29;
        boardSpacePositions[i][3] = posYBoard;
    }
    
    for (int i = 37; i < 44; i++) {
        posYBoard += 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard + 29;
        boardSpacePositions[i][3] = posYBoard;
    }
    
    posXBoard = 569;
    posYBoard = 221;
    
    for (int i = 44; i < 52; i++) {
        posXBoard += 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard;
        boardSpacePositions[i][3] = posYBoard + 29;
    }
    
    for (int i = 52; i < 54; i++) {
        posYBoard += 64;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard;
        boardSpacePositions[i][3] = posYBoard + 29;
    }
    
    for (int i = 54; i < 61; i++) {
        posXBoard -= 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard;
        boardSpacePositions[i][3] = posYBoard + 29;
    }
    
    posXBoard = 533;
    posYBoard = 380;
    
    for (int i = 61; i < 68; i++) {
        posYBoard += 24;
        boardSpacePositions[i][0] = posXBoard;
        boardSpacePositions[i][1] = posYBoard;
        boardSpacePositions[i][2] = posXBoard - 29;
        boardSpacePositions[i][3] = posYBoard;
    }
    
    //Initialize startPositions
    startPositions[this->getColorIndex(Color::Blue)][0][0] = 228;
    startPositions[this->getColorIndex(Color::Blue)][0][1] = 162;
    startPositions[this->getColorIndex(Color::Blue)][1][0] = 228;
    startPositions[this->getColorIndex(Color::Blue)][1][1] = 58;
    startPositions[this->getColorIndex(Color::Blue)][2][0] = 338;
    startPositions[this->getColorIndex(Color::Blue)][2][1] = 162;
    startPositions[this->getColorIndex(Color::Blue)][3][0] = 338;
    startPositions[this->getColorIndex(Color::Blue)][3][1] = 58;
    
    
    startPositions[this->getColorIndex(Color::Red)][0][0] = 628;
    startPositions[this->getColorIndex(Color::Red)][0][1] = 162;
    startPositions[this->getColorIndex(Color::Red)][1][0] = 628;
    startPositions[this->getColorIndex(Color::Red)][1][1] = 58;
    startPositions[this->getColorIndex(Color::Red)][2][0] = 738;
    startPositions[this->getColorIndex(Color::Red)][2][1] = 162;
    startPositions[this->getColorIndex(Color::Red)][3][0] = 738;
    startPositions[this->getColorIndex(Color::Red)][3][1] = 58;
    
    
    startPositions[this->getColorIndex(Color::Green)][0][0] = 628;
    startPositions[this->getColorIndex(Color::Green)][0][1] = 441;
    startPositions[this->getColorIndex(Color::Green)][1][0] = 628;
    startPositions[this->getColorIndex(Color::Green)][1][1] = 545;
    startPositions[this->getColorIndex(Color::Green)][2][0] = 738;
    startPositions[this->getColorIndex(Color::Green)][2][1] = 441;
    startPositions[this->getColorIndex(Color::Green)][3][0] = 738;
    startPositions[this->getColorIndex(Color::Green)][3][1] = 545;
    
    
    startPositions[this->getColorIndex(Color::Yellow)][0][0] = 338;
    startPositions[this->getColorIndex(Color::Yellow)][0][1] = 441;
    startPositions[this->getColorIndex(Color::Yellow)][1][0] = 338;
    startPositions[this->getColorIndex(Color::Yellow)][1][1] = 545;
    startPositions[this->getColorIndex(Color::Yellow)][2][0] = 228;
    startPositions[this->getColorIndex(Color::Yellow)][2][1] = 441;
    startPositions[this->getColorIndex(Color::Yellow)][3][0] = 228;
    startPositions[this->getColorIndex(Color::Yellow)][3][1] = 545;
}

void GlPawnRenderer::render() {
    int x1, y1, x2, y2;
    
    glBegin(GL_QUADS);
    
    switch (this->pawn->getColor()) {
        case Color::Blue:
            glColor3f(0.0, 0.0, 1.0);
            break;
        case Color::Green:
            glColor3f(0.0, 1.0, 0.0);
            break;
        case Color::Red:
            glColor3f(1.0, 0.0, 0.0);
            break;
        default:
            glColor3f(1.0, 1.0, 0.0);
    }
    
    if (this->pawn->getPosition() >= 1 && this->pawn->getPosition() <= Board::Size) {
        x1 = boardSpacePositions[this->pawn->getPosition()-1][0] - 10;
        y1 = boardSpacePositions[this->pawn->getPosition()-1][1] - 10;
        x2 = boardSpacePositions[this->pawn->getPosition()-1][0] + 10;
        y2 = boardSpacePositions[this->pawn->getPosition()-1][1] + 10;
    } else if (this->pawn->getPosition() == 0) {
        x1 = startPositions[this->getColorIndex(this->pawn->getColor())][this->pawn->getStartPosition()][0] - 10;
        y1 = startPositions[this->getColorIndex(this->pawn->getColor())][this->pawn->getStartPosition()][1] - 10;
        x2 = startPositions[this->getColorIndex(this->pawn->getColor())][this->pawn->getStartPosition()][0] + 10;
        y2 = startPositions[this->getColorIndex(this->pawn->getColor())][this->pawn->getStartPosition()][1] + 10;
    }
    
    glVertex2d(x1, y1);
    glVertex2d(x1, y2);
    glVertex2d(x2, y2);
    glVertex2d(x2, y1);
    
    glEnd();
    glFlush();
}

IObjectRenderer* GlPawnRenderer::getNext() {
    return this->next;
}

void GlPawnRenderer::setNext(IObjectRenderer *next) {
    this->next = next;
}

int GlPawnRenderer::getColorIndex(Color color) {
    int index;
    
    switch (color) {
        case Color::Blue:
            index = 0;
            break;
        case Color::Green:
            index = 1;
            break;
        case Color::Red:
            index = 2;
            break;
        default:
            index = 3;
    }
    
    return index;
}