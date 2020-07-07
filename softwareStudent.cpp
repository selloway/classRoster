#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent(
    string studentID, 
    string firstName, 
    string lastName, 
    string emailAddress, 
    int age, 
    int daysToComplete[]
):Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, SOFTWARE) {
}

Degree SoftwareStudent::getDegreeProgram() {
    return degreeType;
}

void SoftwareStudent::print() {
    this->Student::print();
    cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent() {
    Student::~Student();
}