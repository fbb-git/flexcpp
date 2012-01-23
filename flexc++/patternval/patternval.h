#ifndef INCLUDED_PATTERNVAL_
#define INCLUDED_PATTERNVAL_

#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "../states/states.h"

class CharClass;

class PatternVal
{
    typedef std::unordered_map<size_t, size_t> Map;
    typedef std::vector<States::Pair> PairVector;

    States::Pair d_pair;

    public:
        PatternVal(States::Pair const &pair = {0, 0});

        PatternVal &operator=(PatternVal const &other) = default;
        PatternVal &operator=(States::Pair const &pair);

        size_t begin() const;
        size_t end() const;
        States::Pair const &pair() const;

        static PatternVal eof(States &states);
        static PatternVal escape(States &states, std::string const &ch);
        static PatternVal rawText(States &states, std::string const &str);
        static PatternVal dot(States &states);
        static PatternVal concatenate(States &states, PatternVal const &lhs,
                                                      PatternVal const &rhs);
        static PatternVal alternatives(States &states, PatternVal const &lhs, 
                                                       PatternVal const &rhs);
        static PatternVal quantifier(States &states, PatternVal const &pat, 
                                     size_t type);

//        static PatternVal charSet(States &states, CharClass const &charClass);
//        static PatternVal interval(States &states, PatternVal const &pat, 
//                                                size_t lower, size_t upper);
//        static PatternVal plain(States &states, size_t ch);

    private:
        static PatternVal star(States &states, PatternVal const &pattern);
        static PatternVal plus(States &states, PatternVal const &pattern);
        static PatternVal questionMark(States &states, 
                                       PatternVal const &pattern);

//        static PatternVal copy(States &states, PatternVal const &semval, size_t lower, 
//                                                        size_t upper);
//        static void copyPattern(States &states, size_t count, PairVector &pv);
//        static void copyPattern(States &states, size_t lower, size_t upper,
//                                                Map &eject, PairVector &pv);
//
//        static size_t dupPattern(Map &map, States &states, size_t idx);
//
//        static PatternVal optRepeatLastPattern(States &states, 
//                                                PatternVal &pattern,
//                                                size_t lower, 
//                                                PairVector &beginEnd);
//        static PatternVal optionalPatterns(States &states, PatternVal &pattern,
//                                    size_t lower, size_t upper, 
//                                    PairVector &beginEnd);
//        static void jumpToEnd(States &states, PairVector &beginEnd, 
//                                    size_t lower, size_t upper, Map &eject);
//        static void join(States &states, PatternVal &pattern, size_t upper,
//                                                PairVector const &beginEnd);
};

inline PatternVal &PatternVal::operator=(States::Pair const &pair)
{
    d_pair = pair;
    return *this;
}
        
inline size_t PatternVal::begin() const
{
    return d_pair.first;
}

inline size_t PatternVal::end() const
{
    return d_pair.second;
}

inline States::Pair const &PatternVal::pair() const
{
    return d_pair;
}

#endif




