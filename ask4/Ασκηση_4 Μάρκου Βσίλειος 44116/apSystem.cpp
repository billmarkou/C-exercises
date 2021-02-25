#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>
#include <vector>
#include <fstream>

#include "rating.h"
#include "creator.h"
#include "aplication.h"
#include "game.h"
#include "officeAp.h"
#include "apSystem.h"

using namespace std;

// constructor

apSystem::apSystem(){}


// add and delete apps

void apSystem::addApp(aplication *ap)
{
    apList.push_back(ap);
}

void apSystem::deleteBadAps(string ap)
{
    for (it1=apList.begin(); it1!=apList.end(); it1++)
    {
        if(string((*it1)->getApCreator()->getName()) == ap )
        {
            it1=apList.erase(it1);
        }
    }
}


// printing free office apps , astonishing games ..... oh and print all

void apSystem::printOfficeApps()
{
    officeAp* temp;
    for (it1=apList.begin(); it1!=apList.end(); it1++)
    {
        temp = dynamic_cast <officeAp*> (*it1);
        if(temp!=NULL && temp->getApPrice()==0)
        {
            temp->print();
        }
    }
}


void apSystem::printGames()
{
    game* temp;
    for (it1=apList.begin(); it1!=apList.end(); it1++)
    {
        temp = dynamic_cast <game*> (*it1);
        if(temp!=NULL && temp->ratingAverage()>=4)
        {
            temp->print();
        }
    }
}


void apSystem::printList()
{
    int i=1;
	cout << "xxxxxxxxxxxxxxxx!  Printing all the apps in the list  !xxxxxxxxxxxxxxxx" << endl << endl;
	for (it1=apList.begin(); it1!=apList.end(); it1++)
    {
        cout<<endl<<"App no "<<i<<" :"<<endl<<endl;
        (*it1)->print();
        i++;
    }
    cout<< "Total apps in appList #"<<i-1<<endl<<endl;
    cout<< "xxxxxxxxxxxxxxxx!  End of printing  !xxxxxxxxxxxxxxxx"<<endl<<endl;
}


// overloading << so i can print in any channel


ostream & operator << (ostream &channel, apSystem &s)
{
    game* temp;

	for (s.it1=s.apList.begin(); s.it1!=s.apList.end(); s.it1++)
    {

        temp = dynamic_cast <game*> (*s.it1);
        if(temp!=NULL)
        {
            channel << "Game"<<endl;
            channel << (*s.it1)->getApCode()<<endl;
            channel << (*s.it1)->getApName()<<endl;
            channel << (*s.it1)->getApVersion()<<endl;
            channel << (*s.it1)->getApPrice()<<endl;
            channel << (*s.it1)->getGameIsOnline()<<endl;

            channel << (*s.it1)->getApCreator()->getName()<<endl;
            channel << (*s.it1)->getApCreator()->getCode()<<endl;
            channel << (*s.it1)->getApCreator()->getEmail()<<endl;

            for (int i=0; i<(*s.it1)->getRatingsVector()->size(); i++)
            {
                channel<<(*s.it1)->getRatingsVector()->at(i);
            }
            channel << "no ratings"<<endl;
        }
        else  // its officeAp
        {
            channel << "officeAp" <<endl;
            channel << (*s.it1)->getApCode()<<endl;
            channel << (*s.it1)->getApName()<<endl;
            channel << (*s.it1)->getApVersion()<<endl;
            channel << (*s.it1)->getApPrice()<<endl;
            channel << (*s.it1)->getTypeOfFile()<<endl;

            channel << (*s.it1)->getApCreator()->getName()<<endl;
            channel << (*s.it1)->getApCreator()->getCode()<<endl;
            channel << (*s.it1)->getApCreator()->getEmail()<<endl;

            for (int i=0; i<(*s.it1)->getRatingsVector()->size(); i++)
            {
                channel<<(*s.it1)->getRatingsVector()->at(i);
            }
            channel << "no ratings"<<endl;
        }

    }
	 return channel;
}


// save , load from files


void apSystem::save(apSystem &s)        // serializer ... fancy for converting objs to text
{
    ofstream savefile ("/home/bill/Desktop/askisi4/files/saveFile.txt"); // change to save wherever you want !
    if (!savefile){throw 1;}
    savefile << s;
    savefile.close();
}

