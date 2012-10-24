#include "GlutWindow.h"

void (*GlutWindow::timerFunction)();
void (*GlutWindow::displayFunction)();

GlutMouseInput* GlutWindow::mouseInput;

GlutWindow::GlutWindow(GlutMouseInput* mouseInput, void (*displayFunction)(), void (*timerFunction)()) {
    int argc = 0;
    
    GlutWindow::timerFunction = timerFunction;
    GlutWindow::displayFunction = displayFunction;
    GlutWindow::mouseInput = mouseInput;
    
    glutInit(&argc, 0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Parcheesi");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
}

void GlutWindow::mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        std::cout << "Pressed: " << x << ", " << 600-y << "\n";
        mouseInput->setInput(x, y);
    }
}

void GlutWindow::display() {
    GlutWindow::clear();
    
    GlutWindow::displayFunction();
    
    glutSwapBuffers();
}

void GlutWindow::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
}

void GlutWindow::show() {
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
}

void GlutWindow::timer(int v) {
    GlutWindow::timerFunction();
    glutTimerFunc(10, timer, 0);
}

void GlutWindow::redisplay() {
    glutPostRedisplay();
}