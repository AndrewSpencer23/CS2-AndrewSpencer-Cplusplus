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
    string removeTitle;
    string searchGenre;
    string searchTitle;
    string searchID;
    string searchDirector;

    databases::Database movieDatabase; // Creating an instance of a movie database
    readFile(movieDatabase);
    do {
        clearScreen();
        cout << "This program creates a movie database and allows a choice multiple different functions within the database.\n";
        choice = menu();
        switch(choice) {
            case 1:
                databases::Database::addMovie();
                break;
            case 2:
                cout << "Please enter a movie title in the database to delete: ";
                getline(cin, removeTitle);
                databases::Database::removeMovie(removeTitle);
                break;
            case 3:
                databases::Database::searchMovieGenre(searchGenre);
                break;
            case 4:
                databases::Database::searchMovieTitle(searchTitle);
                break;
            case 5:
                databases::Database::searchMovieID(searchID);
                break;
            case 6:
                databases::Database::searchMovieDirector(searchDirector);
                break;
            case 7:
                databases::Database::displayMovies();
                break;
            case 8:
                break;
        }
        if (choice != 8) {
            cin.ignore();
            cout << "Enter to continue...";
            cin.get();
        }
    } while (choice != 8);
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
        << "3. Search for a movie in the database using genre\n"
        << "4. Search for a movie in the database\n"
        << "5. Search for a movie in the database\n"
        << "6. Search for a movie in the database\n"
        << "7. Print out all movies in database\n"
        << "8. Exit the program\n";
    cout << "Enter your choice: [1-8]: ";
    cin >> choice;
    return choice;
}