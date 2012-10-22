#include "GlPawnRenderer.h"
#include <GLUT/GLUT.h>

GlPawnRenderer::GlPawnRenderer(Pawn* pawn) {
    this->pawn = pawn;
    this->next = 0;
}

void GlPawnRenderer::render() {
    glBegin(GL_QUADS);
    
    glColor3f(1, 0, 0);
    
    int x1 = this->pawn->getPosition();
    int y1 = this->pawn->getPosition();
    int x2 = this->pawn->getPosition() + 20;
    int y2 = this->pawn->getPosition() + 20;
    
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