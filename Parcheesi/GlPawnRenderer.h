#ifndef Parcheesi_GlPawnRenderer
#define Parcheesi_GlPawnRenderer

#include "Pawn.h"
#include "IObjectRenderer.h"

class Pawn;

class GlPawnRenderer : public IObjectRenderer {
    private:
        Pawn* pawn;
    public:
        GlPawnRenderer(Pawn* pawn);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* next);
        virtual void render();
};

#endif
