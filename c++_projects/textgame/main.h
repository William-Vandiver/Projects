class NPC {
    private:
        std::string name;
    protected:
        int health;
        int attack;
    public:
        NPC(std::string, int, int);
        std::string getName();
        int getHealth();
        int getAttack();
        int isAlive();
        void takeDamage(int);
        NPC enemyPicker();
};

class Player: public NPC {
    public:
        Player(std::string, int, int);
        void heal(int);
        int getItem(int);
};

/*class Item {
    private:
    std::string
}*/

class Game {
    private:
        NPC * npc;
        Player * player;
        
    public:
        bool gameIsOver;

        Game(NPC *, Player *);

        void combat();
        void useItem();
        void reward();
        void invertory();
};