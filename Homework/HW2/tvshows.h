#pragma once
#include "media.h"

#include <string>

namespace tvshows {
    class tvShow : public media::Media {
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