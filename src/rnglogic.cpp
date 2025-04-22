#include "rnglogic.h"
#include <random>

int RNGLogic::generate(int min, int max){
    if (max < min) return -1;
    std::random_device rd; // Random device to seed the generator
    std::mt19937 gen(rd()); // Seed the random number generator with a random device
    std::uniform_int_distribution<> dist(min, max); // Uniform distribution between minNumber and maxNumber
    return dist(gen);
}