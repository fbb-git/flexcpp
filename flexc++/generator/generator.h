#ifndef INCLUDED_GENERATOR_
#define INCLUDED_GENERATOR_

#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>

#include "../dfas/dfas.h"
#include "../startconditions/startconditions.h"

class Ranges;
class Options;

namespace FBB
{
    class Arg;
}

class Generator
{
    typedef void (Generator::*Inserter)(std::ostream &) const;
    typedef std::unordered_map<std::string, Inserter>   Map;
    typedef Map::value_type                             MapValue;
    typedef Map::const_iterator                         MapConstIter;

    typedef std::pair<size_t, size_t> Pair;
    typedef std::vector<Pair> PVector;

    Options &d_options;
    FBB::Arg &d_arg;
    Rules const &d_rules;
    Ranges const &d_ranges;
    DFAs const &d_dfas;

    mutable std::vector<std::string> d_startStates;
    mutable std::string d_key;          // extracted at $insert statements
    mutable std::string d_line;
    mutable std::vector<FinAcInfo> d_finacs;    // determined at dfas()
    mutable std::vector<size_t> d_dfaIndices;   // determined at dfas()

    static Map s_insert;
    static char const *s_baseFlag;          // text to change to the class 
                                            // name
    static size_t const s_baseFlagSize;     // # of characters in s_baseFlag

    static std::string s_matchedTextFunction;   // default way to call the
    static std::string s_scannerTokenFunction;  // scanner's token en text
                                                // functions.

    public:
        Generator(Rules const &rules, Ranges const &ranges, DFAs const &dfas);

        void baseclassHeader() const;
        void classHeader() const;
        void implementationHeader() const;
        void lexSource() const;

        void actions(DFAs const &dfas);
        void declarations();

    private:
        void insert(std::ostream &out) const;
        void filter(std::istream &in, std::ostream &out) const;
        void key(std::ostream &out) const;

        void namespaceUse(std::ostream &out) const;
        void namespaceClose(std::ostream &out) const;
        void namespaceOpen(std::ostream &out) const;
        void startCondNames(std::ostream &out) const;
        void baseClassH(std::ostream &out) const;
        void classH(std::ostream &out) const;
        void classIH(std::ostream &out) const;
        void lexFunctionDecl(std::ostream &out) const;
        void inlineLexFunction(std::ostream &out) const;
        void ranges(std::ostream &out) const;
        void dfas(std::ostream &out) const;
        void finAcs(std::ostream &out) const;
        void DFAbases(std::ostream &out) const;
        void declarations(std::ostream &out) const;

        size_t dfaCols() const;

        static void outFinAc(FinAcInfo const &finac, std::ostream &out);
        static size_t addFinal(DFARow const &row, std::vector<size_t> &final);
        static void outFinal(size_t rule, std::ostream &out, size_t &count);

        static void dfa(DFAs::Pair const &dfaPair, std::ostream &out, 
                        std::vector<FinAcInfo> &finAcs,
                        std::vector<std::string> &startStates,
                        std::vector<size_t> &dfaOffsets);
        static void dfaRow(DFARow const &row, size_t &index, 
                        std::ostream &out, 
                        std::vector<FinAcInfo> &finAcs);    
        static void dfaTransitions(DFARow const &row, std::ostream &out);
        static void dfaFinAcs(DFARow const &row, std::ostream &out,
                              std::vector<FinAcInfo> &finAcs);

        static void inspectFinAc(FinAcInfo const &finac,
                                 std::vector<FinAcInfo> &finAcs);

        static std::string outDFAbase(std::string const &startState,
                                      size_t offset);
        static void outStartState(std::string const &name, std::ostream &out);
        static void dfaActions(DFAs::Pair const &dfaPair, std::ostream &out,
                                                std::set<size_t> &done);
        static void outAction(DFARow const &row, std::ostream &out,
                                                 std::set<size_t> &done);
};

        
#endif




