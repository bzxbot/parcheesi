#ifndef Parcheesi_GlPawnRenderer
#define Parcheesi_GlPawnRenderer

#include "Pawn.h"

class Pawn;

class GlPawnRenderer {
    private:
        Pawn* pawn;
        GlPawnRenderer* next;
    public:
        GlPawnRenderer(Pawn* pawn);
        void render();
        GlPawnRenderer* getNext();
        void setNext(GlPawnRenderer* next);
};

#endif
