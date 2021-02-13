//
// JYM1 - student.cpp
// Scripting and Programming Applications - C867
// Alexander J. Pfleging
// Student ID# xxx
//

#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
#include <string>

using namespace std;

//

// default constructor
    Student::Student() {
        this -> studentId = "";
        this -> firstName = "";
        this -> lastName = "";
        this -> email = "";
        this -> age = 0;
        this -> daysArray[0] = 11.0;
        this -> daysArray[1] = 22.0;
        this -> daysArray[2] = 33.0;
        this -> dtype = DegreeProgram::UNDECIDED;
    };


// full constructor
    Student::Student(string studentId, string firstName, string lastName, string email,
                     int age, double days1, double days2, double days3, DegreeProgram dtype)
    {
        setStudentId(studentId);
        setLastName(lastName);
        setFirstName(firstName);
        setEmail(email);
        setAge(age);
        setDegreeProgram(dtype);
        setDays(days1, days2, days3);
    };


// deconstructor
    Student::~Student() {};


// print
    /*
    // Evaluator Comments: While a print() function is present in the Student class, it does not appear to use the accessors or provide output of the student data. The instructions state to create in the Student class a "print() to print specific student data"
    void Student::print() {};
     */


// fixed print function
void Student::print()
{
    cout << left << setw(5)  << getStudentId();
    cout << left << setw(12) << getFirstName();
    cout << left << setw(12) << getLastName();
    cout << left << setw(25) << getEmail();
    cout << left << setw(7)  << getAge();
    cout << left << setw(7)  << daysArray[0];
    cout << left << setw(7)  << daysArray[1];
    cout << left << setw(7)  << daysArray[2];
    cout << left << setw(10) << degreeProgramArray[getDegreeProgram()];
    cout << endl;
};


// accessors and mutators
//

// student id
    void Student::setStudentId(string studentId) {
        this -> studentId = studentId;
    };

    string const Student::getStudentId() {
        return this -> studentId;
    };


// first name
    void Student::setFirstName(string firstName) {
        this -> firstName = firstName;
    };

    string const Student::getFirstName() {
        return this -> firstName;
    };


// last name
    void Student::setLastName(string lastName) {
        this -> lastName = lastName;
    };

    string const Student::getLastName() {
        return this -> lastName;
    };


// email address
    void Student::setEmail(string email) {
        this -> email = email;
    };

    string const Student::getEmail() {
        return this -> email;
    };


// age
    void Student::setAge(int age) {
        this -> age= age;
    };

    int Student::getAge() {
        return this -> age;
    };


// days remaining - array of 3
    void Student::setDays(double days1, double days2, double days3)
    {
        this -> daysArray[0] = days1;
        this -> daysArray[1] = days2;
        this -> daysArray[2] = days3;
    };

    double * Student::getDays() {
         return this -> daysArray;
    };


// degree program enum
     void Student::setDegreeProgram(DegreeProgram d) {
        this -> dtype = d;
    };

     DegreeProgram Student::getDegreeProgram() {
         return dtype;
     };
