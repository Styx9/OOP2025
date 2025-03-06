#include "MovieSeries.h"
#include <iostream>
using namespace std;

MovieSeries::MovieSeries() : count(0) {}; //setam counterul la 0 din constructor

void MovieSeries::init()
{
	count = 0;
}
bool MovieSeries::add(Movie* movie)
{
	if (count < 16)
	{
		movies[count++] = movie;
		return true;
	}
	return false;
}
void MovieSeries::print()
{
	for (int i = 0; i < count; i++)
	{
		cout << "Name: " << movies[i]->getMovieName() << endl;;
		cout << "Release Year: " << movies[i]->getReleaseYear() << endl;
		cout << "IMDB score: " << movies[i]->getIMDB()<<endl;
		cout << "Length: " << movies[i]->getMovieLength()<<endl;
		cout << "Number of Passed Years: " << movies[i]->numberPassedYears(movies[i]->getReleaseYear()) << endl;
	}
}
void MovieSeries::sort()
{
	for(int i = 0; i<count-1;i++)
		for(int j = i+1;j<count;j++)
			if (movies[i]->numberPassedYears(movies[i]->getReleaseYear()) > movies[j]->numberPassedYears(movies[j]->getReleaseYear()))
			{
			 Movie* temp = movies[i];
			 movies[i] = movies[j];
			 movies[j] = temp;
		}
}