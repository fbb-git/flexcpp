#ifndef INCLUDED_PATTERN_
#define INCLUDED_PATTERN_

#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "../flextypes/flextypes.h"
#include "../states/states.h"

class CharClass;
class Interval;

class Pattern: private FlexTypes
{
    typedef std::unordered_map<size_t, size_t> Map;
    typedef std::vector<States::Pair> PairVector;

    States::Pair d_pair;

    public:
        Pattern(States::Pair const &pair = States::Pair{0, 0});

        Pattern &operator=(Pattern const &other) = default;
        Pattern &operator=(States::Pair const &pair);

        size_t begin() const;                       // pattern's first state
        size_t end() const;                         // pattern's last state
        States::Pair const &pair() const;           // {begin, end}
        bool canBeEmpty(States const &states) const;// true if there's an
                                                    // empty transition from
                                                    // begin -> end
        void duplicate(Pattern const &src);         // duplicate the states 
                                                    // used by src, and store
                                                    // their begin/end at this
        static Pattern eof(States &states);
        static Pattern escape(States &states, std::string const &ch);
        static Pattern rawText(States &states, std::string const &str);
        static Pattern dot(States &states);
        static Pattern concatenate(States &states, Pattern const &lhs,
                                                      Pattern const &rhs);
        static Pattern alternatives(States &states, Pattern const &lhs, 
                                                       Pattern const &rhs);
        static Pattern quantifier(States &states, Pattern const &pat, 
                                     size_t type);
        static Pattern interval(States &states, Pattern &regex, 
                                                   Interval const &interval);
        static Pattern characterClass(States &states, 
                                      CharClass const &charClass);
    private:
        static Pattern star(States &states, Pattern const &pattern);
        static Pattern plus(States &states, Pattern const &pattern);
        static Pattern questionMark(States &states, 
                                       Pattern const &pattern);

        static Pattern copy(States &states, 
                                Pattern &pattern, 
                                size_t lower, size_t upper);

        static void copyPattern(States &states, size_t count, PairVector &pv);
        static void copyPattern(States &states, size_t lower, size_t upper,
                                                Map &eject, PairVector &pv);

        static size_t dupPattern(Map &map, States &states, size_t idx);

        static Pattern optRepeatLastPattern(States &states, 
                                               Pattern &regex,
                                               size_t lower, 
                                               PairVector &beginEnd);
        static Pattern optionalPatterns(States &states, 
                            Pattern &pattern, 
                            size_t lower, size_t upper, 
                            PairVector &beginEnd);
        static void jumpToEnd(States &states, PairVector &beginEnd, 
                              size_t lower, size_t upper, Map &eject);
        static void join(States &states, Pattern &pattern, size_t upper,
                                         PairVector const &beginEnd);
};

inline Pattern &Pattern::operator=(States::Pair const &pair)
{
    d_pair = pair;
    return *this;
}
        
inline size_t Pattern::begin() const
{
    return d_pair.first;
}

inline size_t Pattern::end() const
{
    return d_pair.second;
}

inline States::Pair const &Pattern::pair() const
{
    return d_pair;
}

#endif

