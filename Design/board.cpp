#include <windows.h>   // use as needed for your system
#include <GL/GL.h>
#include <GL/glut.h>

#include "RgbImage.h" // NEW INCLUDE
#include "Canvas.h"

#define screenWidth 800
#define screenHeight 600

#define PI 3.14159265

GLuint pawnPlus, pawnMinus, pawnL, pawnOnly, board;

//<<<<<<<<<<<<<<<<<<<<<<<< Create Canvas >>>>>>>>>>>
Canvas cvs(screenWidth, screenHeight, "Parcheesi v1.0");


//<<<<<<<<<<<<<<<<<<<<<<<< NEW THINGS >>>>>>>>>>>
/*
* Read a texture map from a BMP bitmap file.
*/
void loadTextureFromFile(char *filename)
{    
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);

   RgbImage theTexMap( filename );

   // Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
   //    Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... );

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   gluBuild2DMipmaps(GL_TEXTURE_2D, 3,theTexMap.GetNumCols(), theTexMap.GetNumRows(),
                GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
}

/*
* Draw the texture in the OpenGL graphics window
*/
void drawUmassLogo(void)
{
	cvs.setWindow(-1.0,1.0,-1.0,1.0);
	//glViewport(0,0,800,600);
	glViewport(275,175,250,250);
	glColor3f(1,1,1);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   glBegin(GL_QUADS);
   
   glTexCoord2f(0.0, 0.0); 
   glVertex3f(-1.0, -1.0, 0.0);
   
   glTexCoord2f(0.0, 1.0); 
   glVertex3f(-1.0, 1.0, 0.0);
   
   glTexCoord2f(1.0, 1.0); 
   glVertex3f(1.0, 1.0, 0.0);
   
   glTexCoord2f(1.0, 0.0); 
   glVertex3f(1.0, -1.0, 0.0);
   
   glEnd();
    glDisable(GL_TEXTURE_2D);

   	cvs.setWindow(-1.0,1.0,-1.0,1.0);
	glViewport(0,0,800,600);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);

	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
   
	glEnd();
}

//<<<<<<<<<<<<<<<<<<<<<<<< END OF NEW THINGS >>>>>>>>>>>


void drawPlayerPlace(float r, float g, float b){
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


void drawVertical(float r, float g, float b){
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

void drawHorizontal(float r, float g, float b){
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

void drawCentral(){
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

void drawSingleSpot(float r, float g, float b){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
		glColor3f(r,g,b);
		glVertex2i(0,0);
		glVertex2i(0,24);
		glVertex2i(24,24);
		glVertex2i(24,0);
	glEnd();
}

void drawSafeSpots(){
	float r,g,b;
	r = g = b = 0.9;
	glViewport(200+192+64,10+2,64,24); // Down
	drawSingleSpot(r,g,b);
	glViewport(200+192+64+64,10+2+4*24,64,24);
	drawSingleSpot(1,0,0);
	glViewport(200+192+64-64,10+2+4*24,64,24);
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
}

//<<<<<<<<<<<<<<<<<<<<<<<< drawTable >>>>>>>>>>>>>>>
void generateBoardDList(){
	board = glGenLists(1);
	glNewList(board, GL_COMPILE);
	cvs.setWindow(-0.01,24.0,0.0,24.01);
	drawSafeSpots();
	/********************
			Bottom
	********************/
	cvs.setWindow(24.01,0.0,24.0,0.0);
	cvs.setViewport(200+192, 200+2*192, 10+2,10+2+192);
	drawVertical(1,0,0);
	
	/********************
			Up
	********************/
	cvs.setWindow(-0.01,24.0,0.0,24.01);
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
	cvs.setWindow(24.01,0.0,0.0,24.01);
	cvs.setViewport(200+3, 200+3+192, 10+192,10+2*192);
	drawHorizontal(0,0,1);

	/********************
			Center
	********************/
	cvs.setWindow(-0.01,24.0,0.0,24.01);
	cvs.setViewport(200+192-24, 200+2*192+24, 10+192-24,10+2*192+24);
	drawCentral();

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

void drawMenuScreen(){
	/************** BACKGROUND *************/
	// BLUE
	cvs.setWindow(0,24,0,24);
	glViewport(120,20,290,290);
	drawPlayerPlace(0,0,1);

	// RED
	cvs.setWindow(24,0,0,24);
	glViewport(screenWidth-120-290,20,290,290);
	drawPlayerPlace(1,0,0);

	// YELLOW
	cvs.setWindow(0,24,24,0);
	glViewport(120,screenHeight-20-290,290,290);
	drawPlayerPlace(1,1,0);

	// GREEN
	cvs.setWindow(24,0,24,0);
	glViewport(screenWidth-120-290,screenHeight-20-290,290,290);
	drawPlayerPlace(0,1,0);
	/************** TITLE ****************/


	/************** MENU *****************/

}

//<<<<<<<<<<<<<<<<<<<<<<<< drawCircle >>>>>>>>>>>>>>
void generatePawnDLists(){
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

//<<<<<<<<<<<<<<<<<<<<<<<< display >>>>>>>>>>>>>>>>>
void display(void)
{
	cvs.clearScreen();
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	cvs.setColor(1.0, 1.0, 1.0);
	
	drawUmassLogo();
	/*
	glCallList(board);

	// Draw Little Pawns
	glColor3f(1,0,0);
	glViewport(0, 0, 20, 20);
	glCallList(pawnOnly);
	
	glColor3f(1,0,0);
	glViewport(30, 0, 20, 20);
	glCallList(pawnPlus);
	
	glColor3f(1,0,0);
	glViewport(60, 0, 20, 20);
	glCallList(pawnMinus);

	glColor3f(1,0,0);
	glViewport(90, 0, 20, 20);
	glCallList(pawnL);
	
	// Draw Big Pawns
	glColor3f(1,0,0);
	glViewport(10, 300, 50, 50);
	glCallList(pawnOnly);
	
	glColor3f(1,0,0);
	glViewport(10, 230, 50, 50);
	glCallList(pawnPlus);
	
	glColor3f(1,0,0);
	glViewport(80, 230, 50, 50);
	glCallList(pawnMinus);

	glColor3f(1,0,0);
	glViewport(80, 300, 50, 50);
	glCallList(pawnL);
	*/
	glFlush();
}


int main(int argc, char** argv) {
	cvs.setBackgroundColor(1.0, 1.0, 1.0);
	// Window is opened in the Canvas constructor
	generatePawnDLists();
	generateBoardDList();
	//loadTextureFromFile( "test.bmp" );
	loadTextureFromFile( "umassd.bmp" );
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
