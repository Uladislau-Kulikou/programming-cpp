#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "discipline.h"


void printDisciplines(std::vector<Discipline*>& disciplines) {
    for (auto& ptr: disciplines){
        ptr->print();
    }
}


void parseDisciplines(std::vector<Discipline*>& disciplines, std::string path) {
    std::ifstream inputFile(path);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int isWeekly, hours;
        std::string name, firstName, lastName, email, place;
        if (!(iss >> isWeekly >> name >> hours >> lastName >> firstName >> email >> place)) {
            throw std::runtime_error("Failed to read input file");
        }
        Teacher teacher = {lastName, firstName, email};
        disciplines.push_back(new Discipline(isWeekly, name, hours, teacher, place));
    }
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