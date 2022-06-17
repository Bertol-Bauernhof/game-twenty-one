class Game21 {
    private:
        // The creation the game deck;
        map <string, int> gameDeck;

        /** Show cards of a player.
         *  @param class Player instance.
         */
        void showCard(Player& player) {
            cout << "\t\t\t\t\t\t_______________________________________________________________________\n";
            cout << "\t\t\t\t\t\t\tPlayer: '" + player.getName() + "', count: " << player.getCount();
            cout << ", face cards: " << player.getFaceCard() <<endl;
        }

        /** Checks the player's name for a fit.
         *  @param listPlayers
         *  @param namePlayer
         *  @return "true" means that a player's name fit.
         *  @return "false" means that a player's name doesn't fit.
         */
        bool checkNameForFit(vector <Player>& listPlayers, string namePlayer) {
            for (int i = 0; i < listPlayers.size(); i++) {
                if (listPlayers.at(i).getName() == namePlayer) {
                    cout << "\t\t\t\t\t\t\t\tError: The player's name is already on the list player. Try again.\n";
                    return true;
                }
            }
            return false;
        }

        /** Give a card from the deck.
         *  @param class Player instance.
         *  @return "false" means the deck is empty OR a player cannot have more cards.
         *  @return "true" means that a card was given successful.
         */
        bool giveCard(Player& player) {
            if (gameDeck.empty()) {
                cout << "\t\t\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                cout << "\t\t\t\t\t\t\t\tThe deck is empty!\n";
                cout << "\t\t\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                return false;
            }
            if (player.getNumberOfCards() == 5) {
                cout << "\t\t\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                cout << "\t\t\t\t\t\t\t\tYou cannot have more than five cards!\n";
                cout << "\t\t\t\t\t\t   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
                return false;
            }
            // Choosing a random number from 0 to current deck size.
            srand( (unsigned) time(0) );
            int randomNumber = rand() % gameDeck.size();
            int i = 0;

            // Choosing a card in the deck
            for (map<string, int> :: iterator it = gameDeck.begin(); it != gameDeck.end(); i++) {
                if (i == randomNumber) {
                    player.setCount(player.getCount() + it->second);
                    player.setFaceCard(it->first);
                    player.setNumberOfCards();
                    gameDeck.erase(it++);
                    cout << "\t\t\t\t\t\t\t\t\t\tA card given.\n";
                    return true;
                }
                ++it;
            }
        }

        /** Game over for a player.
         *  @param class Player instance.
         */
        int gameOver(Player& player) {
            cout << "\t\t\t\t\t\t   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "\t\t\t\t\t\t\t\tCount: " << player.getCount() << ". Face card: " << player.getFaceCard() <<endl;
            cout << "\t\t\t\t\t\t\t\t\t\tGame over!\n";
            cout << "\t\t\t\t\t\t   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            return -1;
        }

        /* Remove a player who have more that 21 count.
        *  @param class Player instance.
        *  @return "0" means that a player don't was remove.
        *  @return "-1" means that a player was remove.
        */
        int removeIfMore(Player& player) {
            if (player.getCount() > 21) {
                return gameOver(player);;
            }
            return 0;
        }

        /** Checks fields "count" and "numberOfCards"  (Ace & Ace)
         *  @param class Player instance.
         */
        bool goldPoint(Player& player) {
            if (player.getCount() == 22 && player.getNumberOfCards() == 2) {
                return true;
            }
            return false;
        }

        /** Checks a field "faceCard"
         *  @param class Player instance.
         */
        bool fivePictures(Player& player) {
            if (player.getFaceCard().max_size() >= 36) {
                return true;
            }
            return false;
        }

        /** Determine a winner in the game.
         *  @param class Player instance.
         *  @return "2" means that a player is the Winner.
         *  @return "-1" means that a player has finished the game.
         */
        int win(Player& player) {
            if (player.getCount() == 21 || goldPoint(player) || fivePictures(player)) {
                system("clear");
                cout << "\n\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Winner >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
                showCard(player);
                cout << "\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
                return 2;
            }
            return gameOver(player);
        }

        /** Ask a player to take a card or not.
         *  @param class Player instance.
         *  @return "2" means that a player is Winner.
         *  @return "1" means that a card was given successful.
         *  @return "0" means a player pass his step.
         *  @return "-1" means that a player has finished the game.
         */
        int ask(Player& player) {
            showCard(player);

            string answer;
            cout << "\t\t\t\t\t\t\tYou, '" << player.getName() << "', want to take a card? (yes/no/win/esc): ";
            cin >> answer;

            if (answer == "Yes" || answer == "yes" || answer == "y") {
                if (!giveCard(player)) {
                    gameOver(player);
                }
                return 1;
            }
            else if (answer == "No" || answer == "no" || answer == "n") {
                cout << "\t\t\t\t\t\t\t\t\t\tPass.\n";
                return 0;
            }
            else if (answer == "Win" || answer == "win" || answer == "w") {
                return win(player);
            }
            else if (answer == "Esc" || answer == "esc" || answer == "e") {
                return gameOver(player);
            }
            cout << "\t\t\t\t\t\t   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                    "\t\t\t\t\t\t\tError: don't right command!\n";
                    "\t\t\t\t\t\t\tTry again\n"
                    "\t\t\t\t\t\t   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            ask(player);
        }

        /** Fill the vector by players.
         *  @param listPlayers.
        */
        int fillListPlayers(vector <Player>& listPlayers) {
            system("clear");
            int numberOfPlayers;

            while (numberOfPlayers > 10 || numberOfPlayers < 2) {
                cout << "\n\n\t\t\t\t\t\t\t___________________________<𝕋𝕙𝕖 𝕔𝕣𝕖𝕒𝕥𝕚𝕠𝕟 𝕠𝕗 𝕡𝕝𝕒𝕪𝕖𝕣𝕤>_________________________\n"
                        "\t\t\t\t\t\t\t\tEntering the number of players to start: ";

                if (!(cin >> numberOfPlayers)) {
                    system("clear");
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "\t\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                            "\t\t\t\t\t\t\t\tError: the number of potential players isn't valid.\n"
                            "\t\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                }
                else if (numberOfPlayers > 10) {
                    system("clear");
                    cout << "\t\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                            "\t\t\t\t\t\t\t\t\t\tError: a lot of players!\n"
                            "\t\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                }
                else if (numberOfPlayers < 2) {
                    system("clear");
                    cout << "\t\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                            "\t\t\t\t\t\t\t\t\t\tError: not enough players!\n"
                            "\t\t\t\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                }
                else {
                    for (int i = 0; i < numberOfPlayers; i++) {
                        string namePlayer;
                        cout << "\t\t\t\t\t\t\t\t\tEnter name player: ";
                        cin >> namePlayer;

                        if (checkNameForFit(listPlayers, namePlayer)) {
                            i--;
                            continue;
                        }
                        listPlayers.push_back(*(new Player(namePlayer)) );
                    }
                }
            }
        }

        /* Show rules of the game. */
        void readRules() {
            system("clear");
            cout << "\n\t\t\t\t=================================================<Game rules>==========================================\n\n"
                    "\t\t\t\tДля начала игры введите количество игроков, которые будут участвовать в игре (минимум 2, максимум 10).\n"
                    "\t\t\t\tЗатем введите имя каждого игрока. Имена не должны повторяться.\n"
                    "\t\t\t\tТак как же выиграть? Вы должны своими картами набрать сумму карт 21 или близкую к ней.\n"
                    "\t\t\t\tЕсли у вас перебор (больше 21), то вы проигрываете автоматически!\n"
                    "\t\t\t\tВ игре все карты от 2 до 10 дают очки по номиналу. Jack-2 очка, Queen-3 очка, King-4 очка, Ace-11 очков.\n"
                    "\t\t\t\tНа выбор предоставляются колоды карт следующего размера: 36 или 52 (используется по умолчанию).\n\n"
                    "\t\t\t\t-Итак вам сдали две карты, вы смотрите на сумму их очков и принимаете решение брать еще карту,\n"
                    "\t\t\t\t в этом случае введите «yes» или «y».\n"
                    "\t\t\t\t-Если карт хватает, то введите «no» или «n», тогда ход перейдёт к следующему игроку.\n"
                    "\t\t\t\t-Чтобы досрочно закончить игру введите «esc» или «e».\n"
                    "\t\t\t\t-Как только сумма ваших карт достигнет 21 введите «win» или «w», тогда вы победите.\n"
                    "\t\t\t\t Учтите, что если вы введете эту команду и ваш счёт меньше 21 и оставшихся игроков больше 1,\n"
                    "\t\t\t\t то автоматически проигрываете.\n\n"
                    "\t\t\t\tОсобые комбинации:\n"
                    "\t\t\t\t«Золотое очко»:\n"
                    "\t\t\t\t  Если первыми двумя картами приходят два туза, то это считается «Золотое очко»\n"
                    "\t\t\t\t  и такие карты сразу выигрывают. В этом случае игрок сразу открывает эти два туза и выигрывает.\n"
                    "\t\t\t\t«Рука»:\n"
                    "\t\t\t\t  Так же выигрышной считается «рука», у которой пять карт-картинок, независимо сколько очков они набирают.\n"
                    "\n\t\t\t\t=======================================================================================================";
        }

        /* For start .*/
        void startGame() {
            // Creating and filling the list of players.
            vector <Player> listPlayers;
            fillListPlayers(listPlayers);

            // Creating and select the deck.
            Deck deck;
            deck.selectDeckSize(gameDeck);

            // First giving of cards.
            for (int i = 0; i < listPlayers.size(); i++) {
                    giveCard(listPlayers.at(i));
                    giveCard(listPlayers.at(i));
            }

            system("clear");
            cout << "\n\t\t\t\t\t\t===============================<𝔾𝕒𝕞𝕖 𝕤𝕥𝕒𝕣𝕥𝕖𝕕>=========================\n\n";
            int numberRound = 0;

            while (!listPlayers.empty()) {
                numberRound++;
                cout << "\n\n\t\t\t\t\t\t\t   ----------------------<ℝ𝕠𝕦𝕟𝕕 " << numberRound << ">----------------------\n";

                for (int numberPlayer = 0; numberPlayer < listPlayers.size(); numberPlayer++) {

                    if (listPlayers.size() == 1) {
                        win(listPlayers.at(numberPlayer));
                        listPlayers.clear();
                        break;
                    }

                    int checkValue = ask(listPlayers.at(numberPlayer));
                    if (checkValue == 2) {
                        listPlayers.clear();
                        break;
                    }
                    else if (checkValue == -1 || removeIfMore(listPlayers.at(numberPlayer)) == -1) {
                        listPlayers.erase(listPlayers.begin() + numberPlayer);
                        numberPlayer--;
                    }
                }
            }
        }

        /* Choose read rules or start the game */
        void choose() {
            system("clear");
            string choice;

            cout << "\n\t\t\t\t=================================================<Menu>=========================================="
                    "\n\n\t\t\t\t\t\tYou must choose read rules or start the game (rules/game): ";
            cin >> choice;

            if (choice == "rules" || choice == "rule" || choice == "r")
                readRules();
            else if (choice == "Game" || choice == "game" || choice == "g")
                startGame();
            else
                choose();
        }

    public:
        /* For running the game.*/
        void run() {
            system("clear");
            string quitGame;

            while (quitGame != "no") {
                cout << "\n\n\t\t\t\t\t\t\t\tPress Enter to Continue.";
                if (cin.get() == '\n') {
                    choose();
                }
                cout << "\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                        "\n\t\t\t\t\t\t\t\tDo you want to continue the game? (yes/no): ";
                cin >> quitGame;
            }
            system("clear");
            cout << "\n\n\t\t\t\t\t\t\t\tDeveloper: " << Developer::NAME();
        }

};
