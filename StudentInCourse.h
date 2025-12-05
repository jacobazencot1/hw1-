#pragma once

#pragma once

#include "Student.h"

class StudentInCourse {
public:
    int studentId;
    Student* student;


    StudentInCourse()
        : studentId(0), student(nullptr) {}

    StudentInCourse(int id, Student* s)
        : studentId(id), student(s) {}


    ~StudentInCourse() = default;

    int getId() const {
        return studentId;
    }

    Student* getStudent() const {
        return student;
    }

    void set(int id, Student* s) {
        studentId = id;
        student = s;
    }
};
