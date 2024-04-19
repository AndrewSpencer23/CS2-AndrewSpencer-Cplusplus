#include "media.h"

media::Media::Media() {
    _id = " ";
    _title = " ";
    _year = 1950;
}

media::Media::~Media() {

}
    
void media::Media::setId(string id) {
    _id = id;
} // Setters


void media::Media::setTitle(string title) {
    _title = title;
}


void media::Media::setYear(int year) {
    _year = year;
}

string media::Media::getId(){
    return _id;
} // Getters


string media::Media::getTitle() {
    return _title;
}


int media::Media::getYear() {
    return _year;
}