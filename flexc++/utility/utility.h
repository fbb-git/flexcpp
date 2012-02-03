#ifndef INCLUDED_UTILITY_
#define INCLUDED_UTILITY_

template <int value>
struct Int
{};

template <typename type>
struct Type
{};

struct DataType         // data types used by semunion: these names are 
{                       // directly available from within classes inheriting
    enum Symbol         // from DataType
    {
        INT,
        TEXT,   
        PATTERN,
        CHARCLASS,
        INTERVAL,
    };
};


#endif

