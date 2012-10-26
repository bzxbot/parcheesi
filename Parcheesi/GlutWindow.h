#ifndef Window_Header
#define Window_Header

#include "Parcheesi.h"
#include "GlutMouseInput.h"

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
        static GlutMouseInput* mouseInput;
        static bool timerActive;
        static bool IsTimerActive();
    public:
        GlutWindow(GlutMouseInput* mouseInput, void (*displayFunction)(), void (*timerFunction)());
        void show();
        void redisplay();
        void stopTimer();
};

#endif