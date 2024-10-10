#include "Cucipiring.h"
#include <iostream>

// Constructor initializes the score
Cucipiring::Cucipiring() : score(0) {}

// Wash a dirty plate and add score
void Cucipiring::washPlate() {
    score += 10; // Add 10 points for washing a plate
    std::cout << "Piring tercuci! Kamu mendapatkan 100 coin." << std::endl;
}

// Getter for score
int Cucipiring::getScore() const {
    return score;
}
