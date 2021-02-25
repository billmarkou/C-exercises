#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "creator.h"

using namespace std;


// constructor / destructor / copy constructor

creator::creator(string increatorCode = "unspecified",
char* increatorName = "unspecified", string increatorEmail = "unspecified")
{
	int l = strlen(increatorName);
	if (l)
	{
		creatorName = new char [l+1];
        strcpy(creatorName,increatorName);
	}else
	{
		creatorName = new char [1];
		creatorName[0] = 0;
	}

	creatorCode = increatorCode;
	creatorEmail = increatorEmail;
}

creator::creator() : creatorCode ("unspecified"), creatorName ("unspecified"),
creatorEmail ("unspecified")
{}


creator::creator(const creator &c)
{
    cout<<"copying creator"<<endl;
    delete[] creatorName;
    creatorName = new char[strlen(c.creatorName)];
    strcpy(creatorName,c.creatorName);
    creatorCode = c.creatorCode;
	creatorEmail = c.creatorEmail;
}

creator::~creator()
{
	cout <<"deleting creator : "<<creatorName <<endl;
	delete [] creatorName;
}


// print

void creator::print()
{
    cout<<"Creator with name : "<<creatorName<<" and code : "
    <<creatorCode<<" has email : "<<creatorEmail<<endl;
}


// overloading = , ==

void creator::operator=(const creator &c)
{
    if (this != &c)
    {
        delete[] creatorName;
        creatorName = new char[strlen(c.creatorName)];
        strcpy(creatorName,c.creatorName);
        creatorCode = c.creatorCode;
        creatorEmail = c.creatorEmail;
        cout<<"Insertion copleted"<<endl;
    }
    else
    {
        creatorName = c.creatorName;
        creatorCode = c.creatorCode;
        creatorEmail = c.creatorEmail;
    }
}

bool creator::operator==(const creator &c)
{
    if (creatorCode == c.creatorCode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream & operator << (ostream &channel ,creator &c)
{
    channel<<"Creator with name : "<<c.getName()<<" and code : "
    <<c.creatorCode<<" has email : "<<c.getEmail()<<endl;
    return channel;
}


// getters

char* creator::getName()
{
	return creatorName;
}

string creator::getCode()
{
	return creatorCode;
}

string creator::getEmail()
{
	return creatorEmail;
}


//setters

void creator::setName(char* increatorName)
{
	int l = strlen(increatorName);
	if (l)
	{
		delete [] creatorName;
		creatorName = new char [l+1];
		memcpy(creatorName, increatorName, l+1);
	}
}

void creator::setCode(string increatorCode)
{
	creatorCode = increatorCode;
}

void creator::setEmail(string increatorEmail)
{
	creatorEmail = increatorEmail;
}



