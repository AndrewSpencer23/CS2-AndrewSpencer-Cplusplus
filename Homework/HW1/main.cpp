#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "database.h"

#include "movie.h"

using namespace std;

#ifdef _WIN32
#define clearScreen() system ("cls") // not secure!
#else
#define clearScreen() system ("clear") // not secure!
#endif

void readFile(databases::Database);
int menu();

int main(int argc, char* argv[]) {

    if(argc >= 2 && (string)argv[1] == "test") // Test loop
    {
        return 0;
    }
    int choice;
    do {
        databases::Database movieDatabase; // Creating an instance of a movie database
        readFile(movieDatabase);
        clearScreen();
        cout << "This program creates a movie database and allows a choice multiple different functions within the database.\n";
        choice = menu();
        switch(choice) {
            case 1:
                databases::Database::addMovie();
                break;
            case 2:
                databases::Database::removeMovie();
                break;
            case 3:
                databases::Database::searchMovie();
                break;
            case 4:
                databases::Database::displayMovies();
                break;
            case 5:
                break;
        }
        if (choice != 5) {
            cin.ignore();
            cout << "Enter to continue...";
            cin.get();
        }
    } while (choice != 5);
    cin.ignore();
    cout << "Good bye! Enter to quit...";
    cin.get();
    return 0;
}

void readFile(databases::Database movieDatabase) {
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
        movieDatabase.setMovie(movie, numMovies);
        numMovies++;
    }
    fin.close(); // Closing input stream
}

int menu() {
    int choice;
    cout << "Menu options: \n"
        << "1. Add a movie to the database\n"
        << "2. Remove a movie from the database\n"
        << "3. Search for a movie in the database\n"
        << "4. Print out all movies in database\n"
        << "5. Exit the program\n";
    cout << "Enter your choice: [1-5]: ";
    cin >> choice;
    return choice;
}