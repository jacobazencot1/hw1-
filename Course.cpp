#include "Course.h"

#include "Student.h"

using namespace std;

StatusType Course::addStudentToCourse(Student* student)
{
    int id = student->getId();
    StatusType status = enrolled.insert(id);
    if (status != StatusType::SUCCESS)
        return status;
    auto* node = enrolled.find(id);
    node->data->studentId = id;
    node->data->student = student;
    return StatusType::SUCCESS;
}