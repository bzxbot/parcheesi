#ifndef Parcheesi_TurnResult
#define Parcheesi_TurnResult

class TurnResult {
    private:
        bool pawnCapture;
        bool sixRoll;
    public:
        TurnResult(bool pawnCapture, bool sixRoll);
        bool IsPawnCapture();
        bool IsSixRoll();
};

#endif
