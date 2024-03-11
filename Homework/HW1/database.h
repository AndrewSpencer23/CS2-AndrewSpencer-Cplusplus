#pragma once

#include "movie.h"

#include <string>

using namespace std;

namespace databases {
    class Database { 
        private: // Declaring variables in class
            int _db_id;
            string _dbname;
            movies::Movie* _movieList[100];
            int _numMovies = 0;
        public:
            void initMovies();
            Database(); // Constructor
            ~Database(); // Destructor

            void setDbId(int); // Setters
            void setDbName(string);
            void setMovieList(movies::Movie*);

            int getDbId(); // Getters
            string getDbName();
            movies::Movie* getMovieList();
    };
}