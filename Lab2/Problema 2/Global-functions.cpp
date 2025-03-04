#include "Global-functions.h"


int compareName(GradesList s1, GradesList s2)
{
	if (s1.getName() == s2.getName())
		return 0;
	else if (s1.getName() > s2.getName())
		return 1;
	else return -1;
}
int compareMathGrade(GradesList s1, GradesList s2)
{
	if (s1.getMathGrade() == s2.getMathGrade())
		return 0;
	else if (s1.getMathGrade() > s2.getMathGrade())
		return 1;
	else return -1;
}
int compareEnglishGrade(GradesList s1, GradesList s2)
{
	if (s1.getEnglishGrade() == s2.getEnglishGrade())
		return 0;
	else if (s1.getEnglishGrade() > s2.getEnglishGrade())
		return 1;
	else return -1;
}
int compareHistoryGrade(GradesList s1, GradesList s2)
{
	if (s1.getHistoryGrade() == s2.getHistoryGrade())
		return 0;
	else if (s1.getHistoryGrade() > s2.getHistoryGrade())
		return 1;
	else return -1;
}
int compareAvrageGrade(GradesList s1, GradesList s2)
{
	if (s1.getAvrageGrade() == s2.getAvrageGrade())
		return 0;
	else if (s1.getAvrageGrade() > s2.getAvrageGrade())
		return 1;
	else return -1;
}
