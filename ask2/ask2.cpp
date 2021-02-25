#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>

using namespace std;


class student
{
// properties
	char *AM;
	string fullName;
	unsigned int semester;
	unsigned int numOfPassedCourses;
	float *arrOfPassedCourses;

public:
// constructors/destructor
	
	student (const char *, string , unsigned int, unsigned int, float*);
	student (const student &);						// copy constructor
	~student();
	
// setters
	void setAM (const char*);
	void setFullName (string);
	void setSemester (unsigned int);
	void setNumOfPassedCourses (unsigned int);
	void editArrOfPassedCourses (int, float);		// replace a spesific grade or .....
	void setArrOfPassedCourses(float*);				// replace the array with a new array of grades

// getters
	const char* getAM ();
	string getFullName ();
	unsigned int getSemester ();
    unsigned int getNumOfPassedCourses ();
    float*  getArrOfPassedCourses ();

// last 3 bullets of the excersise plus some printing for my testing 
	void insertNewGrade(float);
	void print3FirstAttr(ostream &);
	void printGrades();
	void print () const;
};


// constractor

student::student(const char *inAM, string inFullName, unsigned int inSemester = 0, unsigned int inNumOfPassedCourses = 0, float* inArrOfPassedCourses = 0)
{
	
	int i;
	int l = strlen(inAM);

	if (l)
	{
		AM = new char [l + 1];
		strcpy(AM, inAM);	
	}
    AM[l] = NULL;
	
	
	fullName = inFullName;
	semester = inSemester;
	numOfPassedCourses = inNumOfPassedCourses;
	
	int j;
	
	if (numOfPassedCourses)
	{
		arrOfPassedCourses = new float [numOfPassedCourses];
		for(j=0; j<numOfPassedCourses; j++)
		arrOfPassedCourses[j] = inArrOfPassedCourses[j];
	}
	else
	{
		arrOfPassedCourses=0;
	}
    
    
}
	
// copy constructor

student::student(const student &x)
{
	int amL , fullNameL, i;
	printf("Copy constructing\n");
	
	amL = strlen(x.AM);
	AM = new char [amL+1];
    memcpy (AM, x.AM, amL);
	AM[amL] = NULL;
	fullName = x.fullName;
	semester = x.semester;
	numOfPassedCourses = x.numOfPassedCourses;
    if(x.arrOfPassedCourses!=0)
    {
		
		arrOfPassedCourses = new float [numOfPassedCourses];
		for(i=0; i<numOfPassedCourses; i++)
		{
			arrOfPassedCourses[i]=x.arrOfPassedCourses[i];
		}
	}
	else
	{
		arrOfPassedCourses=0;
	}
}
	
// destructor

student::~student()
{
	cout << "deleting student with AM : " << this->AM << endl ;
	delete[] AM;
	delete[] arrOfPassedCourses;
}
	
// setters

void student::setAM(const char* sAM)
{
	int sAmL;
	sAmL = strlen(sAM);
	delete[] AM;
	AM = new char [sAmL+1];
	memcpy (AM, sAM, sAmL);
	AM[sAmL] = NULL;
}


void student::setFullName(string sFullName)
{

	fullName = sFullName;
}


void student::setSemester(unsigned int sSemester)
{
	semester = sSemester;
}


void student::setNumOfPassedCourses(unsigned int sNumOfPassedCourses)
{
	numOfPassedCourses = sNumOfPassedCourses;
}	


void student::editArrOfPassedCourses(int x, float sGrade)
{
	this->arrOfPassedCourses[x] = sGrade;
}


void student::setArrOfPassedCourses(float *newArrOfPassedCourses)
{
	int j;
	delete[] arrOfPassedCourses;
	arrOfPassedCourses = new float [this->numOfPassedCourses];
	for(j=0; j<this->numOfPassedCourses; j++)
	arrOfPassedCourses[j] = newArrOfPassedCourses[j];
}

// getters

const char* student::getAM()
{
	return AM;
}


string student::getFullName()
{
	return fullName;
}


unsigned int student::getSemester()
{
	return semester;
}


unsigned int student::getNumOfPassedCourses()
{
	return numOfPassedCourses;
}

float* student::getArrOfPassedCourses()
{
	return arrOfPassedCourses;
}

// testing , printing and last bullets of the excersise 

void student::insertNewGrade(float x)
{
	int i,j;
	float* temp;
	temp = new float[this->numOfPassedCourses]; 
	for (i=0; i<this->numOfPassedCourses; i++)
	{
		temp[i]=arrOfPassedCourses[i];
	}
	this->numOfPassedCourses++;
	delete [] arrOfPassedCourses;
	this->arrOfPassedCourses = new float[this->numOfPassedCourses];
	for (j=0; j<this->numOfPassedCourses; j++)
	{
		arrOfPassedCourses[j]=temp[j];
	}
	this->arrOfPassedCourses[this->numOfPassedCourses-1] = x ;
	delete [] temp;
	
}


void student::print3FirstAttr(ostream & channel)
{
	channel << "Student " << this->fullName << " with AM " << this->AM << " is currently at semester #" << this->semester <<endl ;	
}


void student::printGrades()
{
	int i;
	float temp = 0, MO = 0;
	cout << "======== Printing grades of student " << this->fullName << " ========" << endl;
	for (i=0; i<this->numOfPassedCourses; i++)
	{
		temp += arrOfPassedCourses[i];
		cout << "Course #" << i <<" : " << this->arrOfPassedCourses[i] << endl;	 
	}
	MO = temp / numOfPassedCourses;
	cout << "The M.O. so far is " << MO << endl;
}


void student::print () const													// my printf for testing porpuses (of objects)
{																				
	printf("================================================\n");
	printf("AM : %s\n", AM);
	printf("Full Name : %s\n", fullName.c_str());
	printf("Semester : %d\n", semester);
	printf("Number Of Passed Courses : %d\n",  numOfPassedCourses);
	if(this->arrOfPassedCourses != NULL)
	{
		
		int i;
		for(i=0; i<this->numOfPassedCourses; i++)
		{
			printf("Array Of Passed Courses : %f\n",  arrOfPassedCourses[i]);
		}
	}	

}	


// main

int main()
{
	float* x;
	int i;
	student a ("44116","vasilis markou",1,2,new float[2]{2.123f,5.0f});		// building object a
	a.print();																// printing it
	student b = a;															// copying a creating b
	b.print();																// printing it
	student c ("45224","giannis roumeliotis");								// building object c with only the nessecery arguments
	c.print();																// printing it so i can see the default values
	c.setAM("12345");														// testing setters
	c.setFullName("nikos xalkiotis");
	c.setSemester(5);
	c.setNumOfPassedCourses(5);
	c.setArrOfPassedCourses(new float[5]{1.123f,2.2f,3.3f,4.4f,5.5f});      // replacing the hall array
	c.print();																// print c to check setters
	cout << "======== !testing getters on object b! ========" << endl;
	cout << b.getAM() << endl;
	cout << b.getFullName() << endl;
	cout << b.getSemester() << endl;
	cout << b.getNumOfPassedCourses() << endl;
	x=b.getArrOfPassedCourses();                                            // at x is the array
	cout << x[1]<<endl;                                                     // i can take the hall array with a for or an element 
	cout << "end of getter test" << endl;
	c.insertNewGrade(10.0f);												// at object c inserting new grade 10 , note that 
	c.print();																// numOfPassedcourses is incresing by one , and print to check
	a.print3FirstAttr(cout);												// printing the 3 first attributes
	c.printGrades();														// printing the analytical score with the MO 


}
