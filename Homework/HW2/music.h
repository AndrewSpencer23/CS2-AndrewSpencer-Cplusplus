#pragma once

#include "media.h"

#include <string>

namespace music {
    class Music : public media::Media {
        private:
            string _songComposer;
            string _songGenre;
            int _numTracks;
            float _totalPlaytime;
        public:
            Music();
            ~Music();

            void setSongComposer(string);
            void setSongGenre(string);
            void setNumTracks(int);
            void setTotalPlaytime(float);

            string getSongComposer();
            string getSongGenre();
            int getNumTracks();
            float getTotalPlaytime();
    };
}