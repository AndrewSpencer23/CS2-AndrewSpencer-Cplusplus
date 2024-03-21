#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "database.h"

#include "movie.h"

using namespace std;

void readFile();

int main(int argc, char* argv[]) {

    if(argc >= 2 && (string)argv[1] == "test") // Test loop
    {
        return 0;
    }

    void readFile();

    return 0;
}

void readFile() {
    databases::Database movieDatabase; // Creating an instance of a movie database
    string id;
    string title;
    int year;
    string genre;
    float rating;
    string director;

    int numMovies;
    string tmpLine;
    ifstream fin;
    fin.open("movies.csv"); // Opening movie csv file to read movies into array

    while (getline(fin, tmpLine)) {
        stringstream iss(tmpLine);
        getline(iss, id, ',');
        getline(iss, title, ',');
        iss << year;
        iss.ignore();
        getline(iss, genre, ',');
        iss << rating;
        iss.ignore();
        getline(iss, director, ',');

        movies::Movie movie;

        movie.setId(id);
        movie.setTitle(title);
        movie.setYear(year);
        movie.setGenre(genre);
        movie.setRating(rating);
        movie.setDirector(director);
        movieDatabase.addMovie(movie, numMovies);
        numMovies++;
    }
    fin.close(); // Closing input stream
}