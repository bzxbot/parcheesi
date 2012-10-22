#ifndef Window_Header
#define Window_Header

class GlutWindow {
    private:
        static void timer(int v);
        static void display();
        static void (*timerFunction)();
        static void (*displayFunction)();
        static void clear();
    public:
        GlutWindow(void (*displayFunction)(), void (*timerFunction)());
        void show();
        void redisplay();
};

#endif