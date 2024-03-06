#pragma once
#include <string>
using namespace std;

namespace movies {
    class Movie { 
        private: // declaring variables in class string _id;
            string _title; 
            int _year; 
            string _genre; 
            float _rating; 
            string _director;

            public:
            Movie();
            ~Movie();
            
        };
}