class GameTwentyOne {
private:
    // The game deck.
    map <string, int> gameDeck;
    // The list players.
    vector <Player> listPlayers;

    /** Show cards of a player.
     *  @param player
     */
    static void showCard(Player& player) {
        cout << "\n\t\t      ____________________________________________________________________________\n"
                "\t\t\t   Player: '" + player.getName() + "', count: " << player.getCount()
             << ", face cards: " << player.getFaceCard();
    }

    static void clearScreen() {
        cout << string( 100, '\n' );
    }

    static void throwError(string message) {
        cout << "\n\t\t\t  ######################################################################"
                "\n\t\t\t\tException: " << message
             << "\n\t\t\t  ######################################################################\n";
    }

    /** Checks the player's name for a fit.
     *  @param listPlayers
     *  @param namePlayer
     *  @return "true" means that a player's name fit.
     *  @return "false" means that a player's name doesn't fit.
     */
    bool isGoodName(const string& currentNamePlayer) {
        for (Player otherPlayer : listPlayers) {
            if (currentNamePlayer == otherPlayer.getName()) {
                throwError("the player's name is already on the list player.");
                return false;
            }
        }
        return true;
    }


    /** Show rules of the game.*/
    static void readRules() {
        clearScreen();
        cout << "\n\t  ==================================================< Game rules >==============================================\n"
                "\t\tTo start the game, enter the number of players who will participate in the game (minimum 2, maximum 10).\n"
                "\t\tThen enter the name of each player. Names should not be repeated.\n"
                "\t\tSo how do you win? You must use your cards to collect amount points 21 or close to it.\n"
                "\t\tIf you have too much (more than 21), then you game over automatically!\n"
                "\t\tIn the game, all cards from 2 to 10 give points at face value.\n"
                "\t\t  Jack-2 points, Queen-3 points, King-4 points, Ace-11 points.\n"
                "\t\t  H - HEART, C - CLUB, D - DIAMOND, S - SPADE.\n"
                "\t\tYou can choose from the following card deck sizes: 36 or 52 (used by default).\n\n"
                "\t\t-So you are dealt two cards, you look at the amount of their points and decide to take another card,\n"
                "\t\t in this case, enter 'yes' or 'y'.\n"
                "\t\t-If there are enough cards, then enter 'no' or 'n', then the move will go to the next player.\n"
                "\t\t-To end the game enter 'esc' or 'e'.\n"
                "\t\t-If amount points 21 enter 'win' or 'w'.\n"
                "\t\t If you enter this command and your amount is less than 21, \n"
                "\t\t you game over automatically.\n\n"
                "\t\tSpecial combinations:\n"
                "\t\t-Gold point:\n"
                "\t\t  If the first two cards come two Aces, then this is considered the Gold point\n"
                "\t\t  If two aces come in the first two cards, then this is counted and such cards immediately win.\n"
                "\t\t-Hand:\n"
                "\t\t  Cards which has five picture cards, regardless of how many points they score.\n"
                "\n\t  ==============================================================================================================";
    }

    /** Show the menu of the game. */
    void callMenu() {
        clearScreen();
        string answer;
        cout << "\n\t\t==============================================< Menu >==========================================="
                "\n\t\t\t\tYou must choose read rules or start the game (rules - 'r'/game - 'g'): ";
        cin >> answer;

        if (answer == "rules" ||  answer == "r")
            readRules();
        else if (answer == "game" || answer == "g")
            startGame();
        else
            callMenu();
    }


    /** SPECIAL COMBINATIONS */
    /** Checks fields "count" and "numberOfCards"  (Ace & Ace)
    *  @param player
    */
    static bool isGoldPoint(Player& player) {
        if (player.getCount() == 22 && player.getNumberOfCards() == 2) {
            cout << "\n\t\t\t\t\t\t   $ GOLD POINT $";
            return true;
        }
        return false;
    }

    /** Checks a field "faceCard"
     *  @param player
     */
    static bool isHand(Player& player) {
        if (player.getFaceCard().size() > 40) {
            cout << "\n\t\t\t\t\t\t      $ HAND $";
            return true;
        }
        return false;
    }


    /** Give a card from the deck.
     *  @param player
     *  @return "false" means the deck is empty OR a player cannot have more cards.
     *  @return "true" means that a card was given successful.
     */
    bool giveCard(Player& player) {
        if(gameDeck.empty()) {
            throwError("the deck is empty!");
            return false;
        }
        if(player.getNumberOfCards() == 5) {
            throwError("you cannot have more than five cards!");
            return false;
        }
        // Choosing a random number from 0 to current deck size.
        srand( (unsigned) time(0) );
        int randomNumber = rand() % gameDeck.size();
        int i = 0;

        // Choosing a card in the deck
        for (map<string, int>::iterator it = gameDeck.begin(); it != gameDeck.end(); i++) {
            if (i == randomNumber) {
                player.setCount(player.getCount() + it->second);
                player.setFaceCard(it->first);
                player.plusCard();
                gameDeck.erase(it++);
                cout << "\t\t\t\t\t\t\t\t\t\tA card given.";
                return true;
            }
            ++it;
        }
        return false;
    }

