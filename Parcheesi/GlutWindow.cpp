#include "GlutWindow.h"
#include <glut/glut.h>

void (*GlutWindow::timerFunction)();
void (*GlutWindow::displayFunction)();

GlutWindow::GlutWindow(void (*displayFunction)(), void (*timerFunction)()) {
    int argc = 0;
    
    GlutWindow::timerFunction = timerFunction;
    GlutWindow::displayFunction = displayFunction;
    
    glutInit(&argc, 0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Parcheesi");
    glutDisplayFunc(display);
}

void GlutWindow::display() {
    GlutWindow::clear();
    
    GlutWindow::displayFunction();
    
    glutSwapBuffers();
}

void GlutWindow::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
}

void GlutWindow::show() {
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
}

void GlutWindow::timer(int v) {
    GlutWindow::timerFunction();
    glutTimerFunc(1000, timer, 0);
}

void GlutWindow::redisplay() {
    glutPostRedisplay();
}