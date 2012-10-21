#ifndef Parcheesi_Renderer
#define Parcheesi_Renderer

#include "GlBoardRenderer.h"
#include "GlPawnRenderer.h"

class GlBoardRenderer;
class GlPawnRenderer;

class GlRenderer {
    private:
        IObjectRenderer* renderer;
    public:
        GlRenderer();
        void render();
        void registerRender(IObjectRenderer* renderer);
};

#endif