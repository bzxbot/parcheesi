#include "GlBoardRenderer.h"
#include <GLUT/GLUT.h>

GlBoardRenderer::GlBoardRenderer(Board* board) {
    this->board = board;
    this->next = 0;
}

void GlBoardRenderer::render() {
    // Render the board.
    
    
    // Drawing test.
    
    glBegin(GL_QUADS);
    
    glColor3f(1, 0, 0);
    
    int x1 = 100;
    int y1 = 100;
    int x2 = 200;
    int y2 = 200;
    
    glVertex2d(x1, y1);
    glVertex2d(x1, y2);
    glVertex2d(x2, y2);
    glVertex2d(x2, y1);
    
    glEnd();
    glFlush();
    
}

IObjectRenderer* GlBoardRenderer::getNext() {
    return this->next;
}

void GlBoardRenderer::setNext(IObjectRenderer *next) {
    this->next = next;
}