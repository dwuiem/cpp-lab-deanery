//
// Created by denis on 30.03.2024.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

void Deanary::hireStudents() {
    std::string line;
    std::ifstream file("..\\bd\\students-data-set.txt");
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
            student->addToGroup(*group);
            for (int i = 6; i < data.size(); i++) {
                student->addMark(std::stoi(data[i]));
            }
        }
        file.close();
    }
}

void Deanary::fireStudents() {

}

void Deanary::addMarksToAll() {

}

void Deanary::getStatistics() {

}

void Deanary::moveStudents() {

}

void Deanary::printInfo() {
    using std::cout, std::cin, std::endl;
    for (auto group: groups) {
        cout << "Group - " << group->title << "(spec: " << group->spec << "):" << endl;
        for (auto student: group->students) {
            cout << "ID: " << student->id << endl;
            cout << "-> Name: " << student->fio << endl;
            cout << "-> Marks: ";
            for (int mark : student->marks) {
                cout << mark << " ";
            }
            cout << endl;
        }
    }
}

void Deanary::saveData() {

}

Group *Deanary::getGroup(const std::string &title) {
    for (Group *g: groups) {
        if (g->title == title) {
            return g;
        }
    }
    return nullptr;
}
