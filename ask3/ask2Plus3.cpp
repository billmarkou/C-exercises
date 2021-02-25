#include <stdio.h>
#include <string.h>
#include <string>
#include <new>
#include <iostream>

using namespace std;


class course 
{
	string code;
	string name;
	unsigned int courseSemester;
public:

// constructor
	course (string, string, unsigned int);
	
// course setters
	void setCourseCode(string);
	void setCourseName(string);
	void setCourseSemester(unsigned int);
	
// course getters
	string getCourseCode() const;
	string getCourseName() const;
	unsigned int getCourseSemester() const;
	
// overload of = for copy purposes
	void operator = (course&);
	
// print
	void print () const;
	
};

// course constructor
course::course(string inCode, string inName, unsigned int inCourseSemester)
{
	code=inCode;
	name=inName;
	courseSemester=inCourseSemester;
}

// course print
void course::print() const
{
	cout << "course code : " << code << endl;
	cout << "course name : " << name << endl;
	cout << "course semester : " << courseSemester << endl;
}



class student
{
// properties
	char *AM;
	string fullName;
	unsigned int semester;
	unsigned int numOfPassedCourses;
	float *arrOfPassedCourses;
	unsigned int numOfDeclaredCourses;
	course** arrOfPointersOfDeclaredCourses; 			 // pointer * points to array * of course*

public:
// constructors/destructor
	
	student (const char *, string , unsigned int, unsigned int, float*, unsigned int, course**);
	student (const student &);						// copy constructor
	~student();
	
// setters
	void setAM (const char*);
	void setFullName (string);
	void setSemester (unsigned int);
	void setNumOfPassedCourses (unsigned int);
	void editArrOfPassedCourses (int, float);		// replace a spesific grade or .....
	void setArrOfPassedCourses(float*);				// replace the array with a new array of grades
	void setArrOfPointersOfDeclaredCourses(course**);
	void setNumOfDeclaredCourses(unsigned int);
	
// getters
	const char* getAM () const;
	string getFullName () const;
	unsigned int getSemester () const;
    unsigned int getNumOfPassedCourses () const;
    float*  getArrOfPassedCourses () const;
    unsigned int getNumOfDeclaredCourses() const;
    course** getArrOfPointersOfDeclaredCourses() const;

// last 3 bullets of the excersise plus some printing for my testing 
	void insertNewGrade(float);
	void print3FirstAttr(ostream &);
	void printGrades();
	void print () const;
	
//  overload +=
	void operator+=(course &);
	
// overload =
	void operator = (student &);
	
// overload operators in order of comparing students based on their semester
	bool operator == (student&); 
	bool operator != (student&); 
	bool operator > (student&); 					// the return value will be true or false 
	bool operator >= (student&); 					// just like theese operators would work 
	bool operator < (student&); 					// with int for example 4=4 will give true
	bool operator <= (student&); 					// i' ll also print a message

};


// constractor
student::student(const char *inAM, string inFullName, unsigned int inSemester = 0, 
unsigned int inNumOfPassedCourses = 0, float* inArrOfPassedCourses = 0, 
unsigned int inNumOfDeclaredCourses = 0, course** inArrOfPointersOfDeclaredCourses = 0)
{
	
	
	int l = strlen(inAM);

	if (l)
	{
		AM = new char [l + 1];
		strcpy(AM, inAM);	
	}
    else
    {
    	AM=new char[1];
    	AM[0]=0;
	}
	
	
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
    
    numOfDeclaredCourses=inNumOfDeclaredCourses;
    
    int k;
   
    if(inNumOfDeclaredCourses!=0)
    {
    	arrOfPointersOfDeclaredCourses = new course* [inNumOfDeclaredCourses]; 
    	for(k=0; k<inNumOfDeclaredCourses; k++)
    	{
    		arrOfPointersOfDeclaredCourses[k]=inArrOfPointersOfDeclaredCourses[k];
		}
    }
    else
    {
    	arrOfPointersOfDeclaredCourses=0;
	}
}
	
// copy constructor
student::student(const student &x)
{
	int amL , fullNameL, i, j;
	printf("Copy constructing student with AM=%s\n",x.AM);
	
	amL = strlen(x.AM);
	AM = new char [amL+1];
    memcpy (AM, x.AM, amL+1);
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
	
	numOfDeclaredCourses=x.numOfDeclaredCourses;
	if(numOfDeclaredCourses!=0)
	{
		arrOfPointersOfDeclaredCourses = new course* [numOfDeclaredCourses] ;	
		arrOfPointersOfDeclaredCourses=x.arrOfPointersOfDeclaredCourses;
				
	}
	else
	{
		arrOfPointersOfDeclaredCourses=0;
	}
}
	
// destructor
student::~student()
{
	cout << "deleting student with AM : " << this->AM << endl ;
	delete[] AM;
	delete[] arrOfPassedCourses;
	delete[] arrOfPointersOfDeclaredCourses;
}
	
// student setters

