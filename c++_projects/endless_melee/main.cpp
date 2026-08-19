#include "game.h"
#include "dialogue.h"

std::string name;

int main() {
std::string name = intro();

Player player = Player(name, 100, 5);
NPC npc = NPC("", 0, 0);
npc = npc.enemyPicker();
Game game(&npc, &player);

// add this to the game loop to keep player updated on their condiction
std::cout << "YOUR STATS ARE HEALTH: " << player.getHealth() << " ATTACK: " << player.getAttack() << "\n";
game.combat();
}