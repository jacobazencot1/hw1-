#pragma once
class Student {
private:
    int id;
    int basePoints;
    int coursesCount;

public:
    Student(int id = 0): id(id), basePoints(0), coursesCount(0) {}
    int getId() const { return id; }
    int getBasePoints() const { return basePoints; }
    void addPoints(int p) { basePoints += p; }

    void incCourses() { coursesCount++; }
    void decCourses() { coursesCount--; }
    int getCoursesCount() const { return coursesCount; }
    void setId(int newId) { id = newId; }

};
