//
// Created by denis on 30.03.2024.
//

#ifndef DEANERY_DEANARY_H
#define DEANERY_DEANARY_H


class Group;

class Student;

class Deanary {
private:
    std::vector<Group *> groups;

    void saveData();

    Group *getGroup(const std::string& title);

public:

    Deanary() = default;

    void hireStudents();

    void fireStudents();

    void addMarksToAll();

    void getStatistics();

    void moveStudents();

    void printInfo();
};


#endif //DEANERY_DEANARY_H
