#include "gtest/gtest.h"
#include "../../src/classes/Student/Student.h"

TEST(check_op, test1){
    Student stud1 = Student();
    stud1.setGrades({10, 9, 8, 5, 6, 9, 10});
    stud1.setExam(8);
    stud1.setGalutinis();
    EXPECT_EQ(
            (0.4 * ((double)(10 + 9 + 8 + 5 + 6 + 9 + 10)/7)) + (0.6 * 8),
            stud1.getGalutinis());
}

TEST(check_op, test2){
    Student stud1 = Student();
    stud1.setGrades({10, 9, 8, 5, 6, 9, 10});
    stud1.setExam(8);
    stud1.setGalutinis();
    EXPECT_EQ(
            0.4 * 5 + 0.6 * 8,
            stud1.getGalutinisMedian());
}