#include "database.h"
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;


void databases::Database::initMovies() {
    for(int i = 0; i < 100; i++) {
        _movieList[i] = nullptr;
    }
}


void databases::Database::initTvShows() {
    for(int i = 0; i < 100; i++) {
        _tvShowList[i] = nullptr;
    }
}


void databases::Database::initMusic() {
    for(int i = 0; i < 100; i++) {
        _musicList[i] = nullptr;
    }
}


void databases::Database::readFileMovies() {
    string id;
    string title;
    int year;
    string genre;
    float rating;
    string director;

    string tmpLine;
    ifstream fin;
    fin.open("movies.csv"); // Opening movie csv file to read movies into array

    while (std::getline(fin, tmpLine)) {
        stringstream iss(tmpLine);
        getline(iss, id, ',');
        getline(iss, title, ',');
        cout << title << endl;
        iss >> year;
        iss.ignore();
        getline(iss, genre, ',');
        iss >> rating;
        iss.ignore();
        getline(iss, director, ',');

        movies::Movie* movie = new movies::Movie();

        movie->setId(id);
        movie->setTitle(title);
        movie->setYear(year);
        movie->setGenre(genre);
        movie->setRating(rating);
        movie->setDirector(director);
        setMovie(movie, _numMovies);
        _numMovies++;
    }
    fin.close(); // Closing input stream
}


void databases::Database::readFileTv() {
    string id;
    string title;
    int year;
    string tvGenre;
    float tvRating;
    int numEpisodes;

    string tmpLine;
    ifstream fin;
    fin.open("tvshows.csv"); // Opening movie csv file to read movies into array

    while (std::getline(fin, tmpLine)) {
        stringstream iss(tmpLine);
        getline(iss, id, ',');
        getline(iss, title, ',');
        iss >> year;
        iss.ignore();
        getline(iss, tvGenre, ',');
        iss >> tvRating;
        iss.ignore();
        iss >> numEpisodes;
        iss.ignore();

        tvshows::tvShow* tvShow = new tvshows::tvShow();

        tvShow->setId(id);
        tvShow->setTitle(title);
        tvShow->setYear(year);
        tvShow->setTvGenre(tvGenre);
        tvShow->setTvRating(tvRating);
        tvShow->setNumEpisodes(numEpisodes);
        setTvShow(tvShow, _numTvShows);
        _numTvShows++;
    }
    fin.close(); // Closing input stream
}


void databases::Database::readFileMusic() {
    string songID;
    string songTitle;
    int songYear;
    string songComposer;
    string songGenre;
    int numTracks;
    int totalPlaytime;

    string tmpLine;
    ifstream fin;
    fin.open("music.csv"); // Opening movie csv file to read movies into array

    while (std::getline(fin, tmpLine)) {
        stringstream iss(tmpLine);
        getline(iss, songID, ',');
        getline(iss, songTitle, ',');
        iss >> songYear;
        iss.ignore();
        getline(iss, songComposer, ',');
        getline(iss, songGenre, ',');
        iss >> numTracks;
        iss.ignore();
        iss >> totalPlaytime;
        iss.ignore();

        music::Music* music = new music::Music();

        music->setId(songID);
        music->setTitle(songTitle);
        music->setYear(songYear);
        music->setSongComposer(songComposer);
        music->setSongGenre(songGenre);
        music->setNumTracks(numTracks);
        music->setTotalPlaytime(totalPlaytime);

        setMusic(music, _numMusic);
        _numMusic++;
    }
    fin.close(); // Closing input stream
}

void databases::Database::removeMovie(string removeTitle) {
    bool foundMovie = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getTitle() == removeTitle) {

            for(int j = i; j < _numMovies - 1; j++) {
                _movieList[j] = _movieList[j + 1];
            }

            _numMovies--;
            foundMovie = true;

            std::cout << removeTitle << " has been successfully deleted from the movie database. Please continue..." << endl;
        }
    }
    if(foundMovie == false) {
        cout << "Movie not found in database. Please continue..." << endl;
    }
}


