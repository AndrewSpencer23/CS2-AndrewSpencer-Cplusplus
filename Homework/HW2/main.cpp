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
    string searchTitle;
    string searchID;
    int searchYear;
    
    databases::Database mediaDatabase; // Creating an instance of a media database
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
                music::Music* addedMusic;
                addedMusic = new music::Music();
                mediaDatabase.addMusic(addedMusic);
                break;
            case 3:
                clearScreen();
                tvshows::tvShow* addedTvShow;
                addedTvShow = new tvshows::tvShow();
                mediaDatabase.addTvShow(addedTvShow);
                break;
            case 4:
                clearScreen();
                std::cout << "Please enter a media title in the database to delete: ";
                cin.ignore();
                std::getline(cin, removeTitle);
                clearScreen();
                mediaDatabase.removeMedia(removeTitle);
                break;
            case 5:
                clearScreen();
                std::cout << "Please enter a media ID to search for in the database: ";
                cin.ignore();
                std::getline(cin, searchID);
                mediaDatabase.searchMediaID(searchID);
                break;
            case 6:
                clearScreen();
                std::cout << "Please enter a media title to search for in the database: ";
                cin.ignore();
                std::getline(cin, searchTitle);
                mediaDatabase.searchMediaTitle(searchTitle);
                break;
            case 7:
                clearScreen();
                std::cout << "Please enter a media year to search for in the database: ";
                cin.ignore();
                cin >> searchYear;
                mediaDatabase.searchMediaYear(searchYear);
                break;
            case 8:
                clearScreen();
                mediaDatabase.displayMovies();
                break;
            case 9:
                clearScreen();
                mediaDatabase.displayMusic();
                break;
            case 10:
                clearScreen();
                mediaDatabase.displayTvShows();
                break;
            case 11:
                break;
        }
        if (choice != 11) {
            std::cin.ignore();
            std::cout << "Enter to continue...";
            std::cin.get();
        }
    } while (choice != 11);
    std::cin.ignore();
    std::cout << "Good bye! Enter to quit...";
    std::cin.get();
    clearScreen();
    return 0;
}


int menu() {
    int choice;
    std::cout << "Menu options: \n"
        << "1. Add a movie to the database\n"
        << "2. Add music to the database\n"
        << "3. Add a tv show to the database\n"
        << "4. Remove media from the database\n"
        << "5. Search for media in the database using ID\n"
        << "6. Search for media in the database using title\n"
        << "7. Search for media in the database using year\n"
        << "8. Print out all movies in database\n"
        << "9. Print out all music in database\n"
        << "10. Print out all tv shows in database\n"
        << "11. Exit the program\n";
    std::cout << "Enter your choice: [1-11]: ";
    std::cin >> choice;
    return choice;
}