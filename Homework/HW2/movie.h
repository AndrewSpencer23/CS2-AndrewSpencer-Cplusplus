#pragma once
#include "media.h"

#include <string>

using namespace std;

namespace movies {
    class Movie : private media::Media { 
        private:
            string _genre; 
            float _rating; 
            string _director;

        public:
            Movie(); // Constructor
            ~Movie(); // Destructor

            void setGenre(string);
            void setRating(float);
            void setDirector(string);

            string getGenre();
            float getRating();
            string getDirector();
    };
}