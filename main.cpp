//
// JYM1 - main.cpp
// Scripting and Programming Applications - C867
// Alexander J. Pfleging
// Student ID# xxx
//

#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"
#include "roster.h"

using namespace std;

//

// create line break
void lineBreak() {
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << endl;
};


// create load break
void loadBreak() {
    cout << "~~~~~~~~" << endl;
}


// create contine/quit function
void waitForCommand() {
    string x;
    cout << "Type 'c' to continue" << endl;
    cout << "Type 'q' to quit" << endl;
    
    while(x != "c" && x != "q") {
        cin >> x;
        
        if (x == "c" | x == "q") {
            break;
        }
        else {
        cout << "Invalid command..." << endl;
        }
    }
    
    if (x == "q") {
        exit(-1);
    }
    else if (x == "c") {
        return;
    }
};



int main() {
    
    // Print out student details
    cout << "Scripting and Programming Applications - C867" << endl;
    cout << "C++" << endl;
    cout << "Student ID# 000821291" << endl;
    cout << "Alexander J Pfleging" << endl;

    lineBreak();
    
    cout << "Welcome to Class Roster Manager 1984!" << endl;
    
    lineBreak();
    waitForCommand();
    lineBreak();
    
    // parse student data
    cout << "Parsing student data..." << endl;
    loadBreak();
    
    Roster* classRoster = new Roster(currRosterSize);
    
    for (int i = 0; i < classRoster -> rosterLimit; i++) {
        classRoster -> studentParser(studentData[i]);
        cout << "Student " << i + 1 << " parsed successfully" << endl;
    };
    
    loadBreak();
    cout << "Parsing complete... Roster created..." << endl;

    lineBreak();

    
    // print all student info
    cout << "Printing student roster..." << endl;
    loadBreak();
    
    classRoster -> printAll();
    
    lineBreak();
    
    
    // print invalid emails
    cout << "Printing invalid emails..." << endl;
    loadBreak();
    
    classRoster -> printInvalidEmails();
    
    lineBreak();
    
    
    // print average days for each student
    cout << "Printing average days in class for each student..." << endl;
    loadBreak();
    
    for (int i = 0; i < classRoster -> rosterLimit; i++) {
        classRoster -> printAverageDays(classRoster -> classRosterArray[i] -> getStudentId());
    };
    
    lineBreak();

    
    // print by degree program
    cout << "Printing roster by degree program..." << endl;
    loadBreak();
    
    classRoster -> printByDegree(SOFTWARE);
    
    lineBreak();
    
    
    // print by student - A2
    cout << "Printing student record..." << endl;
    loadBreak();
    
    classRoster -> printStudent("A2");
    
    lineBreak();
    
    
    // remove student - A3
    cout << "Removing student record..." << endl;
    loadBreak();
    
    classRoster -> removeStudent("A3");
    
    lineBreak();
    
    
    // print remaining students
    cout << "Printing remaining student roster..." << endl;
    loadBreak();
    
    classRoster -> printAll();
    
    lineBreak();
    
    
    // remove student - A3 again // expect to see error message
    cout << "Removing student record..." << endl;
    loadBreak();
    
    classRoster -> removeStudent("A3");
    
    lineBreak();
    
    
    // release memory and exit
    cout << "Exiting program..." << endl;
    loadBreak();
    
    classRoster -> ~Roster();
    
    cout << "Thank you for using Class Roster Manager 1984!" << endl;
    cout << "Goodbye..." << endl;

    
    return 0;
};
