class Player {
private:
    int count = 0;
    string faceCard;
    string name;
    int numberOfCards;

public:
    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setCount(int count) {
        this->count = count;
    }
    void setFaceCard(string faceCard) {
        this->faceCard = faceCard;
    }

    // Getters
    int getCount() {
        return count;
    }
    string getName() {
        return name;
    }
    string getFaceCard() {
        return faceCard;
    }
    int getNumberOfCards() {
        return numberOfCards;
    }

    // Constructors
    Player() {
        this->name = "no name";
        this->count = 0;
        this->numberOfCards = 0;
    }
    Player(string name) {
        new (this) Player();
        this->name = name;
    }

    void plusCard() {
        this->numberOfCards++;
    }

};
