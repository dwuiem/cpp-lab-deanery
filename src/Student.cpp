//
// Created by denis on 30.03.2024.
//

#include <string>
#include <vector>

#include "Student.h"
#include "Group.h"

void Student::addToGroup(Group &groupRef) {
    groupRef.addStudent(*this);
    this->group = &groupRef;
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}

double Student::getAverageMark() {
    double markSummary = 0;
    for (int mark : marks) {
        markSummary += mark;
    }
    return markSummary / marks.size();
}

bool Student::isHeadOfGroup() {
    return (this->group->head == this);
}

Student::Student() {
    id = -1;
    fio = "";
}
