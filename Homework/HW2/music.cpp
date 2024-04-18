#include "music.h"

#include <string>

music::Music::Music() {
    _songComposer = " ";
    _songGenre = " ";
    _numTracks = 1;
    _totalPlaytime = 0.1;
}

music::Music::~Music() {
    delete this;
}

void music::Music::setSongComposer(string songComposer) {
    _songComposer = songComposer;
}

void music::Music::setSongGenre(string songGenre) {
    _songGenre = songGenre;
}

void music::Music::setNumTracks(int numTracks) {
    _numTracks = numTracks;
}

void music::Music::setTotalPlaytime(int totalPlaytime) {
    _totalPlaytime = totalPlaytime;
}

string music::Music::getSongComposer() {
    return _songComposer;
}

string music::Music::getSongGenre() {
    return _songComposer;
}

int music::Music::getNumTracks() {
    return _numTracks;
}

int music::Music::getTotalPlaytime() {
    return _totalPlaytime;
}