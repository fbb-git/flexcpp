#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <vector>
#include <set>

class DFARow;
class Rules;
class States;

class DFA
{
    std::vector<DFARow> d_row;
    typedef std::set<size_t> StateSet;

    public:
        DFA();

        void build(std::vector<size_t> const &active, 
                   States const &states, Rules const &rules, size_t nRanges);

    private:
        static void fillStartSet(size_t idx, Rules const &rules, 
                                                        StateSet &start);
};

#endif
