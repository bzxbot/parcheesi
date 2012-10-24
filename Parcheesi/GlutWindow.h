#ifndef Window_Header
#define Window_Header

#include "Parcheesi.h"

#include "iostream"

#include <glut/glut.h>

class GlutWindow {
    private:
        static void timer(int v);
        static void display();
        static void mouse(int button, int state, int x, int y);
        static void (*timerFunction)();
        static void (*displayFunction)();
        static void clear();
    public:
        GlutWindow(void (*displayFunction)(), void (*timerFunction)());
        void show();
        void redisplay();
};

#endif