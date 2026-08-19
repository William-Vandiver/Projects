#include "game.h"

Game::Game(NPC * _npc, Player * _player){
    npc = _npc;
    player = _player;

    gameIsOver = false;
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