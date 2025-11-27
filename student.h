#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class NodeStudent {
public:
    NodeStudent(int id);
    int getId() const;
    int getPoints() const;
    NodeStudent* fatherPtr;
    NodeStudent* lSon;
    NodeStudent* rSon;
    int insert (NodeStudent* std);
    int remove( NodeStudent* std);
    NodeStudent* ptrStd;




private:
    int id;
    int points;
};






#endif
