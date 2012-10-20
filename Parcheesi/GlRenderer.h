#ifndef Parcheesi_Renderer
#define Parcheesi_Renderer

#include "GlBoardRenderer.h"

class GlRenderer {
    private:
        GlBoardRenderer* glBoardRenderer;
    public:
        GlRenderer(GlBoardRenderer* glBoardRenderer);
        void render();
};

#endif
