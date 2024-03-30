//
// Created by denis on 30.03.2024.
//

#ifndef DEANERY_GROUP_H
#define DEANERY_GROUP_H


class Deanary;
class Student;

class Group {
public:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;
    Group();
    Group(std::string title, std::string spec) : title(std::move(title)), spec(std::move(spec)) {};
    Group(const Group &groupRef) = default;
    Group(Group &&groupRef) = default;
    void addStudent(Student &studentRef);
    void removeStudent(Student &studentRef);
    void chooseHead(Student &headRef);
    double getAverageMark() const;
    bool isEmpty() const;
    bool containsStudent(int id);
    bool containsStudent(std::string fio);
    Student* getStudent(int id);
    Student* getStudent(std::string fio);
};


#endif //DEANERY_GROUP_H
