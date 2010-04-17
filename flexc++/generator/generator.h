#ifndef INCLUDED_GENERATOR_
#define INCLUDED_GENERATOR_

#include <vector>
#include <string>
#include <iosfwd>

#include "../dfas/dfas.h"

class Ranges;

class Generator
{
    typedef std::pair<size_t, size_t> Pair;
    typedef std::vector<Pair> PVector;

    std::ostream &d_out;
    Ranges const &d_ranges;

    public:
        Generator(std::ostream &out, Ranges const &ranges);
        void charTable() const;
        void dfas(DFAs const &dfas);

    private:
        void acceptStates(PVector const &accept);
        void dfaEntryPoints(std::vector<size_t> const &entryPoints);

        static void dfa(DFAs::Pair const &dfaPair, std::ostream &out, 
                        PVector &accept,
                        std::vector<std::string> &startStates,
                        std::vector<size_t> &dfaOffsets);
        static void dfaRow(DFARow const &row, std::ostream &out, 
                        PVector &accept);    
        static size_t addAccept(DFARow const &row, PVector &accept);
        static void outPair(Pair const &pair, std::ostream &out, 
                                                            size_t &count);
};
        
#endif
