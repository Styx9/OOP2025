#include "Movie.h"
#include "MovieSeries.h"
#include "Globals.h"
#include <iostream>



int main() {
    Movie ep5;
    ep5.setMovieName("Star Wars: Episode V - The Empire Strikes Back");
    ep5.setIMDB(8.7);
    ep5.setReleaseYear(1980);
    ep5.setMovieLength(124);

    Movie ep4;
    ep4.setMovieName("Star Wars: Episode IV - A New Hope");
    ep4.setIMDB(8.6);
    ep4.setReleaseYear(1977);
    ep4.setMovieLength(121);

    Movie ep6;
    ep6.setMovieName("Star Wars: Episode VI - Return of the Jedi");
    ep6.setIMDB(8.3);
    ep6.setReleaseYear(1983);
    ep6.setMovieLength(131);

    printf(
        R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
compareName(ep4, ep5),
compareReleaseYear(ep4, ep5),
compareIMDB(ep4, ep5),
compareLenght(ep4, ep5),
comparePassedYears(ep4, ep5));

    MovieSeries series;
    series.init();
    series.add(&ep5);
    series.add(&ep4);
    series.add(&ep6);

    series.sort();
    series.print();
}
