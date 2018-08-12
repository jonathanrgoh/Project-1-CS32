// Student.h
#ifndef STUDENT_INCLUDED
#define STUDENT_INCLUDED

class Student
{
	...
	void enroll(Course* cp);
	...
	Course* m_studyList[10]
};

#endif // STUDENT_INCLUDED

=======================================

// Course.h

#ifndef COURSE_INCLUDED
#define COURSE_INCLUDED
	
Class Student;

class Student
{
	...
	Student* m_roster[1000]
};

#endif // COURSE_INCLUDED

=======================================
	
// myapp.cpp
	
#include "Student.h"

int main()
{
	Student s(...);
	......
	Course* cp; 
	...
	cp = new Course();
	s.enroll(cp);
}

/* 

If you declare a variable of type Foo, the compiler has to know how big a Foo oject is.
If you call a member function of foo, the compiler has to know there is such a function.

When tou declare a pointer or a reference to a foo object, the compiler needs to kmow only that Foo is the name of a type.

*/

// "Circular Dependency"

#include "Student.h"
#include "Course.h"

void enroll(Course* cp)
{
	int units = cp->units();
};

#endif // STUDENT_INCLUDED



======================================
======================================
	
class Circle
{
public:
	Circle(double x, double y, double r)
private:
	double m_x;
	
};

Circle::Circle(double x, double y, double r)
	: m_x(x), m_y(y), m_r(r)
{
	if (r<=0)
		...
	m_x=x;
	m_y=y;
	m_r=r;
}

class StickFigure
{
public:
	StickFigure(double bl,double headDiam, string nm, double hx, double hy);
private:
	double m_bodyLength;
	string m_name;
	Circle m_head;
};

StickFigure::StickFigure(double bl,double headDiam, string nm, double hx, double hy)
	:m_bodyLength(bl), m_name(nm), m_head(hx,hy,headDiam/2)
{
}

int main()
{
	StickFigure(5,4,"Fred",-2,5);
}

/*

How an object is constructed:
1) -----
2) Construct the data members
		If the member initialization list says how to initialize the member, do that.
		If not: if the member is of class type, default-construct it
				if the member is of a builtin type, leave it unitilialized
3) Execute the boy of the constructor

*/

======================================
	==================================

Employee::Employee(string nm, double sal, int ag)
{
	name = nm;
	salary = sal;
	age = ag;
}

sruct Employee
{
	Employee(string nm, double sal, int ag);
	string name;
	double salary;
	int age;
}

Employee e("Ricky", 80000, 42);

StickFigure sf(5,4,"Fred",-2,5);

