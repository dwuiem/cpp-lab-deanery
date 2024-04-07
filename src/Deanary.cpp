//
// Created by denis on 30.03.2024.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <ctime>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

void Deanary::hireStudents(const std::string &path) {
    std::string line;
    std::ifstream file(path);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::vector<std::string> data;
            std::string token;
            while (iss >> token) {
                data.push_back(token);
            }
            int id = std::stoi(data[0]);
            std::string fio = data[1] + " " + data[2] + " " + data[3];
            Group *group = getGroup(data[4]);
            if (group == nullptr) {
                group = new Group(data[4], data[5]);
                groups.push_back(group);
            }
            Student *student = new Student(id, fio);
            group->addStudent(student);
            for (int i = 6; i < data.size(); i++) {
                student->addMark(std::stoi(data[i]));
            }
        }
        file.close();
    }
}

void Deanary::fireStudents() {
    for (Group *group : groups) {
        for (const Student *student : group->getStudents()) {
            if (student->getAverageMark() < 3.5) {
                group->removeStudent(const_cast<Student *>(student));
            }
        }
    }
    saveData();
}

void Deanary::addMarksToAll() {
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist(1, 10);
    for (auto group : groups) {
        for (auto student : group->getStudents()) {
            int newMark = dist(rng);
            const_cast<Student *>(student)->addMark(newMark);
        }
    }
    saveData();
}

void Deanary::moveStudents(const std::string &oldGroup, const std::string &newGroup) {
    Group *g1 = getGroup(oldGroup);
    Group *g2 = getGroup(newGroup);
    if (g1 == nullptr || g2 == nullptr) return;
    for (auto student : g1->getStudents()) {
        g2->addStudent(const_cast<Student *>(student));
        g1->removeStudent(const_cast<Student *>(student));
    }
    saveData();
}

/* This method print info about all students in all group in form:
 * Group - ... (spec: ...) - HEAD: ...
 * AVG mark of group: ...
 * ID: ...
 * -> Name: ...
 * -> Marks: ...
 * -> AVG Mark: ...
 */

void Deanary::printInfo() {
    using std::cout, std::cin, std::endl;
    cout << "---------------------- DEANERY INFO ----------------------" << endl;
    for (auto group : groups) {
        if (!group->isEmpty()) {
            cout << "Group - " << group->getTitle() << " (spec: " << group->getSpec() << ") - HEAD: "
                 << (group->getHead() == nullptr ? "NONE" : group->getHead()->getFio()) << endl;
            cout << "AVG mark of group: " << group->getAverageMark() << endl;
            for (auto student : group->getStudents()) {
                cout << "ID: " << student->getId() << endl;
                cout << "-> Name: " << student->getFio() << endl;
                cout << "-> Marks: ";
                for (int mark : student->getMarks()) {
                    cout << mark << " ";
                }
                cout << endl;
                cout << "-> AVG Mark: " << student->getAverageMark() << endl;
            }
        }
    }
}

void Deanary::saveData(const std::string &path) {
    std::ofstream file;
    file.open(path);
    if (file.is_open()) {
        for (auto group : groups) {
            for (auto student : group->getStudents()) {
                file << student->getId() << " " << student->getFio() << " " << group->getTitle() << " " << group->getSpec() << " ";
                for (int mark : student->getMarks()) {
                    file << mark << " ";
                }
                file << std::endl;
            }
        }
        file.close();
    }
}

Group *Deanary::getGroup(const std::string &title) {
    for (Group *g : groups) {
        if (g->getTitle() == title) {
            return g;
        }
    }
    return nullptr;
}

std::vector<Group *> Deanary::getGroups() const {
    return groups;
}
