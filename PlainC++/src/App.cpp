#include <iostream>

#include "Animal.h"


int main(){
    std::cout << "Built by CMake" << std::endl;

    Animal myAnimal = Animal();
    myAnimal.walk();
    myAnimal.isAnimalWalking() ? std::cout << "Animal is walking" << std::endl 
                               : std::cout << "Animal is not waling" << std::endl;
    
    return EXIT_SUCCESS;
}