#include "Movie.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
const char* Movie::getMovieName()
{
	return movieName;
}
void Movie::setMovieName(const char* newMovieName) {
    movieName = (char*)malloc(strlen(newMovieName) + 1); //alocare dinamica
    if (movieName) {
        strcpy(movieName, newMovieName); 
    }
}

int Movie::getReleaseYear() {
	return releaseYear;
}
void Movie::setReleaseYear(int year) {
	releaseYear = year;
}
double Movie::getIMDB()
{
	return IMDB;
}
void Movie::setIMDB(double score)
{
	IMDB = score;
}
int Movie::getMovieLength()
{
	return movieMinutes;
}
void Movie::setMovieLength(int minutes) {
	movieMinutes = minutes;
}
int Movie::numberPassedYears(int releaseYear)
{
	return 2025 - releaseYear;
}