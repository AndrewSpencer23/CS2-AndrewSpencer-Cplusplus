#include "tvshows.h"

#include <string>

tvshows::tvShow::tvShow() {
    _tvGenre = " ";
    _tvRating = 0.1;
    _numEpisodes = 1;
}

tvshows::tvShow::~tvShow() {

}

void tvshows::tvShow::setTvGenre(string tvGenre) {
    _tvGenre = tvGenre;
}

void tvshows::tvShow::setTvRating(float tvRating) {
    _tvRating = tvRating;
}

void tvshows::tvShow::setNumEpisodes(int numEpisodes) {
    _numEpisodes = numEpisodes;
}
            
string tvshows::tvShow::getTvGenre() {
    return _tvGenre;
}

float tvshows::tvShow::getTvRating() {
    return _tvRating;
}

int tvshows::tvShow::getNumEpisodes() {
    return _numEpisodes;
}