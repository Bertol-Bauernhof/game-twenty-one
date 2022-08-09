class Deck {
private:
    map <string, int> deck;

    /** The deck of cards.
     * {face of a card, value of a card}
     */
    map <string, int> size36 = {
            {"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"10C", 10}, {"Jack C", 2}, {"Queen C", 3}, {"King C", 4}, {"Ace C", 11},
            {"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"10D", 10}, {"Jack D", 2}, {"Queen D", 3}, {"King D", 4}, {"Ace D", 11},
            {"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"10H", 10}, {"Jack H", 2}, {"Queen H", 3}, {"King H", 4}, {"Ace H", 11},
            {"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"10S", 10}, {"Jack S", 2}, {"Queen S", 3}, {"King S", 4}, {"Ace S", 11}
    };

    map <string, int> size52 = {
            {"2C", 2}, {"3C", 3}, {"4C", 4}, {"5C", 5}, {"6C", 6}, {"7C", 7}, {"8C", 8}, {"9C", 9}, {"10C", 10}, {"Jack C", 2}, {"Queen C", 3}, {"King C", 4}, {"Ace C", 11},
            {"2D", 2}, {"3D", 3}, {"4D", 4}, {"5D", 5}, {"6D", 6}, {"7D", 7}, {"8D", 8}, {"9D", 9}, {"10D", 10}, {"Jack D", 2}, {"Queen D", 3}, {"King D", 4}, {"Ace D", 11},
            {"2H", 2}, {"3H", 3}, {"4H", 4}, {"5H", 5}, {"6H", 6}, {"7H", 7}, {"8H", 8}, {"9H", 9}, {"10H", 10}, {"Jack H", 2}, {"Queen H", 3}, {"King H", 4}, {"Ace H", 11},
            {"2S", 2}, {"3S", 3}, {"4S", 4}, {"5S", 5}, {"6S", 6}, {"7S", 7}, {"8S", 8}, {"9S", 9}, {"10S", 10}, {"Jack S", 2}, {"Queen S", 3}, {"King S", 4}, {"Ace S", 11}
    };

    /** The method for select deck size. */
public:
    void selectSize() {
        string deckSize;
        Layout::openedPrint("Select deck size", "Select deck size (36/52 is default): ", "_", 31);
        cin >> deckSize;

        if (deckSize == "36")
            deck = size36;
        else
            deck = size52;
    }

    /** Give a card from the deck.
     *  @param player
     *  @return "false" means the deck is empty OR a player cannot have more cards.
     *  @return "true" means that a card was given successful.
     */
    bool giveCard(Player& player) {
        if(deck.empty()) {
            Service::printException("The deck is empty!");
            return false;
        }
        if(player.getNumberOfCards() == 5) {
            Service::printException("You cannot have more than five cards!");
            return false;
        }

        // Choosing a random number from 0 to current deck size.
        srand( (unsigned) time(0) );
        int randomNumber = rand() % deck.size();
        int i = 0;

        // Choosing a card in the deck
        for (map<string, int>::iterator it = deck.begin(); it != deck.end(); i++) {
            if (i == randomNumber) {
                player.setCount(player.getCount() + it->second);
                player.setFaceCard(player.getFaceCard() + "| " + it->first);
                player.plusCard();
                deck.erase(it++);
                cout << "\t\t\t\t\t\t\t\t\t\t\tA card given.";
                return true;
            }
            ++it;
        }
        return false;
    }
};
