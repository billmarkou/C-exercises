#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "rating.h"
#include "creator.h"
#include "aplication.h"
#include "officeAp.h"

using namespace std;

// constructor

officeAp::officeAp(char* officeCode, string officeName, float officeVesrsion, creator* c, unsigned int officePrice, string intypeOfFile)
{
	int l = strlen(officeCode);
	if (l)
	{
		apCode = new char [l + 1];
		strcpy(apCode, officeCode);
	}
    else
    {
    	apCode=new char[1];
    	apCode[0]=0;
	}

	apName = officeName;
	apVersion = officeVesrsion;
	apPrice = officePrice;
	typeOfFile = intypeOfFile;

	if(c)
	{
		this->c=c;
	}
}


officeAp::officeAp(const officeAp &of)
{
    cout <<"Copying office application with name : "<<of.apName<<endl;
    int l = strlen(of.apCode);
    if (l)
	{
		apCode = new char [l + 1];
		strcpy(apCode, of.apCode);
	}
    else
    {
    	apCode=new char[1];
    	apCode[0]=0;
	}

	apName = of.apName;
	apVersion = of.apVersion;
	apPrice = of.apPrice;
	apRating = of.apRating;
	typeOfFile = of.typeOfFile;

	if(of.c)
	{
		c=of.c;
	}
}


// print

void officeAp::print()
{
    cout<<"---------Office ap info---------"<<endl;
    cout<<"Office application with code : "<<apCode<<" and name : "
    <<apName<<" current version : "<<apVersion<<" handling files : "
    <<typeOfFile<<" pricing at : "<<apPrice<<endl;

    cout<<"---------Creator---------"<<endl;
    cout << (*c)<<endl;

    cout<<"---------Ratings tab---------"<<endl;
	if (apRating.size())
	{
		for (unsigned int i=0; i<apRating.size(); i++)
		{
			apRating.at(i).print();
		}
	}
	else
	{
		cout<< "no ratings yet"<<endl;
	}
	cout << endl << endl;
}


// getters

string officeAp::getTypeOfFile()
{
	return typeOfFile;
}

bool officeAp::getGameIsOnline(){}


// setters

void officeAp::setTypeOfFile(string intypeOfFile)
{
	typeOfFile = intypeOfFile;
}

void officeAp::setGameIsOnline(bool g){}
