#pragma once

#include "media.h"

#include <string>

namespace music {
    class Music : public media::Media {
        private:
            string _songComposer;
            string _songGenre;
            int _numTracks;
            int _totalPlaytime;
        public:
            Music();
            ~Music();

            void setSongComposer(string);
            void setSongGenre(string);
            void setNumTracks(int);
            void setTotalPlaytime(int);

            string getSongComposer();
            string getSongGenre();
            int getNumTracks();
            int getTotalPlaytime();
    };
}