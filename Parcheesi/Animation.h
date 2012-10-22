#ifndef Animation_Header
#define Animation_Heaer

class Animation {
    public:
        Animation(int from, int to);
        void setNext(Animation* next);
        Animation* getNext();
    private:
        int from;
        int to;
        Animation* next;
};

#endif