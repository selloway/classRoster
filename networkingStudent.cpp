#include <iostream>
#include "networkingStudent.h"
using namespace std;

NetworkingStudent::NetworkingStudent(
    string studentID, 
    string firstName, 
    string lastName, 
    string emailAddress, 
    int age, 
    int daysToComplete[] 
):Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, NETWORKING) {
}

Degree NetworkingStudent::getDegreeProgram() {
    return degreeType;
}

void NetworkingStudent::print() {
    this->Student::print();
    cout << "NETWORKING" << "\n";
}

NetworkingStudent::~NetworkingStudent() {
    Student::~Student();
}