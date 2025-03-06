#pragma once
class Movie {

	char* movieName;
	int releaseYear;
	double IMDB;
	int movieMinutes;

public:
	const char* getMovieName();
	void setMovieName(const char* movieName);
	int getReleaseYear();
	void setReleaseYear(int year);
	double getIMDB();
	void setIMDB(double IMDB);
	int getMovieLength();
	void setMovieLength(int movieMinutes);
	int numberPassedYears(int releaseYear);
};
