#pragma once
#include "tvshows.h"
#include "media.h"

#include <string>

namespace tvshows {
    class tvShow : media::Media {
        private:
            string _tvGenre;
            float _tvRating;
            int _numEpisodes;
    
        public:
            tvShow();
            ~tvShow();

            void setTvGenre(string);
            void setTvRating(float);
            void setNumEpisodes(int);
            
            string getTvGenre();
            float getTvRating();
            int getNumEpisodes();
    };
}