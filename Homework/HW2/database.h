#pragma once


#include "movie.h"


#include <string>


using namespace std;


namespace databases {
    class Database {
        private: // Declaring variables in class
            int _dbId;
            string _dbName;
            movies::Movie* _movieList[100];
            int _numMovies;
        public:
            void initMovies(); // Methods within database class
            void readFile();
            void removeMovie(string);
            void setMovie(movies::Movie*, int);
            void addMovie(movies::Movie*);
            void displayMovies();
            void searchMovieGenre(string);
            void searchMovieTitle(string);
            void searchMovieID(string);
            void searchMovieDirector(string);
           
            Database(); // Constructor
            ~Database(); // Destructor

            void setDbId(int); // Setters
            void setDbName(string);

            int getDbId(); // Getters
            string getDbName();
    };
}
