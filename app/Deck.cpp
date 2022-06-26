class Deck {
private:
    /** The deck of cards.
     * {face of a card, value of a card}
     */
    map <string, int> deck36 = {
            {"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"10C", 10}, {"Jack C", 2}, {"Queen C", 3}, {"King C", 4}, {"Ace C", 11},
            {"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"10D", 10}, {"Jack D", 2}, {"Queen D", 3}, {"King D", 4}, {"Ace D", 11},
            {"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"10H", 10}, {"Jack H", 2}, {"Queen H", 3}, {"King H", 4}, {"Ace H", 11},
            {"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"10S", 10}, {"Jack S", 2}, {"Queen S", 3}, {"King S", 4}, {"Ace S", 11}
    };

    map <string, int> deck52 = {
            {"2C", 2}, {"3C", 3}, {"4C", 4}, {"5C", 5}, {"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"10C", 10}, {"Jack C", 2}, {"Queen C", 3}, {"King C", 4}, {"Ace C", 11},
            {"2D", 2}, {"3D", 3}, {"4D", 4}, {"5D", 5}, {"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"10D", 10}, {"Jack D", 2}, {"Queen D", 3}, {"King D", 4}, {"Ace D", 11},
            {"2H", 2}, {"3H", 3}, {"4H", 4}, {"5H", 5}, {"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"10H", 10}, {"Jack H", 2}, {"Queen H", 3}, {"King H", 4}, {"Ace H", 11},
            {"2S", 2}, {"3S", 3}, {"4S", 4}, {"5S", 5}, {"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"10S", 10}, {"Jack S", 2}, {"Queen S", 3}, {"King S", 4}, {"Ace S", 11}
    };

    /** The method for select deck size. */
public:
    void selectDeckSize(map <string, int>& deck) {
        string deckSize;
        cout << "\n\n\n\t\t\t_______________________________< Select deck size >____________________________\n"
                "\t\t\t\tSelect deck size (36/52 is default): ";
        cin >> deckSize;

        if (deckSize == "36")
            deck = deck36;
        else
            deck = deck52;
    }
};