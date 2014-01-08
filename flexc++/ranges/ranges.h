#ifndef INCLUDED_USAGE_
#define INCLUDED_USAGE_

#include <string>
#include <vector>
#include <set>

#include <bobcat/fswap>

#include "../flextypes/flextypes.h"

class States;
class State;
class StateData;

// After computing the ranges (after determineSubsets and finalizeStates) the
// indices of d_alphabet refer to the characters of the input alphabet and
// their values refer to the subset (the range) to which the character
// belongs.  if adjacent indices have identical values then they belong to the
// same character set.

class Ranges: private FlexTypes
{
    friend std::ostream &operator<<(std::ostream &out, Ranges const &ranges);

    size_t *d_alphabet;       // all (by default) 256 characters
    size_t d_alphabetSize;

    size_t d_nRanges;
    size_t d_bol;           // nrs for EOF__ and BOL
    size_t d_eof;
    States &d_states;


    bool *d_usedRanges;           // ranges used in the DFA's
    
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
                                    // d_alphabet. 

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

        void clearUsedRanges();
        bool usedRange(size_t rangeNr) const;
        void useRange(size_t rangeNr);
        size_t nUsedRanges() const;

        size_t nRanges() const;
        size_t const *alphabet() const;

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

inline size_t Ranges::nRanges() const
{
    return d_nRanges;
}

inline size_t const *Ranges::alphabet() const
{
    return d_alphabet;
}

inline size_t Ranges::rangeOf(char ch) const
{
    return d_alphabet[static_cast<unsigned char>(ch)];
}

inline size_t Ranges::rangeOfBOL() const
{
    return d_bol;
}

inline size_t Ranges::rangeOfEOF() const
{
    return d_eof;
}

inline bool Ranges::usedRange(size_t rangeNr) const
{
    return d_usedRanges[rangeNr - 1];
}

inline void Ranges::useRange(size_t rangeNr)
{
    d_usedRanges[rangeNr - 1] = true;
}

std::ostream &operator<<(std::ostream &out, Ranges const &ranges);

#endif
