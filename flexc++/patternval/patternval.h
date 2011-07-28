#ifndef INCLUDED_PATTERNVAL_
#define INCLUDED_PATTERNVAL_

#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "../semval/semval.h"
#include "../states/states.h"

class PatternVal: public SemVal
{
    typedef std::unordered_map<size_t, size_t> Map;
    typedef std::vector<States::Pair> PairVector;

    States::Pair d_pair;

    public:
        PatternVal() = default;
        PatternVal(States::Pair const &pair);

        size_t begin() const;
        size_t end() const;
        States::Pair const &pair() const;

        static spSemVal charSet(States &states, SemVal const &charClass);
        static spSemVal concatenate(States &states, SemVal &lhs, SemVal &rhs);
        static spSemVal dot(States &states);
        static spSemVal eof(States &states);
        static spSemVal interval(States &states, SemVal &pat, size_t lower, 
                                                                size_t upper);
        static spSemVal opOr(States &states, SemVal &lhs, SemVal &rhs);
        static spSemVal plain(States &states, size_t ch);
        static spSemVal plain(States &states, std::string const &ch);
        static spSemVal quantifier(States &states, SemVal &pat, size_t type);
        static spSemVal str(States &states, std::string const &str);

    private:
        static spSemVal star(States &states, SemVal &pattern);
        static spSemVal plus(States &states, SemVal &pattern);
        static spSemVal questionMark(States &states, SemVal &pattern);

        static size_t patternCopy(States &states, size_t begin, size_t end);

        static void copyStates(States &states, 
                        std::unordered_map<size_t, size_t> const &old2new);
        static void copyState(std::pair<size_t, size_t> const &fromTo, 
                       std::unordered_map<size_t, size_t> const &old2new,
                       States &states);
//////////
        static spSemVal copy(States &states, SemVal &semval, size_t lower, 
                                                        size_t upper);
        static void copyPattern(States &states, size_t count, PairVector &pv);
        static void copyPattern(States &states, size_t lower, size_t upper,
                                                Map &eject, PairVector &pv);

        static size_t dupPattern(Map &map, States &states, size_t idx);

        static spSemVal optRepeatLastPattern(States &states, 
                                                PatternVal &pattern,
                                                size_t lower, 
                                                PairVector &beginEnd);
        static spSemVal optionalPatterns(States &states, PatternVal &pattern,
                                    size_t lower, size_t upper, 
                                    PairVector &beginEnd);
        static void jumpToEnd(States &states, PairVector &beginEnd, 
                                    size_t lower, size_t upper, Map &eject);
        static void join(States &states, PatternVal &pattern, size_t upper,
                                                PairVector const &beginEnd);
};
        
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




