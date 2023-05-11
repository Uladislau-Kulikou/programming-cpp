#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <iostream>
#include <string>
#include <vector>


class Teacher {
private:
    std::string lastName;
    std::string firstName;
    std::string email;
public:
    Teacher(const std::string& lastName, const std::string& firstName, const std::string& email)
        : lastName(lastName), firstName(firstName), email(email) {}

    const std::string& getLastName() const {
        return lastName;
    }

    const std::string& getFirstName() const {
        return firstName;
    }

    const std::string& getEmail() const {
        return email;
    }

    void setLastName(const std::string& lastName) {
        this->lastName = lastName;
    }

    void setFirstName(const std::string& firstName) {
        this->firstName = firstName;
    }

    void setEmail(const std::string& email) {
        this->email = email;
    }
};

class Discipline {
private:
    bool isWeekly;
    std::string name;
    int hours;
    Teacher teacher;
    std::string place;

public:
    Discipline(bool isWeekly, std::string name, int hours, Teacher teacher, std::string place)
        : isWeekly(isWeekly), name(name), hours(hours), teacher(teacher), place(place) {}

    bool getIsWeekly() const {
        return isWeekly;
    }

    std::string getName() const {
        return name;
    }

    int getHours() const {
        return hours;
    }

    Teacher getTeacher() const {
        return teacher;
    }

    std::string getPlace() const {
        return place;
    }

    void setIsWeekly(bool isWeekly) {
        this->isWeekly = isWeekly;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setHours(int hours) {
        this->hours = hours;
    }

    void setTeacher(Teacher teacher) {
        this->teacher = teacher;
    }

    void setPlace(std::string place) {
        this->place = place;
    }

    void print() const {
        std::cout << "\nНазва предмету: " << name << std::endl;
        std::cout << "Є щотижневим: " << (isWeekly ? "Так" : "Ні") << std::endl;
        std::cout << "Годин на тиждень: " << hours << std::endl;
        std::cout << "Викладач: " << teacher.getFirstName() << " " << teacher.getLastName() << std::endl;
        std::cout << "Пошта викладача: " << teacher.getEmail() << std::endl;
        std::cout << "Місце: " << place << std::endl;
    }
};


extern void printDisciplines(std::vector<Discipline*>& disciplines);

extern void parseDisciplines(std::vector<Discipline*>& disciplines, std::string path);

extern void sortDisciplines(std::vector<Discipline*>& disciplines, std::string sortKey);

extern void deleteVector(std::vector<Discipline*>& disciplines);

#endif  // DISCIPLINE_H
