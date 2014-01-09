#ifndef INCLUDED_PATTERN_
#define INCLUDED_PATTERN_

#include <memory>
#include <iosfwd>
#include <unordered_map>
#include <vector>

#include "../flextypes/flextypes.h"

class CharClass;
class Interval;
class States;

class Pattern: private FlexTypes
{
    typedef std::pair<size_t, size_t> Pair;

    typedef std::unordered_map<size_t, size_t> Map;
    typedef std::vector<Pair> PairVector;

    struct LopData;
    std::shared_ptr<LopData> d_lopData;

    Pair d_pair;

    public:
        Pattern(Pair const &pair = Pair{0, 0});
        Pattern(States &states,                     // lop pattern
                Pattern const &lhs, Pattern const &rhs,     
                                    size_t lopStartCondition);    

        Pattern &operator=(Pattern const &other) = default;
        Pattern &operator=(Pair const &pair);

        size_t begin() const;                       // pattern's first state
        size_t end() const;                         // pattern's last state
        Pair const &pair() const;                   // {begin, end}
        Pair rhsPair() const;                       // LOP's rhs's states

        bool canBeEmpty(States const &states) const;// true if there's an
                                                    // empty transition from
                                                    // begin -> end

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

        bool isLopPattern() const;
        size_t scIndex() const;         // 1st SC index of a LOP rule
                                        // (undefined behavior if called 
                                        //  for non-LOP rules)

    private:
        Pattern duplicate(States &states) const;    // return Pattern which
                                                    // duplicates (new copy)
                                                    // the states of `this'
                                                    // pattern.

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

struct Pattern::LopData
{
    size_t startCondition;
    size_t mid;                     // begin of the RHS pattern in d_pair
    Pattern lhs;                    // duplicate of the LHS pattern
};

inline size_t Pattern::scIndex() const
{
    return d_lopData->startCondition;
}

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

inline Pattern::Pair Pattern::rhsPair() const
{
    return Pair(d_lopData->mid, d_pair.second);
}

inline bool Pattern::isLopPattern() const
{
    return d_lopData != 0;
}

#endif

