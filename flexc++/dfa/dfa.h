#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <vector>

class Rules;
class DFA
{
    std::vector<DFARow> d_row;
    public:
        DFA();

        build(Rules const &rules, std::vector<size_t> const &active)
    private:
};
        
#endif
