class Service {

public:
    static void clearScreen() {
        cout << string( 60, '\n' );
    }

    static void printException(string textMessage) {
        Layout::closedPrint("Exception", textMessage, "#", 33);
    }

    static void pause(int ms) {
        Sleep(ms);
    }

    static void showPercent(int i) {
        int dashes = (40 * i) / 100;
        cout << "\t\t\t\t\t" << '|' << left << setw(40) << string(dashes, '*') << '|' << setw(3) << i << "%";
    }

    static void loader() {
        static const int width = 40;

        for (int i=0; i < 101; i++) {
            showPercent(i);
            pause(40);
            cout << string(width+6, '\b');
            pause(60);
            clearScreen();
        }
    }

    /** Checks the player's name for a fit.
     *  @param listPlayers
     *  @param namePlayer
     *  @return "true" means that a player's name fit.
     *  @return "false" means that a player's name doesn't fit.
     */
    static bool checkName(const string& currentName, vector<Player> listPlayers) {
        for (Player otherPlayer : listPlayers) {
            if (currentName == otherPlayer.getName()) {
                Service::printException("The player's name is already on the list player.");
                return false;
            }
        }
        return true;
    }

    /** Show cards of a player.
     *  @param player
     */
    static string informationPlayer(Player& player) {
        string message = "Player '" + player.getName()
                         + "', count: " + to_string(player.getCount())
                         + ", face cards: " + player.getFaceCard();
        return message;
    }

    /** Remove a player who have more that 21 count.
       *  @param player
       *  @return "false" means that a player don't was remove.
       *  @return "true" means that a player was remove.
       */
    static bool removePlayer(Player& player, vector <Player>& listPlayers) {
        for (int i=0; i < listPlayers.size(); i++) {
            if (listPlayers.at(i).getName() == player.getName()) {
                listPlayers.erase(listPlayers.begin() + i);
                return true;
            }
        }
        return false;
    }

    /** Show rules of the game.*/
    static void readRules() {
        clearScreen();
        cout << "\n\t  ===================================================== Rules ================================================\n";

        pause(1500);
        cout << "\t\tTo start the game, enter the number of players who will participate in the game (minimum 2, maximum 10).\n"
                "\t\tThen enter the name of each player. Names should not be repeated.\n"
                "\t\tSo how do you win? You must use your cards to collect amount points 21 or close to it.\n"
                "\t\tIf you have too much (more than 21), then you game over automatically!\n"
                "\t\tIn the game, all cards from 2 to 10 give points at face value.\n"
                "\t\t  Jack-2 points, Queen-3 points, King-4 points, Ace-11 points.\n"
                "\t\t  H - HEART, C - CLUB, D - DIAMOND, S - SPADE.\n"
                "\t\tYou can choose from the following card deck sizes: 36 or 52 (used by default).\n\n";

        pause(15000);
        cout << "\t\t-So you are dealt two cards, you look at the amount of their points and decide to take another card,\n"
                "\t\t in this case, enter 'yes' or 'y'.\n"
                "\t\t-If there are enough cards, then enter 'no' or 'n', then the move will go to the next player.\n"
                "\t\t-To end the game enter 'esc' or 'e'.\n"
                "\t\t-If amount points 21 enter 'win' or 'w'.\n"
                "\t\t If you enter this command and your amount is less than 21, \n"
                "\t\t you game over automatically.\n\n";

        pause(15000);
        cout << "\t\tSpecial combinations:\n"
                "\t\t-Gold point:\n"
                "\t\t  If the first two cards come two Aces, then this is considered the Gold point\n"
                "\t\t  If two aces come in the first two cards, then this is counted and such cards immediately win.\n"
                "\t\t-Hand:\n"
                "\t\t  Cards which has five picture cards, regardless of how many points they score.\n"
                "\n\t  ==============================================================================================================";

        pause(6000);
    }

    static const string Developer() {
        static const string NAME = "Bertolt Winterhalter";
        return NAME;
    }
};
