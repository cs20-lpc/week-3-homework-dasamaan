#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Student.hpp"
#include <iostream>
using namespace std;

struct Node {
    Student data;
    Node* next;
    Node(const Student& s) : data(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void insertStudent(const Student& s) {
        Node* newNode = new Node(s);
        if (!head) head = newNode;
        else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = newNode;
        }
    }

    bool deleteStudent(int id) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->data.getId() == id) {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    Student* searchStudent(int id) {
        Node* curr = head;
        while (curr) {
            if (curr->data.getId() == id) return &(curr->data);
            curr = curr->next;
        }
        return nullptr;
    }

    void displayAll() const {
        Node* curr = head;
        if (!curr) {
            cout << "No students in list." << endl;
            return;
        }
        while (curr) {
            curr->data.display();
            curr = curr->next;
        }
    }

    int count() const {
        int cnt = 0;
        Node* curr = head;
        while (curr) { cnt++; curr = curr->next; }
        return cnt;
    }
};

#endif