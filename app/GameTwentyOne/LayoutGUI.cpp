class LayoutGUI {
private:
    static string multiplicationSymbols(string symbol, int number) {
        string output = "";
        while (number--) {
            output += symbol;
        }
        return output;
    }

public:
    static void openedPrint(string textMessage, string symbol, int number) {
        cout << "\n\t\t\t  " + multiplicationSymbols(symbol, number) +
                "\n\t\t\t\t" << textMessage;
    }

    static void openedPrint(string textTitle, string textMessage, string symbol, int number) {
        cout << "\n\t\t\t" + multiplicationSymbols(symbol, number) + " " + textTitle + " " + multiplicationSymbols(symbol, number) +
                "\n\t\t\t\t" + textMessage;
    }

    static void closedPrint(string textMessage, string symbol, int number) {
        openedPrint(textMessage, symbol, number);
        cout << "\n\t\t\t  " + multiplicationSymbols(symbol, number);
    }

    static void closedPrint(string textTitle, string textMessage, string symbol, int number) {
        openedPrint(textTitle, textMessage, symbol, number);
        cout << "\n\t\t\t" + multiplicationSymbols(symbol, number*2 + textTitle.length()+2) + "\n";
    }
};
