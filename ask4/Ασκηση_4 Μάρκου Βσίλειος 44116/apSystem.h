#ifndef PROJECT4_APSYSTEM_H
#define PROJECT4_APSYSTEM_H

#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>

#include "rating.h"
#include "creator.h"
#include "aplication.h"
#include "game.h"
#include "officeAp.h"

using namespace std;


class apSystem
{
public:

    list <aplication*> apList;
    list <aplication*>::iterator it1;

//public:

    // constructor

    apSystem ();


    // add aplication and delete bad creator ones

    void addApp(aplication*);
    void deleteBadAps (string);

    // genuin print

    void printList();

    // bullets

    void printGames();
    void printOfficeApps();
    friend ostream & operator << (ostream&, apSystem&);


    // save and load from files

    void save(apSystem&);
    list <aplication*>* load(ifstream&);
};




#endif //PROJECT4_APSYSTEM_H