void student::setAM(const char* sAM)
{
	int sAmL;
	sAmL = strlen(sAM);
	delete[] AM;
	AM = new char [sAmL+1];
	memcpy (AM, sAM, sAmL+1);
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


void student::setNumOfDeclaredCourses(unsigned int inNumOfDeclaredCourses)
{
	numOfDeclaredCourses = inNumOfDeclaredCourses;
}


void student::setArrOfPointersOfDeclaredCourses(course** inArrOfPointersOfDeclaredCourses)
{
	delete [] arrOfPointersOfDeclaredCourses;
	arrOfPointersOfDeclaredCourses = new course*[numOfDeclaredCourses];
	arrOfPointersOfDeclaredCourses = inArrOfPointersOfDeclaredCourses;
}



// course setters

void course::setCourseCode(string inCode)
{
	code=inCode;
}

void course::setCourseName(string inName)
{
	name=inName;
}

void course::setCourseSemester(unsigned int inCourseSemeter)
{
	courseSemester=inCourseSemeter;
}


// student getters

const char* student::getAM() const
{
	return AM;
}


string student::getFullName() const
{
	return fullName;
}


unsigned int student::getSemester() const
{
	return semester;
}


unsigned int student::getNumOfPassedCourses() const
{
	return numOfPassedCourses;
}


float* student::getArrOfPassedCourses() const
{
	return arrOfPassedCourses;
}


unsigned int student::getNumOfDeclaredCourses() const
{
	return numOfDeclaredCourses;
}


course** student::getArrOfPointersOfDeclaredCourses() const
{
	return arrOfPointersOfDeclaredCourses;
}


// course getters


string course::getCourseCode() const
{
	return code;
}

string course::getCourseName() const
{
	return name;
}

unsigned int course::getCourseSemester() const
{
	return courseSemester;
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
	else
	{
		cout << "there are no passed courses" << endl;
	}	
	cout << "the number of courses you have declared is : " << numOfDeclaredCourses << endl;
	if(numOfDeclaredCourses!=0)
	{
		int j;
		for(j=0; j<numOfDeclaredCourses; j++)
		{
			cout << "declared course #" << j+1 << " : "<< arrOfPointersOfDeclaredCourses[j]->getCourseName() << endl; 
		}
	}
	else
	{
		cout << "no declared courses" << endl;
	}
	printf("================================================\n");
}	



// ! bullets of ask 3 !

void student::operator +=(course& c)						// overload of +=
{
	course** temp;
	temp = new course* [numOfDeclaredCourses];
	memcpy(temp, arrOfPointersOfDeclaredCourses, numOfDeclaredCourses*sizeof(course*));
	delete [] arrOfPointersOfDeclaredCourses;
    numOfDeclaredCourses++;
	arrOfPointersOfDeclaredCourses = new course* [numOfDeclaredCourses];
	memcpy(arrOfPointersOfDeclaredCourses, temp, numOfDeclaredCourses*sizeof(course*));
	arrOfPointersOfDeclaredCourses[numOfDeclaredCourses-1] = &c;
	delete[] temp;
}


void course::operator =(course& c)							// overload of = for object course
{
	if(this != &c)
	{
		cout << "copying course : " << c.name << " to course : " << name << endl;
		code=c.code;
		name=c.name;
		courseSemester=c.courseSemester;
	}
}


void student::operator = (student& s)						// overload of = for object student
{
	if(this != &s)
	{
		cout << "copying student with AM : " << s.AM << " to student with AM : " << AM << endl;
		delete[] AM;
		delete[] arrOfPassedCourses;
		delete[] arrOfPointersOfDeclaredCourses;
		AM = new char [strlen(s.AM)];
	    strcpy(AM, s.AM);
		fullName = s.fullName;
		semester = s.semester;
		numOfPassedCourses = s.numOfPassedCourses;
		if(s.arrOfPassedCourses!=0)
	    {
			
			arrOfPassedCourses = new float [numOfPassedCourses];
			for(int i=0; i<numOfPassedCourses; i++)
			{
				arrOfPassedCourses[i]=s.arrOfPassedCourses[i];
			}
		}
		else
		{
			arrOfPassedCourses=0;
		}
		
		numOfDeclaredCourses=s.numOfDeclaredCourses;
		if(s.numOfDeclaredCourses!=0)
		{
			arrOfPointersOfDeclaredCourses = new course* [numOfDeclaredCourses] ;	
			arrOfPointersOfDeclaredCourses=s.arrOfPointersOfDeclaredCourses;
					
		}
		else
		{
			arrOfPointersOfDeclaredCourses=0;
		}
	}
}


// overloading operators for student semester comparison

bool student::operator ==(student& s)
{
	if (semester == s.semester)
	{
		cout << "student with AM : " << AM << " is in the !same! semester with student with AM : " << s.AM << endl ;
		return true;
	}
	else
	{
		cout << "student with AM : " << AM << " is in a !different! semester with student with AM : " << s.AM << endl ;
		return false;
	}
}


bool student::operator !=(student& s)
{
	if (semester != s.semester)
	{
		cout << "student with AM : " << AM << " is in a !different! semester with student with AM : " << s.AM << endl ;
		return true;
	}
	else
	{
		cout << "student with AM : " << AM << " is in the !same! semester with student with AM : " << s.AM << endl ;
		return false;
	}
}


bool student::operator > (student& s)
{
	if (semester > s.semester)
	{
		cout << "student with AM : " << AM << " is in a !higher! semester than student with AM : " << s.AM << endl ;
		return true;
	}
	else
	{
		cout << "student with AM : " << AM << " is !not! in a higher semester than student with AM : " << s.AM << endl ;
		return false;
	}
}


bool student::operator < (student& s)
{
	if (semester > s.semester)
	{
		cout << "student with AM : " << AM << " is in a !lower! semester than student with AM : " << s.AM << endl ;
		return true;
	}
	else
	{
		cout << "student with AM : " << AM << " is !not! in a lower semester than student with AM : " << s.AM << endl ;
		return false;
	}
}


bool student::operator >= (student& s)
{
	if (semester > s.semester)
	{
		cout << "student with AM : " << AM << " is in a !higher or! equal semester than student with AM : " << s.AM << endl ;
		return true;
	}
	else
	{
		cout << "student with AM : " << AM << " is !not! in a higher !or! equal semester than student with AM : " << s.AM << endl ;
		return false;
	}
}


bool student::operator <= (student& s)
{
	if (semester > s.semester)
	{
		cout << "student with AM : " << AM << " is in a !lower or! equal semester than student with AM : " << s.AM << endl ;
		return true;
	}
	else
	{
		cout << "student with AM : " << AM << " is !not! in a lower !or! equal semester than student with AM : " << s.AM << endl ;
		return false;
	}
}


// overloading << for couting students basic attributes

ostream & operator << (ostream &channel, const student &s)
{
	channel << "Printing students basic attributes : " << endl << endl;
	channel << "AM : " << s.getAM() << endl << "Fullname : " << s.getFullName() <<
	 endl << "Semester : " << s.getSemester() << endl;
	channel << "Number of passed courses : " << s.getNumOfPassedCourses() << endl <<
	 "Number of declared courses : " << s.getNumOfDeclaredCourses() << endl;
	 return channel;
}



// main

int main()
{
	float* x, *y;
	int i;
	y = new float [2];
	y[0]= 2.123f;
	y[1]= 3.456f;

	student a ("44116","vasilis markou",1,2,y);								// building object a
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
	cout << "======== !end of getter test! ========" << endl;

	c.insertNewGrade(10.0f);												// at object c inserting new grade 10 , note that 
	c.print();																// numOfPassedcourses is incresing by one , and print to check
	a.print3FirstAttr(cout);												// printing the 3 first attributes
	c.printGrades();														// printing the analytical score with the MO 



//              ===================================     ask 3     ===================================



	cout << "===================================     ask 3     ===================================" << endl;


	course one  ("123", "cpp", 5);											// building object course one
	course two ("456", "c", 4);												
	course three ("789","java",3);
	//course * one = new course ("123", "cpp", 5);

	cout << "Printing object course one" << endl;
	one.print();															// printing object one

	cout << "======== !testing getters on object one! ========" << endl;
	cout << one.getCourseCode() << endl;
	cout << one.getCourseName() << endl;
	cout << one.getCourseSemester() << endl;
	cout << "======== !end of getter test! ========" << endl;

	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	cout << "======== !testing setters on object one! ========" << endl;
	one.setCourseCode("321");
	one.setCourseName("LS");
	one.setCourseSemester(8);
	one.print();
	cout << "======== !end of setter test! ========" << endl;

	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	cout << "======== !testing the course array on object student d! ========" << endl;
	y=new float[2];
	y[0]=2.123f;
	y[1]=5.0f;
	course** co=new course* [1];
	co[0]= &two;
	student d ("55123","thanasis markou",10,2,y,2,new course*[2]{&one,&two});
	d.print();
	student copyD = d;
	copyD.print();
	d.setNumOfDeclaredCourses(1) ;
	d.setArrOfPointersOfDeclaredCourses(co);
	d.print();
	cout << "======== !end of course array test! ========" << endl;
	
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	
	cout << "======== !testing += overload on student d java course! ========" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	d += three;
	d.print();
	
	cout << "======== !testing = overload on course three and student d! ========" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	student e ("00000","no one",0,0,0,0,0);
	course four ("0","empty",0);
	four.print();
	four = two;
	four.print();
	e = d;
	e.print();
	
	cout << "======== !testing comparison operators overloads ! ========" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	a==b;
	a>b;
	b!=b;
	c!=b;
	if (c!=b)								// checking the return values
	{
		cout << "the return values work as well, just in case i need them for if statements for control" << endl;
	}
	else
	{
		cout << "trust me u' ll never see this message ";
	}
	
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "======== !testing << overload for printing the basic attributes of a student! ========" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	
	cout << a << endl << b << endl << c << endl << c << endl;             // printing basic attributes 
	  																	  
	cout << "===================================     destuctors     ===================================" << endl;

}



