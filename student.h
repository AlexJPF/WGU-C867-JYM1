//
// JYM1 - student.h
// Scripting and Programming Applications - C867
// Alexander J. Pfleging
// Student ID# xxx
//

#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using std::string;

//

class Student {
    
private:
    string          studentId;
    string          firstName;
    string          lastName;
    string          email;
    int             age;
    double          daysArray[3];
    DegreeProgram   dtype;


public:
    
    // default constructor
        Student();

    // full constructor
        Student(string studentId, string firstName, string lastName, string email,
                int age, double days1, double days2, double days3, DegreeProgram dtype);
    
    // accessors
        string const    getStudentId();
        string const    getFirstName();
        string const    getLastName();
        string const    getEmail();
        DegreeProgram   getDegreeProgram();
        int             getAge();
        double *        getDays();

    // mutators
        void setStudentId(string studentId);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setDays(double days1, double days2, double days3);
        void setDegreeProgram(DegreeProgram dtype);
    
    // deconstructor
        ~Student();

    // other stuff
        void print();
        const static int daysSizeArr = 3;

};
