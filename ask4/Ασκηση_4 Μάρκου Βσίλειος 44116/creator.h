#ifndef PROJECT4_CREATOR_H
#define PROJECT4_CREATOR_H


#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

using namespace std;


class creator
{
protected:

	string creatorCode;
	char* creatorName;
	string creatorEmail;

public:

	// constructor / destructor / copy constructor

    creator();
	creator(string, char*, string);
	creator(const creator&);
	~creator();

	// print

	void print();

	// getters

	char* getName();
	string getCode();
	string getEmail();

	//setters

	void setName(char*);
	void setCode(string);
	void setEmail(string);

	// overloading = , == , <<

	void operator = (const creator&);
	bool operator == (const creator&);
	friend ostream & operator << (ostream& ,creator&);
};


#endif //PROJECT4_CREATOR_H
