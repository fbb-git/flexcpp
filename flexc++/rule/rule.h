#ifndef INCLUDED_RULE_
#define INCLUDED_RULE_

#include <vector>
#include <string>
#include <set>

#include "../block/block.h"

class States;

class Rule
{
    friend std::ostream &operator<<(std::ostream &out, Rule const &rule);


    typedef std::pair<size_t, size_t> Pair;     // first/final state nrs.

    size_t d_start;             // index in States
    size_t d_final;             // index in States

    Block d_block;              // action block

    bool d_bol;                 // this rule is matched if starting at BOL
    bool d_viable;              // this rule is viable, i.e., it can be
                                // matched

    std::string d_source;       // context of the rule: source and lineNr
    size_t      d_lineNr;

    public:
        Rule() = default;               // for vector operations by Rules
        Rule(States const &states, bool bol, Pair fstfin, Block const &block,
             std::string const &source, size_t lineNr);

        size_t startState() const;
        size_t finalState() const;
        Block const &block() const;

        void setViable(bool yes);
        void setBol();

        bool bol() const;
        bool viable() const;

        std::string const &source() const;
        size_t lineNr() const;
        
    private:
        void setStates(std::vector<size_t> &prePostA, 
                        States const &states, size_t begin, size_t end);
        static bool cmpAccept(size_t left, size_t right, 
                                                        States const &states);
};

inline std::string const &Rule::source() const
{
    return d_source;
}

inline size_t Rule::lineNr() const
{
    return d_lineNr;
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

inline size_t Rule::startState() const
{
    return d_start;
}

inline size_t Rule::finalState() const
{
    return d_final;
}

inline Block const &Rule::block() const
{
    return d_block;
}

#endif














