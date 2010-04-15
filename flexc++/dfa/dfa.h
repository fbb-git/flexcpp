#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <iosfwd>
#include <vector>
#include <string>
#include <set>

class Rules;
class States;

#include "../dfarow/dfarow.h"

class DFA
{
    friend std::ostream &operator<<(std::ostream & out, DFA const &dfa);

    size_t d_nRanges;

    std::vector<DFARow> d_row;
    typedef std::set<size_t> StateSet;

    public:
        DFA(size_t nRanges);

        void build(std::string const &ruleSet, Rules const &rules, 
                   States const &states);

    private:
        static void fillStartSet(size_t idx, Rules const &rules, 
                                             StateSet &start);
};


#endif
