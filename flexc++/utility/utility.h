#ifndef INCLUDED_UTILITY_
#define INCLUDED_UTILITY_

template <int tp>
struct Int
{};

struct DataType         // data types used by semunion: these names are 
{                       // directly available from within classes inheriting
    enum                // from DataType
    {
        INT,
        TEXT,   
        PATTERNVAL,
        CHARCLASS
    };
};


#endif

