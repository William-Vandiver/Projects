#include <string>

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
