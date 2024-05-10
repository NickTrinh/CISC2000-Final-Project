//Nick Trinh
#ifndef STUDENT_H
#define STUDENT_H

#include "UnivMember.h"
#include <vector>
#include <string>

using namespace std;

class Student : public UnivMember {
private:
    vector<string> courses;

public:
    Student();
    Student(string fullName);
    ~Student();

    void addCourse(string course);
    void removeCourse(string course);
    void displayCourses() const;
    vector<string> getCourses() const;

    // File I/O methods
    void writeToFile(string filename) const;
    static vector<Student> readFromFile(string filename);

    // Overloaded operator
    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);

    // Inherited methods from UnivMember
    using UnivMember::getFirstName;
    using UnivMember::getLastName;
    using UnivMember::getUnivID;
    using UnivMember::getRole;
};

#endif