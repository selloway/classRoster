#include <string>
#include <cstring>
#include <iostream>
#include "roster.h"

#define COURSE_TITLE "Scripting and Programming Applications - C867"
#define LANG "C++"
#define STUDENT_ID "000946474"
#define NAME "Sara Elloway"

Roster::Roster() {
    this->rosterSize = 0;
    this->studentCount = 0;
    this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) {
    this->rosterSize = rosterSize;
    this->studentCount = 0;
    this->classRosterArray = new Student*[rosterSize];
}

Student* Roster::getStudentAt(int index) {
    return classRosterArray[index];
}

void Roster::parseAdd(string row) {
    int n = row.length();
    Degree degreeType;
    if (row[n-1] == 'Y') {
        degreeType = SECURITY;
    }
    else if (row[n-1] == 'G') {
        degreeType = NETWORKING;
    }
    else if (row[n-1] == 'E') {
        degreeType = SOFTWARE;
    }
    else {
        cout << "Error: degree type not recognized" << endl;
        return;
    }
    int right = row.find(",");
    string studentID = row.substr(0, right);

    int left = right + 2;
    right = row.find(",", left);
    string firstName = row.substr(left, right - left);

    left = right + 2;
    right = row.find(",", left);
    string lastName = row.substr(left, right - left);

    left = right + 2;
    right = row.find(",", left);
    string emailAddress = row.substr(left, right - left);

    left = right + 2;
    right = row.find(",", left);
    int age = stoi(row.substr(left, right - left));

    left = right + 2;
    right = row.find(",", left);
    int daysInCourse1 = stoi(row.substr(left, right - left));

    left = right + 2;
    right = row.find(",", left);
    int daysInCourse2 = stoi(row.substr(left, right - left));

    left = right + 2;
    right = row.find(",", left);
    int daysInCourse3 = stoi(row.substr(left, right - left));

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeType);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
    int courseDays[Student::daysArraySize];
    courseDays[0] = daysInCourse1;
    courseDays[1] = daysInCourse2;
    courseDays[2] = daysInCourse3; 
    if (degreeType == SECURITY) {
        classRosterArray[studentCount] = new SecurityStudent (studentID, firstName, lastName, emailAddress, age, courseDays);
        studentCount++;
    }
    else if (degreeType == NETWORKING) {
        classRosterArray[studentCount] = new NetworkingStudent (studentID, firstName, lastName, emailAddress, age, courseDays);
        studentCount++;
    }
    else if (degreeType == SOFTWARE) {
        classRosterArray[studentCount] = new SoftwareStudent (studentID, firstName, lastName, emailAddress, age, courseDays);
        studentCount++;
    }
    else {
        cout << "Error: invalid entry - '" << degreeType << "'" << endl; 
    }
}

void Roster::printAll() {
    for (int i = 0; i < this->studentCount; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[studentCount - 1];
            studentCount--;
        }
    }
    return found;
}

void Roster::averageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i < this->studentCount; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            int* d = classRosterArray[i]->getDaysToComplete();
            cout << "Average days in a course for student " << studentID << " is: " << (d[0] + d[1] + d[2]) / 3 << endl;
        }
    }
    if (!found) {
        cout << "Student not found" << endl;
    }
}


//valid defined as including an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
    cout << "Displaying invalid emails: " << endl;
    bool any = false;
    for (int i = 0; i < this->studentCount; i++) {
        any = false;
        string e = classRosterArray[i]->getEmailAddress();
        if (e.rfind ("@") == string::npos) {
            cout << e << endl;
        }
        else if (e.rfind (".") == string::npos) {
            cout << e << endl;
        } 
        else if (e.rfind (" ") != string::npos) {
            cout << e << endl;
        }
    }
}

void Roster::printByDegreeProgram(Degree degreeType) {
    for (int i = 0; i < this->studentCount; i++) {
        Degree degreeProg = this->classRosterArray[i]->getDegreeProgram();
        if (degreeProg == degreeType) {
            this->classRosterArray[i]->print();
        }
    }
}
 
Roster::~Roster() {
    cout << "deleting" << endl;
    for (int i = 0; i < this->studentCount; i++) {
        delete this->classRosterArray[i];
    }
    delete this->classRosterArray;
}

void printIntro(){
    cout << "Course: " << COURSE_TITLE << endl;
    cout << "Programming Language: " << LANG << endl;
    cout << "Student ID: " << STUDENT_ID << endl;
    cout << "Name: " << NAME << endl;
}

int main() {
    printIntro();

    int numStudents = 5; 
    const string studentData[5] =
    {
        "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
        "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORKING",
        "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
        "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
        "A5, Sara, Elloway, selloway@gmail.com, 26, 57, 1, 54, SOFTWARE" 
    };

    Roster* classRoster = new Roster(numStudents);
    for (int i = 0; i < numStudents; i++) {
        classRoster->parseAdd(studentData[i]);
    }
    cout << "Displaying all students: " << endl;
    classRoster->printAll();

    classRoster->printInvalidEmails();

    cout << "Displaying average days to complete course: " << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->averageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
    }

    cout << "Displaying students in Software degree program: " << endl;
    classRoster->printByDegreeProgram(SOFTWARE);


    cout << "Removing student A3..." << endl;
    if (classRoster->remove("A3")) {
        classRoster->printAll();
        numStudents--;
    }
    else {
        cout << "Error: Student ID not found" << endl;
    }

    cout << "Removing student A3..." << endl;
    if (classRoster->remove("A3")) {
        classRoster->printAll();
        numStudents--;
    }
    else {
        cout << "Error: Student ID not found" << endl;
    }

    //FIXME: Illegal instruction: 4 
    delete classRoster;    
return 0;
}




