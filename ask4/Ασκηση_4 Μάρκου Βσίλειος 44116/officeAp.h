#ifndef PROJECT4_OFFICEAP_H
#define PROJECT4_OFFICEAP_H


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


class officeAp : public aplication
{
	string typeOfFile;

public:

	// constructor / copy constructor

	officeAp(char*, string, float, creator*, unsigned int, string);
    officeAp(const officeAp&);


	// print

	virtual void print();


	// getters

	string getTypeOfFile();
    bool getGameIsOnline();


	// setters

	void setTypeOfFile(string);
	void setGameIsOnline(bool);
};


#endif //PROJECT4_OFFICEAP_H
