// You can edit anything you want in this file.
// However, you need to implement all public StudentCourseManager function, as provided below as a template

#include "TechSystem26a1.h"
#include "Student.h"

TechSystem::TechSystem(): students(), courses(), global_bonus(0){}


TechSystem::~TechSystem() =default;

StatusType TechSystem::addStudent(int studentId)
{
    if (studentId <= 0)
        return StatusType::INVALID_INPUT;

    StatusType status = students.insert(studentId);
    if (status != StatusType::SUCCESS)
        return status;

    auto* node = students.find(studentId);
    Student* studentData = node->data;
    studentData->setId(studentId);
    studentData->addPoints(-global_bonus);

    return StatusType::SUCCESS;

}

StatusType TechSystem::removeStudent(int studentId)
{
    if (studentId <= 0)
        return StatusType::INVALID_INPUT;
    auto* node = students.find(studentId);
    if (!node) return StatusType::FAILURE;

    if (node->data->getCoursesCount() > 0)
        return StatusType::FAILURE;
    return students.remove(studentId);
}

StatusType TechSystem::addCourse(int courseId, int points)
{
    if (courseId <= 0 || points <= 0)
        return StatusType::INVALID_INPUT;

    StatusType status = courses.insert(courseId);
    if (status != StatusType::SUCCESS)
        return status;

    auto* node = courses.find(courseId);
    node->data->setId(courseId);
    node->data->setPoints(points);

    return StatusType::SUCCESS;
}

StatusType TechSystem::removeCourse(int courseId)
{
    if (courseId <= 0)
        return StatusType::INVALID_INPUT;
    auto* node = courses.find(courseId);
        if (!node)
            return StatusType::FAILURE;

        Course* course = node->data;

        if (!course->isEmpty())
            return StatusType::FAILURE;

        return courses.remove(courseId);

}

StatusType TechSystem::enrollStudent(int studentId, int courseId)
{
        if (studentId<=0 || courseId<=0) return StatusType::INVALID_INPUT;
        auto* studentToEnroll = students.find(studentId);
        if (!studentToEnroll)
            return StatusType::FAILURE;

        auto* studentToEnrollData = studentToEnroll->data;


        auto* course = courses.find(courseId);
        if (!course)
            return StatusType::FAILURE;

        Course* courseData = course->data;
        if (courseData->isStudentInCourse(studentId))
            return StatusType::FAILURE;

        StatusType status= courseData->addStudentToCourse(studentToEnrollData);
        if (status != StatusType::SUCCESS)
            return status;

        studentToEnrollData->incCourses();

        return StatusType::SUCCESS;
}

StatusType TechSystem::completeCourse(int studentId, int courseId)
{
        if (studentId<=0 || courseId<=0) return StatusType::INVALID_INPUT;

        auto* studentNode = students.find(studentId);
        if (!studentNode)
            return StatusType::FAILURE;
        auto* studentData = studentNode->data;


        auto* courseNode = courses.find(courseId);
        if (!courseNode)
            return StatusType::FAILURE;
        auto* courseData = courseNode->data;


        auto* StdInCourseNode = courseData->enrolled.find(studentId);
        if (!StdInCourseNode)
            return StatusType::FAILURE;


        int pts = courseData->getPoints();
        studentData->addPoints(pts);


        courseData->enrolled.remove(studentId);


        studentData->decCourses();

        return StatusType::SUCCESS;
}

StatusType TechSystem::awardAcademicPoints(int points)
{

        if (points <= 0)
            return StatusType::INVALID_INPUT;

        global_bonus += points;
        return StatusType::SUCCESS;
}

output_t<int> TechSystem::getStudentPoints(int studentId)
{
    if (studentId <= 0)
        return { StatusType::INVALID_INPUT };
    auto* node = students.find(studentId);
    if (!node)
        return { StatusType::FAILURE };

    int total = node->data->getBasePoints() + global_bonus;

    return { total };

}
