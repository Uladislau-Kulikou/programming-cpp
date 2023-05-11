#include "discipline.h"

int main() {
    std::vector<Discipline*> disciplines;
    parseDisciplines(disciplines, "assets/input.txt");
    sortDisciplines(disciplines, "hours");
    printDisciplines(disciplines);
    deleteVector(disciplines);
    return 0;
}
