// TODO:  Student class methods implementation here.
#include "Student.hpp"

Student::Student() : id(0), name(""), gpa(0.0) {}

Student::Student(int _id, string _name, double _gpa) : id(_id), name(_name), gpa(_gpa) {}

int Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::addCourse(const Course& c) {
    courses.push_back(c);
}

void Student::display() const {
    cout << id << " " << name << " " << gpa;
    if (courses.empty()) {
        cout << " None" << endl;
    } else {
        cout << endl;
        for (const auto& course : courses) {
            cout << "  ";
            course.display();
        }
    }
}