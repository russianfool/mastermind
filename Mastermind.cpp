#include "Mastermind.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

Mastermind::Mastermind(int seed)
    : duplicates(false)
    , score(0)
    , solved(false)
{
    // TODO: proper random function from <random> with seed
    if (seed == 1) {
        srand(time(NULL));
    }
    else {
        srand(seed);
    }
    
    int i = 0, tmp = 0;
    bool dupes[NUM_ELEMENTS] = {false};
    while (i < FIELD_SIZE) {
        tmp = rand() % NUM_ELEMENTS;
        if (dupes[tmp] == false) {
            solution[i++] = tmp;
            dupes[tmp] = true;
        }
    }
}



bool Mastermind::CheckGuess(int sol[FIELD_SIZE])
{
    if (!solved) {
        score++;
    }
    
    // TODO: error checking/range checking
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (sol[i] != solution[i]) {
            return false;
        }
    }
    
    solved = true;
    return true;
}



int Mastermind::GetScore()
{
    return score;
}


// Used for debugging
void Mastermind::PrintSolution()
{
    for(int i = 0; i < FIELD_SIZE; i++) {
        std::cout << solution[i];
    }
    
    std::cout << std::endl;
}