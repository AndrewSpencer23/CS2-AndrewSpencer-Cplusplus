#include "movie.h"


movies::Movie::Movie() {
    _rating = 0.1;
    _director = " ";
} // Constructor


movies::Movie::~Movie() {
    delete this;
} // Destructor


void movies::Movie::setGenre(string genre) {
    _genre = genre;
}


void movies::Movie::setRating(float rating) {
    _rating = rating;
}


void movies::Movie::setDirector(string director) {
    _director = director;
}


string movies::Movie::getGenre() {
    return _genre;
}


float movies::Movie::getRating() {
    return _rating;
}


string movies::Movie::getDirector() {
    return _director;
}