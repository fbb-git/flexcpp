#ifndef INCLUDED_DFAROW_
#define INCLUDED_DFAROW_

#include <iosfwd>
#include <vector>
#include <set>
#include <unordered_map>

#include "../ranges/ranges.h"
#include "../rules/rules.h"
#include "../states/states.h"
#include "../finacinfo/finacinfo.h"

namespace FBB
{
    class Table;
}

class States;

class DFARow
{
    typedef std::pair<size_t, size_t> Pair;

    typedef std::set<size_t> StateSet;
    typedef std::vector<StateSet> StateSetVector;   // a set of states per
                                                    // input symbol

    std::vector<FinAcInfo> d_finAcInfo;             // info about LA-using rules

    std::set<size_t> d_finalRule;               // Final state for which 
                                                // rule(s)?

    typedef std::unordered_map<size_t, size_t>::value_type MapValue;
    std::unordered_map<size_t, size_t> d_map;   // Relate input symbols (key) 
                                                // to the row to transit to 
                                                // (value)

    States *d_states;                       // using ptrs so no op= needs
                                            // to be implemented
    StateSetVector *d_stateSets;            // For each DFArow it contains the
                                            // indices of the States used for
                                            // that DFArow.
    Rules const *d_rules;
    Ranges *d_ranges;

    size_t d_thisIdx;                       // row index in the DFA
    size_t d_nRanges;

    public:
        DFARow() = default;

        DFARow(
            Rules const &rules,
                // all States
            States &states,            
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

//SF? char ruleAcceptType(size_t rule) const;
   
        std::set<size_t> const &final() const;

        std::unordered_map<size_t, size_t> const &map() const;
        size_t size() const;

        std::string const &action(size_t idx) const;  // only for FINAL rows
        std::vector<FinAcInfo> &finAcInfos();
             
        bool hasPostAstates(size_t ruleIdx, size_t rowIdx) const;
        bool hasPreAstates(size_t ruleIdx, size_t rowIdx) const;

        bool operator==(DFARow const &rhs) const;

        void uniqueMap(std::vector<size_t> const &xlat);

        static void mergeFinalSet(DFARow &dfaRow);
        static void mergeFinal(size_t rule, 
                               std::vector<FinAcInfo> &finAcInfo);

    private:
        void tabulateTransitions(FBB::Table &table) const;
        void tabulateFinals(FBB::Table &table) const;
        void tabulateAccepts(FBB::Table &table) const;

            // determine the eClosure of a set of transitions for each of the
            // char-ranges of the input alphabet, including the special 
            // characters like FINAL, BOL, etc.
            // If that e-closure isn't in d_stateSets yet, add it to that
            // vector. 
            // Construct d_map mapping an input symbol to a row in the DFA
        static void transit(size_t stateIdx, DFARow &thisRow, 
                                             size_t rangeChar,
                                             StateSet &nextSet);
        void setFinal(size_t ruleIdx);
        static void nextAcceptType(size_t rule, DFARow &row);

        static void translate(MapValue &transition, 
                                            std::vector<size_t> const &xlat);
        static void outAccept(size_t rule, std::ostream &out, 
                                                    DFARow const &obj);
        static void insertFinAcInfo(size_t idx, DFARow &thisRow);
        static bool stateOfRule(size_t state, 
                                std::vector<size_t> const &haystack);
};

inline std::unordered_map<size_t, size_t> const &DFARow::map() const
{
    return d_map;
}

inline std::vector<FinAcInfo> &DFARow::finAcInfos()
{
    return d_finAcInfo;
}

inline std::set<size_t> const &DFARow::final() const
{
    return d_finalRule;
}

inline size_t DFARow::size() const
{
    return d_ranges->size();
}

FBB::Table &operator<<(FBB::Table& out, DFARow const &row);
        
#endif


