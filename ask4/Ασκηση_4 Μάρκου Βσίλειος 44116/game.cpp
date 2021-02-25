#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>

#include "rating.h"
#include "creator.h"
#include "aplication.h"
#include "game.h"


using namespace std;


// constructor / copy constructor

game::game(char* gameCode, string gameName, float gameVesrsion, creator* c, unsigned int gamePrice, bool ingameIsOnline)
{
	int l = strlen(gameCode);
    if (l)
	{
		apCode = new char [l + 1];
		strcpy(apCode, gameCode);
	}
    else
    {
    	apCode=new char[1];
    	apCode[0]=0;
	}

	apName = gameName;
	apVersion = gameVesrsion;
	apPrice = gamePrice;
	gameIsOnline = ingameIsOnline;

	if(c)
	{
		this->c=c;
	}
}


game::game(const game &g)
{
    cout <<"Copying game with name : "<<g.apName<<endl;
    int l = strlen(g.apCode);
    if (l)
	{
		apCode = new char [l + 1];
		strcpy(apCode, g.apCode);
	}
    else
    {
    	apCode=new char[1];
    	apCode[0]=0;
	}

	apName = g.apName;
	apVersion = g.apVersion;
	apPrice = g.apPrice;
	apRating = g.apRating;
	gameIsOnline = g.gameIsOnline;

	if(g.c)
	{
		c=g.c;
	}
}


// print
void game::print()
{
    cout<<"---------Game info---------"<<endl;
    cout<<"Game with code : "<<apCode<<" and name : "<<apName
    <<" version : "<<apVersion<<" pricing at : "<<apPrice<<endl;

    if (gameIsOnline)
	{
		cout << "game is online" <<endl;
	}
	else cout << "game is not online" <<endl;

    cout<<"---------Creator---------"<<endl;
    cout<<(*c);

    cout<<"---------Rating tab---------"<<endl;
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


// getter
bool game::getGameIsOnline()
{
	return gameIsOnline;
}

string game::getTypeOfFile(){}


// setter
void game::setGameIsOnline(bool gameIsOnline)
{
	this->gameIsOnline= gameIsOnline;
}

void game::setTypeOfFile(string s){}



