#include "GlPawnRenderer.h"
#include <GLUT/GLUT.h>

//GLuint pawnPlus, pawnMinus, pawnL, pawnOnly;

GlPawnRenderer::GlPawnRenderer(Pawn* pawn) {
	initialize();
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
	
	endPoints[this->getColorIndex(Color::Blue)][0] = 430;
	endPoints[this->getColorIndex(Color::Blue)][1] = 295;
	endPoints[this->getColorIndex(Color::Yellow)][0] = 484;
	endPoints[this->getColorIndex(Color::Yellow)][1] = 356;
	endPoints[this->getColorIndex(Color::Green)][0] = 550;
	endPoints[this->getColorIndex(Color::Green)][1] = 295;
	endPoints[this->getColorIndex(Color::Red)][0] = 484;
	endPoints[this->getColorIndex(Color::Red)][1] = 235;
	
	posXBoard = 240 - 24;
	posYBoard = 278;
	
	for (int i = 0; i < 7; i++) {
		posXBoard += 24;
		specialPositions[this->getColorIndex(Color::Blue)][i][0] = posXBoard;
		specialPositions[this->getColorIndex(Color::Blue)][i][1] = posYBoard;
		specialPositions[this->getColorIndex(Color::Blue)][i][2] = posXBoard;
		specialPositions[this->getColorIndex(Color::Blue)][i][3] = posYBoard + 29;
	}
	
	posXBoard = 470;
	posYBoard = 48 - 24;
	
	for (int i = 0; i < 7; i++) {
		posYBoard += 24;
		specialPositions[this->getColorIndex(Color::Red)][i][0] = posXBoard;
		specialPositions[this->getColorIndex(Color::Red)][i][1] = posYBoard;
		specialPositions[this->getColorIndex(Color::Red)][i][2] = posXBoard + 29;
		specialPositions[this->getColorIndex(Color::Red)][i][3] = posYBoard;
	}
	
	posXBoard = 737 + 24;
	posYBoard = 278;
	
	for (int i = 0; i < 7; i++) {
		posXBoard -= 24;
		specialPositions[this->getColorIndex(Color::Green)][i][0] = posXBoard;
		specialPositions[this->getColorIndex(Color::Green)][i][1] = posYBoard;
		specialPositions[this->getColorIndex(Color::Green)][i][2] = posXBoard;
		specialPositions[this->getColorIndex(Color::Green)][i][3] = posYBoard + 29;
	}
	
	posXBoard = 469;
	posYBoard = 545 + 24;
	
	for (int i = 0; i < 7; i++) {
		posYBoard -= 24;
		specialPositions[this->getColorIndex(Color::Yellow)][i][0] = posXBoard;
		specialPositions[this->getColorIndex(Color::Yellow)][i][1] = posYBoard;
		specialPositions[this->getColorIndex(Color::Yellow)][i][2] = posXBoard + 29;
		specialPositions[this->getColorIndex(Color::Yellow)][i][3] = posYBoard;
	}
	
}

