// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Course.hpp"
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;
    vector<Course> courses;

public:
    Student();  // default
    Student(int _id, string _name, double _gpa);

    int getId() const;
    string getName() const;
    double getGpa() const;

    void addCourse(const Course& c);
    void display() const;
};

#endif