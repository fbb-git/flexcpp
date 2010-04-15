#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <vector>
#include <string>
#include <set>

class Rules;
class States;

#include "../dfarow/dfarow.h"

class DFA
{
    std::vector<DFARow> d_row;
    typedef std::set<size_t> StateSet;

    public:
        DFA();

        void build(std::string const &ruleSet, Rules const &rules, 
                   States const &states, size_t nRanges);

    private:
        static void fillStartSet(size_t idx, Rules const &rules, 
                                             StateSet &start);
};

#endif
