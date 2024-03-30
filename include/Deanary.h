//
// Created by denis on 30.03.2024.
//

#ifndef DEANERY_DEANARY_H
#define DEANERY_DEANARY_H


class Group;
class Student;

class Deanary {
public:
    std::vector<Group*> groups;
    void createGroups();
    void hireStudents();
    void fireStudents();
    void addMarksToAll();
    void getStatistics();
    void moveStudents();
    void printInfo();
private:
    void saveData();
};


#endif //DEANERY_DEANARY_H
