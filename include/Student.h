//
// Created by denis on 30.03.2024.
//

#ifndef DEANERY_STUDENT_H
#define DEANERY_STUDENT_H

class Deanary;
class Group;

class Student {
public:
    int id;
    std::string fio;
    std::vector<int> marks;
    Group* group;
    Student();
    Student(int id, std::string fio) : id(id), fio(std::move(fio)) {};
    Student(const Student &studentRef) = default;
    Student(Student &&studentRef) = default;
    void addToGroup(Group &groupRef);
    void addMark(int mark);
    double getAverageMark();
    bool isHeadOfGroup();
};


#endif //DEANERY_STUDENT_H
