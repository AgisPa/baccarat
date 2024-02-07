#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

int rand_pick() {
    //The following line has been written in order to cahnge the seed of 
    //randomness everytime that the algorithm is executed
    srand(time(NULL));

    int RandIndex = rand() % 52 * 8;
    return RandIndex;
}
std::string find_symbol(int i) {
    char symbols[13][3] = { "10","1","2","3","4","5","6","7","8","9","J","Q","K" };
    std::string res;
    res = symbols[i];
    return res;
}

int main() {

    struct Card
    {
        int suit, value, symbol;
    };

    Card cards[52 * 8];
    for (int i = 0; i < 52 * 8; ++i) {
        cards[i].suit = i % 4; // 4 suits
        cards[i].value = i % 13; // 13 values
        if (cards[i].value >= 10 || cards[i].value == 0) {
            //Changing value for face cards to 10 
            cards[i].value = 10;
        };
        cards[i].symbol = i % 13;
        //std::cout << cards[i].symbol;
    };

    //Game initialization by burning one card and after that also burning 
    // a number of cards equal to the that card's value. This process simply
    // restricts the starting number of cards but shouldn't change the probbability
    // of outcome, here it was done mainly to completely simulate the game.
    int initrand;
    initrand = rand_pick();
    for (int i = 0; i < cards[initrand].value; ++i) {
        int newrand;
        newrand = rand_pick();
        cards[newrand].value = 0;
    }
    cards[initrand].value = 0;

    //Game starts by drawing two cards for each side (player and banker) card by card alternating sides 
    int Phand[3];
    std::string PhandSymbol[3];
    int Bhand[3];
    std::string BhandSymbol[3];
    int brand;
    int prand;

    for (int i = 0; i < 2; ++i)
    {
        prand = rand_pick();
        //Loop makes sure no burnt cards are picked
        while (cards[prand].value == 0)
        {
            prand = rand_pick();
        }
        Phand[i] = cards[prand].value;
        PhandSymbol[i] = find_symbol(cards[prand].symbol);
        //Line below burns the card so it can not be picked again
        cards[prand].value = 0;

        brand = rand_pick();
        while (cards[brand].value == 0)
        {
            brand = rand_pick();
        }
        Bhand[i] = cards[brand].value;
        BhandSymbol[i] = find_symbol(cards[brand].symbol);
        cards[brand].value = 0;
    }
    int psum;
    int bsum;
    psum = 0;
    bsum = 0;
    for (int i = 0; i < 2; ++i) {
        psum += Phand[i];
        bsum += Bhand[i];
    }
    psum = psum % 10;
    bsum = bsum % 10;

    int bthirdrand;
    int pthirdrand;

    //Checking if either player or banker have a sum equal to 8 or 9
    if ((psum == 8 || psum == 9) && (psum > bsum)) {
        std::cout << "PHand - BHand - Outcome\n";
        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
    }
    else if ((bsum == 8 || bsum == 9) && (psum < bsum)) {
        std::cout << "PHand - BHand - Outcome\n";
        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
    }
    else if ((psum == 8 || psum == 9) && (psum == bsum)) {
        std::cout << "PHand - BHand - Outcome\n";
        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE\n";
    }
    else {
        if (6 <= psum && psum <= 7) {//Player stands
            if (6 <= bsum && bsum <= 7) {
                if (psum > bsum) {
                    std::cout << "PHand - BHand - Outcome\n";
                    std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
                }
                else if (bsum > psum) {
                    std::cout << "PHand - BHand - Outcome\n";
                    std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
                }
                else {
                    std::cout << "PHand - BHand - Outcome\n";
                    std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE";
                }
            }
            else {//Banker draws while player stands
                bthirdrand = rand_pick();
                while (cards[brand].value == 0)
                {
                    bthirdrand = rand_pick();
                }
                Bhand[2] = cards[bthirdrand].value;
                cards[bthirdrand].value = 0;
                BhandSymbol[2] = find_symbol(cards[bthirdrand].symbol);
                bsum += Bhand[2];
                bsum = bsum % 10;
                if (psum > bsum) {
                    std::cout << "PHand - BHand - Outcome\n";
                    std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-PLAYER\n";
                }
                else if (bsum > psum) {
                    std::cout << "PHand - BHand - Outcome\n";
                    std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-BANKER\n";
                }
                else {
                    std::cout << "PHand - BHand - Outcome\n";
                    std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-TIE\n";
                }
            }
        }
        else {//Player draws 
            pthirdrand = rand_pick();
            while (cards[pthirdrand].value == 0)
            {
                pthirdrand = rand_pick();
            }
            Phand[2] = cards[pthirdrand].value;
            cards[pthirdrand].value = 0;
            PhandSymbol[2] = find_symbol(cards[pthirdrand].symbol);
            psum = psum + Phand[2];
            psum = psum % 10;

            if (Phand[2] == 8) {//Casses for banker draw
                if (0 <= bsum && bsum <= 2) {
                    bthirdrand = rand_pick();
                    while (cards[bthirdrand].value == 0)
                    {
                        bthirdrand = rand_pick();
                    }
                    Bhand[2] = cards[bthirdrand].value;
                    cards[bthirdrand].value = 0;
                    BhandSymbol[2] = find_symbol(cards[bthirdrand].symbol);
                    bsum += Bhand[2];
                    bsum = bsum % 10;
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-TIE\n";
                    }
                }
                else {
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE\n";
                    }
                }
            }
            else if (6 <= Phand[2] && Phand[2] <= 7) {
                if (0 <= bsum && bsum <= 6) {
                    bthirdrand = rand_pick();
                    while (cards[bthirdrand].value == 0)
                    {
                        bthirdrand = rand_pick();
                    }
                    Bhand[2] = cards[bthirdrand].value;
                    cards[bthirdrand].value = 0;
                    BhandSymbol[2] = find_symbol(cards[bthirdrand].symbol);
                    bsum += Bhand[2];
                    bsum = bsum % 10;
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-TIE\n";
                    }
                }
                else {
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE\n";
                    }
                }

            }
            else if (4 <= Phand[2] && Phand[2] <= 5) {
                if (0 <= bsum && bsum <= 5) {
                    bthirdrand = rand_pick();
                    while (cards[bthirdrand].value == 0)
                    {
                        bthirdrand = rand_pick();
                    }
                    Bhand[2] = cards[bthirdrand].value;
                    cards[bthirdrand].value = 0;
                    BhandSymbol[2] = find_symbol(cards[bthirdrand].symbol);
                    bsum += Bhand[2];
                    bsum = bsum % 10;
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-TIE\n";
                    }
                }
                else {
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE\n";
                    }
                }
            }
            else if (2 <= Phand[2] && Phand[2] <= 3) {
                if (0 <= bsum && bsum <= 4) {
                    bthirdrand = rand_pick();
                    while (cards[bthirdrand].value == 0)
                    {
                        bthirdrand = rand_pick();
                    }
                    Bhand[2] = cards[bthirdrand].value;
                    cards[bthirdrand].value = 0;
                    BhandSymbol[2] = find_symbol(cards[bthirdrand].symbol);
                    bsum += Bhand[2];
                    bsum = bsum % 10;
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-TIE\n";
                    }
                }
                else {
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE\n";
                    }
                }
            }
            else {
                if (0 <= bsum && bsum <= 3) {
                    bthirdrand = rand_pick();
                    while (cards[bthirdrand].value == 0)
                    {
                        bthirdrand = rand_pick();
                    }
                    Bhand[2] = cards[bthirdrand].value;
                    cards[bthirdrand].value = 0;
                    BhandSymbol[2] = find_symbol(cards[bthirdrand].symbol);
                    bsum += Bhand[2];
                    bsum = bsum % 10;
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "," << BhandSymbol[2] << "-TIE\n";
                    }
                }
                else {
                    if (psum > bsum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-PLAYER\n";
                    }
                    else if (bsum > psum) {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-BANKER\n";
                    }
                    else {
                        std::cout << "PHand - BHand - Outcome\n";
                        std::cout << PhandSymbol[0] << "," << PhandSymbol[1] << "," << PhandSymbol[2] << "-" << BhandSymbol[0] << "," << BhandSymbol[1] << "-TIE\n";
                    }
                }
            }


        }
    }
    return 0;
};