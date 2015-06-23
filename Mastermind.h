#ifndef MASTERMIND_H
#define MASTERMIND_H
#pragma once

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
    bool CheckGuess(char solutions[FIELD_SIZE]);
    int GetScore();
    void PrintSolution();

protected:
    int solution[FIELD_SIZE];
    bool duplicates;
    int score;
    bool solved;
    
    bool CheckRange(colors c);


};

#endif //MASTERMIND_H