#include "GlBoardRenderer.h"
#include <glut/glut.h>
#include "Canvas.h"

Canvas cvs;

GlBoardRenderer::GlBoardRenderer(Board* board) {
    this->board = board;
    this->next = 0;
}

void GlBoardRenderer::render() {
    this->drawTable();

    cvs.setWindow(0, 800, 0, 600);
    cvs.setViewport(0, 800, 0, 600);
    
    glFlush();
}

IObjectRenderer* GlBoardRenderer::getNext() {
    return this->next;
}

void GlBoardRenderer::setNext(IObjectRenderer *next) {
    this->next = next;
}

void GlBoardRenderer::drawVertical(float r, float g, float b){
	int x = 8, y = 3;
	// Middle Stripe Color
	glBegin(GL_QUADS);
    glColor3f(r,g,b);
    glVertex2i(x, -1);
    glVertex2i(x, y*7);
    glVertex2i(x+x, y*7);
    glVertex2i(x+x, -1);
	glEnd();
	// 1st Stripe
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUAD_STRIP);
    glColor3f(0,0,0);
    for(int i = 1; i < 9; i++){
        glVertex2i(0, y*i);
        glVertex2i(x, y*i);
    }
	glEnd();
	// Middle Stripe
	glBegin(GL_QUAD_STRIP);
    for(int i = 0; i < 9; i++){
        glVertex2i(x, y*i);
        glVertex2i(x+x, y*i);
    }
	glEnd();
    
	// 3rd Stripe
	glBegin(GL_QUAD_STRIP);
    for(int i = 1; i < 9; i++){
        glVertex2i(x+x, y*i);
        glVertex2i(x+x+x, y*i);
    }
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void GlBoardRenderer::drawHorizontal(float r, float g, float b){
	int x = 3, y = 8;
	// Middle Stripe Color
	glBegin(GL_QUADS);
    glColor3f(r,g,b);
    glVertex2i(0, y);
    glVertex2i(x*7, y);
    glVertex2i(x*7, y*2);
    glVertex2i(0, y*2);
	glEnd();
	// 1st Stripe
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUAD_STRIP);
    glColor3f(0,0,0);
    for(int i = 1; i < 9; i++){
        glVertex2i(x*i,0);
        glVertex2i(x*i,y);
    }
	glEnd();
	// Middle Stripe
	glBegin(GL_QUAD_STRIP);
    for(int i = 0; i < 9; i++){
        glVertex2i(x*i, y);
        glVertex2i(x*i, y*2);
    }
	glEnd();
    
	// 3rd Stripe
	glBegin(GL_QUAD_STRIP);
    for(int i = 1; i < 9; i++){
        glVertex2i(x*i, 2*y);
        glVertex2i(x*i, 3*y);
    }
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void GlBoardRenderer::drawCentral(){
	cvs.setWindow(0, 18.0, 0, 18.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES); // Down
    glColor3f(1,0,0);
    glVertex2i(2, 2);
    glVertex2i(9, 9);
    glVertex2i(16, 2);
	glEnd();
	glBegin(GL_TRIANGLES); // Right
    glColor3f(0,1,0);
    glVertex2i(16, 2);
    glVertex2i(9, 9);
    glVertex2i(16, 16);
	glEnd();
	glBegin(GL_TRIANGLES); // Up
    glColor3f(1,1,0);
    glVertex2i(16, 16);
    glVertex2i(9, 9);
    glVertex2i(2, 16);
	glEnd();
	glBegin(GL_TRIANGLES); // Left
    glColor3f(0,0,1);
    glVertex2i(2, 16);
    glVertex2i(9, 9);
    glVertex2i(2, 2);
	glEnd();
	// Pyramid
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,0,0);
    glVertex2i(9, 9);
    glVertex2i(2, 2);
    glVertex2i(2, 16);
    glVertex2i(16, 16);
    glVertex2i(16, 2);
    glVertex2i(2, 2);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.2,1.8);
    glVertex2f(1.8,0.2);
    glVertex2f(1,1);
    glVertex2f(2,2);
    
    glVertex2f(0.2,16.2);
    glVertex2f(1.8,17.8);
    glVertex2f(2,16);
    glVertex2f(1,17);
    
    glVertex2f(17.8,1.8);
    glVertex2f(16.2,0.2);
    glVertex2i(17,1);
    glVertex2i(16,2);
    
    glVertex2f(17.8,16.2);
    glVertex2f(16.2,17.8);
    glVertex2i(16,16);
    glVertex2i(17,17);
    
    
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void GlBoardRenderer::drawSingleSpot(float r, float g, float b){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
    glColor3f(r,g,b);
    glVertex2i(0,0);
    glVertex2i(0,24);
    glVertex2i(24,24);
    glVertex2i(24,0);
	glEnd();
}


