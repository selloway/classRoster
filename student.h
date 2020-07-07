#ifndef __STUDENT_H__
#include <string>
#include "degree.h"
using namespace std;

class Student {
    public:
    const static int daysArraySize = 3;
    
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[daysArraySize];

    Degree degreeType;

    Student();
    Student(string studentID, 
            string firstName, 
            string lastName, 
            string emailAddress, 
            int age, 
            int daysToComplete[],
            Degree degreeType
            );
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToComplete();
    virtual Degree getDegreeProgram() = 0;

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete[]);
  
    virtual void print() = 0;

    virtual ~Student();

};

#define __STUDENT_H__
#endif