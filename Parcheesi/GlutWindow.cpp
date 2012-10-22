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
    glutInitWindowSize(500, 300);
    glutCreateWindow("Parcheesi");
    glutDisplayFunc(display);
    glutTimerFunc(1000/20, timer, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 300);
}

void GlutWindow::display() {
    GlutWindow::displayFunction();
    glutSwapBuffers();
}

void GlutWindow::show() {
    glutMainLoop();
}

void GlutWindow::timer(int v) {
    GlutWindow::timerFunction();

    glutTimerFunc(1000, timer, 0);
}

void GlutWindow::redisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    glutPostRedisplay();
}