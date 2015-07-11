#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Mastermind.h"

//For boris solution
#include <vector>
#include <array>

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

void GenerateRandomSolution(std::array<int, FIELD_SIZE>& solution, std::array<bool, NUM_ELEMENTS>& colors)
{
    int i = 0, tmp = 0;
    while (i < FIELD_SIZE) {
        tmp = rand() % NUM_ELEMENTS;
        if (colors[tmp] == false) {
            solution[i++] = tmp;
            colors[tmp] = true;
        }
    }
}

void ShuffleColors(std::array<int, FIELD_SIZE>& solution, const std::array<bool, NUM_ELEMENTS>& colors)
{
    bool used[NUM_ELEMENTS] = {0};
    int i = 0, tmp = 0;
    while (i < FIELD_SIZE) {
        tmp = rand() % NUM_ELEMENTS;
        if ((colors[tmp]) && (!used[tmp])) {
            solution[i++] = tmp;
            used[tmp] = true;
        }
    }
}

int ImprovedBogo(int seed=1)
{
    Mastermind game(seed);
    
    std::vector<std::array<int, FIELD_SIZE>> solutions;
    std::vector<std::pair<int, int>> responses;
    
    int cur = -1;
    bool colorsGuessed = false;
    std::array<bool, NUM_ELEMENTS> colors;
    
    do {
        cur++;
        if ((cur + 1) > solutions.size()) {
            solutions.push_back(std::array<int, FIELD_SIZE>{{0}});
            responses.push_back(std::pair<int, int>{0, 0});
        }
        
        if (!colorsGuessed) {
            colors.fill(false);
            
            GenerateRandomSolution(solutions[cur], colors);
        }
        
        ShuffleColors(solutions[cur], colors);
        
        responses[cur] = game.CheckGuess(solutions[cur].data());
        if ((responses[cur].first + responses[cur].second) == FIELD_SIZE) {
            colorsGuessed = true;
        }
    } while (responses[cur].first != FIELD_SIZE);
    
    return game.GetScore();
}

double RunSolution(int (*f)(int), int times)
{
    int i, sum;
    for (i = 0, sum = 0; i < times; i++) {
        sum += (*f)(1);
        if ((i % 1000) == 0 && i != 0) {
            std::cout << "Still running solutions: " 
                    << i << " done." << std::endl;
        }
    }    
    return (double)sum/i;
}

int main()
{
    double ret;
    ret = RunSolution(BogoSolve, 10000);
    std::cout << "Bogo solution solved in " << ret << " on average" << std::endl;
    
    ret = RunSolution(ImprovedBogo, 10000);
    std::cout << "Improved bogo solution solved in " << ret << " on average" << std::endl;
    
    return 0;
}