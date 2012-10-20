#include "GlRenderer.h"

GlRenderer::GlRenderer(GlBoardRenderer* glBoardRenderer) {
    this->glBoardRenderer = glBoardRenderer;
}

void GlRenderer::render() {
    glBoardRenderer->render();
}