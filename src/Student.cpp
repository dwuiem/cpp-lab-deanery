//
// Created by denis on 30.03.2024.
//

#include <string>
#include <vector>

#include "Student.h"
#include "Group.h"

void Student::addToGroup(Group &groupRef) {
    this->group = &groupRef;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() const {
    double markSummary = 0;
    for (int mark : marks) {
        markSummary += mark;
    }
    return markSummary / marks.size();
}

bool Student::isHeadOfGroup() const {
    return (group->getHead() == this);
}

Student::Student() {
    id = -1;
    fio = "";
}

int Student::getId() const {
    return id;
}

std::string Student::getFio() const {
    return fio;
}

const Group *Student::getGroup() const {
    return group;
}

std::vector<int> Student::getMarks() const {
    return marks;
}
