#include "Grades.h"
#include "Global-functions.h"
#include <iostream>
using namespace std;
int main()
{
	GradesList s1, s2;
	s1.setName("Gigel Ionel");
	s1.setEnglishGrade(7);
	s1.setHistoryGrade(8);
	s1.setMathGrade(10);
	
	s2.setName("Anca Marcu");
	s2.setEnglishGrade(6);
	s2.setHistoryGrade(9);
	s2.setMathGrade(8);

	cout << "Compare by name:  " << compareName(s1, s2) << endl;
	cout << "Compare by English grade:  " << compareEnglishGrade(s1, s2) << endl;
	cout << "Compare by Math grade:  " << compareMathGrade(s1, s2) << endl;
	cout << "Compare by History grade:  " << compareHistoryGrade(s1, s2) << endl;
	cout << "Compare by Avrage grade:  " << compareAvrageGrade(s1, s2) << endl;



}