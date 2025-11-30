// You can edit anything you want in this file.
// However you need to implement all public StudentCourseManager function, as provided below as a template

#include "TechSystem26a1.h"


TechSystem::TechSystem()
{
    //AvlTree StudentsTree;;
    //AvlTree CourseTree;
}

TechSystem::~TechSystem()
{
    //StudentTree.delete()
    //CourseTree.delete()
}

StatusType TechSystem::addStudent(int studentId)
{
    //NodeStudent node= new NodeStudent(studentId,points = -currentBonus);
    //StudentTree.insertStudent(node);
    //     צריך לבדוק אם הפעולה הצליחה
    return StatusType::FAILURE;
}

StatusType TechSystem::removeStudent(int studentId)
{
    //StudentTree.remove(studentId);
    return StatusType::FAILURE;
}

StatusType TechSystem::addCourse(int courseId, int points)
{
    //NodeCourse node = new NodeCourse (courseId,points);
    //CourseTree.insertCourse(node);
    return StatusType::FAILURE;
}

StatusType TechSystem::removeCourse(int courseId)
{
    //RemoveTree.remove(courseId);
    return StatusType::FAILURE;
}

StatusType TechSystem::enrollStudent(int studentId, int courseId)
{

    return StatusType::FAILURE;
}

StatusType TechSystem::completeCourse(int studentId, int courseId)
{
    return StatusType::FAILURE;
}

StatusType TechSystem::awardAcademicPoints(int points)
{
    return StatusType::FAILURE;
}

output_t<int> TechSystem::getStudentPoints(int studentId)
{
    return 0;
}