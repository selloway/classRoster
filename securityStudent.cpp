#include <iostream>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent(
    string studentID, 
    string firstName, 
    string lastName, 
    string emailAddress, 
    int age, 
    int daysToComplete[]
):Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, SECURITY) {
}

Degree SecurityStudent::getDegreeProgram() {
    return degreeType;
}

void SecurityStudent::print() {
    this->Student::print();
    cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent() {
    Student::~Student();
}