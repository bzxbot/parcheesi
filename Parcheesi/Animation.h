#ifndef Animation_Header
#define Animation_Header

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