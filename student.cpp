#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "student.h"

Student::Student() {
    studentID = " ";
    firstName = " ";
    lastName = " ";
    emailAddress = " ";
    age = 0;
    
    return;
}

Student::Student(
    string studentID, 
    string firstName, 
    string lastName, 
    string emailAddress, 
    int age, 
    int daysToComplete[],
    Degree degreeType
) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysArraySize; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeType = degreeType;
}

Degree Student::getDegreeProgram() {
    return degreeType;
}

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int * Student::getDaysToComplete() {
    return daysToComplete;
}

void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
} 

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToComplete(int daysToComplete[]) {
    for (int i = 0; i < daysArraySize; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

void Student::print() {
    cout << "\tFirst Name: " << this->getFirstName();
    cout << "\tLast Name: " << this->getLastName();
    cout << "\tAge: " << this->getAge();
    int* dtc = this->getDaysToComplete();
    cout << "\tDays in Course: {" << dtc[0] << ", " << dtc[1] << ", " << dtc[2] << "} ";
    cout << "Degree Program: " << endl;
    return;
}

Student::~Student() {
    
}
