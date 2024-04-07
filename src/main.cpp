#include <string>
#include <vector>
#include <utility>

#include "Deanary.h"
#include "Student.h"
#include "Group.h"

using namespace std;

int main() {
    Deanary deanary;

    // Parse students from students-data-set.txt
    deanary.hireStudents("..\\bd\\students-data-set.txt");
    // Get group by name
    Group *group = deanary.getGroup("23CST-5");

    // Find student with ID = 1 and change his info
    const Student *student = group->getStudent(1);

    // Make him a head of group
    group->chooseHead(*student);

    deanary.printInfo();

    // Move all students from 23cst-4 to 23cst-5
    deanary.moveStudents("23CST-4", "23CST-5");

    // Adding marks
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();

    deanary.printInfo();

    deanary.fireStudents();

    deanary.printInfo();
    return 0;
}
