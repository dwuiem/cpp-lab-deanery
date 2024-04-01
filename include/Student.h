//
// Created by denis on 30.03.2024.
//

#ifndef DEANERY_STUDENT_H
#define DEANERY_STUDENT_H

class Deanary;

class Group;

class Student {
public:
    Student();

    Student(int id, std::string fio) : id(id), fio(std::move(fio)) {};

    Student(const Student &studentRef) = default;

    Student(Student &&studentRef) = default;

    ~Student() = default;

    void addToGroup(Group &groupRef);

    void addMark(int mark);

    double getAverageMark();

    bool isHeadOfGroup();

    std::string fio;
    int id;
    Group *group = nullptr;
    std::vector<int> marks;
};


#endif //DEANERY_STUDENT_H
