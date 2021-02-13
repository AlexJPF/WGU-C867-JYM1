//
// JYM1 - roster.h
// Scripting and Programming Applications - C867
// Alexander J. Pfleging
// Student ID# xxx
//

#pragma once
#include <string>
#include "degree.h"
#include "student.h"
#include <vector>

using namespace std;
using std::string;

//

const int currRosterSize = 5;

static string studentData[currRosterSize] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Alexander,Pfleging,apflegi@wgu.edu,31,11,3,2,SOFTWARE"
};



class Roster {
    
public:
    
    int rosterLimit;
    int lastIndex;

    Student** classRosterArray;
    void studentParser(string row);
    void getRoster();

    void addToRoster(string sid, string first, string last, string em, int age,
        double d1, double d2, double d3, DegreeProgram d);

    void removeStudent(string studentId);

    void printAll();
    
    void printStudent(string studentId);

    void printAverageDays(string studentId);

    void printInvalidEmails();

    void printByDegree(DegreeProgram d);

    // constructors
    Roster();
    Roster(int rLimit);
    ~Roster();
    
};
