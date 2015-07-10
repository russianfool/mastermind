#include "Mastermind.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

Mastermind::Mastermind(int seed)
    : duplicates(false)
    , score(0)
    , solved(false)
    , solColors {false}
{
    // TODO: proper random function from <random> with seed
    if (seed == 1) {
        srand(time(NULL));
    }
    else {
        srand(seed);
    }
    
    int i = 0, tmp = 0;
    
    while (i < FIELD_SIZE) {
        tmp = rand() % NUM_ELEMENTS;
        if (solColors[tmp] == false) {
            solution[i++] = tmp;
            solColors[tmp] = true;
        }
    }
}



std::pair<unsigned, unsigned> Mastermind::CheckGuess(int sol[FIELD_SIZE])
{
    if (!solved) {
        score++;
    }
    
    bool recColors[NUM_ELEMENTS] = {false};
    std::pair<unsigned, unsigned> p (0, 0);
    
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (sol[i] == solution[i]) {
            p.first++;
            recColors[solution[i]] = true;
        } else if ((solColors[sol[i]] == true)
                    && (recColors[sol[i]] == false)) 
        {
            p.second++;
            recColors[sol[i]] = true;
        }
    }
    
    return p;
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