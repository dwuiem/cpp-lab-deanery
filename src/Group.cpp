//
// Created by denis on 30.03.2024.
//

#include <string>
#include <vector>

#include "Group.h"
#include "Student.h"

void Group::addStudent(Student &studentRef) {
    students.push_back(&studentRef);
}

void Group::removeStudent(Student &studentRef) {
    studentRef.group = nullptr;
    if (this->head == &studentRef) {
        this->head = nullptr;
    }
    for (auto iter = students.begin(); iter != students.end(); ++iter) {
        if (*iter == &studentRef) {
            students.erase(iter);
            break;
        }
    }
}

void Group::chooseHead(Student &headRef) {
    this->head = &headRef;
}

double Group::getAverageMark() const {
    double markSummary = 0;
    double markAmount = 0;
    for (Student* student : students) {
        for (int mark : student->marks) {
            markSummary += mark;
            markAmount++;
        }
    }
    return markSummary / markAmount;
}

bool Group::isEmpty() const {
    return students.empty();
}

bool Group::containsStudent(int id) {
    return getStudent(id) == nullptr;
}

bool Group::containsStudent(std::string fio) {
    return getStudent(fio) == nullptr;
}

Group::Group() {
    title = "";
    spec = "";
}

Student *Group::getStudent(int id) {
    for (Student* student : students) {
        if (student->id == id) {
            return student;
        }
    }
    return nullptr;
}

Student *Group::getStudent(std::string fio) {
    for (Student* student : students) {
        if (student->fio == fio) {
            return student;
        }
    }
    return nullptr;
}
