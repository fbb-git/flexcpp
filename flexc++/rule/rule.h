#ifndef INCLUDED_RULE_
#define INCLUDED_RULE_

#include <vector>
#include <string>
#include <set>

#include "../block/block.h"
#include "../pattern/pattern.h"
#include "../flextypes/flextypes.h"

class States;

class Rule: public FlexTypes
{
    friend std::ostream &operator<<(std::ostream &out, Rule const &rule);


    typedef std::pair<size_t, size_t> Pair;     // first/final state nrs.

    Pattern d_pattern;          // pattern to match for this rule.
                                // first: States start index, 
                                // second: States final index

    Block d_block;              // action block

    bool d_bol;                 // this rule is matched if starting at BOL
    bool d_viable;              // this rule is viable, i.e., it can be
                                // matched

    RuleType d_type;

    public:
        Rule() = default;               // for vector operations by Rules

        Rule(States &states, bool bol, Pattern const &pattern,
             Block const &block, RuleType type);

        Pair const &pair() const;
        size_t startState() const;
        size_t finalState() const;
        Block const &block() const;

        void setViable(bool yes);
        void setBol();

        bool bol() const;
        bool viable() const;

        std::string const &source() const;
        size_t lineNr() const;

        bool orAction() const;
        void setOrAction();
        void assignBlock(Block const &block);
        void noAction();

        bool isLopRule() const;
        RuleType type() const;

        Pattern const &pattern() const;

    private:
        void setStates(std::vector<size_t> &prePostA, 
                        States const &states, size_t begin, size_t end);
        static bool cmpAccept(size_t left, size_t right, 
                                                        States const &states);
};

inline Rule::RuleType Rule::type() const
{
    return d_type;
}


inline Pattern const &Rule::pattern() const
{
    return d_pattern;
}

inline std::string const &Rule::source() const
{
    return d_block.filename();
}

inline size_t Rule::lineNr() const
{
    return d_block.lineNr();
}

inline bool Rule::isLopRule() const
{
    return d_type == RuleType::LOP_1;
}

inline void Rule::setBol() 
{
    d_bol = true;
}

inline void Rule::setViable(bool yes) 
{
    d_viable = yes;
}

inline bool Rule::bol() const
{
    return d_bol;
}

inline bool Rule::viable() const
{
    return d_viable;
}

inline Rule::Pair const &Rule::pair() const
{
    return d_pattern.pair();
}

inline size_t Rule::startState() const
{
    return d_pattern.pair().first;
}

inline size_t Rule::finalState() const
{
    return d_pattern.pair().second;
}

inline Block const &Rule::block() const
{
    return d_block;
}

inline void Rule::assignBlock(Block const &block)
{
    d_block = block;    
}

inline bool Rule::orAction() const
{
    return d_block.orAction();
}

inline void Rule::setOrAction()
{
    return d_block.setOrAction();
}

inline void Rule::noAction()
{
    d_block.clear();
}

#endif
