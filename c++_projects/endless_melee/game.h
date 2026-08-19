#include "characters.h"
#include "items.h"
#include <iostream>

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