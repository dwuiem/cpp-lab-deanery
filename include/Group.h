//
// Created by denis on 30.03.2024.
//

#ifndef DEANERY_GROUP_H
#define DEANERY_GROUP_H


class Deanary;

class Student;

class Group {
public:
    Group();

    Group(std::string title, std::string spec) : title(std::move(title)), spec(std::move(spec)) {};

    Group(const Group &groupRef) = default;

    Group(Group &&groupRef) = default;

    ~Group() = default;

    Group &operator=(const Group &other) = default;

    void addStudent(Student *studentRef);

    void removeStudent(Student *studentRef);

    void chooseHead(const Student &headRef);

    double getAverageMark() const;

    bool isEmpty() const;

    bool containsStudent(int id);

    bool containsStudent(std::string fio);

    const Student *getStudent(int id);

    const Student *getStudent(std::string fio);

    std::string getTitle() const;

    std::string getSpec() const;

    std::vector<const Student *> getStudents() const;

    const Student* getHead() const;

private:
    std::string title;
    std::string spec;
    std::vector<const Student *> students;
    const Student *head = nullptr;
};


#endif //DEANERY_GROUP_H
