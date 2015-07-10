#ifndef MASTERMIND_H
#define MASTERMIND_H
#pragma once

#include <utility>
#include <set>

const int FIELD_SIZE = 5;

// Enums for display purposes, everyone else can simply use numbers
enum colors {
    RED, GREEN, BLUE, YELLOW, BROWN, BLACK, BEIGE, WHITE,
    NUM_ELEMENTS
};

static const char * EnumStrings[] = 
    {" ", "R", "G", "B", "Y", "Br", "Bl", "Be", "W"};

class Mastermind
{
public:
    Mastermind(int seed = 1);
    
    // Returns the count of pips, black then white
    std::pair<unsigned, unsigned> CheckGuess(int sol[FIELD_SIZE]);
    int GetScore();
    void PrintSolution();

protected:
    int solution[FIELD_SIZE];
    bool solColors[NUM_ELEMENTS];
    bool duplicates;
    int score;
    bool solved;
    
    bool CheckRange(colors c);
};

#endif //MASTERMIND_H