namespace B {
    class Deck{
    int* cards;
    public:
        void allocate();
        void add_cards();
        int get_card();
        Deck();
    };
}