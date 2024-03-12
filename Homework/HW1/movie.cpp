#include "movie.h"


movies::Movie::Movie() {
    _id = " ";
    _title = " ";
    _year = 1950;
    _rating = 0.1;
    _director = " ";
} // Constructor


movies::Movie::~Movie() {
    delete this;
} // Destructor


void movies::Movie::setId(string id) {
    _id = id;
} // Setters


void movies::Movie::setTitle(string title) {
    _title = title;
}


void movies::Movie::setYear(int year) {
    _year = year;
}


void movies::Movie::setGenre(string genre) {
    _genre = genre;
}


void movies::Movie::setRating(float rating) {
    _rating = rating;
}


void movies::Movie::setDirector(string director) {
    _director = director;
}

string movies::Movie::getId(){
    return _id;
} // Getters


string movies::Movie::getTitle() {
    return _director;
}


int movies::Movie::getYear() {
    return _year;
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