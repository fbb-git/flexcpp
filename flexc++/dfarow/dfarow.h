#ifndef INCLUDED_DFAROW_
#define INCLUDED_DFAROW_

#include <set>
#include <vector>
#include <unordered_map>

class States;

class DFARow
{
    typedef std::set<size_t> StateSet;
    typedef std::vector<StateSet> StateSetVector;

    size_t d_finalRule;                     // Final state for which rule?
    std::vector<size_t> d_acceptRules;      // Accept state for which rule(s)?

    std::unordered_map<size_t, size_t> d_map;   // Relate input symbols to
                                                // the rows to transit to.

    States const *d_states;                 // using ptrs so no op= needs
    StateSetVector *d_stateSets;            // to be implemented

    size_t d_thisIdx;
    size_t d_nRanges;

    public:
        DFARow(
                // all States
            States const &states,            
                // sets of state nrs defining the rows of the DFA
            StateSetVector &stateSets, 
                // index in the DFA (and in stateSets) of this row
            size_t thisIdx,
                // number of character ranges
            size_t nRanges
        );

            // visit all states of this row and determine their transitions
        void transitions(); 

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
        void setAccept(size_t type, size_t stateIdx);
};
        
#endif


