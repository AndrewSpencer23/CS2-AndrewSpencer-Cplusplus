#include "database.h"

void databases::Database::initMovies() {
    for(int i = 0; i < 100; i++) {
        _movieList[i] = nullptr;
    }
}

databases::Database::Database() {

} // Constructor


databases::Database::~Database() {

} // Destructor

     
int getDbId() {

} // Getters


string getDbName() {

}


movies::Movie* getMovieList() {

}

void setDbId(int) {

} // Setters


void setDbName(string){

}


void setMovieList(movies::Movie*) {
    
}