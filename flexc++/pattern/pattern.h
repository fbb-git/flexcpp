#ifndef INCLUDED_PATTERN_
#define INCLUDED_PATTERN_

#include <memory>
#include <iosfwd>
#include <vector>

#include <bobcat/linearmap>

#include "../flextypes/flextypes.h"

class CharClass;
class Interval;
class States;

class Pattern: private FlexTypes
{
        typedef FBB::LinearMap<size_t, size_t>  Map;
        typedef std::pair<size_t, size_t>           Pair;
        typedef std::vector<Pair>                   PairVector;

    struct LopData;
    std::shared_ptr<LopData> d_lopData;

    Pair d_pair;

    static size_t const s_max = -1;
    size_t d_length = s_max;        // if fixed: the length of the pattern 
                                    // otherwise s_max

    public:
        Pattern(Pair const &pair = Pair{0, 0});

        Pattern(States &states,                     // 2: lop pattern
                Pattern const &lhs, Pattern const &rhs,     
                                    size_t lopStartCondition);    

        Pattern(States &states,                     // 3: lop pattern,
                size_t tailLength,                  // having fixed sized tail.
                Pattern const &lhs, Pattern const &rhs);    

        Pattern &operator=(Pattern const &other) = default;
        Pattern &operator=(Pair const &pair);

        size_t begin() const;                       // pattern's first state
        size_t end() const;                         // pattern's last state
        Pair const &pair() const;                   // {begin, end}
        Pair rhsPair() const;                       // LOP's rhs's states
        Pattern const &lhs() const;                 // LOP's lhs duplicate

        bool canBeEmpty(States const &states) const;// true if there's an
                                                    // empty transition from
                                                    // begin -> end or if the
                                                    // Pattern has a fixed
                                                    // length of 0.

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

        RuleType type() const;
        bool fixedLength() const;
        size_t length() const;          // if fixedLength() the length of the
                                        // text matched by this pattern

        size_t scIndex() const;         // 1st SC index of a LOP rule
                                        // (undefined behavior if called 
                                        //  for non-LOP rules)
        size_t lopTailLength() const;   // length of a fixed tail of a LOP
                                        // rule as retrieved by
                                        // Generator::actions 

    private:
        Pattern duplicate(States &states) const;    // return Pattern which
                                                    // duplicates (new copy)
                                                    // the states of `this'
                                                    // pattern.

        static bool empty(States const &states, size_t idx);

        static Pattern star(States &states, Pattern const &pattern);
        static Pattern plus(States &states, Pattern const &pattern);
        static Pattern questionMark(States &states, 
                                       Pattern const &pattern);

        // lower and upper are the lower and upper limits of an Interval
        static Pattern copy(States &states, 
                                Pattern &pattern, 
                                size_t lower, size_t upper);

        static void copyPattern(States &states, size_t count, PairVector &pv);
        static void copyPattern(States &states, size_t lower, size_t upper,
                                                Map &eject, PairVector &pv);

            // used by copyPattern
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
    size_t scOrLength;              // Start condition index, or tail length
                                    // for fixed-sized tail LOP rules
    size_t mid;                     // begin of the RHS pattern in d_pair
                                    // or 0, in which case scOrLength
                                    // is the length of the fixed-sized 
                                    // LOP rhs pattern's tail
    Pattern lhs;                    // duplicate of the LHS pattern or an
                                    // empty pattern with fixed-sized LOP
                                    // rules 
};

inline Pattern const &Pattern::lhs() const
{
    return d_lopData->lhs;
}

inline size_t Pattern::scIndex() const
{
    return d_lopData->scOrLength;
}

inline size_t Pattern::lopTailLength() const
{
    return d_lopData->scOrLength;
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

inline Pattern::RuleType Pattern::type() const
{
    return d_lopData == 0 ?         RuleType::NORMAL :
           d_lopData->mid == 0 ?    RuleType::LOP_FIXED :
                                    RuleType::LOP_1;
}

inline bool Pattern::fixedLength() const
{
    return d_length != s_max;
}

inline size_t Pattern::length() const
{
    return d_length;
}

#endif

