#include "GlutWindow.h"
#include <glut/glut.h>

GlutWindow::GlutWindow(void (*displayFunction)(), void (*idleFunction)()) {
    int argc = 0;
    char **argv = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 300);
    glutCreateWindow("Parcheesi");
	glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(displayFunction);
    glutIdleFunc(idleFunction);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 300);
}

void GlutWindow::show() {
    glutMainLoop();
}