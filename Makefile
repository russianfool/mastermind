CC=g++
CPPFLAGS=--std=c++11

MastermindTest: Mastermind.o
	$(CC) $(CPPFLAGS) Mastermind.o main.cpp -o MastermindTest

Mastermind.o: Mastermind.cpp Mastermind.h
	$(CC) $(CPPFLAGS) -c Mastermind.cpp

clean:
	rm -rf Mastermind.o MastermindTest
