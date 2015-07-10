#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Mastermind.h"

int BogoSolve(int seed=1)
{
    Mastermind game(seed);
    // Use the same random list after this function, but at a different spot
    // So no cheating here!
    
    bool solved = false;
    
    int solution[FIELD_SIZE];
    do {
        int i = 0, tmp = 0;
        bool dupes[NUM_ELEMENTS] = {false};
        while (i < FIELD_SIZE) {
            tmp = rand() % NUM_ELEMENTS;
            if (dupes[tmp] == false) {
                solution[i++] = tmp;
                dupes[tmp] = true;
            }
        }
    } while (game.CheckGuess(solution).first != FIELD_SIZE);
    
    return game.GetScore();
}

int main()
{       
    int i, sum;
    for (i = 0, sum = 0; i < 10000; i++) {
        sum += BogoSolve();
    }
    
    std::cout << "Bogo solution solved in " << (double)sum/i << " on average" << std::endl;
    
    return 0;
}