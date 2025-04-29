#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;

//functie pt impartit prop in cuvinte
vector<string> stringWords(const string& s)
{
	vector<string> words;
	size_t start = 0;
	size_t end;
	while ((end = s.find(' ', start)) != string::npos)
	{
		if (end > start) // daca avem spatii duble le ignora
		{
			words.push_back(s.substr(start, end - start));
		}
		start = end + 1;
	}
	if (start < s.length())
		words.push_back(s.substr(start));
	return words;
}
map<string, int> wordFrequency(vector<string>& words)
{
	map<string, int> frecv;
	for (const string& word : words)
	{
		frecv[word]++;
	}
	return frecv;
}
bool compareWords(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first > b.first; 
}
vector<pair<string, int>> sortWords(const map<string, int> frecv)
{
	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&compareWords)> pq(compareWords); //??

	for (const auto& entry : frecv)
		pq.push(entry); //asta este tot ce trb sa facem pq face sortarea pt noi
	vector<pair<string, int >> sortedList;
	while (!pq.empty())
	{
		sortedList.push_back(pq.top());
		pq.pop();
	}
	return sortedList;
}

int main()
{
	ifstream fin("input.txt");
	string s,line;
	while (getline(fin, line))
	{
		s += line + " ";
	}//acum avem in string prop noastra
	for (auto& c : s)
	{
 		c = tolower(c);
		if (c == '?' || c == '!' || c == '.' || c == ',') 
			c = ' '; //facem totul spatiu sa fie usor la separare
	}
	vector<string>splitWords = stringWords(s);
	map<string, int>pr_que = wordFrequency(splitWords);
	vector<pair<string, int>> sorteList = sortWords(pr_que);
	for (const auto& word : sorteList)
		cout << word.first << " => " << word.second << endl;
	return 0;
}