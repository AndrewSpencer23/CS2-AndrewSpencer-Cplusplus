#include "database.h"

void databases::Database::initMovies() {
    for(int i = 0; i < 100; i++) {
        _movieList[i] = nullptr;
    }
}

void removeMovie() {

}


void addMovie() {

}


void displayMovies() {

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


void databases::Database::setMovieList(movies::Movie movieList[]) {
    
}

     
int databases::Database::getDbId() {
    return _dbId;
} // Getters


string databases::Database::getDbName() {
    return _dbName;
}


movies::Movie* databases::Database::getMovieList() {

}