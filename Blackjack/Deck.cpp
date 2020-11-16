#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "Deck.h"
#include "Card.h"

using namespace std;
using namespace B;

class Deck{
    List<Card> cards;
    public:
        int get_card();
        Deck() {

        }
};
