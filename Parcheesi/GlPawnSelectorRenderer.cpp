#include "GlPawnSelectorRenderer.h"

GLuint pawnPlus, pawnMinus, pawnL, pawnOnly;

#define PI 3.14159265

GlPawnSelectorRenderer::GlPawnSelectorRenderer(PawnSelector* pawnSelector) {
    this->pawnSelector = pawnSelector;
    this->next = 0;
    
    initialize();
}

IObjectRenderer* GlPawnSelectorRenderer::getNext() {
    return this->next;
}

void GlPawnSelectorRenderer::setNext(IObjectRenderer *next) {
    this->next = next;
}

void GlPawnSelectorRenderer::initialize() {
    int x = 0, y = 0, r = 10;
    
	/*********** pawnOnly **************/
	pawnOnly = glGenLists(1);
	glNewList(pawnOnly, GL_COMPILE);
	cvs.setWindow(-10.0, 10, -10.0, 10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLineWidth(1.0);
	glBegin(GL_POLYGON);
    for(GLfloat angle = 0; angle <= 360; angle+=360/50){ // Draw the Circle
        // Calculate and position each vertex
        glVertex2f(x+r*cos(angle*PI/180),y+r*sin(angle*PI/180));
    }
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0,0,0);
	// ----------- Begin drawing the Circle with TriangleFans
    glBegin(GL_POLYGON);
    for(GLfloat angle = 0; angle <= 360; angle+=360/50){ // Draw the Circle
        // Calculate and position each vertex
        glVertex2f(x+r*cos(angle*PI/180),y+r*sin(angle*PI/180));
    }
	glEnd();
	glBegin(GL_LINE_STRIP);
    for(GLfloat angle = -180; angle <= 70; angle+=360/50){ // Draw the Circle
        // Calculate and position each vertex
        glVertex2f(x+r*0.8*cos(angle*PI/180),y+r*0.8*sin(angle*PI/180));
    }
	glEnd();
	glEndList();
    
	/*********** pawnPlus **************/
	pawnPlus = glGenLists(1);
	glNewList(pawnPlus, GL_COMPILE);
    glCallList(pawnOnly);
    // Draw Plus
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-5,0);
    glVertex2f(5,0);
    glVertex2f(0,-5);
    glVertex2f(0,5);
    glEnd();
    glLineWidth(1.0);
	glEndList();
    
	/*********** pawnMinus **************/
	pawnMinus = glGenLists(1);
	glNewList(pawnMinus, GL_COMPILE);
    glCallList(pawnOnly);
    // Draw Plus
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-5,0);
    glVertex2f(5,0);
    glEnd();
    glLineWidth(1.0);
	glEndList();
    
	/*********** pawnL *****************/
	pawnL = glGenLists(1);
	glNewList(pawnL, GL_COMPILE);
    glCallList(pawnOnly);
    // Draw L
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(0,-5);
    glVertex2f(0,5);
    glEnd();
    glLineWidth(1.0);
	glEndList();
}

void GlPawnSelectorRenderer::render() {
    
    if(!pawnSelector->isActive())
        return;

    switch (pawnSelector->getType()) {
        case PawnType::Blank:
            glColor3f(1,0,0);
            glViewport(10, 300, 50, 50);
            glCallList(pawnOnly);
            break;
        case PawnType::Pipe:
            glColor3f(1,0,0);
            glViewport(80, 300, 50, 50);
            glCallList(pawnL);
            break;
        case PawnType::Minus:
            glColor3f(1,0,0);
            glViewport(80, 230, 50, 50);
            glCallList(pawnMinus);
            break;
        case PawnType::Plus:
            glColor3f(1,0,0);
            glViewport(10, 230, 50, 50);
            glCallList(pawnPlus);
            break;
        case PawnType::None:
            break;
    }
}