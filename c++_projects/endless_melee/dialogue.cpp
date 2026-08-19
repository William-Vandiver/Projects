#include <iostream>
#include "dialogue.h"

std::string intro() {
    std::string name;

    std::cout << "Hello, traveral do you seek glory and adventure? Well you find none of that here, " << 
    "all who enter never return!\n";
    std::cout << "What is your name? So I can add it to list of others gone before you\n";
    std::cin >> name;
    std::cout << "Very well " << name << " and may you have better luck then the others!\n";

    return name;
}