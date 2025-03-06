#include "Globals.h"
#include <cstring>

int compareName(Movie m1, Movie m2)
{
	if (strcmp(m1.getMovieName(), m2.getMovieName()) == 0)
		return 0;
	if (strcmp(m1.getMovieName(), m2.getMovieName()) < 0)
		return -1;
	return 1;
}
int compareReleaseYear(Movie m1, Movie m2)
{
	int releaseYear1 = m1.getReleaseYear();
	int releaseYear2 = m2.getReleaseYear();
	if (releaseYear1 < releaseYear2)
		return -1;
	if (releaseYear2 > releaseYear2)
		return 1;
	return 0;
}
int compareIMDB(Movie m1, Movie m2)
{
	double IMDB1 = m1.getIMDB();
	double IMDB2 = m2.getIMDB();
	if (IMDB1 < IMDB2)
		return -1;
	if (IMDB1 > IMDB2)
		return 1;
	return 0;
}
int compareLenght(Movie m1, Movie m2)
{
	int minutes1 = m1.getMovieLength();
	int minutes2 = m2.getMovieLength();
	if (minutes1 < minutes2)
		return -1;
	if (minutes2 > minutes2)
		return 1;
	return 0;
}
int comparePassedYears(Movie m1, Movie m2)
{
	int passedYears1 = m1.numberPassedYears(m1.getReleaseYear());
	int passedYears2 = m2.numberPassedYears(m2.getReleaseYear());
	if (passedYears1 < passedYears2)
		return -1;
	if (passedYears1 > passedYears2)
		return 1;
	return 0;
}