#pragma once

#include "wet1util.h"
#include "Avl.h"
#include "StudentInCourse.h"


class Course {
public:
    int courseId;
    int points;
    Avl<StudentInCourse> enrolled;


    Course() : courseId(0), points(0) {}
    Course(int id, int pts = 0) : courseId(id), points(pts) {}

    int getId() const { return courseId; }
    int getPoints() const { return points; }
    void setPoints(int pts) { points = pts; }
    bool isEmpty() const { return enrolled.getRoot() == nullptr; }
    StatusType addStudentToCourse(Student* student);
    bool isStudentInCourse(int studentId) { return enrolled.find(studentId) != nullptr;}
    void setId(int newId) { courseId = newId; }

};
