#include "characters.h"
#include <random>

NPC enemy1 = NPC("Goblin", 10, 5);
NPC enemy2 = NPC("Rat", 5, 1);
NPC enemy3 = NPC("Skeleton", 20, 5);
NPC enemy4 = NPC("Orc", 100, 5);
NPC enemy5 = NPC("Litch", 300, 25);

NPC::NPC (std::string _name, int _health, int _attack) {
    name = _name;
    health = _health;
    attack = _attack;
}

Player::Player (std::string _name, int _health, int _attack): NPC(_name, _health, _attack) {}

std::string NPC::getName() {
    return name;
}

int NPC::getHealth() {
    return health;
}

int NPC::getAttack() {
    return attack;
}

int NPC::isAlive() {
    return health > 0;
}

void NPC::takeDamage(int amount) {
    health -= amount;
}

void Player::heal(int amount) {
    health += amount;
}
/*int Player::getItem(int item) {
    int i;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    if (i <= 10) {
        item = item1;
    } else if (i > 10 && i <= 50) {
        item = item2;
    } else if (i > 50 && i <= 70) {
        item = item3;
    } else if (i > 70 && i <= 99) {
        item = item4;
    } else {
        item = item5;
    }
    return item;

}*/

NPC NPC::enemyPicker() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int i = dist(gen);
    NPC enemy = NPC("", 0, 0);
    if (i <= 10) {
        enemy = enemy2;
    } else if (i > 10 && i <= 50) {
        enemy = enemy1;
    } else if (i > 50 && i <= 70) {
        enemy = enemy3;
    } else if (i > 70 && i <= 99) {
        enemy = enemy4;
    } else {
        enemy = enemy5;
    }
    return enemy;
}