void GlPawnRenderer::calculatePawnPosition() {
    float goal[2], pawnPosition[2];
    float size, v[2];
    
    pawnPosition[0] = this->pawn->getXCoordinate();
    pawnPosition[1] = this->pawn->getYCoordinate();
    
    if (this->pawn->getPosition() >= 1 && this->pawn->getPosition() <= Board::Size) {
        goal[0] = boardSpacePositions[this->pawn->getPosition()-1][0];
        goal[1] = boardSpacePositions[this->pawn->getPosition()-1][1];
        
        if (this->pawn->getPosition() == this->pawn->getPlayer()->getStartingPosition() && !Parcheesi::getInstance()->getNumberOfTurns()) {
            this->pawn->setCoordinates(goal[0], goal[1]);
            return;
        }
	} else if (this->pawn->getPosition() == -8) {
		
		goal[0] = endPoints[this->getColorIndex(this->pawn->getColor())][0];
		goal[1] = endPoints[this->getColorIndex(this->pawn->getColor())][1];
		
	} else if (this->pawn->getPosition() < 0) {
		
		goal[0] = specialPositions[this->getColorIndex(this->pawn->getColor())][-(this->pawn->getPosition()+1)][0];
		goal[1] = specialPositions[this->getColorIndex(this->pawn->getColor())][-(this->pawn->getPosition()+1)][1];
		
    } else {
        goal[0] = startPositions[this->getColorIndex(this->pawn->getColor())][this->pawn->getStartPosition()][0];
        goal[1] = startPositions[this->getColorIndex(this->pawn->getColor())][this->pawn->getStartPosition()][1];
        
        if (pawnPosition[0] == 0.0 && pawnPosition[1] == 0.0) {
            this->pawn->setCoordinates(goal[0], goal[1]);
            return;
        }
    }
    
    if (goal[0] == pawnPosition[0] && goal[1] == pawnPosition[1])
        return;
    
    v[0] = goal[0] - pawnPosition[0];
    v[1] = goal[1] - pawnPosition[1];
    
    size = sqrt(v[0]*v[0]+v[1]*v[1]);
    
    if (size != 0.0)
    {
        v[0] = v[0]*this->speed/size + pawnPosition[0];
        v[1] = v[1]*this->speed/size + pawnPosition[1];
        
        if (v[0] <= goal[0]+2*this->speed && v[0] >= goal[0]-2*this->speed) { //Avoid oscilations
            v[0] = goal[0];
        }
        
        if (v[1] <= goal[1]+2*this->speed && v[1] >= goal[1]-2*this->speed) { //Avoid oscilations
            v[1] = goal[1];
        }
        
        if (v[0] == goal[0] && v[1] == goal[1]) {
            Parcheesi::getInstance()->dequeueAnimation();
        }
        
        this->pawn->setCoordinates(v[0], v[1]);
    }
}

void GlPawnRenderer::render() {
    float p1[2], p2[2];
	
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
    
    this->calculatePawnPosition();
    
    p1[0] = this->pawn->getXCoordinate() - 10;
    p1[1] = this->pawn->getYCoordinate() - 10;
    p2[0] = this->pawn->getXCoordinate() + 10;
    p2[1] = this->pawn->getYCoordinate() + 10;
    
    //glVertex2d((int)p1[0], (int)p1[1]);
    //glVertex2d((int)p1[0], (int)p2[1]);
    //glVertex2d((int)p2[0], (int)p2[1]);
    //glVertex2d((int)p2[0], (int)p1[1]);
	
	glViewport(this->pawn->getXCoordinate()-10, this->pawn->getYCoordinate()-10, 20, 20);
	
    switch (this->pawn->getType()) {
        case PawnType::Blank:
            glCallList(pawnOnly);
            break;
        case PawnType::Pipe:
            glCallList(pawnL);
            break;
        case PawnType::Minus:
            glCallList(pawnMinus);
            break;
        case PawnType::Plus:
            glCallList(pawnPlus);
            break;
        case PawnType::None:
            break;
    }
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

void GlPawnRenderer::initialize() {
    int x = 0, y = 0, r = 10;
    
	/*********** pawnOnly **************/
	pawnOnly = glGenLists(1);
	glNewList(pawnOnly, GL_COMPILE);
	cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLineWidth(1.0);
	glBegin(GL_POLYGON);
    for(GLfloat angle = 0; angle <= 360; angle+=360/50){ // Draw the Circle
        // Calculate and position each vertex
        glVertex2f(x+r*cos(angle*M_PI/180),y+r*sin(angle*M_PI/180));
    }
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0,0,0);
	// ----------- Begin drawing the Circle with TriangleFans
    glBegin(GL_POLYGON);
    for(GLfloat angle = 0; angle <= 360; angle+=360/50){ // Draw the Circle
        // Calculate and position each vertex
        glVertex2f(x+r*cos(angle*M_PI/180),y+r*sin(angle*M_PI/180));
    }
	glEnd();
	glBegin(GL_LINE_STRIP);
    for(GLfloat angle = -180; angle <= 70; angle+=360/50){ // Draw the Circle
        // Calculate and position each vertex
        glVertex2f(x+r*0.8*cos(angle*M_PI/180),y+r*0.8*sin(angle*M_PI/180));
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