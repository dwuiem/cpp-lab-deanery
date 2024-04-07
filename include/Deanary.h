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

    void saveData(const std::string &path = "..\\bd\\students-data-set.txt");

public:

    Group *getGroup(const std::string &title);

    Deanary() = default;

    void hireStudents(const std::string &path);

    void fireStudents();

    void addMarksToAll();

    void printInfo();

    void moveStudents(const std::string &oldGroup, const std::string &newGroup);

    std::vector<Group *> getGroups() const;
};


#endif //DEANERY_DEANARY_H
