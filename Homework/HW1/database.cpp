#include "database.h"

void databases::Database::initMovies() {
    for(int i = 0; i < 100; i++) {
        _movieList[i] = nullptr;
    }
}