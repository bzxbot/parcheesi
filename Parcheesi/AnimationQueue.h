#ifndef AnimationQueue_Header
#define AnimationQueue_Header

#include "Animation.h"

class AnimationQueue {
    public:
        void enqueue(Animation* animation);
        Animation* dequeue();
    private:
        Animation* first;
        Animation* last;
};

#endif