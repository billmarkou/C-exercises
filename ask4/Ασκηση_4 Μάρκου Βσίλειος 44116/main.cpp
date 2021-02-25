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
#include "officeAp.h"
#include "game.h"
#include "apSystem.h"

using namespace std;

int main()
{

// creating the apSystem instance

apSystem madRobot; // thats standar instance
apSystem madLoadedRobot;  // thats the instance i use for loading

// creating creators

creator cr1 ("cr1", "Hiddeo Kozima", "hk@gmail.com");
creator cr2 ("cr2", "Nintedo", "Nedo@gmail.com");
creator cr3 ("cr3", "Linus Torvalds", "LT@gmail.com");
creator cr4 ("cr4", "microsoft", "billG@outlook.com");


// creating ratings

rating ra1 (1, "hater", "walking simulator");
rating ra2 (3, "bill", "meeh its ok i guess");
rating ra3 (5, "fanboy", "best game ever");
rating ra4 (3, "mrRobot", "good");
rating ra5 (5, "casual", "very nice");
rating ra6 (5, "everyone", "Game of the year");

// creating office ap

officeAp of1 ("of1", "word", 2.1f, &cr4, 20, "docx");
officeAp of2 ("of2", "excel", 2.5f, &cr4, 0, "excel");

// creating games

game ga1 ("g1", "death stranding", 1.2f, &cr1, 60, 1);
game ga2 ("g2", "Zelda breath of the wild", 1.5f, &cr2, 60, 0);


// adding ratings to apps

ga1.addRating(ra1);
ga1.addRating(ra2);
ga1.addRating(ra3);
ga2.addRating(ra6);

// inserting mad robots apps

madRobot.addApp(&ga1);
madRobot.addApp(&ga2);
madRobot.addApp(&of1);
madRobot.addApp(&of2);

cout<<endl<<"!!!!!!!!!!!!!!!!!!!  START OF PROGRAM  !!!!!!!!!!!!!!!!!!!"<<endl<<endl;

cout <<endl<<"==================  Printing the madRobots list  =================="<<endl;

madRobot.printList();   // print madrobots apps

cout <<endl<<"==================  Printing awesome games  =================="<<endl;

madRobot.printGames(); // print all games with average over 4

cout <<endl<<"==================  Printing free officeApps  =================="<<endl;

madRobot.printOfficeApps();  // printing officeAps that are FREE !!! $$$$

cout <<endl<<"==================  Save and load  =================="<<endl;

madRobot.it1 = madRobot.apList.begin();             // by using this iterator i can have access
(*madRobot.it1)->getApCreator()->print();           // to all of madrobots attributes through
cout<<endl<<endl;                                   // the use of getter and setters of classes

madRobot.deleteBadAps("Hiddeo Kozima");             // deleting all apps cause kozima went rogue !

cout<<madRobot;                                     // showing the overload of <<

try
{
    madRobot.save(madRobot);                        // saves in correct format all of madRobots apps
}                                                   // in the file saveFile located in folder filles
catch (int v)
{
    cout << "cant open file to save"<<endl;
}
ifstream loadFile("/home/bill/Desktop/askisi4/files/loadFile.txt");  // open file of data for madRobot
try              // !change path acording to your file location!     // the fuction load closes the file
{                                                                    // after its done
    list <aplication*>* loadedList = madRobot.load(loadFile);
    madLoadedRobot.apList = *loadedList;                             // loads the list to madLoadedRobot
    madLoadedRobot.printList();                                      // and then prints it with the formal way
}                                                                    // note there are some gibrish printings
catch (char o)                                                       // those were for debugging
{
    if (o=='a')
    {
        cout << "your file is missing an application code "<<endl;
    }
    else if (o=='b')
    {
        cout << "your file is missing an application name "<<endl;
    }
    else if (o=='c')
    {
        cout << "your file is missing an application version "<<endl;
    }
    else if (o=='d')
    {
        cout << "your file is missing an application price "<<endl;
    }
    else if (o=='e')
    {
        cout << "your file is missing if application is online or what files can handle  "<<endl;
    }
    else if (o=='f')
    {
        cout << "your file is missing an application creators name "<<endl;
    }
    else if (o=='g')
    {
        cout << "your file is missing an application creators code "<<endl;
    }
    else if (o=='h')
    {
        cout << "your file is missing an application creators mail"<<endl;
    }
    else if (o=='k')
    {
        cout << "your file is missing an application rators name "<<endl;
    }
    else if (o=='l')
    {
        cout << "your file is missing an application rators comment "<<endl;
    }
    else if (o=='m')
    {
        cout << "your file is missing an application rators stars "<<endl;
    }
    else if (o=='n')
    {
        cout << "your file is missing a label if its game or officeapp "<<endl;
    }

}

cout<<"!!!!!!!!!!!!!!!!!!!  SECCESFULL END OF PROGRAM  !!!!!!!!!!!!!!!!!!!"<<endl<<endl;



}
