#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "creator.h"
#include "aplication.h"
#include "rating.h"



using namespace std;



// adding to the vector

void aplication::addRating(rating &r)
{
    apRating.push_back(r);
}


// ==

bool aplication::operator==(const aplication &ap)
{
    if (apCode == ap.apCode)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//  destructor / copy constructor

aplication::~aplication()
{
    cout<<"deleting aplication with name : "<<apName<<endl;
    delete [] apCode;
}


// getters

char* aplication::getApCode()
{
	return apCode;
}

string aplication::getApName()
{
	return apName;
}

float aplication::getApVersion()
{
	return apVersion;
}

creator* aplication::getApCreator()
{
	return c;
}

unsigned int aplication::getApPrice()
{
	return apPrice;
}

vector <rating>* aplication::getRatingsVector()
{
    return &apRating;
}


// setters

void aplication::setApCode(char* inapCode)
{
		delete [] apCode;
		apCode = new char [strlen(inapCode)];
		strcpy(apCode, inapCode);
}

void aplication::setApName(string inapName)
{
	apName = inapName;
}

void aplication::setApVersion(float inapVersion)
{
	apVersion = inapVersion;
}

void aplication::setApCreator(creator* c)
{
	this->c = c;
}

void aplication::setApPrice(unsigned int inapPrice)
{
	apPrice = inapPrice;
}



