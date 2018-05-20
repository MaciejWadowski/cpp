//
// Created by wadziuxxx on 5/19/18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H


#include <iosfwd>
#include <iostream>
#include <regex>
#include <algorithm>
#include <initializer_list>
#include <sstream>
#include <stdexcept>

namespace moviesubs{

    class MovieSubtitlesErrorCases : public std::invalid_argument{
    public:
        MovieSubtitlesErrorCases(const std::string &message, const std::string &line);
    };

    class NegativeFrameAfterShift : public MovieSubtitlesErrorCases{
    public:
        NegativeFrameAfterShift(const std::string &message, const std::string &num);
    };

    class SubtitleEndBeforeStart : public MovieSubtitlesErrorCases{
    public:
        SubtitleEndBeforeStart(const std::string &message, const std::string &line);

        int LineAt()const;

    private:
        int num;
    };

    class MissingTimeSpecification : public MovieSubtitlesErrorCases{
    public:
        MissingTimeSpecification(const std::string &message, const std::string &line);
    };

    class OutOfOrderFrames : public MovieSubtitlesErrorCases{
    public:
        OutOfOrderFrames(const std::string &message, const std::string &line);
    };

    class InvalidSubtitleLineFormat : public MovieSubtitlesErrorCases{
    public:
        InvalidSubtitleLineFormat(const std::string &message, const std::string &line);
    };

    class MovieSubtitles{
    public:

        MovieSubtitles() = default;

        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) = 0;
    };

    class MicroDvdSubtitles : public MovieSubtitles{
    public:

        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;

    };

    class  SubRipSubtitles : public MovieSubtitles{
    public:

        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) override;

    };

}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
