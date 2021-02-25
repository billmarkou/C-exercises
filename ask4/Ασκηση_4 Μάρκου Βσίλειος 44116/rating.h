#ifndef PROJECT4_RATING_H
#define PROJECT4_RATING_H


#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

using namespace std;


class rating
{
protected:

	int stars;
	string ratorsName;
	string comments;

public:

	// constructor / destructor / copy constructor

    rating();
	rating(int, string, string);
	rating(const rating&);
	~rating();

	// print

	void print();

	// getters

	int getStars();
	string getRatorsName();
	string getComments();

	// setters

	void setStars(int);
	void setRatorsName(string);
	void setComments(string);

	// overloading = , ==

	void operator = (const rating&);
	bool operator == (const rating&);
    friend ostream & operator << (ostream &channel ,rating &r);

};



#endif //PROJECT4_RATING_H
