class Game21 {

private:
    Deck *deck = new Deck();
    // The list players.
    vector <Player> listPlayers;


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
            if (!deck->giveCard(player)) {
                ask(player, numberPlayer);
            }
            if(player.getCount() > 21) {
                isGameOver(player);
                numberPlayer--;
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

        Service::printException("Don't right command! Try again.");
        return ask(player, numberPlayer);
    }

    /** Game over for a player.
     *  @param player
     *  @return "false" means that a player has not finished the game.
     *  @return "true" means that a player finished the game.
     */
    bool isGameOver(Player& player) {
        string message = Service::informationPlayer(player)
                         + "\n\t\t\t\t\t\t\tGame over!";
        LayoutGUI::closedPrint(message, "*", 62);
        return Service::removePlayer(player, listPlayers);
    }

    /** Determine a winner in the game.
     *  @param player
     *  @return "2" means that a player is the Winner.
     *  @return "-1" means that a player has finished the game.
     */
    bool isWinner(Player& player) {
        if (player.getCount() == 21
            || Combination::isGoldPoint(player)
            || Combination::isHand(player)
            || listPlayers.size() == 1 && player.getCount() < 21) {

            Service::clearScreen();
            string message = "\n\t\t\t   " + Service::informationPlayer(player);
            LayoutGUI::closedPrint( "Winner", message, "<>", 19);
            cout << string(1000, '\b');
            Service::pause(1700);
            listPlayers.clear();
            return true;
        }
        return false;
    }

    /** Fill the listPlayers.
     *  @param listPlayers.
    */
    void fillListPlayers() {
        Service::clearScreen();
        int numberOfPlayers;

        while (true) {
            LayoutGUI::openedPrint("The creation of players", "Entering the number of players to start: ", "_", 28);

            if (!(cin >> numberOfPlayers)) {
                Service::clearScreen();
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Service::printException("The number of potential players isn't valid!");
                continue;
            }
            else if (numberOfPlayers > 10) {
                Service::clearScreen();
                Service::printException("A lot of players!");
                continue;
            }
            else if (numberOfPlayers < 2) {
                Service::clearScreen();
                Service::printException("Not enough players!");
                continue;
            }

            for (int i = 1; i <= numberOfPlayers; i++) {
                string name;
                cout << "\n\t\t\t\t____________________________________________________________"
                        "\n\t\t\t\t\t" << i << ") Enter name player: ";
                cin >> name;

                if (Service::checkName(name, listPlayers)) {
                    listPlayers.push_back( *(new Player(name)) );
                    continue;
                }
                i--;
            }
            break;
        }
    }

    /** Show the menu of the game. */
    void callMenu() {
        Service::clearScreen();

        string answer;
        LayoutGUI::openedPrint("Menu", "You must choose read rules or start the game (rules - 'r'/game - 'g'): ", "=", 40);
        cin >> answer;

        if (answer == "rules" ||  answer == "r")
            Service::readRules();
        else if (answer == "game" || answer == "g")
            startGame();
        else
            callMenu();
    }

    /** Start the game*/
    void start() {

        // Creating and filling the list with players.
        fillListPlayers();

        // Creating and select the deck.
        deck->selectSize();

        // First giving of cards.
        for (Player& player : listPlayers) {
            deck->giveCard(player);
            deck->giveCard(player);
        }

        Service::clearScreen();
        LayoutGUI::openedPrint("Game started", "", "=", 28);

        int numberRound;
        while (!listPlayers.empty()) {

            if (numberRound > 6) {
                Service::printException("No winners.");
                listPlayers.clear();
                break;
            }

            Service::pause(2000);

            Service::clearScreen();
            numberRound++;
            LayoutGUI::openedPrint("Round " + to_string(numberRound), "", "-", 30);

            for (int i = 0; i < listPlayers.size(); i++) {
                if (listPlayers.size() == 1) {
                    isWinner(listPlayers.at(i));
                    break;
                }

                LayoutGUI::openedPrint(Service::informationPlayer(listPlayers.at(i)), "_", 64);
                ask(listPlayers.at(i), i);
            }
        }
    }


public:
    void launch() {

        string keyWord;
        while (keyWord != "n") {
            cout << "\n\n\t\t\t\t\t\tPress Enter to Continue.";

            if (cin.get() == '\n') {
                Service::loader();
                callMenu();
            }

            LayoutGUI::openedPrint("Do you want to continue the game? (yes - 'y'/no - 'n'): ", "~", 70);
            cin >> keyWord;
        }
        Service::clearScreen();
        cout << "\n\n\t\tDeveloper: " << Service::Developer();
    }

};