void databases::Database::removeMusic(string removeTitle) {
    bool foundMusic = false;
    for(int i = 0; i < _numMusic; i++) {
        if(_musicList[i]->getTitle() == removeTitle) {

            for(int j = i; j < _numMovies - 1; j++) {
                _musicList[j] = _musicList[j + 1];
            }

            _numMusic--;
            foundMusic = true;

            std::cout << removeTitle << " has been successfully deleted from the music database. Please continue..." << endl;
        }
    }
    if(foundMusic == false) {
        cout << "Music not found in database. Please continue..." << endl;
    }
}


void databases::Database::removeTvShow(string removeTitle) {
    bool foundTvShow = false;
    for(int i = 0; i < _numTvShows; i++) {
        if(_tvShowList[i]->getTitle() == removeTitle) {

            for(int j = i; j < _numTvShows - 1; j++) {
                _tvShowList[j] = _tvShowList[j + 1];
            }

            _numTvShows--;
            foundTvShow = true;

            std::cout << removeTitle << " has been successfully deleted from the tv show database. Please continue..." << endl;
        }
    }
    if(foundTvShow == false) {
        cout << "Tv show not found in database. Please continue..." << endl;
    }
}


void databases::Database::setMovie(movies::Movie* movie, int numMovies) {
    if(numMovies < 100) {
        _movieList[numMovies] = movie;
    }
    else {
        cout << "There are too many movies in the database, cannot add more." << endl;
    }
}


void databases::Database::setMusic(music::Music* music, int numMusic) {
    if(numMusic < 100) {
        _musicList[numMusic] = music;
    }
    else {
        cout << "There are too many tracks in the database, cannot add more." << endl;
    }
}


void databases::Database::setTvShow(tvshows::tvShow* tvShow, int numTvShows) {
    if(numTvShows < 100) {
        _tvShowList[numTvShows] = tvShow;
    }
    else {
        cout << "There are too many shows in the database, cannot add more." << endl;
    }
}


void databases::Database::addMovie(movies::Movie* addedMovie) {
    string addID;
    string addTitle;
    int addYear;
    string addGenre;
    float addRating;
    string addDirector;

    if(_numMovies < 100) {
        setMovie(addedMovie, (_numMovies++));
    }

    cout << "Please enter an ID for the new movie: ";
    cin >> addID;
    addedMovie->setId(addID);
    cout << endl;


    cout << "Please enter a title for the new movie: ";
    cin.ignore();
    getline(cin, addTitle);
    addedMovie->setTitle(addTitle);
    cout << endl;

    cout << "Please enter a year for the new movie: ";
    cin >> addYear;
    addedMovie->setYear(addYear);
    cout << endl;

    cout << "Please enter a genre for the new movie: ";
    cin.ignore();
    getline(cin, addGenre);
    addedMovie->setGenre(addGenre);
    cout << endl;

    cout << "Please enter a rating for the new movie: ";
    cin >> addRating;
    addedMovie->setRating(addRating);
    cout << endl;

    cout << "Please enter a director for the new movie: ";
    cin.ignore();
    getline(cin, addDirector);
    addedMovie->setDirector(addDirector);
    cout << endl;

    cout << "Movie successfully added to the database! Please continue...";
}


