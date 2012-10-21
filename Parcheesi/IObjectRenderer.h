#ifndef Parcheesi_IObjectRenderer
#define Parcheesi_IObjectRenderer

class IObjectRenderer {
    protected:
        IObjectRenderer* next;
    public:
        virtual void render() = 0;
        virtual IObjectRenderer* getNext() = 0;
        virtual void setNext(IObjectRenderer* next) = 0;
    
};

#endif
