// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>
using namespace std;

class Course {
private:
    string courseName;
    string location;

public:
    Course();  // default constructor
    Course(string name, string loc);  // parameterized constructor

    string getCourseName() const;
    string getLocation() const;

    void display() const;
};

#endif