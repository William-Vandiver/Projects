// this was ment be a simple text game, to using very basic of c++ oop i learn from zenva and codecademy,
// the scope of things i wanted to do here have gotten so big that im forking this into new text game 
// with better encapsulation

#include <iostream>
#include "main.h"
#include <random>

std::string name;

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

Game::Game(NPC * _npc, Player * _player){
    npc = _npc;
    player = _player;

    gameIsOver = false;
}

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

void Game::combat() {
    int input;
    while (npc -> isAlive()) {
        std::cout << "You are met by " << npc ->getName() << " preapre yourself for a fight!!!\n";
        std::cout << "Pick your action\n" << "1. Attack\n" << "2. Heal\n" << "3. Use Item\n";
        std::cin >> input;
        switch (input) {
            case 1:
                std::cout << "You attack!\n";
                    npc ->takeDamage(player ->getAttack());
                    std::cout << "You hit the " << npc ->getName() << " they have taken " << player ->getAttack() <<"\n";
                    if(!npc ->isAlive()) {
                        std::cout << "The " << npc ->getName() << " has been killed! It has drop a Item.\n";
                        return;
                    }

                    player ->takeDamage(npc ->getAttack());
                    std::cout << "The " << npc ->getName() << " has attack you dealing " << npc ->getAttack() << "\n";
                    if(!player ->isAlive()) {
                        gameIsOver = true;
                        std::cout << "You have fallen in combat your name will soon be forgotten!";
                        return;
                    }
                break;
            case 2:
                std::cout << "you heal!";
                break;
            case 3:
                std::cout << "you use a item!";
                break;
            default:
                std::cout << "Pick a Number between 1 and 3 to do an action!";
                break;
        }
    }
}

void Game::reward() {

}

void Game::useItem() {

}

void Game::invertory(){

}

void intro() {
std::cout << "Hello, traveral do you seek glory and adventure? Well you find none of that here, " << 
"all who enter never return!\n";
std::cout << "What is your name? So I can add it to list of others gone before you\n";
std::cin >> name;
std::cout << "Very well " << name << " and may you have better luck then the others!\n";

}

int main() {
intro();

Player player = Player(name, 100, 5);
NPC npc = NPC("", 0, 0);
npc = npc.enemyPicker();
Game game(&npc, &player);

// add this to the game loop to keep player updated on their condiction
std::cout << "YOUR STATS ARE HEALTH: " << player.getHealth() << " ATTACK: " << player.getAttack() << "\n";
game.combat();
}