#ifndef INCLUDED_DFAROW_
#define INCLUDED_DFAROW_

#include <iosfwd>
#include <vector>
#include <set>

#include <bobcat/linearmap>

#include "../rules/rules.h"
#include "../states/states.h"

#include "../flextypes/flextypes.h"

namespace FBB
{
    class Table;
}

class States;

class DFARow: private FlexTypes
{
    typedef std::pair<size_t, size_t> Pair;
    typedef std::set<size_t> StateSet;
    typedef std::vector<StateSet> StateSetVector;   // a set of states per
                                                    // input symbol

    FBB::LinearMap<size_t, size_t> d_map;   // Relate input symbols (key) 
                                                // to the row to transit to 
                                                // (value)

    std::pair<size_t, size_t> d_finalRule;      // Final state for which 
                                                // rule(s)?
    size_t d_thisIdx;                           // this row's index in the DFA

    // pointers to the outside world (using ptrs so no op= is required)

    States *d_states;

    StateSetVector *d_stateSets;            // For each DFArow the indices 
                                            // of the States used for this
                                            // DFArow.
    Rules *d_rules;

    size_t d_nRanges;
    std::vector<bool> *d_usedRanges;

    public:
        typedef FBB::LinearMap<size_t, size_t>::value_type MapValue;

        DFARow() = default;

        DFARow(
            Rules &rules,
                // all States
            States &states,            
                // sets of state nrs defining the rows of the DFA
            StateSetVector &stateSets, 
                // index in the DFA (and in stateSets) of this row
            size_t thisIdx,
                // info about used character ranges
            size_t nRanges,
            std::vector<bool> *usedR
        );

            // visit all states of this row and determine their transitions
        void transitions(); 

        void tabulate(FBB::Table &table) const;


        FBB::LinearMap<size_t, size_t> const &map() const;
        size_t size() const;            // the number of character-ranges

        std::string const &action(size_t idx) const;  // only for FINAL rows

        std::pair<size_t, size_t> const &final() const; // final row for which
                                        // rules? the 1st index is a non-BOL
                                        // rule index, the 2nd a BOL rule
                                        // index.
                                        // std::numeric_limits<size_t>::max())
                                        // indicates `not a final rule index'
        bool operator==(DFARow const &rhs) const;

        void uniqueMap(std::vector<size_t> const &xlat);

    private:
        void updateViable(size_t &destIdx, size_t ruleIdx); // in setfinal.cc

        void tabulateTransitions(FBB::Table &table) const;
        void tabulateFinals(FBB::Table &table) const;

            // determine the eClosure of a set of transitions for each of the
            // char-ranges of the input alphabet, including the special 
            // characters like FINAL, BOL, etc.
            // If that e-closure isn't in d_stateSets yet, add it to that
            // vector. 
            // Construct d_map mapping an input symbol to a row in the DFA
        void transit(size_t stateIdx, size_t rangeChar, StateSet &nextSet);
        void setFinal(size_t ruleIdx);
        static void nextAcceptType(size_t rule, DFARow &row);

        static void translate(MapValue &transition, 
                                            std::vector<size_t> const &xlat);
        static bool stateOfRule(size_t state, 
                                std::vector<size_t> const &haystack);

        static bool sameTransits(
            FBB::LinearMap<size_t, size_t> const &lhs,
            FBB::LinearMap<size_t, size_t> const &rhs);
};

inline FBB::LinearMap<size_t, size_t> const &DFARow::map() const
{
    return d_map;
}

inline std::pair<size_t, size_t> const &DFARow::final() const
{
    return d_finalRule;
}

inline size_t DFARow::size() const
{
    return d_nRanges;
}

FBB::Table &operator<<(FBB::Table& out, DFARow const &row);

#endif


