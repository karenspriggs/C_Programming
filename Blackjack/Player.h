namespace B {
    class Player{
        public:
            int score = 0;
            int current_total = 0;
            Player() {

            }
            void update_total(int value);
            int make_choice();
            int make_choice_dealer();
    };
}