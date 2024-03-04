#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <stdexcept>
using namespace std;

#include "IntList.h"

IntList::IntList() : head(nullptr), tail(nullptr) {

}

IntList::~IntList() {
    clear();
}

IntList::IntList(const IntList &cpy) : head(nullptr), tail(nullptr) {
    IntNode *current = cpy.head;

    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}

IntList &IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();

        IntNode *current = rhs.head;

        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }

    return *this;
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
}

void IntList::push_front(int value) {
    IntNode *newVal = new IntNode(value);

    if (empty()) {
        head = tail = newVal;
    } else {
        newVal->next = head;
        head = newVal;
    }
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }

        delete temp;
    }
}

bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

const int &IntList::front() const {
    return head->value;
}

const int &IntList::back() const {
    return tail->value;
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);

    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::selection_sort() {
    vector<int> selection;

    IntNode *val = head;

    while(val != nullptr) {
        selection.push_back(val->value);
        val = val->next;
    }

    sort(selection.begin(), selection.end());
    val = head;

    int index = 0;

    while (val != nullptr) {
        val->value = selection[index];
        val = val->next;
        ++index;
    }
   
}

void IntList::insert_ordered(int value) {

    IntNode *newNode = new IntNode(value);

    if (empty() || value <= head->value) {
        newNode->next = head;
        head = newNode;

        if (empty()) {
            tail = newNode;
        }
        return;
    }

    IntNode *val = head;
    while ((val->next != nullptr) && (val->next->value < value)) {
        val = val->next;
    }

    newNode->next = val->next;
    val->next = newNode;

    if (newNode->next == nullptr) {
        tail = newNode;
    }
    
}

void IntList::remove_duplicates() {
    if (empty()) {
        return;
    }

    IntNode *val = head;

    while (val != nullptr) {
        IntNode *temp = val;

        while (temp->next != nullptr) {
            if (val->value == temp->next->value) {
                IntNode *duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;

                if (temp->next == nullptr) {
                    tail = temp;
                }
            }
            else {
                temp = temp->next;
            }
        }
        val = val->next;
    }
}



ostream &operator<<(ostream &out, const IntList &rhs) {
    IntNode *currentVal = rhs.head;

    while (currentVal != nullptr) {
        out << currentVal->value;

        if (currentVal->next != nullptr) {
            out << " ";
        }

        currentVal = currentVal->next;
    }

    return out;
}

if (rhs.head == 0) {
            return out;
        }
        operator<<(out, rhs.head);
        return out;
