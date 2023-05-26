#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "discipline.hpp"
#include <nlohmann/json.hpp>

void printDisciplines(std::vector<Discipline*>& disciplines) {
    if (disciplines.size() == 0){
        std::cout << "\nEmpty list\n" << std::endl;
        return;
    }
    for (auto& ptr: disciplines){
        ptr->print();
    }
}


std::vector<Discipline*> parseDisciplines(const std::string& path) {
    std::ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    nlohmann::json_abi_v3_11_2::json jsonData;
    inputFile >> jsonData;
    std::vector<Discipline*> disciplines;
    for (const auto& item : jsonData) {
        bool isWeekly = item["isWeekly"].get<bool>();
        std::string name = item["name"].get<std::string>();
        int hours = item["hours"].get<int>();
        std::string lastName = item["teacher"]["lastName"].get<std::string>();
        std::string firstName = item["teacher"]["firstName"].get<std::string>();
        std::string email = item["teacher"]["email"].get<std::string>();
        Teacher teacher(lastName, firstName, email);
        std::string place = item["place"].get<std::string>();

        disciplines.push_back(new Discipline(isWeekly, name, hours, teacher, place));
    }
    return disciplines;
}


void sortDisciplines(std::vector<Discipline*>& disciplines, std::string sortKey) {
    if (sortKey == "name") {
        std::sort(disciplines.begin(), disciplines.end(), [](const Discipline* d1, const Discipline* d2) {
            return d1->getName() < d2->getName();
        });
    } else if (sortKey == "teacher") {
        std::sort(disciplines.begin(), disciplines.end(), [](const Discipline* d1, const Discipline* d2) {
            return d1->getTeacher().getLastName() < d2->getTeacher().getLastName();
        });
    } else if (sortKey == "hours") {
        std::sort(disciplines.begin(), disciplines.end(), [](const Discipline* d1, const Discipline* d2) {
            return d1->getHours() > d2->getHours();
        });
    } else {
        throw std::runtime_error("Invalid sort key");
    }
}

void deleteVector(std::vector<Discipline*>& disciplines){
    for (auto& ptr: disciplines){
        delete ptr;
    }
    disciplines.clear();
}

std::vector<Discipline*> findDisciplines(const std::vector<Discipline*>& disciplines, const std::string& field, const std::string& value) {
    std::vector<Discipline*> valids;

    for (Discipline* discipline : disciplines) {
        if (field == "isWeekly" && value ==  std::to_string(discipline->getIsWeekly())) {
            valids.push_back(discipline);
        }
        else if (field == "name" && value == (discipline->getName())) {
            valids.push_back(discipline);
        }
        else if (field == "hours" && value ==  std::to_string(discipline->getHours())) {
            valids.push_back(discipline);
        }
        else if (field == "teacherLastName" && value == (discipline->getTeacher().getLastName())) {
            valids.push_back(discipline);
        }
        else if (field == "teacherFirstName" && value == (discipline->getTeacher().getFirstName())) {
            valids.push_back(discipline);
        }
        else if (field == "teacherEmail" && value == (discipline->getTeacher().getEmail())) {
            valids.push_back(discipline);
        }
        else if (field == "place" && value == (discipline->getPlace())) {
            valids.push_back(discipline);
        }
    }
    return valids;
}

std::vector<Discipline*> mergeDisciplines(const std::vector<Discipline*>& d1, const std::vector<Discipline*>& d2) {
    std::vector<Discipline*> mergedDiscipline(d1.begin(), d1.end());
    mergedDiscipline.insert(mergedDiscipline.end(), d2.begin(), d2.end());
    return mergedDiscipline;
}
