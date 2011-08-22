#ifndef INCLUDED_USAGE_
#define INCLUDED_USAGE_

#include <string>
#include <vector>
#include <set>

#include <bobcat/fswap>

class States;
class State;
class StateData;

class Ranges
{
    friend std::ostream &operator<<(std::ostream &out, Ranges const &ranges);

    size_t *d_ranges;       // all (by default) 256 characters
    size_t d_size;

    size_t d_subsets;
    size_t d_bol;           // nrs for EOF__ and BOL
    size_t d_eof;
    States &d_states;
    bool *d_used;           // ranges used in the DFA's
    
    public:
        Ranges(States &states, size_t size = 256);  // default:   
                                                    // 1 << (sizeof(char) * 8)
        Ranges(Ranges const &other);
        Ranges(Ranges &&tmp);
        ~Ranges();

        Ranges &operator=(Ranges const &other);
        Ranges &operator=(Ranges &&tmp);

        void swap(Ranges &other);

        void determineSubsets();    // determine the ranges for chars in
                                    // d_ranges. 

        void finalizeStates();      // all chars, strings and sets are 
                                    // converted to character sets.
                                    // there can be at most 256 character sets
                                    // (one for each character) so there's no
                                    // collision with the special characters
                                    // like EMPTY and FINAL.

        size_t rangeOf(char ch) const;
        size_t rangeOfBOL() const;
        size_t rangeOfEOF() const;

        void add(std::string const &str);
        void add(size_t ch);

        void clearUsed();
        bool used(size_t rangeNr) const;
        void setUsed(size_t rangeNr);
        size_t nUsed() const;

        size_t size() const;
        size_t const *ranges() const;
        
    private:
        static bool collision(std::string const &str, size_t const *next);
        static bool chCollision(unsigned char ch, unsigned char &pre, 
                                                        size_t const *next);
        static void countRanges(size_t &count, std::vector<size_t> &ranges);


        void update(std::string const &str, size_t const *next);
        void subsetCount();
        static void reassign(size_t &count, std::vector<size_t> &ranges);

        void inspectState(State const &state);
        void finalizeState(State &state);

        static void charsetToRanges(StateData &data, size_t *ranges);
        static void outChar(std::ostream &out, size_t idx);
};

inline void Ranges::swap(Ranges &other)
{
    FBB::fswap(*this, other);
}

inline size_t Ranges::size() const
{
    return d_subsets;
}

inline size_t const *Ranges::ranges() const
{
    return d_ranges;
}

inline size_t Ranges::rangeOf(char ch) const
{
    return d_ranges[static_cast<unsigned char>(ch)];
}

inline size_t Ranges::rangeOfBOL() const
{
    return d_bol;
}

inline size_t Ranges::rangeOfEOF() const
{
    return d_eof;
}

inline bool Ranges::used(size_t rangeNr) const
{
    return d_used[rangeNr - 1];
}

inline void Ranges::setUsed(size_t rangeNr)
{
    d_used[rangeNr - 1] = true;
}

std::ostream &operator<<(std::ostream &out, Ranges const &ranges);

#endif
