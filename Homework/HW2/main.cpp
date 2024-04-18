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
    

    databases::Database mediaDatabase; // Creating an instance of a movie database
    mediaDatabase.readFileMovies();
    mediaDatabase.readFileMusic();
    mediaDatabase.readFileTv();

    do {
        clearScreen();
        std::cout << "This program creates a movie database and allows a choice multiple different functions within the database.\n";
        choice = menu();
        switch(choice) {
            case 1:
                clearScreen();
                movies::Movie* addedMovie;
                addedMovie = new movies::Movie();
                mediaDatabase.addMovie(addedMovie);
                break;
            case 2:
                clearScreen();
                std::cout << "Please enter a movie title in the database to delete: ";
                cin.ignore();
                std::getline(cin, removeTitle);
                clearScreen();
                mediaDatabase.removeMovie(removeTitle);
                break;
            case 3:
                clearScreen();
                std::cout << "Please enter a movie genre to search for in the database: ";
                cin.ignore();
                std::getline(cin, searchGenre);
                mediaDatabase.searchMovieGenre(searchGenre);
                break;
            case 4:
                clearScreen();
                std::cout << "Please enter a movie ID to search for in the database: ";
                cin.ignore();
                std::getline(cin, searchID);
                mediaDatabase.searchMovieID(searchID);
                break;
            case 5:
                clearScreen();
                std::cout << "Please enter a movie director to search for in the database: ";
                cin.ignore();
                std::getline(cin, searchDirector);
                mediaDatabase.searchMovieDirector(searchDirector);
                break;
            case 6:
                clearScreen();
                std::cout << "Please enter a movie title to search for in the database: ";
                cin.ignore();
                std::getline(cin, searchTitle);
                mediaDatabase.searchMovieTitle(searchTitle);
                break;
            case 7:
                clearScreen();
                mediaDatabase.displayMovies();
                break;
            case 8:
                break;
        }
        if (choice != 8) {
            std::cin.ignore();
            std::cout << "Enter to continue...";
            std::cin.get();
        }
    } while (choice != 8);
    std::cin.ignore();
    std::cout << "Good bye! Enter to quit...";
    std::cin.get();
    clearScreen();
    return 0;
}


int menu() {
    int choice;
    std::cout << "Menu options: \n"
        << "Movie Functions:\n"
        << "1. Add a movie to the database\n"
        << "2. Remove a movie from the database\n"
        << "3. Search for a movie in the database using genre\n"
        << "4. Search for a movie in the database using ID\n"
        << "5. Search for a movie in the database using director\n"
        << "6. Search for a movie in the database using title\n"
        << "7. Print out all movies in database\n\n"
        << "Music Functions:\n"
        << "8. Exit the program\n";
    std::cout << "Enter your choice: [1-8]: ";
    std::cin >> choice;
    return choice;
}