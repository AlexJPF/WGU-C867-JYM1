//
// JYM1 - roster.cpp
// Scripting and Programming Applications - C867
// Alexander J. Pfleging
// Student ID# xxx
//

#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

//

// default constructor
Roster::Roster() {
    this -> rosterLimit = 0;
    this -> lastIndex = -1;
    this -> classRosterArray = { nullptr };
};


// base constructor
Roster::Roster(int rLimit) {
    this -> rosterLimit = rLimit;
    this -> lastIndex = -1;
    this -> classRosterArray = new Student * [rosterLimit];
};


// parse data and create roster array
void Roster::studentParser(string row) {

    if (lastIndex < rosterLimit) {
        lastIndex++;
        double darray[Student::daysSizeArr];
        string degreeProgramString;

        this -> classRosterArray[lastIndex] = new Student;
        
        // student id
        int rhs = studentData[lastIndex].find(",");
        this -> classRosterArray[lastIndex] -> setStudentId(studentData[lastIndex].substr(0, rhs));

        // first name
        int lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex] -> setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

        // last name
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

        // email address
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex] -> setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

        // age
        std::string::size_type size;
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex] -> setAge(std::stoi(studentData[lastIndex].substr(lhs, rhs - lhs), &size));

        // days in each course
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        darray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        darray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        darray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

        // combine and set days
        classRosterArray[lastIndex] -> setDays(darray[0], darray[1], darray[2]);

        // degree program
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        degreeProgramString = studentData[lastIndex].substr(lhs, rhs - lhs);
        
        if (degreeProgramString == "SECURITY") {
            classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
        }
        else if (degreeProgramString == "NETWORK") {
            classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
        }
        else if (degreeProgramString == "SOFTWARE") {
            classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
        }
        else {
            classRosterArray[lastIndex]->setDegreeProgram(UNDECIDED);
        }
    }
};


// print roster
    /*
    // Evaluator Comments: The printAll() function is present, but does not call print() as stipulated by the assessment instructions.
    void Roster::printAll() {
        for (int i = 0; i < this -> rosterLimit; i++) {
            cout << classRosterArray[i] -> getStudentId() << "    "
                
                << "First Name: "       << classRosterArray[i]   -> getFirstName() << "    "
                << "Last Name: "        << classRosterArray[i]   -> getLastName() << "    "
                << "Age: "              << classRosterArray[i]   -> getAge() << "    "
                << "daysInCourse: ["    << *classRosterArray[i]  -> getDays() << ","
                                        << *(classRosterArray[i] -> getDays() + 1) << ","
                                        << *(classRosterArray[i] -> getDays() + 2) << "]    "
                << "Degree Program: "   << degreeProgramArray[classRosterArray[i] -> getDegreeProgram()] << endl;
        };
    };
    */


// fixed print roster function
void Roster::printAll() {
    for (int i = 0; i <= this -> lastIndex; i++) {
        (this -> classRosterArray)[i] -> print();
    }
};


// print student
void Roster::printStudent(string studentId) {
    cout << "Searching database for student # " << studentId << "..." << endl;
    cout << endl;
    
    for (int i = 0; i <= lastIndex; i++) {
        if (this -> classRosterArray[i] -> getStudentId() == studentId) {
            this -> classRosterArray[i] -> print();
        }
    }
};


// add to roster
void Roster::addToRoster(string sid, string first, string last, string em, int age,
                         double d1, double d2, double d3, DegreeProgram d) {
    this -> rosterLimit++;
    classRosterArray[this -> rosterLimit - 1] = new Student(sid, first, last, em, age, d1, d2, d3, d );
    cout << "New Student " << classRosterArray[this -> rosterLimit -1] -> getFirstName() << " added Successfully" << endl;
};
        

// identify and print invalid emails
void Roster::printInvalidEmails()
{
    std::vector<std::string> invalidEmails;
    invalidEmails.reserve(this -> rosterLimit);
    bool invalid = false;
    string email;
    for (unsigned int i = 0; i < this -> rosterLimit; i++)
    {
        email = this -> classRosterArray[i] -> getEmail();
        if (!(email.find('@') < email.length()))
        {
            invalidEmails.push_back(email);
            invalid = true;
            continue;
        }
       
        if (email.find(' ') < 20)
        {
            invalidEmails.push_back(email);
            invalid = true;
            continue;
        }
        if (!(email.find('.') < email.length()))
        {
            invalidEmails.push_back(email);
            invalid = true;
        }
    }
    if (invalid)
    {
        
        for (string& emails : invalidEmails)
            cout << emails << endl;
        
    }
    else
        cout << "All emails are valid" << endl;
}


// calculate and print average days
void Roster::printAverageDays(string studentId) {
    double sum;
    double average;
    for (int i = 0; i < this -> rosterLimit; i++) {
        if (studentId == this -> classRosterArray[i] -> getStudentId()) {
            sum = *(this -> classRosterArray[i] -> getDays()) + *(this -> classRosterArray[i] -> getDays() + 1) + *(this -> classRosterArray[i] -> getDays() + 2);
            average = sum / 3;
            cout << "Average Days in Course for " << this -> classRosterArray[i] -> getFirstName() << " equals " << average << " days" << endl;
        }
    }
};


// print by degree program
    /*
    void Roster::printByDegree(DegreeProgram d) {
        for (int i = 0; i < rosterLimit; i++) {
            if (d == this -> classRosterArray[i] -> getDegreeProgram()) {
                cout << this -> classRosterArray[i] -> getFirstName() << "  #" << this -> classRosterArray[i] -> getStudentId() << endl;
            };
        };
    };
     */


// fixed print by degree program
void Roster::printByDegree(DegreeProgram d) {
    cout << "Searching database for degree program: " << degreeProgramArray[d] << "..." << endl;
    cout << endl;
    
    for (int i = 0; i <= lastIndex; i++) {
        if (this -> classRosterArray[i] -> getDegreeProgram() == d) {
            this -> classRosterArray[i] -> print();
        }
    }
};


// remove student
    /*
    void Roster::removeStudent(string studentId) {
        cout << "Searching database for student # " << studentId << "..." << endl;
        bool studentFound = false;
        for (int i = 0; i < rosterLimit - 2; i++) {
            if (studentId == this -> classRosterArray[i] -> getStudentId()) {
                studentFound = true;

                for (int j = 0; j < rosterLimit; j++) {
                    if (this -> classRosterArray[i] != this -> classRosterArray[j]) {
                        this -> classRosterArray[i] = this -> classRosterArray[j];
                    }
                }
            }
        }

        if (!studentFound) {
            cout << "Error: Student does not exist" << endl;
        };
        if (studentFound) {
            rosterLimit = rosterLimit - 1;
            cout << "Student Deleted" << endl;
        }
    };
    */


// fixed remove student function
void Roster::removeStudent(string studentId) {
    cout << "Searching database for student # " << studentId << "..." << endl;
    cout << endl;
    
    bool studentFound = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this -> classRosterArray[i] -> getStudentId() == studentId) {
            studentFound = true;
            delete this -> classRosterArray[i];
            this -> classRosterArray[i] = this -> classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    
    if (!studentFound) {
        cout << "Error! Student # " << studentId << " does not exist in roster..." << endl;
    }
    if (studentFound) {
        rosterLimit = rosterLimit - 1;
        cout << "Student # " << studentId << " deleted from roster..." << endl;
    }
}


// destructor
Roster::~Roster() {
    for (int i = 0; i < rosterLimit; i++)
        delete classRosterArray[i];
}
