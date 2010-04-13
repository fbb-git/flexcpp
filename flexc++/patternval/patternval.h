#ifndef INCLUDED_PATTERNVAL_
#define INCLUDED_PATTERNVAL_

#include <iosfwd>
#include <unordered_map>

#include "../semval/semval.h"
#include "../states/states.h"

class PatternVal: public SemVal
{
    States::Pair d_pair;

    public:
        PatternVal() = default;
        PatternVal(States::Pair const &pair);

        size_t begin() const;
        size_t end() const;

        static spSemVal eof(States &states);
        static spSemVal str(States &states, State::Type type,
                            std::string const &str);
        static spSemVal str(States &states, State::Type type,
                            SemVal const &charClass);
        static spSemVal plain(States &states, size_t ch);
        static spSemVal plain(States &states, std::string const &ch);
        static spSemVal concatenate(States &states, SemVal &lhs, SemVal &rhs);
        static spSemVal bol(States &states, SemVal &pattern);
        static spSemVal opOr(States &states, SemVal &lhs, SemVal &rhs);
        static spSemVal quantifier(States &states, SemVal &pat, size_t type);
        static spSemVal interval(States &states, SemVal &pat, size_t lower,
                                                              size_t upper);

    private:
        static spSemVal star(States &states, SemVal &pattern);
        static spSemVal plus(States &states, SemVal &pattern);
        static spSemVal questionMark(States &states, SemVal &pattern);

        static size_t patternCopy(States &states, size_t begin, size_t end);
        static void exitPath(size_t from, States &states, size_t to);
        static void add(States &states, 
                        std::unordered_map<size_t, size_t> &old2new, 
                        size_t idx);
        static spSemVal copy(States &states, SemVal &semval, size_t lower, 
                                                             size_t upper);
        static void copyStates(States &states, 
                        std::unordered_map<size_t, size_t> const &old2new);
        static void copyState(std::pair<size_t, size_t> const &fromTo, 
                       std::unordered_map<size_t, size_t> const &old2new,
                       States &states);
};
        
inline size_t PatternVal::begin() const
{
    return d_pair.first;
}

inline size_t PatternVal::end() const
{
    return d_pair.second;
}

#endif




