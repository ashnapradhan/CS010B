#include "SortedSet.h"

SortedSet::SortedSet() : IntList() {
}

SortedSet::SortedSet(const SortedSet& other) : IntList(other) {
}

SortedSet::SortedSet(const IntList& other) : IntList(other) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {
}

bool SortedSet::in(int value) const {
    if (head == nullptr) {
        return false;
    }
    IntNode *val2 = head;

    while(val2 != nullptr) {
        if (val2->value == value) {
            return true;
        }
        val2 = val2->next;
    }
  
   return false;
}

void SortedSet::add(int value) {
    IntList::selection_sort();
    IntList::insert_ordered(value);
    IntList::remove_duplicates();
}

void SortedSet::push_front(int value) {
   IntList::push_front(value);
   IntList::selection_sort();
}

void SortedSet::push_back(int value) {
    IntList::push_back(value);
    IntList::selection_sort();
}

void SortedSet::insert_ordered(int value) {
    IntList::insert_ordered(value);
    IntList::selection_sort();
    IntList::remove_duplicates();
}

SortedSet SortedSet::operator|(const SortedSet& set) const{
    SortedSet result;

    IntNode* current = head;
    while (current != nullptr) {
        result.add(current->value);
        current = current->next;
    }

    current = set.head;
    while (current != nullptr) {
        result.add(current->value);
        current = current->next;
    }

    return result;
}

SortedSet SortedSet::operator&(const SortedSet& set) const {
    SortedSet result;
    IntNode* current = head;

    while(current != nullptr) {
        if (set.in(current->value)) {
            result.IntList::push_back(current->value);
        }
        current = current->next;
    }
    return result;
}

SortedSet SortedSet::operator|=(const SortedSet& set) {
    if (this == &set) {
        return *this;
    }

    IntNode* current = set.head;

    while (current != nullptr) {
        this->add(current->value);
        current = current->next;
    }

    return *this;
}

SortedSet SortedSet::operator&=(const SortedSet& set) {
    if (this == &set) {
        return *this;
    }

    SortedSet result(*this);
    clear();
    IntNode* current = result.head;

    while (current) {
        if (set.in(current->value)) {
            IntList::push_back(current->value);
        }
        current = current->next;
    }

    return *this;
}



