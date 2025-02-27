#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void sort_words(char words[][100], int count) //am facut un simlu bubble sort pt sortare avand in vedere ca nu sunt asa multe cuvinte 
{
	for(int i = 0;i<count-1;i++)
		for (int j = i + 1; j < count; j++)
		{
			int len1 = strlen(words[i]);
			int len2 = strlen(words[j]);
			if (len1 < len2 || (len1 == len2 && strcmp(words[i], words[j]) > 0))
			{
				char temp[100];
				strcpy(temp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], temp);
			}
		}
}

int main()
{
	char input[100]; char* p; char words[100][100]; //vector de cuvinter pe care il sortam ulterior
	int count=0;//nr de cuv
	fgets(input, sizeof(input), stdin);//am folosit fgets pt ca scanf_s nu poate lua cuv dupa space
	p = strtok(input, " \n");
	while (p)
	{
		strcpy(words[count], p);
		count++;
		p = strtok(NULL, " \n");
	}
	sort_words(words, count);
	for (int i = 0; i < count; i++)
		printf("%s\n", words[i]);
	return 0;
}