    /** Remove a player who have more that 21 count.
       *  @param player
       *  @return "false" means that a player don't was remove.
       *  @return "true" means that a player was remove.
       */
    bool removePlayer(Player& player) {
        for (int i=0; i < listPlayers.size(); i++) {
            if (listPlayers.at(i).getName() == player.getName()) {
                listPlayers.erase(listPlayers.begin() + i);
                return true;
            }
        }
        return false;
    }

    /** Game over for a player.
     *  @param player
     *  @return "false" means that a player has not finished the game.
     *  @return "true" means that a player finished the game.
     */
    bool isGameOver(Player& player) {
        cout << "\n\t\t\t #####################################################################\n"
                "\t\t\t\t\tCount: " << player.getCount()
             << ". Face card: " << player.getFaceCard()
             << "\n\t\t\t\t\t\t\tGame over!"
                "\n\t\t\t #####################################################################\n";
        return removePlayer(player);
    }

    /** Determine a winner in the game.
     *  @param player
     *  @return "2" means that a player is the Winner.
     *  @return "-1" means that a player has finished the game.
     */
    bool isWinner(Player& player) {
        if (player.getCount() == 21
            || isGoldPoint(player)
            || isHand(player)
            || listPlayers.size() == 1 && player.getCount() < 21) {

            clearScreen();
            cout << "\n\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Winner >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
            isGoldPoint(player);
            isHand(player);
            showCard(player);
            cout << "\n\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
            listPlayers.clear();
            return true;
        }
        return false;
    }


    /** Ask a player to take a card or not.
     *  @param player
     *  @return "2" means that a player is the Winner.
     *  @return "1" means that a card was given successful.
     *  @return "0" means a player pass his step.
     *  @return "-1" means that a player has finished the game.
     */
    int ask(Player& player, int& numberPlayer) {
        string answer;
        cout << "\n\t\t\t\tYou, '" << player.getName() << "', want to take a card? (yes/no/win/esc): ";
        cin >> answer;

        if (answer == "Esc" || answer == "esc" || answer == "e") {
            isGameOver(player);
            --numberPlayer;
            return -1;
        }

        else if (answer == "No" || answer == "no" || answer == "n") {
            cout << "\t\t\t\t\t\t\t\t\t\t\tPass.";
            return 0;
        }

        else if (answer == "Yes" || answer == "yes" || answer == "y") {
            if (!giveCard(player)) {
                ask(player, numberPlayer);
            }
            if(player.getCount() > 21) {
                isGameOver(player);
                --numberPlayer;
                return -1;
            }
            return 1;
        }

        else if (answer == "Win" || answer == "win" || answer == "w") {
            if (!isWinner(player)) {
                isGameOver(player);
                --numberPlayer;
                return -1;
            }
            return 2;
        }

        throwError("don't right command! Try again.");
        return ask(player, numberPlayer);
    }


    /** Fill the listPlayers.
     *  @param listPlayers.
    */
    void fillListPlayers() {
        clearScreen();
        int numberOfPlayers;

        while (true) {
            cout << "\n\n\t\t\t___________________________< The creation of players >_________________________\n"
                    "\t\t\t\tEntering the number of players to start: ";

            if (!(cin >> numberOfPlayers)) {
                clearScreen();
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throwError("the number of potential players isn't valid!");
                continue;
            }
            else if (numberOfPlayers > 10) {
                clearScreen();
                throwError("a lot of players!");
                continue;
            }
            else if (numberOfPlayers < 2) {
                clearScreen();
                throwError("not enough players!");
                continue;
            }
            for (int i = 1; i <= numberOfPlayers; i++) {
                string namePlayer;
                cout << "\n\t\t\t\t____________________________________________________________"
                        "\n\t\t\t\t\t" << i << ") Enter name player: ";
                cin >> namePlayer;

                if (isGoodName(namePlayer)) {
                    listPlayers.push_back( *(new Player(namePlayer)) );
                    continue;
                }
                i--;
            }
            break;
        }
    }


    /** Start the game*/
    void startGame() {
        // Creating and filling the list with players.
        fillListPlayers();
        // Creating and select the deck.
        Deck deck;
        deck.selectDeckSize(gameDeck);

        // First giving of cards.
        for (Player& player : listPlayers) {
            giveCard(player);
            giveCard(player);
        }

        clearScreen();
        cout << "\n\t\t\t===============================< Game started >=========================";

        int numberRound;
        while (!listPlayers.empty() && numberRound < 6) {

            numberRound++;
            cout << "\n\n\t\t\t\t   ----------------------< Round " << numberRound << " >----------------------\n";

            for (int numberPlayer = 0; numberPlayer < listPlayers.size(); numberPlayer++) {
                if (listPlayers.size() == 1) {
                    isWinner(listPlayers.at(numberPlayer));
                    break;
                }
                showCard(listPlayers.at(numberPlayer));
                ask(listPlayers.at(numberPlayer), numberPlayer);
            }
        }
        throwError("No winners.");
    }


public:
    /** For running the game.*/
    void run() {

        string exit;
        while (exit != "n") {
            cout << "\n\n\t\t\t\t\t\tPress Enter to Continue.";
            if (cin.get() == '\n') {
                callMenu();
            }

            cout << "\n\n\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                    "\n\t\t\tDo you want to continue the game? (yes - 'y'/no - 'n'): ";
            cin >> exit;
        }
        clearScreen();
        cout << "\n\n\t\tDeveloper: " << Developer::NAME();
    }

};
