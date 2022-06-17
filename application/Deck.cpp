class Deck {
    private:
        /** The deck of cards
         * {face of a card, value of a card}
         */ 
        map <string, int> deck36 = {
            {"♣ 6", 6}, {"♣ 7", 7}, {"♣ 8", 8}, {"♣ 9", 9}, {"♣ 10", 10}, {"♣ Jack", 2}, {"♣ Queen", 3}, {"♣ King", 4}, {"♣ Ace", 11},
            {"♢ 6", 6}, {"♢ 7", 7}, {"♢ 8", 8}, {"♢ 9", 9}, {"♢ 10", 10}, {"♢ Jack", 2}, {"♢ Queen", 3}, {"♢ King", 4}, {"♢ Ace", 11}, 
            {"♡ 6", 6}, {"♡ 7", 7}, {"♡ 8", 8}, {"♡ 9", 9}, {"♡ 10", 10}, {"♡ Jack", 2}, {"♡ Queen", 3}, {"♡ King", 4}, {"♡ Ace", 11},
            {"♠ 6", 6}, {"♠ 7", 7}, {"♠ 8", 8}, {"♠ 9", 9}, {"♠ 10", 10}, {"♠ Jack", 2}, {"♠ Queen", 3}, {"♠ King", 4}, {"♠ Ace", 11}
        };
        
        map <string, int> deck52 = {
            {"♣ 2", 2}, {"♣ 3", 3}, {"♣ 4", 4}, {"♣ 5", 5}, {"♣ 6", 6}, {"♣ 7", 7}, {"♣ 8", 8}, {"♣ 9", 9}, {"♣ 10", 10}, {"♣ Jack", 2}, {"♣ Queen", 3}, {"♣ King", 4}, {"♣ Ace", 11},
            {"♢ 2", 2}, {"♢ 3", 3}, {"♢ 4", 4}, {"♢ 5", 5}, {"♢ 6", 6}, {"♢ 7", 7}, {"♢ 8", 8}, {"♢ 9", 9}, {"♢ 10",10}, {"♢ Jack", 2}, {"♢ Queen", 3}, {"♢ King", 4}, {"♢ Ace", 11}, 
            {"♡ 2", 2}, {"♡ 3", 3}, {"♡ 4", 4}, {"♡ 5", 5}, {"♡ 6", 6}, {"♡ 7", 7}, {"♡ 8", 8}, {"♡ 9", 9}, {"♡ 10", 10}, {"♡ Jack", 2}, {"♡ Queen", 3}, {"♡ King", 4}, {"♡ Ace", 11},
            {"♠ 2", 2}, {"♠ 3", 3}, {"♠ 4", 4}, {"♠ 5", 5}, {"♠ 6", 6}, {"♠ 7", 7}, {"♠ 8", 8}, {"♠ 9", 9}, {"♠ 10", 10}, {"♠ Jack", 2}, {"♠ Queen", 3}, {"♠ King", 4}, {"♠ Ace", 11}
        };
        
    /* The method for select deck size. */    
    public:
        void selectDeckSize(map <string, int>& gameDeck) {
            string deckSize;
            cout << "\n\t\t\t\t\t\t\t\tSelect deck size (36/52 is default): ";
            cin >> deckSize;

            if (deckSize == "36") 
                gameDeck = deck36;
            else     
                gameDeck = deck52; 
        }
};