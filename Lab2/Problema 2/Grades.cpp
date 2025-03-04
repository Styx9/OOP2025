#include <iostream>
#include "Grades.h"

GradesList::GradesList() :mathGrade(0), englishGrade(0), historyGrade(0) {} //initializam notele cu 0 in constructor\

void GradesList::setName(const std::string& name) {
	studentName = name;
}
std::string GradesList::getName() {
	return studentName;
}
bool GradesList::setMathGrade(float grade)
{
	if (grade >= 1.0f && grade <= 10.0f)
	{
		mathGrade = grade;
		return true;
	}
	return false;
}
float GradesList::getMathGrade()
{
	return mathGrade;
}
bool GradesList::setHistoryGrade(float grade)
{
	if (grade >= 1.0f && grade <= 10.0f)
	{
		historyGrade = grade;
		return true;
	}
	return false;
}
float GradesList::getHistoryGrade()
{
	return historyGrade;
}
float GradesList::getEnglishGrade()
{
	return englishGrade;
}
bool GradesList::setEnglishGrade(float grade)
{
	if (grade >= 1.0f && grade <= 10.0f)
	{
		englishGrade = grade;
		return true;
	}
	return false;
}
float GradesList::getAvrageGrade()
{
	return (mathGrade + englishGrade + historyGrade) / 3.0f;
}
