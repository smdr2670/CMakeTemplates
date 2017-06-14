#include "Animal.h"


void Animal::walk(){
    isWalking = true;
}

void Animal::stop() {
    isWalking = true;
}

bool Animal::isAnimalWalking() const {
    return isWalking;
}