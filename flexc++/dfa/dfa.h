#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <iosfwd>
#include <vector>
#include <string>
#include <set>

class Rules;
class States;

#include <bobcat/mstream>

#include "../dfarow/dfarow.h"

class DFA
{
    friend std::ostream &operator<<(std::ostream & out, DFA const &dfa);

    typedef std::set<size_t> Size_tSet;

    Ranges *d_ranges;
    Rules *d_rules;
    States *d_states;

    std::vector<DFARow> d_row;
    std::vector<Size_tSet> d_stateSet;      // states belonging to a DFA row

    size_t d_nUsedRanges = 0;             // number of ranges used by this DFA
    bool *d_used = 0;

    static FBB::Mstream s_verbose;  // writes to cout if verbose was set

    public:
        DFA() = default;        // only used for vector-resizing operations

        DFA(Ranges &ranges, Rules &d_rules, States &states);

        void build(std::string const &name, 
                   std::vector<size_t> const &active);

        std::vector<DFARow>::const_iterator begin() const;
        std::vector<DFARow>::const_iterator end() const;

        size_t size() const;

        static void setVerbose(bool on);

    private:
        void keepUniqueRows();
        void inspectRows(std::vector<size_t> &unique);
        void shrinkDFA(std::vector<size_t> &unique);


        size_t available(DFARow const &nextRow);
};

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

//        void mergeFinalSet();

#endif

