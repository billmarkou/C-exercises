#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "rating.h"

using namespace std;

// constructor / destructor / copy constructor
rating::rating(int instars, string inratorsName, string incomments)
{
	stars = instars;
	ratorsName = inratorsName;
	comments = incomments;
}

rating::rating(const rating &r)
{
    cout<<"copying rating of : "<<r.ratorsName<<endl;
    stars = r.stars;
	ratorsName = r.ratorsName;
	comments = r.comments;
}

rating::rating() : stars(0), ratorsName("unspecified"), comments("unspecified")
{}

rating::~rating()
{
	cout<<"deleting rating of : "<<ratorsName<<endl;
}


// print

void rating::print()
{
	cout<<"Rating made from "<<ratorsName<<" says : "
	<<comments<<endl<<"stars : "<<stars<<endl;
}


// overloadings = , ==

void rating::operator=(const rating &r)
{
    if (this != &r)
    {
        stars = r.stars;
        ratorsName = r.ratorsName;
        comments = r.comments;
        cout<<"Insertion completed"<<endl;
    }
}

bool rating::operator==(const rating &r)
{
    if (stars == r.stars && ratorsName == r.ratorsName && comments == r.comments)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream & operator << (ostream &channel ,rating &r)
{
    channel<<r.getRatorsName()<<endl
	<<r.getComments()<<endl<<r.stars<<endl;
    return channel;
}


// getters

int rating::getStars()
{
	return stars;
}

string rating::getRatorsName()
{
	return ratorsName;
}

string rating::getComments()
{
	return comments;
}


// setters
void rating::setStars(int instars)
{
	stars = instars;
}

void rating::setRatorsName(string inratorsName)
{
	ratorsName = inratorsName;
}

void rating::setComments(string incomments)
{
	comments = incomments;
}
