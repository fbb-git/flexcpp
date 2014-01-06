#ifndef INCLUDED_PATTERN_
#define INCLUDED_PATTERN_

#include <memory>
#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "../flextypes/flextypes.h"
#include "../states/states.h"

class CharClass;
class Interval;

class Pattern: private FlexTypes
{
    typedef std::pair<size_t, size_t> Pair;

    typedef std::unordered_map<size_t, size_t> Map;
    typedef std::vector<Pair> PairVector;

    Pair d_pair;
    std::shared_ptr<Pattern> d_lopRhs;

    public:
        Pattern(Pair const &pair = Pair{0, 0});
        Pattern(Pattern const &lhs, Pattern const &rhs);    // lop pattern

//        ~Pattern();

        Pattern &operator=(Pattern const &other) = default;
        Pattern &operator=(Pair const &pair);

        size_t begin() const;                       // pattern's first state
        size_t end() const;                         // pattern's last state
        Pair const &pair() const;                   // {begin, end}
        Pattern const *rhs() const;                 // 0 or LOP's rhs

        bool canBeEmpty(States const &states) const;// true if there's an
                                                    // empty transition from
                                                    // begin -> end

        Pattern duplicate(States &states) const;
                                                    // duplicate the states 
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

        static Pattern lop(Pattern const &lhs, Pattern const &rhs);
        bool isLopPattern() const;

    private:
        static size_t dup(Map &indexMap, States &states, size_t index);

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

inline size_t Pattern::begin() const
{
    return d_pair.first;
}

inline size_t Pattern::end() const
{
    return d_pair.second;
}

inline Pattern::Pair const &Pattern::pair() const
{
    return d_pair;
}

inline Pattern const *Pattern::rhs() const
{
    return d_lopRhs.get();
}

inline bool Pattern::isLopPattern() const
{
    return d_lopRhs != 0;
}

#endif

