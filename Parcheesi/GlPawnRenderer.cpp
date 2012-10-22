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
}

void GlPawnRenderer::render() {
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
    
    int x1 = boardSpacePositions[this->pawn->getPosition()-1][0] - 10;
    int y1 = boardSpacePositions[this->pawn->getPosition()-1][1] - 10;
    int x2 = boardSpacePositions[this->pawn->getPosition()-1][0] + 10;
    int y2 = boardSpacePositions[this->pawn->getPosition()-1][1] + 10;
    
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