#include "GlRenderer.h"

GlRenderer::GlRenderer() {
    this->renderer = 0;
}

void GlRenderer::render() {
    IObjectRenderer* renderer = this->renderer;
    
    while(renderer != 0) {
        renderer->render();
        renderer = renderer->getNext();
    }
}

void GlRenderer::registerRender(IObjectRenderer* renderer) {
    if (this->renderer == 0) {
        this->renderer = renderer;
    } else {
        IObjectRenderer* previous = this->renderer;
        IObjectRenderer* current = previous;
        while(current->getNext() != 0) {
            previous = current;
            current = current->getNext();
        }
        previous->setNext(renderer);
    }
}