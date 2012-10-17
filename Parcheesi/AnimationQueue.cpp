#include "AnimationQueue.h"

void AnimationQueue::enqueue(Animation *animation) {
    if (this->first == 0) {
        this->first = animation;
        this->last = animation;
    } else {
        this->last->setNext(animation);
        this->last = animation;
    }
}

Animation* AnimationQueue::dequeue() {
    
    if (this->first == 0)
        return 0;
    
    if (this->first == this->last) {
        Animation* dequeued = this->first;
        this->first = 0;
        this->last = 0;
        return dequeued;
    }
    
    Animation* dequeued = this->first;
    
    this->first = this->first->getNext();
    
    return dequeued;
}