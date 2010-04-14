#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <vector>
#include <set>

class DFARow;
class Rules;
class States;

class DFA
{
    States const &d_states;

    std::vector<DFARow> d_row;
    typedef std::set<size_t> StateSet;

    public:
        DFA(States const &states);

        void build(std::vector<size_t> const &active, Rules const &rules);

    private:
        static void fillStartSet(size_t idx, Rules const &rules, 
                                                        StateSet &start);
        StateSet eClosure(StateSet &current);
};

#endif
