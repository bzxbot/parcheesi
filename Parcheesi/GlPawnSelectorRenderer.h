#ifndef Parcheesi_GlPawnSelectorRenderer
#define Parcheesi_GlPawnSelectorRenderer

#include "IObjectRenderer.h"
#include "PawnSelector.h"
#include "Canvas.h"

#include <GLUT/GLUT.h>
#include <math.h>

class GlPawnSelectorRenderer : public IObjectRenderer {
    private:
        Canvas cvs;
        PawnSelector* pawnSelector;
        void initialize();
        
    public:
        GlPawnSelectorRenderer(PawnSelector* pawnSelector);
        virtual IObjectRenderer* getNext();
        virtual void setNext(IObjectRenderer* next);
        virtual void render();
};

#endif
