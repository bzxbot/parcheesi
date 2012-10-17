#include "Animation.h"

Animation::Animation(int from, int to) {
    this->from = from;
    this->to = to;
}

void Animation::setNext(Animation* next) {
    this->next = next;
}

Animation* Animation::getNext() {
    return this->next;
}