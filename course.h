#pragma once

#include "student.h"

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class NodeCourse {
public:
    NodeCourse(int id);
    int getId() const;
    int getPoints() const;
    NodeCourse* fatherPtr;
    NodeCourse* lSon;
    NodeCourse* rSon;
    int insert (NodeCourse* std);
    int remove( NodeCourse* std);
    NodeStudent* stdInCourse;






private:
    int id;
    int points;
};

#endif
