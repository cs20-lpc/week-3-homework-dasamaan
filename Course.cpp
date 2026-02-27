// TODO:  Course class methods implementation here.
#include "Course.hpp"

Course::Course() : courseName(""), location("") {}

Course::Course(string name, string loc) : courseName(name), location(loc) {}

string Course::getCourseName() const { return courseName; }

string Course::getLocation() const { return location; }

void Course::display() const {
    cout << courseName << " " << location << endl;
}