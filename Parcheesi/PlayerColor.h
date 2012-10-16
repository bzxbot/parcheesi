class PlayerColor {
    public:
        enum Color {
            Blue,
            Red,
            Green,
            Yellow
        };
        PlayerColor(Color color, int startingPosition, int endingPosition);
        int getStartingPosition();
        int getEndingPosition();
    private:
        Color color;
        int startingPosition;
        int endingPosition;
};
