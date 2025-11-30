#include "Student.h"

using namespace std;

NodeStudent::NodeStudent(int id) : id(id) , points(0){}

//Keep in mind for destructor

int NodeStudent::insert(NodeStudent *std) {
    if(std == NULL){

        return;
    }
}