//
// Created by denis on 30.03.2024.
//

#include <string>
#include <vector>

#include "Group.h"
#include "Student.h"

void Group::addStudent(Student *studentRef) {
    students.push_back(studentRef);
    studentRef->addToGroup(*this);
}

void Group::removeStudent(Student *studentRef) {
    if (studentRef->isHeadOfGroup()) {
        head = nullptr;
    }
    for (auto iter = students.begin(); iter != students.end(); iter++) {
        if (*iter == studentRef) {
            students.erase(iter);
            break;
        }
    }
}

void Group::chooseHead(const Student &headRef) {
    this->head = &headRef;
}

double Group::getAverageMark() const {
    double markSummary = 0;
    double markAmount = 0;
    for (const Student *student : students) {
        for (int mark : student->getMarks()) {
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
    return getStudent(id) != nullptr;
}

bool Group::containsStudent(std::string fio) {
    return getStudent(fio) != nullptr;
}

Group::Group() {
    title = "";
    spec = "";
    head = nullptr;
}

const Student *Group::getStudent(int id) {
    for (const Student *student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

const Student *Group::getStudent(std::string fio) {
    for (const Student *student : students) {
        if (student->getFio() == fio) {
            return student;
        }
    }
    return nullptr;
}

std::string Group::getTitle() const {
    return title;
}

std::string Group::getSpec() const {
    return spec;
}

std::vector<const Student *> Group::getStudents() const {
    return students;
}

const Student *Group::getHead() const {
    return head;
}
