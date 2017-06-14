#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{

    private:
        bool isWalking;

    public:
        Animal(bool walking = false) : isWalking(walking) {}
        
        void walk();
        void stop();

        bool isAnimalWalking() const;

};

#endif 