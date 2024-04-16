#pragma once
#include <string>

using namespace std;

namespace media {
    class Media {
        private:
            string _id; // declaring variables in class
            string _title;
            int _year;

        public:
            Media(); // Constructor
            ~Media(); // Destructor
            
            virtual void setId(string); // Virtual Setters
            virtual void setTitle(string);
            virtual void setYear(int);

            virtual string getId(); // Virtual Getters
            virtual string getTitle();
            virtual int getYear();

            virtual string displayInfo();
    };
}