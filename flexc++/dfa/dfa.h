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

    Ranges *d_ranges;

    std::vector<DFARow> d_row;
    typedef std::set<size_t> StateSet;

    public:
        DFA();
        DFA(Ranges &ranges);

        void build(std::vector<size_t> const &active, Rules const &rules, 
                   States &states);

        std::vector<DFARow>::const_iterator begin() const;
        std::vector<DFARow>::const_iterator end() const;

        size_t size() const;

    private:
        void processLArules();

        static void processLArule(LARule const &laRule, 
                                  std::vector<DFARow> &rows); 

        static void processRule(size_t rule, std::vector<DFARow> &rows,
                                size_t rowIdx, bool parentFinal, 
                                int acceptCount);

        static void processRow(LARule &laRule, size_t rule, 
                               std::vector<DFARow> &rows, size_t rowIdx, 
                                bool parentFinal, int acceptCount);

        static void inspect(std::pair<size_t, size_t> const &transit, 
                            size_t oldRow, 
                            size_t rule, std::vector<DFARow> &rows,
                            bool parentFinal, int acceptCount);
 
        static void fillStartSet(size_t idx, Rules const &rules, 
                                             StateSet &start);
};

inline DFA::DFA()
:
    d_ranges(0)    
{}

inline std::vector<DFARow>::const_iterator DFA::begin() const
{
    return d_row.begin();
}

inline std::vector<DFARow>::const_iterator DFA::end() const
{
    return d_row.end();
}

inline size_t DFA::size() const
{
    return d_row.size();
}


#endif

