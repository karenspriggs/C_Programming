namespace B {
    class Deck{
    Card cards[64];
    public:
        void add_cards();
        int get_card();
        Deck();
    };
}