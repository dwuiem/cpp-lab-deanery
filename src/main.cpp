#include <string>
#include <vector>
#include <utility>
#include <fstream>

#include "Deanary.h"
#include "Student.h"
#include "Group.h"

int main() {
    Deanary deanary;
    deanary.hireStudents();
    deanary.printInfo();
    return 0;
}
