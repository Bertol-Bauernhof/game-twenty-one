class Combination {
public:
    /** SPECIAL COMBINATIONS */
    /** Checks fields "count" and "numberOfCards"  (Ace & Ace)
    *  @param player
    */
    static bool isGoldPoint(Player& player) {
        if (player.getCount() == 22 && player.getNumberOfCards() == 2) {
            return true;
        }
        return false;
    }

    /** Checks a field "faceCard"
    *  @param player
    */
    static bool isHand(Player& player) {
        if (player.getFaceCard().size() > 40) {
            return true;
        }
        return false;
    }
};
