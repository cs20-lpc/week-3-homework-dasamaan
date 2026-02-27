#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

int main()
{
  LinkedList students;
  int choice;

  do {
    cout << "\n1. Insert Student\n2. Delete Student\n3. Search Student\n4. Display All\n5. Count Students\n6. Add a course\n7. Exit\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
      int id; string name; double gpa;
      cout << "Enter ID: "; cin >> id;
      cin.ignore();
      cout << "Enter Name: "; getline(cin, name);
      cout << "Enter GPA: "; cin >> gpa;
      students.insertStudent(Student(id, name, gpa));
    }
    else if (choice == 2) {
      int id;
      cout << "Enter ID to delete: "; cin >> id;
      if (students.deleteStudent(id))
        cout << "Deleted student with ID " << id << endl;
      else
        cout << "Student not found.\n";
    }
    else if (choice == 3) {
      int id;
      cout << "Enter ID to search: "; cin >> id;
      Student* s = students.searchStudent(id);
      if (s) s->display();
      else cout << "Student not found.\n";
    }
    else if (choice == 4) students.displayAll();
    else if (choice == 5) cout << "Total students: " << students.count() << endl;
    else if (choice == 6) {
      int id; string cname, loc;
      cout << "Enter ID: "; cin >> id;
      Student* s = students.searchStudent(id);
      if (!s) { cout << "Student not found.\n"; continue; }
      cin.ignore();
      cout << "Enter Course Name: "; getline(cin, cname);
      cout << "Enter location: "; getline(cin, loc);
      s->addCourse(Course(cname, loc));
    }
  } while (choice != 7);

  return 0;
}
