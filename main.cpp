#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "Student.h"
#include "Professor.h"
#include "Course.h"

using namespace std;

int main() {
    ifstream studentsFile("StudentsWithCRNs.txt");
    ifstream coursesFile("CoursesFall2023Tab.txt");
    string line;

    
    map<string, Course> courses;

    // Read StudentsWithCRNs.txt with >> operator
    vector<Student> students;
    ifstream inputFile("StudentsWithCRNs.txt");

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string fullName;

            // Read student name
            if (getline(iss, fullName, '\t')) {
                Student student(fullName);

                // Read CRNs
                string crn;
                while (getline(iss, crn, '\t')) {
                    student.addCourse(crn);
                }

                students.push_back(student);
            }
        }
        inputFile.close();
    }

    // Read CoursesFall2023Tab.txt
    getline(coursesFile, line); // Skip the header line

    while (getline(coursesFile, line)) {
        istringstream iss(line);
        string subject, courseNumber, section, description, hours, crn, term, instructor, meetingTimes, time;

        getline(iss, subject, '\t');
        getline(iss, courseNumber, '\t');
        getline(iss, section, '\t');
        getline(iss, description, '\t');
        getline(iss, hours, '\t');
        getline(iss, crn, '\t');
        getline(iss, term, '\t');
        getline(iss, instructor, '\t');
        getline(iss, meetingTimes, '\t');
        getline(iss, time, '\t');

        Course course(subject, courseNumber, section, description, stoi(hours), crn, term, instructor, meetingTimes, time);
        courses[crn] = course;
    }

    // Overload << to write the Student object to studentOutput.txt
    ofstream outFile("studentOutput.txt");
    for (auto student : students) {
        outFile << "Name: " << student.getFirstName() << " " << student.getLastName() << endl;
        outFile << "ID: " << student.getUnivID() << endl;
        outFile << "Role: " << student.getRole()<< endl << "Courses: \n";
        for (auto crn : student.getCourses()) {
            outFile << courses[crn].getDescription() << "\n";
        }
        outFile << "\n\n";
    }
    outFile.close();

    Student student("\" Doe, John\"");
    student.addCourse("40115");
    student.addCourse("11234");
    student.addCourse("40121");
    student.addCourse("36380");
    student.addCourse("49837");


    // Appending new Student object to studentOutput.txt
    ofstream appendFile("studentOutput.txt", ios::app);
    if (appendFile.is_open()) {
        appendFile << "Name: " << student.getFirstName() << " " << student.getLastName() << endl;
        appendFile << "ID: " << student.getUnivID() << endl;
        appendFile << "Role: " << student.getRole()<< endl << "Courses: \n";
        for (auto crn : student.getCourses()) {
            appendFile << courses[crn].getDescription() << "\n";
        }
        appendFile << "\n\n";
        appendFile.close();
    }

    ofstream JohnDoeFile("CoursesForJohnDoe.txt");
    if (JohnDoeFile.is_open()) {
        JohnDoeFile << "Courses for " << student.getFirstName() << " " << student.getLastName() << ":\n";
        cout<< "Courses info for " << student.getFirstName() << " " << student.getLastName() << ":\n";
        for (auto crn : student.getCourses()) {
            JohnDoeFile << courses[crn].getDescription() << "\n";
            courses[crn].display();
        }
        JohnDoeFile << "\n\n";
        JohnDoeFile.close();
    }

    return 0;
}