#include "gtest/gtest.h"
#include "discipline.h"

Discipline ds1(false, "Алгебра", 10, Teacher("Бромов", "Сергей", "bromov@gmail.com"), "Karazin");
Discipline ds2(true, "Геометрія", 2, Teacher("Сакутин", "Роман", "sakutin@gmail.com"), "KHPI");
Discipline ds3(true, "Біологія", 5, Teacher("Есенина", "Ольга", "esenina@gmail.com"), "KNURE");

class DisciplineSortingTest : public ::testing::Test {
protected:
    void SetUp() override {
        disciplines.push_back(&ds1);
        disciplines.push_back(&ds2);
        disciplines.push_back(&ds3);
    }

    void TearDown() override {
        deleteVector(disciplines);
    }

    std::vector<Discipline*> disciplines;
};

TEST_F(DisciplineSortingTest, SortByName) {
    sortDisciplines(disciplines, "name");

    EXPECT_STREQ(disciplines[0]->getName().c_str(), "Алгебра");
    EXPECT_STREQ(disciplines[1]->getName().c_str(), "Біологія");
    EXPECT_STREQ(disciplines[2]->getName().c_str(), "Геометрія");
}

TEST_F(DisciplineSortingTest, SortByHours) {
    sortDisciplines(disciplines, "hours");

    EXPECT_EQ(disciplines[0]->getHours(), 10);
    EXPECT_EQ(disciplines[1]->getHours(), 5);
    EXPECT_EQ(disciplines[2]->getHours(), 2);
}

TEST_F(DisciplineSortingTest, SortByTeacher) {
    sortDisciplines(disciplines, "teacher");

    EXPECT_STREQ(disciplines[0]->getTeacher().getLastName().c_str(), "Бромов");
    EXPECT_STREQ(disciplines[1]->getTeacher().getLastName().c_str(), "Есенина");
    EXPECT_STREQ(disciplines[2]->getTeacher().getLastName().c_str(), "Сакутин");
}
