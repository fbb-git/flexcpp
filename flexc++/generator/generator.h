#ifndef INCLUDED_GENERATOR_
#define INCLUDED_GENERATOR_

#include <vector>
#include <string>
#include <fstream>
#include <set>

#include "../dfas/dfas.h"

class Ranges;

class Generator
{
    typedef std::pair<size_t, size_t> Pair;
    typedef std::vector<Pair> PVector;

    std::ofstream d_out;
    Ranges const &d_ranges;
    std::vector<std::string> d_startStates;
    size_t d_nRules;

    public:
        Generator(size_t nRules, Ranges const &ranges);
        void charTable();
        void dfas(DFAs const &dfas);
        void actions(DFAs const &dfas);
        void declarations();

    private:
        size_t dfaCols() const;

        void finalRules(std::vector<size_t> const &final);
        static size_t addFinal(DFARow const &row, std::vector<size_t> &final);
        static void outFinal(size_t rule, std::ostream &out, size_t &count);

        void dfaEntryPoints(std::vector<size_t> const &entryPoints);

        static void dfa(DFAs::Pair const &dfaPair, std::ostream &out, 
                        PVector &accept, std::vector<size_t> &final,
                        std::vector<std::string> &startStates,
                        std::vector<size_t> &dfaOffsets);
        static void dfaRow(DFARow const &row, std::ostream &out, 
                        PVector &accept, std::vector<size_t> &final);    
        static std::string outEntryPoint(std::string const &startState,
                                         size_t offset);
        static void outStartState(std::string const &name, std::ostream &out);
        static void dfaActions(DFAs::Pair const &dfaPair, std::ostream &out,
                                                std::set<size_t> &done);
        static void outAction(DFARow const &row, std::ostream &out,
                                                 std::set<size_t> &done);
};
        
#endif




