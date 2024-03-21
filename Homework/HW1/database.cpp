#include "database.h"
#include <iostream>
#include <iomanip>

using namespace std;

void databases::Database::initMovies() {
    for(int i = 0; i < 100; i++) {
        _movieList[i] = nullptr;
    }
}


void databases::Database::removeMovie() {

}


void databases::Database::setMovie(movies::Movie movie, int numMovies) {
    if(numMovies < 100) {
        *_movieList[numMovies] = movie;
    }
    else {
        cout << "There are too many movies in the database, cannot add more." << endl;
    }
}

void databases::Database::addMovie() {
    
}


void databases::Database::displayMovies() {
    cout << "DISPLAYING ALL MOVIES TO THE CONSOLE:" << endl << endl;
    for(int i = 0; i < 100; i++) {
        cout << "Movie: " << i << endl << endl;
        cout << "ID: " << _movieList[i]->getId() << endl;
        cout << "TITLE: " << _movieList[i]->getTitle() << endl;
        cout << "YEAR: " << _movieList[i]->getYear() << endl;
        cout << "GENRE: " << _movieList[i]->getGenre() << endl;
        cout << "RATING: " << _movieList[i]->getRating() << endl;
        cout << "DIRECTOR: " << _movieList[i]->getDirector() << endl << endl;
    }
}


void searchMovie() {

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
