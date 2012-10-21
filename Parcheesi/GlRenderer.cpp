#include "GlRenderer.h"

GlRenderer::GlRenderer() {
    this->glBoardRenderer = 0;
    this->glPawnRenderer = 0;
}

void GlRenderer::render() {
    glBoardRenderer->render();
    GlPawnRenderer* glPawnRenderer = this->glPawnRenderer;
    
    while(glPawnRenderer != 0) {
        glPawnRenderer->render();
        glPawnRenderer = glPawnRenderer->getNext();
    }
}

void GlRenderer::registerBoardRenderer(GlBoardRenderer* glBoardRenderer) {
    this->glBoardRenderer = glBoardRenderer;
}

void GlRenderer::registerPawnRenderer(GlPawnRenderer* glPawnRenderer) {
    if (this->glPawnRenderer == 0) {
        this->glPawnRenderer = glPawnRenderer;
    } else {
        GlPawnRenderer* previous = this->glPawnRenderer;
        GlPawnRenderer* current = previous;
        while(current->getNext() != 0) {
            previous = current;
            current = current->getNext();
        }
        previous->setNext(glPawnRenderer);
    }
}