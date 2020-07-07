#include <string>
#include <iostream>
#include "student.h"
#include "networkingStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster {
    private:
    int studentCount;
    int rosterSize;
    Student** classRosterArray;

    public:
    Roster();
    Roster(int rosterSize); 

    Student* getStudentAt(int );
    void parseAdd(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
    void printAll();
    bool remove(string studentID);
    void averageDaysInCourse (string StudentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degreeType);

    ~Roster();
};