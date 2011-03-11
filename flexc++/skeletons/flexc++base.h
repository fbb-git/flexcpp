#ifndef \@BASE_H_INCLUDED
#define \@BASE_H_INCLUDED

#include <iosfwd>
#include <queue>
#include <string>
#include <vector>

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
        size_t d_lastRead;                  // last read character

        public:
            Input(std::istream &iStream);
            size_t get();                   // the next range
            
        private:
            size_t nextChar();             // obtain the next character
    };

    size_t          d_state;
    std::ostream   *d_out;              // ptr for easy stream switching
$insert 4 declarations
    static size_t  const s_ranges[];
    static int     const s_finAc[][4];

    protected:
        enum Result
        {
            EXHAUSTED,              // all input exhausted
            CONTINUE,               // transition succeeded, go on
            MATCH,                  // matched a rule
            UNDEFINED               // no continuation from here
        };

        Input           d_input;
    

    public:
        enum StartCondition {
$insert 12 startCondNames
        };

    private:
        StartCondition d_currentStartCondition;

    protected:
        \@Base();
        \@Base(std::istream &iStream);
        Result transition(size_t range);
        void echoFirst();
        int matched();
};

$insert namespace-close

#endif //  \@BASE_H_INCLUDED




