#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "database.h"

#include "movie.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc >= 2 && (string)argv[1] == "test")
    {
        return 0;
    }

    int numMovies; // Will update later, this will be how many lines are read in from the movies file.

    movies::Movie movieList[numMovies]; // Creating instance of a movie class using an array of movies.

    databases::Database* movieDatabase; // Creating an instance of a movie database as a pointer.

    ifstream fin;
    fin.open("movies.csv");

    fin.close();
    return 0;
}

void tests() {

}