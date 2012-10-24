#ifndef Parcheesi_GlutMouseInput
#define Parcheesi_GlutMouseInput

#include "PawnSelector.h"

#include <math.h>

class GlutMouseInput {
    private:
        PawnSelector* first;
        void (*inputCallbackFunction)(PawnType type);
    public:
        GlutMouseInput(PawnSelector* pawnSelector, void (*inputCallbackFunction)(PawnType type));
        bool setInput(int x, int y);
    
};

#endif
