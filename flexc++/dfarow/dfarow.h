#ifndef INCLUDED_DFAROW_
#define INCLUDED_DFAROW_

#include <iosfwd>
#include <vector>
#include <set>
#include <unordered_map>

#include "../ranges/ranges.h"
#include "../rules/rules.h"

namespace FBB
{
    class Table;
}

class States;

class DFARow
{
    typedef std::pair<size_t, size_t> Pair;

    typedef std::set<size_t> StateSet;
    typedef std::vector<StateSet> StateSetVector;

    std::vector<size_t> d_finalRule;            // Final state for which 
                                                // rule(s)?

        // map rule indices to accept types
    std::unordered_map<size_t, size_t> d_acceptRules;   

    std::unordered_map<size_t, size_t> d_map;   // Relate input symbols (key) 
                                                // to the row to transit to 
                                                // (value)

    States const *d_states;                 // using ptrs so no op= needs
    StateSetVector *d_stateSets;            // to be implemented
    Rules const *d_rules;
    Ranges *d_ranges;

    size_t d_thisIdx;                       // row index in the DFA
    size_t d_nRanges;

    public:
        DFARow(
            Rules const &rules,
                // all States
            States const &states,            
                // sets of state nrs defining the rows of the DFA
            StateSetVector &stateSets, 
                // index in the DFA (and in stateSets) of this row
            size_t thisIdx,
                // info about used character ranges
            Ranges &ranges
        );

            // visit all states of this row and determine their transitions
        void transitions(); 

        void tabulate(FBB::Table &table) const;
        void setInheriting();

        std::vector<size_t> const &final() const;
        std::unordered_map<size_t, size_t> const &map() const;
        size_t size() const;
        std::unordered_map<size_t, size_t> const &acceptMap() const;
        std::string const &action(size_t idx) const;  // only for FINAL rows

    private:
            // determine the eClosure of a set of transitions for each of the
            // char-ranges of the input alphabet, including the special 
            // characters like FINAL, BOL, etc.
            // If that e-closure isn't in d_stateSets yet, add it to that
            // vector. 
            // Construct d_map mapping an input symbol to a row in the DFA
        static void transit(size_t stateIdx, DFARow &thisRow, 
                                             size_t rangeChar,
                                             StateSet &nextSet);
        void setFinal(size_t stateIdx);
        void setAccept(size_t stateIdx);

        static Pair toInheriting(Pair const &inPair);
};

inline std::unordered_map<size_t, size_t> const &DFARow::map() const
{
    return d_map;
}

inline std::unordered_map<size_t, size_t> const &DFARow::acceptMap() const
{
    return d_acceptRules;
}

inline std::vector<size_t> const &DFARow::final() const
{
    return d_finalRule;
}

inline size_t DFARow::size() const
{
    return d_ranges->size();
}

FBB::Table &operator<<(FBB::Table& out, DFARow const &row);
        
#endif


