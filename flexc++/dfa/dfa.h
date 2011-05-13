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
    Rules *d_rules;
    States *d_states;

    std::vector<DFARow> d_row;

    typedef std::set<size_t> StateSet;
    std::vector<StateSet> d_stateSet;    

    bool d_verbose;
    bool d_sawACCEPT;           // used by visitAccCount

    size_t d_rule;              // used when computing AccCount values 

    public:
        DFA() = default;        // only used for vector-resizing operations

        DFA(Ranges &ranges, Rules &d_rules, States &states);

        void build(std::string const &name, 
                   std::vector<size_t> const &active);

        std::vector<DFARow>::const_iterator begin() const;
        std::vector<DFARow>::const_iterator end() const;

        size_t size() const;

    private:
        void keepViableAccCounts();
        void mergeFinalSet();

//        int maxAccept(size_t rowIdx) const;
//        static bool cmpAccept(size_t left, size_t right, 
//                                                        States const &states);

        static void translate(DFARow &row, std::vector<size_t> const &unique);

        void keepUniqueRows();
        void inspectRows(std::vector<size_t> &unique);
        void shrinkDFA(std::vector<size_t> &unique);


        size_t available(DFARow const &nextRow);

        void computeAccCounts();
        static void visitAccCount(AccCount &accCount, DFA &dfa);
        static void determineAccCount(AccCount &accCount, size_t thisRow,
                                      size_t fmRow, AccCount *fmAccCount, 
                                      DFA &dfa);
        bool setAccCount(AccCount &accCount, size_t thisRow, size_t fmRow, 
                         AccCount *fmAccCount);
        static void transitAccCount(DFARow::MapValue const &rangeToRow, 
                    size_t fmRow, AccCount *fmAccCount, DFA &dfa);

//        void propagateLAsteps(std::vector<bool> &visited,
//                           size_t stateIdx, int steps);

//        static void processRule(size_t rule, DFA &dfa, size_t rowIdx, 
//                                bool parentFinal, int tailSize);

//        static void processRow(FinAc &finAc, size_t rule, DFA &dfa, 
//                               size_t rowIdx, int parentFinal, int tailSize);

//        static void inspect(std::pair<size_t, size_t> const &transit, 
//                            size_t oldRow, size_t rule, DFA &dfa,
//                            int parentFinal, int tailSize);
 
        static void fillStartSet(size_t idx, Rules const &rules, 
                                             StateSet &start);
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

#endif

