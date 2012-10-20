#ifndef Window_Header
#define Window_Header

class GlutWindow {
    public:
        GlutWindow(void (*displayFunction)(), void (*idleFunction)());
        void show();
};

#endif