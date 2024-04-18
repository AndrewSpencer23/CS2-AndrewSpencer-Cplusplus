#pragma once


#include "movie.h"
#include "media.h"
#include "tvshows.h"
#include "music.h"


#include <string>


using namespace std;


namespace databases {
    class Database : public media::Media {
        private: // Declaring variables in class
            int _dbId;
            string _dbName;
            movies::Movie* _movieList[100];
            tvshows::tvShow* _tvShowList[100];
            music::Music* _musicList[100];
            int _numMovies;
            int _numTvShows;
            int _numMusic;
        public:
            void initMovies(); // Methods within database class
            void initTvShows();
            void initMusic();

            void readFileMovies();
            void readFileTv();
            void readFileMusic();
            
            void removeMovie(string);

            void setMovie(movies::Movie*, int);
            void setMusic(music::Music*, int);
            void setTvShow(tvshows::tvShow*, int);

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
