#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "database.h"

#include "movie.h"

using namespace std;

int main(int argc, char* argv[]) {

    if(argc >= 2 && (string)argv[1] == "test") // Test loop
    {
        return 0;
    }

    int numMovies; // Will update later, this will be how many lines are read in from the movies file.

    databases::Database* movieDatabase; // Creating an instance of a movie database as a pointer.

    string id;
    string title;
    int year;
    string genre;
    float rating;
    string director;

    int row;
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

        row++;
    }
    numMovies = row;
    fin.close(); // Closing input stream
    return 0;
}