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

    bool isHeadOfGroup() const;

    double getAverageMark() const;

    int getId() const;

    std::string getFio() const;

    const Group* getGroup() const;

    std::vector<int> getMarks() const;

private:
    std::string fio;
    int id;
    const Group *group = nullptr;
    std::vector<int> marks;
};


#endif //DEANERY_STUDENT_H
