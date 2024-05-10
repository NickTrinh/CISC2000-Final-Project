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

    // Overload << to write the Student object +1
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
    student.addCourse("Computer Science II");
    student.addCourse("Data Structures");

    cout << student << endl;

    // Writing the Student object to a file
    ofstream outputFile("studentPrintOverloadTest.txt");
    if (outputFile.is_open()) {
        outputFile << student << endl;
        outputFile.close();
    }


    return 0;
}