void databases::Database::addMusic(music::Music* addedMusic) {
    string addID;
    string addTitle;
    int addYear;
    string addSongComposer;
    string addSongGenre;
    int addNumTracks;
    int addTotalPlaytime;

    if(_numMusic < 100) {
        setMusic(addedMusic, (_numMusic++));
    }

    cout << "Please enter an ID for the new music: ";
    cin >> addID;
    addedMusic->setId(addID);
    cout << endl;


    cout << "Please enter a title for the new music: ";
    cin.ignore();
    getline(cin, addTitle);
    addedMusic->setTitle(addTitle);
    cout << endl;

    cout << "Please enter a year for the new music: ";
    cin >> addYear;
    addedMusic->setYear(addYear);
    cout << endl;

    cout << "Please enter a composer for the new music: ";
    cin.ignore();
    getline(cin, addSongComposer);
    addedMusic->setSongComposer(addSongComposer);
    cout << endl;

    cout << "Please enter a genre for the new music: ";
    cin.ignore();
    getline(cin, addSongGenre);
    addedMusic->setSongGenre(addSongGenre);
    cout << endl;

    cout << "Please enter a number of tracks for the new music: ";
    cin >> addNumTracks;
    addedMusic->setNumTracks(addNumTracks);
    cout << endl;

    cout << "Please enter a total playtime for the new music: ";
    cin >> addTotalPlaytime;
    addedMusic->setTotalPlaytime(addTotalPlaytime);
    cout << endl;

    cout << "Music successfully added to the database! Please continue...";
}


void databases::Database::addTvShow(tvshows::tvShow* addedTvShow) {
    string addID;
    string addTitle;
    int addYear;
    string addTvGenre;
    float addTvRating;
    int addNumEpisodes;

    if(_numTvShows < 100) {
        setTvShow(addedTvShow, (_numTvShows++));
    }

    cout << "Please enter an ID for the new show: ";
    cin >> addID;
    addedTvShow->setId(addID);
    cout << endl;


    cout << "Please enter a title for the new show: ";
    cin.ignore();
    getline(cin, addTitle);
    addedTvShow->setTitle(addTitle);
    cout << endl;

    cout << "Please enter a year for the new show: ";
    cin >> addYear;
    addedTvShow->setYear(addYear);
    cout << endl;

    cout << "Please enter a genre for the new show: ";
    cin.ignore();
    getline(cin, addTvGenre);
    addedTvShow->setTvGenre(addTvGenre);
    cout << endl;

    cout << "Please enter a rating for the new show: ";
    cin >> addTvRating;
    addedTvShow->setTvRating(addTvRating);
    cout << endl;

    cout << "Please enter a number of episodes for the new show: ";
    cin >> addNumEpisodes;
    addedTvShow->setNumEpisodes(addNumEpisodes);
    cout << endl;

    cout << "show successfully added to the database! Please continue...";
}


void databases::Database::displayMovies() {

    cout << "DISPLAYING ALL MOVIES TO THE CONSOLE:" << endl << endl;

    for(int i = 0; i < _numMovies; i++) {
        cout << "Movie: " << i + 1 << endl << "-----------------------------" << endl;
        cout << setw(4) << "ID: " << _movieList[i]->getId() << endl;
        cout << setw(5) << "TITLE: " << _movieList[i]->getTitle() << endl;
        cout << setw(5) << "YEAR: " << _movieList[i]->getYear() << endl;
        cout << setw(5) << "GENRE: " << _movieList[i]->getGenre() << endl;
        cout << setw(5) << "RATING: " << _movieList[i]->getRating() << endl;
        cout << setw(5) << "DIRECTOR: " << _movieList[i]->getDirector() << endl << endl;
    }
}


void databases::Database::displayMusic() {

    cout << "DISPLAYING ALL MUSIC TO THE CONSOLE:" << endl << endl;

    for(int i = 0; i < _numMusic; i++) {
        cout << "Music: " << i + 1 << endl << "-----------------------------" << endl;
        cout << setw(4) << "ID: " << _musicList[i]->getId() << endl;
        cout << setw(5) << "TITLE: " << _musicList[i]->getTitle() << endl;
        cout << setw(5) << "YEAR: " << _musicList[i]->getYear() << endl;
        cout << setw(5) << "COMPOSER: " << _musicList[i]->getSongComposer() << endl;
        cout << setw(5) << "GENRE: " << _musicList[i]->getSongGenre() << endl;
        cout << setw(5) << "# OF TRACKS: " << _musicList[i]->getNumTracks() << endl << endl;
        cout << setw(5) << "TOTAL PLAYTIME: " << _musicList[i]->getTotalPlaytime() << endl << endl;
    }
}