void GlBoardRenderer::drawPlayerPlace(float r, float g, float b){
	// Background Polygon
	glBegin(GL_POLYGON);
	glColor3f(r*0.7,g*0.7,b*0.7);
	glVertex2f(0,23);
	glVertex2f(0,2);
	glVertex2f(2,0);
	glVertex2f(23,0);
	glColor3f(r*0.5,g*0.5,b*0.5);
	glVertex2f(23,3);
	glVertex2f(23,21);
	glVertex2f(21,23);
	glVertex2f(3,23);
	glEnd();
	
	// Line Polygon
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(r*0.4,g*0.4,b*0.4);
	glVertex2f(1,2.7);
	glVertex2f(2.7,1);
	
	glVertex2f(22,1);
	
	glVertex2f(22,20.3);
	glVertex2f(20.3,22);
	
	glVertex2f(1,22);
	
	glEnd();
	
	// Line Polygon #2
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glColor3f(r*0.4,g*0.4,b*0.4);
	glVertex2f(0.5,2.5);
	glVertex2f(2.5,0.5);
	
	glVertex2f(22.5,0.5);
	
	glVertex2f(22.5,20.5);
	glVertex2f(20.5,22.5);
	
	glVertex2f(0.5,22.5);
	
	glEnd();
	
	glLineWidth(1.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	// Turtle Graphics Star
	int n = 60;
	glColor3f(r*0.5,g*0.5,b*0.5);
	cvs.moveTo(14, 10);
	cvs.turnTo(-(36-24));
	
	for(int i = 1; i <=n; i++)
	{
		cvs.turn(-24);
		for(int j = 1; j <10; j++){
			cvs.turn(j*36);
			cvs.forward(5,1);
		}
	}
	glBegin(GL_POLYGON);
	glColor3f(r*0.7,g*0.7,b*0.7);
	glVertex2f(12,16);
	glVertex2f(13,15);
	glVertex2f(18,15);
	glVertex2f(19,16);
	glVertex2f(19,21);
	glVertex2f(18,22);
	glVertex2f(13,22);
	glVertex2f(12,21);
	glEnd();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3f(r*0.5,g*0.5,b*0.5);
	glVertex2f(12,16);
	glVertex2f(13,15);
	glVertex2f(18,15);
	glVertex2f(19,16);
	glVertex2f(19,21);
	glVertex2f(18,22);
	glVertex2f(13,22);
	glVertex2f(12,21);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void GlBoardRenderer::drawSafeSpots(){
	float r,g,b;
	r = g = b = 0.9;
	glViewport(200+192+64,10+2,64,24); // Down
	drawSingleSpot(r,g,b);
	glViewport(200+192+64+64,10+3+4*24,64,24);
	drawSingleSpot(1,0,0);
	glViewport(200+192+64-64,10+3+4*24,64,24);
	drawSingleSpot(r,g,b);
    
	glViewport(200+192+64,3*192-18,64,24); // Up
	drawSingleSpot(r,g,b);
	glViewport(200+192+64+64,3*192-18-4*24,64,24);
	drawSingleSpot(r,g,b);
	glViewport(200+192+64-64,3*192-18-4*24,64,24);
	drawSingleSpot(1,1,0);
    
	glViewport(200+4,10+64+192,24,64); // Left
	drawSingleSpot(r,g,b);
	glViewport(200+4+4*24,10+64+192+64,24,64);
	drawSingleSpot(r,g,b);
	glViewport(200+4+4*24,10+64+192-64,24,64);
	drawSingleSpot(0,0,1);
    
	glViewport(200-28+3*192,10+64+192,24,64); // Right
	drawSingleSpot(r,g,b);
	glViewport(200-27+3*192-4*24,10+64+192+64,24,64);
	drawSingleSpot(0,1,0);
	glViewport(200-27+3*192-4*24,10+64+192-64,24,64);
	drawSingleSpot(r,g,b);
	
	// BLUE
	cvs.setWindow(0,24,0,24);
	cvs.setViewport(200, 200+192, 10+2,10+2+192);
	drawPlayerPlace(0,0,1);
	
	// RED
	cvs.setWindow(24,0,0,24);
	cvs.setViewport(200+2*192, 200+3*192, 10+2,10+2+192);
	drawPlayerPlace(1,0,0);
	
	// YELLOW
	cvs.setWindow(0,24,24,0);
	cvs.setViewport(200, 200+192, 10-3+2*192,10-3+3*192);
	drawPlayerPlace(1,1,0);
	
	// GREEN
	cvs.setWindow(24,0,24,0);
	cvs.setViewport(200+2*192, 200+3*192, 10-3+2*192,10-3+3*192);
	drawPlayerPlace(0,1,0);
	glEndList();
}

//<<<<<<<<<<<<<<<<<<<<<<<< drawTable >>>>>>>>>>>
void GlBoardRenderer::drawTable(){
	cvs.setWindow(-0.01,24.0,0.0,24.01);
	drawSafeSpots();
	/********************
     Bottom
     ********************/
	cvs.setWindow(24.01,0.0,24.01,0.0);
	cvs.setViewport(200+192, 200+2*192, 10+3,10+3+192);
	drawVertical(1,0,0);
	
	/********************
     Up
     ********************/
	cvs.setWindow(-0.01,24.0,-0.01,24.01);
	cvs.setViewport(200+192, 200+2*192, 10-3+2*192,10-3+3*192);
	drawVertical(1,1,0);
    
	/********************
     Right
     ********************/
	cvs.setViewport(200-3+2*192, 200-3+3*192, 10+192,10+2*192);
	drawHorizontal(0,1,0);
	
	/********************
     Left
     ********************/
	cvs.setWindow(24.01,0.0,-0.01,24.01);
	cvs.setViewport(200+3, 200+3+192, 10+192,10+2*192);
	drawHorizontal(0,0,1);
    
	/********************
     Center
     ********************/
	cvs.setWindow(-0.01,24.0,0.0,24.01);
	cvs.setViewport(200+192-24, 200+2*192+24, 10+192-24,10+2*192+24);
	drawCentral();
}