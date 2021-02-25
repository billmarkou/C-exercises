#ifndef PROJECT4_GAME_H
#define PROJECT4_GAME_H


#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "rating.h"
#include "creator.h"
#include "aplication.h"

using namespace std;


class game : public aplication
{
	bool gameIsOnline;

public:


	// constructor / copy constructor

	game (char*, string, float, creator*, unsigned int, bool);
    game (const game&);


	// print

	virtual void print();


	// getter

    bool getGameIsOnline();
    string getTypeOfFile();


	// setters

	void setGameIsOnline(bool);
    void setTypeOfFile(string);
};

#endif //PROJECT4_GAME_H
