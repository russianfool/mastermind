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
        if (game.GetScore() % 1000 == 0) {
            std::cout << "Bogo still running, " 
                << game.GetScore() 
                << " solutions tried" 
                << std::endl;
        }
    } while (game.CheckGuess(solution) == false);
    
    return game.GetScore();
}

int main()
{
    int bogoResult = BogoSolve();
    
    std::cout << "Bogo solution solved in " << bogoResult << std::endl;
    
    return 0;
}