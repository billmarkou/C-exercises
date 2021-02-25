#ifndef PROJECT4_APLICATION_H
#define PROJECT4_APLICATION_H


#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "rating.h"
#include "creator.h"

using namespace std;


class aplication
{
protected:

	char* apCode;
	string apName;
	float apVersion;
	creator* c;
	vector <rating> apRating;
	unsigned int apPrice;

public:

	virtual void print()=0;
	~aplication();


    // adding to the vector

    void addRating (rating&);


    // getters

	char* getApCode();
	string getApName();
	float getApVersion();
	creator* getApCreator();
	unsigned int getApPrice();
	virtual bool getGameIsOnline()=0;
	virtual string getTypeOfFile()=0;
	vector <rating>* getRatingsVector();

	// setters

	void setApCode(char*);
	void setApName(string);
	void setApVersion(float);
	void setApCreator(creator*);
	void setApPrice(unsigned int);
    virtual void setGameIsOnline(bool)=0;
    virtual void setTypeOfFile(string)=0;


	// rating

	int ratingAverage()
	{
        int temp=0;
        for(unsigned int i=0; i<apRating.size(); i++)
        {
            temp += apRating[i].getStars();
        }
        return temp/apRating.size();
	}


	// overloading

	bool operator == (const aplication&);

};


#endif //PROJECT4_APLICATION_H
