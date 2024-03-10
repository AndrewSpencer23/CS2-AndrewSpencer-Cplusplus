#pragma once

#include <string>

using namespace std;

namespace movies {
    class Movie { 
        private:
            string _id; // declaring variables in class
            string _title;
            int _year; 
            string _genre; 
            float _rating; 
            string _director;

        public:
            Movie(); // Constructor
            ~Movie(); // Destructor

            string getId(); // Getters
            string getTitle();
            int getYear();
            string getGenre();
            float getRating();
            string getDirector();

            void setId(string); // Setters
            void setTitle(string);
            void setYear(int);
            void setGenre(string);
            void setRating(float);
            void setDirector(string);
    };
}