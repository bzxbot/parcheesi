#include "GlDiceRenderer.h"
#include "Parcheesi.h"

GLuint dice[7];

GlDiceRenderer::GlDiceRenderer(int value) {
    this->value = value;
	this->next = 0;
    
    initialize();
}

IObjectRenderer* GlDiceRenderer::getNext() {
    return this->next;
}

void GlDiceRenderer::setNext(IObjectRenderer *next) {
    this->next = next;
}

void GlDiceRenderer::initialize() {
	dice[0] = glGenLists(1);
	glNewList(dice[0], GL_COMPILE);
	
	cvs.setWindow(-10.1, 10.0, -10.0, 10.1);
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(-10,-8);
	glVertex2f(-8,-10);
	
	glVertex2f(8,-10);
	glVertex2f(10, -8);
	
	
	glColor3f(0.9,0.9,0.9);
	glVertex2f(10,8);
	glColor3f(1,1,1);
	glVertex2f(8,10);
	
	glVertex2f(-8,10);
	glVertex2f(-10,8);
	glEnd();
	
	glColor3f(0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-10,-8);
	glVertex2f(-8,-10);
	
	glVertex2f(8,-10);
	glVertex2f(10, -8);
	
	glVertex2f(10,8);
	glVertex2f(8,10);
	
	glVertex2f(-8,10);
	glVertex2f(-10,8);
	glEnd();
    glEndList();
	
	// DRAW DICE 1
	dice[1] = glGenLists(1);
	glNewList(dice[1], GL_COMPILE);
	
	glCallList(dice[0]);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(0,0);
	glEnd();
    glEndList();
	
	// DRAW DICE 1
	dice[2] = glGenLists(1);
	glNewList(dice[2], GL_COMPILE);
	
	glCallList(dice[0]);
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(-5,-5);
	glVertex2f(5,5);
	glEnd();
    glEndList();
	
	// DRAW DICE 2
	dice[3] = glGenLists(1);
	glNewList(dice[3], GL_COMPILE);
	
	glCallList(dice[0]);
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(-5,-5);
	glVertex2f(0,0);
	glVertex2f(5,5);
	glEnd();
    glEndList();
	
	// DRAW DICE 4
	dice[4] = glGenLists(1);
	glNewList(dice[4], GL_COMPILE);
	
	glCallList(dice[0]);
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(-5,-5);
	glVertex2f(5,-5);
	glVertex2f(5,5);
	glVertex2f(-5,5);
	glEnd();
    glEndList();
	
	// DRAW DICE 4
	dice[5] = glGenLists(1);
	glNewList(dice[5], GL_COMPILE);
	
	glCallList(dice[0]);
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(-5,-5);
	glVertex2f(5,-5);
	glVertex2f(5,5);
	glVertex2f(-5,5);
	glVertex2f(0,0);
	glEnd();
    glEndList();
	
	// DRAW DICE 2
	dice[6] = glGenLists(1);
	glNewList(dice[6], GL_COMPILE);
	
	glCallList(dice[0]);
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(-5,-5);
	glVertex2f(5,0);
	glVertex2f(5,-5);
	glVertex2f(5,5);
	glVertex2f(-5,0);
	glVertex2f(-5,5);
	glEnd();
    glEndList();
}

void GlDiceRenderer::render() {
    
	if (!(Parcheesi::getInstance()->lastDiceRoll() == this->value && Parcheesi::getInstance()->getState() == State::PlayerInput))
		return;
	
	glViewport(80, 100, 50, 50);
	
    switch (this->value) {
        case 1:
			glCallList(dice[1]);
            break;
        case 2:
			glCallList(dice[2]);
            break;
        case 3:
			glCallList(dice[3]);
            break;
        case 4:
			glCallList(dice[4]);
            break;
        case 5:
			glCallList(dice[5]);
            break;
		case 6:
			glCallList(dice[6]);
			break;
    }
}