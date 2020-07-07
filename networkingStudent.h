#include <string>
#include "student.h"

class NetworkingStudent : public Student {

public:
    NetworkingStudent();
    NetworkingStudent(
        string studentID, 
        string firstName, 
        string lastName, 
        string emailAddress, 
        int age, 
        int daysToComplete[]
    );
    Degree getDegreeProgram();
    string getDegreeProgramName();
    void print();

    ~NetworkingStudent();
};