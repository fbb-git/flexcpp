#ifndef INCLUDED_DFAS_
#define INCLUDED_DFAS_

#include <string>
#include <vector>
#include <iosfwd>

#include "../rules/rules.h"

class States;
class Ranges;
class DFA;
    
class DFAs
{
    friend std::ostream &operator<<(std::ostream &out, DFAs const &dfas);

    public:
        typedef std::pair<std::string, DFA *> Pair;
        typedef std::vector<Pair> DFAInfo;

    private:
        DFAInfo d_dfa;
    
        Rules &d_rules;
        States &d_states;
        Ranges &d_ranges;
        
    public:
        DFAs(Rules &rules, States &states, Ranges &ranges);
        ~DFAs();

        void build();
        DFAInfo::const_iterator begin() const;
        DFAInfo::const_iterator end() const;
        DFAInfo::const_iterator find(std::string const &key) const;

    private:
};

inline DFAs::DFAInfo::const_iterator DFAs::begin() const
{
    return d_dfa.begin();
}

inline DFAs::DFAInfo::const_iterator DFAs::end() const
{
    return d_dfa.end();
}
        
#endif




