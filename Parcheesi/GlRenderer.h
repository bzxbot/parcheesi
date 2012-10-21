#ifndef Parcheesi_Renderer
#define Parcheesi_Renderer

#include "GlBoardRenderer.h"
#include "GlPawnRenderer.h"

class GlBoardRenderer;
class GlPawnRenderer;

class GlRenderer {
    private:
        GlBoardRenderer* glBoardRenderer;
        GlPawnRenderer* glPawnRenderer;
    public:
        GlRenderer();
        void render();
        void registerBoardRenderer(GlBoardRenderer* glBoardRenderer);
        void registerPawnRenderer(GlPawnRenderer* glPawnRenderer);
};

#endif
