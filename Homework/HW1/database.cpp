#include "database.h"
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;


void databases::Database::initMovies() {
    for(int i = 0; i < 100; i++) {
        _movieList[i] = nullptr;
    }
}


void databases::Database::readFile() {
    string id;
    string title;
    int year;
    string genre;
    float rating;
    string director;

    string tmpLine;
    ifstream fin;
    fin.open("movies.csv"); // Opening movie csv file to read movies into array

    while (std::getline(fin, tmpLine)) {
        stringstream iss(tmpLine);
        getline(iss, id, ',');
        getline(iss, title, ',');
        cout << title << endl;
        iss >> year;
        iss.ignore();
        getline(iss, genre, ',');
        iss >> rating;
        iss.ignore();
        getline(iss, director, ',');

        movies::Movie* movie = new movies::Movie();

        movie->setId(id);
        movie->setTitle(title);
        movie->setYear(year);
        movie->setGenre(genre);
        movie->setRating(rating);
        movie->setDirector(director);
        setMovie(movie, _numMovies);
        _numMovies++;
    }
    fin.close(); // Closing input stream
}


void databases::Database::removeMovie(string removeTitle) {
    bool foundMovie = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getTitle() == removeTitle) {

            for(int j = i; j < _numMovies - 1; j++) {
                _movieList[j] = _movieList[j + 1];
            }

            _numMovies--;
            foundMovie = true;

            std::cout << removeTitle << " has been successfully deleted from the movie database. Please continue..." << endl;
        }
    }
    if(foundMovie == false) {
        cout << "Movie not found in database. Please continue..." << endl;
    }
}




void databases::Database::setMovie(movies::Movie* movie, int numMovies) {
    if(numMovies < 100) {
        _movieList[numMovies] = movie;
    }
    else {
        cout << "There are too many movies in the database, cannot add more." << endl;
    }
}


void databases::Database::addMovie(movies::Movie* addedMovie) {
    string addID;
    string addTitle;
    int addYear;
    string addGenre;
    float addRating;
    string addDirector;

    if(_numMovies < 100) {
        cout << "inside if" << endl;
        setMovie(addedMovie, (_numMovies++));
        cout << "Outside setmovie" << endl;
    }

    cout << "Please enter an ID for the new movie: ";
    cin >> addID;
    cout << "Past getline ";
    addedMovie->setId(addID);
    cout << "past setid ";
    cout << endl;


    cout << "Please enter a title for the new movie: ";
    cin.ignore();
    getline(cin, addTitle);
    addedMovie->setTitle(addTitle);
    cout << endl;

    cout << "Please enter a year for the new movie: ";
    cin >> addYear;
    addedMovie->setYear(addYear);
    cout << endl;

    cout << "Please enter a genre for the new movie: ";
    cin.ignore();
    getline(cin, addGenre);
    addedMovie->setGenre(addGenre);
    cout << endl;

    cout << "Please enter a rating for the new movie: ";
    cin >> addRating;
    addedMovie->setRating(addRating);
    cout << endl;

    cout << "Please enter a director for the new movie: ";
    cin.ignore();
    getline(cin, addDirector);
    addedMovie->setDirector(addDirector);
    cout << endl;

    cout << "Movie successfully added to the database! Please continue...";
}




void databases::Database::displayMovies() {

    cout << "DISPLAYING ALL MOVIES TO THE CONSOLE:" << endl << endl;

    for(int i = 0; i < _numMovies; i++) {
        cout << "Movie: " << i + 1 << endl << "-----------------------------" << endl;
        cout << setw(4) << "ID: " << _movieList[i]->getId() << endl;
        cout << setw(5) << "TITLE: " << _movieList[i]->getTitle() << endl;
        cout << setw(5) << "YEAR: " << _movieList[i]->getYear() << endl;
        cout << setw(5) << "GENRE: " << _movieList[i]->getGenre() << endl;
        cout << setw(5) << "RATING: " << _movieList[i]->getRating() << endl;
        cout << setw(5) << "DIRECTOR: " << _movieList[i]->getDirector() << endl << endl;

    }
}




void databases::Database::searchMovieGenre(string searchGenre) {
    bool genreFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getGenre() == searchGenre) {
            std::cout << searchGenre << " has been successfully found in the movie database." << endl;
            genreFound = true;
        }
    }
    if(genreFound == false) {
        cout << "Movie not found in the database" << endl;
    }
}




void databases::Database::searchMovieTitle(string searchTitle) {
    bool titleFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getTitle() == searchTitle) {
            std::cout << searchTitle << " has been successfully found in the movie database." << endl;
            titleFound = true;
        }
    }
    if(titleFound == false) {
        cout << "Movie not found in the database" << endl;
    }
}




void databases::Database::searchMovieID(string searchID) {
    bool IDFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getId() == searchID) {
            std::cout << searchID << " has been successfully found in the movie database." << endl;
            IDFound = true;
        }
    }
    if(IDFound == false) {
        cout << "Movie not found in the database" << endl;
    }
}




void databases::Database::searchMovieDirector(string searchDirector) {
    bool directorFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getDirector() == searchDirector) {
            std::cout << searchDirector << " has been successfully found in the movie database." << endl;
            directorFound = true;
        }
    }
    if(directorFound == false) {
        cout << "Movie not found in the database" << endl;
    }
}




databases::Database::Database() {
    _dbId = 0;
    _dbName = " ";
    _numMovies = 0;
    initMovies();
} // Constructor




databases::Database::~Database() {
    delete this;
} // Destructor




void databases::Database::setDbId(int dbId) {
    _dbId = dbId;
} // Setters




void databases::Database::setDbName(string dbName){
    _dbName = dbName;
}


 
int databases::Database::getDbId() {
    return _dbId;
} // Getters




string databases::Database::getDbName() {
    return _dbName;
}