list <aplication*>* apSystem::load(ifstream &loadFile)      // deserializer doing the oposite
{                                                           // for me the hardest part ........

    list <aplication*>* apList = new list<aplication*>();
    string mytext;
    while (getline(loadFile, mytext))
    {
        if (mytext == "Game")
        {
            getline(loadFile, mytext);
            char* apCode = &mytext[0];
            if (apCode==NULL){throw 'a';}
            cout << "code for game is : "<< apCode <<endl;

            getline(loadFile, mytext);
            string apName = mytext;
            if (apName.length()==0){throw 'b';}
            cout << "name for game is : "<< apName <<endl;

            getline(loadFile, mytext);
            char* p;
            float apVersion = strtof(&mytext[0],&p);
            if (apVersion==NULL){throw 'c';}
            cout << "version for game is : "<< apVersion <<endl;

            getline(loadFile, mytext);
            unsigned int apPrice = stoi(mytext);
            if (apPrice==NULL){throw 'd';}
            cout << "price for game is : "<< apPrice <<endl;

            getline(loadFile, mytext);
            bool gameIsOnline=0;
            if (mytext == "1") gameIsOnline = 1 ;
            if (mytext.length()==0){throw 'e';}
            cout << "game is online for game is : "<< gameIsOnline <<endl;

            getline(loadFile, mytext);
            string apCreatorName = mytext;
            if (apCreatorName.length()==0){throw 'f';}
            cout << "name for game creator is : "<< apCreatorName <<endl;

            getline(loadFile, mytext);
            char* apCreatorCode = &mytext[0];
            if (apCreatorCode==NULL){throw 'g';}
            cout << "code for game creator is : "<< apCreatorCode <<endl;

            getline(loadFile, mytext);
            string apCreatorEmail = mytext;
            if (apCreatorEmail.length()==0){throw 'h';}
            cout << "email for game creator is : "<< apCreatorEmail <<endl;

            creator* cre1 = new creator(apCreatorName, apCreatorCode, apCreatorEmail);
            aplication* apl1 = new game(apCode, apName, apVersion, cre1, apPrice, gameIsOnline);

            getline(loadFile, mytext);
            if (mytext != "no ratings")
            {
                int flag=0;
                while (flag==0)
                {
                    string apRatorsName = mytext;
                    if (apRatorsName.length()==0){throw 'k';}
                    cout << "name for game rator is : "<< apRatorsName <<endl;

                    getline(loadFile, mytext);
                    string apRatorsComments = mytext;
                    if (apRatorsComments.length()==0){throw 'l';}
                    cout << "rators comments for game are : "<< apRatorsComments <<endl;

                    getline(loadFile, mytext);
                    unsigned int apRatingStars = stoi(mytext);
                    if (apRatingStars==NULL){throw 'm';}
                    cout << "stars for the game : "<< apRatingStars <<endl;

                    rating * rat1 = new rating(apRatingStars, apRatorsName, apRatorsComments);
                    apl1->addRating(*rat1);

                    getline(loadFile, mytext);
                    if (mytext == "no ratings")
                    {
                        flag = 1;
                    }
                }

            }

            apList->push_back(apl1);

        }
        else if(mytext == "OfficeAp")
        {
            getline(loadFile, mytext);
            char* apCode = &mytext[0];
            if (apCode==NULL){throw 'a';}
            cout << "code for office is : "<< apCode <<endl;

            getline(loadFile, mytext);
            string apName = mytext;
            if (apName.length()==0){throw 'b';}
            cout << "name for office is : "<< apName <<endl;

            getline(loadFile, mytext);
            char* p;
            float apVersion = strtof(&mytext[0],&p);
            if (apVersion==NULL){throw 'c';}
            cout << "version for office is : "<< apVersion <<endl;

            getline(loadFile, mytext);
            int apPrice = stoi(mytext);
            if (apPrice==NULL){throw 'd';}
            cout << "price for office is : "<< apPrice <<endl;

            getline(loadFile, mytext);
            string fileType = mytext;
            if (mytext.length()==0){throw 'e';}
            cout << "type of file for office is : "<< fileType <<endl;

            getline(loadFile, mytext);
            string apCreatorName = mytext;
            if (apCreatorName.length()==0){throw 'f';}
            cout << "name for office creator is : "<< apCreatorName <<endl;

            getline(loadFile, mytext);
            char* apCreatorCode = &mytext[0];
            if (apCreatorCode==NULL){throw 'g';}
            cout << "code for office creator is : "<< apCreatorCode <<endl;

            getline(loadFile, mytext);
            string apCreatorEmail = mytext;
            if (apCreatorEmail.length()==0){throw 'h';}
            cout << "email for office creator is : "<< apCreatorEmail <<endl;



            creator* cre2 = new creator(apCreatorName, apCreatorCode, apCreatorEmail);
            aplication* apl2 = new officeAp(apCode, apName, apVersion, cre2, apPrice, fileType);

            getline(loadFile, mytext);
            if (mytext != "no ratings")
            {
                int flag=0;
                while (flag==0)
                {
                    string apRatorsName = mytext;
                    if (apRatorsName.length()==0){throw 'k';}
                    cout << "name for officeap rators is : "<< apRatorsName <<endl;

                    getline(loadFile, mytext);
                    string apRatorsComments = mytext;
                    if (apRatorsComments.length()==0){throw 'l';}
                    cout << "rators comments for officeap are : "<< apRatorsComments <<endl;

                    getline(loadFile, mytext);
                    unsigned int apRatingStars = stoi(mytext);
                    if (apRatingStars==NULL){throw 'm';}
                    cout << "stars for that officeap : "<< apRatingStars <<endl;

                    rating * rat1 = new rating(apRatingStars, apRatorsName, apRatorsComments);
                    apl2->addRating(*rat1);

                    getline(loadFile, mytext);
                    if (mytext == "no ratings")
                    {
                        flag = 1;
                    }
                }

            }

            apList->push_back(apl2);        // we made the item and now we are putting it in

        }
        else {throw 'n';}
    }
    loadFile.close();
    return apList;
}
