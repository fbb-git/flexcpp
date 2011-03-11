#ifndef \@BASE_H_INCLUDED
#define \@BASE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <queue>

$insert namespace-open

// ScannerBase

class \@Base
{
        // encapsulate all Input operations. The member get returns the next
        // input range number
    class Input
    {
        enum 
        {
            AT_EOF = ~0U
        };
        
        std::queue<unsigned char> d_queue;  // pending input chars
        std::istream *d_in;                 //  ptr for easy streamswitching
        bool d_returnBOL;                   // initially true
        std::string d_readBuffer;
        size_t d_lastChar;                  // last read character

        public:
            size_t get();                   // the next range

        private:
            size_t nextChar();             // obtain the next character
    };

    class Transition
    {
        public:
            enum Result
            {
                EXHAUSTED,              // all input exhausted
                CONTINUE,               // transition succeeded, go on
                MATCH,                  // matched a rule
                UNDEFINED               // no continuation from here
            };

            Result operator[](size_t range);
    };

    std::ostream *d_out;                // ptr for easy stream switching
    Input d_input;
    Transition d_transition;

    public:
        enum StartCondition {
$insert startCondNames
        };

    private:
        StartCondition d_currentStartCondition;


};

$insert namespace-close

#endif //  \@BASE_H_INCLUDED
