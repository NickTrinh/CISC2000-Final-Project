#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Student::Student() : UnivMember(){}

Student::Student(string fullName) : UnivMember(){
    setUnivName(fullName);
    setRole("Student");
}

Student::~Student() {}

void Student::addCourse(string course) {
    courses.push_back(course);
}

void Student::removeCourse(string course) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (*it == course) {
            courses.erase(it);
            break;
        }
    }
}

void Student::displayCourses() const {
    cout << "Courses: ";
    for (auto course : courses) {
        cout << course << " ";
    }
    cout << endl;
}

vector<string> Student::getCourses() const {
    return courses;
}

void Student::writeToFile(string filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << getFirstName() << ", " << getLastName() << ", " << getUnivID() << ", " << getRole();
        for (const auto& course : courses) {
            file << ", " << course;
        }
        file << endl;
        file.close();
    }
}

vector<Student> Student::readFromFile(string filename) {
    vector<Student> students;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string firstName, lastName, univID, role;
            getline(iss, firstName, ',');
            iss >> ws;
            getline(iss, lastName, ',');
            iss >> ws;
            getline(iss, univID, ',');
            iss >> ws;
            getline(iss, role, ',');

            Student student(firstName + " " + lastName);
            student.setUnivID(univID);

            string course;
            while (getline(iss, course, ',')) {
                student.addCourse(course);
            }

            students.push_back(student);
        }
        file.close();
    }
    return students;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Name: " << student.getFirstName() << " " << student.getLastName() << endl;
    os << "ID: " << student.getUnivID() << endl;
    os << "Role: " << student.getRole() << endl;
    os << "Courses: ";

    const vector<string>& courses = student.getCourses();
    for (size_t i = 0; i < courses.size(); ++i) {
        os << courses[i];
        if (i < courses.size() - 1) {
            os << ", ";
        }
    }
    os << endl;

    return os;
}

istream& operator>>(istream& is, Student& student) {
    string line;
    if (getline(is, line)) {
        istringstream iss(line);
        string firstName, lastName, univID, role;

        // Read name
        if (getline(iss, firstName, ' ') && getline(iss, lastName)) {
            student.setUnivName(firstName + " " + lastName);
        }

        // Read ID
        if (getline(iss, univID)) {
            student.setUnivID(univID);
        }

        // Read role
        if (getline(iss, role)) {
            student.setRole(role);
        }

        // Read courses
        string course;
        while (getline(iss, course, ',')) {
            // Remove leading whitespace from the course
            course.erase(0, course.find_first_not_of(" "));
            student.addCourse(course);
        }
    }

    return is;
}