void databases::Database::displayTvShows() {

    cout << "DISPLAYING ALL TV SHOWS TO THE CONSOLE:" << endl << endl;

    for(int i = 0; i < _numTvShows; i++) {
        cout << "TV SHOW: " << i + 1 << endl << "-----------------------------" << endl;
        cout << setw(4) << "ID: " << _tvShowList[i]->getId() << endl;
        cout << setw(5) << "TITLE: " << _tvShowList[i]->getTitle() << endl;
        cout << setw(5) << "YEAR: " << _tvShowList[i]->getYear() << endl;
        cout << setw(5) << "GENRE: " << _tvShowList[i]->getTvGenre() << endl;
        cout << setw(5) << "RATING: " << _tvShowList[i]->getTvRating() << endl;
        cout << setw(5) << "# OF EPISODES: " << _tvShowList[i]->getNumEpisodes() << endl << endl;
    }
}


void databases::Database::searchMediaID(string searchID) {
    bool IDFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getId() == searchID) {
            std::cout << searchID << " has been successfully found in the movie database." << endl;
            IDFound = true;
        }
    }
    for(int i = 0; i < _numMusic; i++) {
        if(_musicList[i]->getId() == searchID) {
            std::cout << searchID << " has been successfully found in the music database." << endl;
            IDFound = true;
        }
    }
    for(int i = 0; i < _numTvShows; i++) {
        if(_tvShowList[i]->getId() == searchID) {
            std::cout << searchID << " has been successfully found in the tv show database." << endl;
            IDFound = true;
        }
    }
    if(IDFound == false) {
        cout << "ID not found in the media database" << endl;
    }
}




void databases::Database::searchMediaTitle(string searchTitle) {
    bool titleFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getTitle() == searchTitle) {
            std::cout << searchTitle << " has been successfully found in the movie database." << endl;
            titleFound = true;
        }
    }
    for(int i = 0; i < _numMusic; i++) {
        if(_musicList[i]->getTitle() == searchTitle) {
            std::cout << searchTitle << " has been successfully found in the music database." << endl;
            titleFound = true;
        }
    }
    for(int i = 0; i < _numTvShows; i++) {
        if(_tvShowList[i]->getTitle() == searchTitle) {
            std::cout << searchTitle << " has been successfully found in the tv show database." << endl;
            titleFound = true;
        }
    }
    if(titleFound == false) {
        cout << "Title not found in the media database" << endl;
    }
}


void databases::Database::searchMediaYear(int searchYear) {
    bool yearFound = false;
    for(int i = 0; i < _numMovies; i++) {
        if(_movieList[i]->getYear() == searchYear) {
            std::cout << searchYear << " has been successfully found in the movie database." << endl;
            yearFound = true;
        }
    }
    for(int i = 0; i < _numMusic; i++) {
        if(_musicList[i]->getYear() == searchYear) {
            std::cout << searchYear << " has been successfully found in the music database." << endl;
            yearFound = true;
        }
    }
    for(int i = 0; i < _numTvShows; i++) {
        if(_tvShowList[i]->getYear() == searchYear) {
            std::cout << searchYear << " has been successfully found in the tv show database." << endl;
            yearFound = true;
        }
    }
    if(yearFound == false) {
        cout << "Year not found in the media database" << endl;
    }
}


databases::Database::Database() {
    _dbId = 0;
    _dbName = " ";
    _numMovies = 0;
    initMovies();
} // Constructor




databases::Database::~Database() {
    delete this;
} // Destructor




void databases::Database::setDbId(int dbId) {
    _dbId = dbId;
} // Setters




void databases::Database::setDbName(string dbName){
    _dbName = dbName;
}


 
int databases::Database::getDbId() {
    return _dbId;
} // Getters




string databases::Database::getDbName() {
    return _dbName;
}
