#pragma once
#include <string>
using namespace std;

namespace movies {
    class Movie { 
        private: // declaring variables in class
            string _id;
            string _title;
            int _year; 
            string _genre; 
            float _rating; 
            string _director;

        public:
            Movie();
            ~Movie();

            string getId();
            string getTitle();
            int getYear();
            string getGenre();
            float getRating();
            string getDirector();

            string setId(string);
            string setTitle(string);
            int setYear(int);
            string setGenre(string);
            float setRating(float);
            string setDirector(string);
    };
}