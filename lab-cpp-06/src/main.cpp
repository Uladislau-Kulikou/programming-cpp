#include "discipline.hpp"

int main() {
    std::vector<Discipline*> profile_disciplines = parseDisciplines("assets/profile_disciplines.json");
    std::vector<Discipline*> non_profile_disciplines = parseDisciplines("assets/non_profile_disciplines.json");
    std::vector<Discipline*> all_disciplines = mergeDisciplines(profile_disciplines, non_profile_disciplines);

    sortDisciplines(all_disciplines, "hours");
    printDisciplines(all_disciplines);

    std::vector<Discipline*> shortDisciplines = findDisciplines(all_disciplines, "hours", "1");
    std::cout << "\033[32m" << "\nКороткі предмети:"<< "\033[0m" << std::endl;
    printDisciplines(shortDisciplines);

    deleteVector(all_disciplines);

    return 0;
}
