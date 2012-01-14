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
class States;

namespace FBB
{
    class Arg;
}

class Generator
{
    enum
    {
        RFC_INDICES = 2, // begin/end indices in the run-time RFC array
    };

    enum Flags
    {
        FINAL           = 1,    // Final row
        INCREMENTING    = 2,    // Incrementing row of LOP rule
        COUNT           = 4,    // Count-row (= d_count) of LOP rule 
        BOL             = 8,    // Rule is a LOP rule
    };

    struct RuleFlagCount    // (RFC)
    {
        size_t d_rule;
        size_t d_flag;
        size_t d_count;
    };

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
    std::string d_baseclassScope;
    std::string d_constructionFilename;

    bool d_lineDirectives;
    bool d_debug;
    bool d_debugStep;

    mutable std::vector<std::string> d_startStates;
    mutable std::string d_key;          // extracted at $insert statements
    mutable std::string d_line;
    mutable std::string d_field;

    mutable std::vector<RuleFlagCount> d_rfc;   // determined at dfas()
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

        void construction(States const &states);
        void baseclassHeader() const;
        void classHeader() const;
        void implementationHeader() const;
        void lexSource() const;
        void showFilenames() const;

        void declarations();

    private:
        void DFAbases(std::ostream &out) const;
        static std::string outDFAbase(std::string const &startState,
                                      size_t offset);

        void actions(std::ostream &out) const;
        void tailCount(std::ostream &out) const;
        void baseClassH(std::ostream &out) const;
        void baseIncludes(std::ostream &out) const;
        void classH(std::ostream &out) const;
        void classHead(std::ostream &out) const;
        void classIH(std::ostream &out) const;
        void debug(std::ostream &out) const;
        void debugDecl(std::ostream &out) const;
        void debugFunctions(std::ostream &out) const;
        void debugInit(std::ostream &out) const;
        void debugStep(std::ostream &out) const;
        void declarations(std::ostream &out) const;
        void dfas(std::ostream &out) const;
        void filter(std::istream &in, std::ostream &out) const;
        void inlineLexFunction(std::ostream &out) const;
        void inputImplementation(std::ostream &out) const;
        void inputInterface(std::ostream &out) const;
        void insert(std::ostream &out) const;
        void insertSstream(std::ostream &out) const;
        void interactiveLex(std::ostream &out) const;
        void key(std::ostream &out) const;
        void lexFunctionDecl(std::ostream &out) const;
        void namespaceClose(std::ostream &out) const;
        void namespaceOpen(std::ostream &out) const;
        void namespaceUse(std::ostream &out) const;
        void ranges(std::ostream &out) const;
        void scannerConstructors(std::ostream &out) const;
        void startCondNames(std::ostream &out) const;

        size_t dfaCols() const;

        void rfcs(std::ostream &out) const;
        static void outRFC(RuleFlagCount const &rfc, std::ostream &out,
                                                     size_t &idx);
        static void dfa(DFAs::Pair const &dfaPair, std::ostream &out, 
                        std::vector<RuleFlagCount> &tailCounts,
                        std::vector<std::string> &startStates,
                        std::vector<size_t> &dfaOffsets);
        static void dfaRow(DFARow const &row, size_t &index, 
                        std::ostream &out, std::vector<RuleFlagCount> &rfc);
        static void dfaTransitions(DFARow const &row, std::ostream &out);
        static void dfaRFCs(DFARow const &row, std::ostream &out,
                            std::vector<RuleFlagCount> &rfc);
        static void storeRFC(TailCount const &tailcount,
                             std::pair<size_t, size_t> &final,
                             std::vector<RuleFlagCount> &rfc);

        static void outStartState(std::string const &name, std::ostream &out);
        static void ruleAction(Rule const &rule, std::ostream &out, 
                               size_t &idx, bool lineDirectives);
};

#endif




