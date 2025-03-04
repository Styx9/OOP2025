#pragma once
#include <string>
class GradesList
{
private:
	std::string studentName;
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	GradesList();
	void setName(const std::string& studentName);
	std::string getName();
	bool setMathGrade(float mathGrade);
	float getMathGrade();
	bool setEnglishGrade(float mathGrade);
	float getEnglishGrade();
	bool setHistoryGrade(float mathGrade);
	float getHistoryGrade();
	float getAvrageGrade();
};