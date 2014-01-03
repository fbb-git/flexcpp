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
class Block;

class Generator
{
    enum
    {
        RF_INDICES = 2, // begin/end indices in the run-time RF array
    };

    enum Flags
    {
        FINAL           = 1,    // Final row
        INCREMENTING    = 2,    // Incrementing row of LOP rule
        COUNT           = 4,    // Count-row (= d_count) of LOP rule 
        BOL             = 8,    // Rule is a LOP rule
    };

    struct RuleFlag    // (RF)
    {
        size_t d_rule;
        size_t d_flag;
    };

    typedef void (Generator::*Inserter)(std::ostream &) const;
    typedef std::unordered_map<std::string, Inserter>   Map;
    typedef Map::value_type                             MapValue;
    typedef Map::const_iterator                         MapConstIter;

    typedef std::pair<size_t, size_t> Pair;
    typedef std::vector<Pair> PVector;

    Options &d_options;
    Rules const &d_rules;
    Ranges const &d_ranges;
    DFAs const &d_dfas;
    std::string d_baseclassScope;
    std::string d_constructionFilename;

    bool d_lineDirectives;
    bool d_debug;

    mutable std::vector<std::string> d_startStates;
    mutable std::string d_key;          // extracted at $insert statements
    mutable std::string d_line;
    mutable std::string d_field;

    mutable std::vector<RuleFlag> d_rf;    // determined at dfas()
    mutable std::vector<size_t> d_dfaIndices;   // determined at dfas()

    static Map s_insert;
    static char const *s_baseFlag;          // text to change to the class 
                                            // name
    static size_t const s_baseFlagSize;     // # of characters in s_baseFlag

    static char const *s_namespaceBaseFlag; // text to change to the 
                                            // namespace + class name
    static size_t const s_namespaceBaseFlagSize;    // # of characters 

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
        static std::string filename(std::string const &path);

        void DFAbases(std::ostream &out) const;
        static std::string outDFAbase(std::string const &startState,
                                      size_t offset);

        void warnExisting(std::string const &fileName, 
                          std::string const &option,
                          std::string const &expectedOptionValue,
                          std::string const &regex) const;

        bool grep(std::string const &fileName, std::string const &regex) 
                                                                        const;

        void actions(std::ostream &out) const;
        void baseClassH(std::ostream &out) const;
        void baseIncludes(std::ostream &out) const;
        void caseCheck(std::ostream &out) const;
        void classH(std::ostream &out) const;
        void classHead(std::ostream &out) const;
        void classIH(std::ostream &out) const;
        bool debugCodeRequired() const;
        void debug(std::ostream &out) const;
        void debugDecl(std::ostream &out) const;
        void debugFunctions(std::ostream &out) const;
        void declarations(std::ostream &out) const;
        void dfas(std::ostream &out) const;
        void filter(std::istream &in, std::ostream &out) const;
        void inlineLexFunction(std::ostream &out) const;
        void inputImplementation(std::ostream &out) const;
        void inputInterface(std::ostream &out) const;
        void insert(std::ostream &out) const;
        void insertSstream(std::ostream &out) const;
        void interactiveDecl(std::ostream &out) const;
        void interactiveInit(std::ostream &out) const;
        void interactiveLex(std::ostream &out) const;
        void key(std::ostream &out) const;
        void lexFunctionDecl(std::ostream &out) const;
        void namespaceClose(std::ostream &out) const;
        void namespaceOpen(std::ostream &out) const;
        void namespaceUse(std::ostream &out) const;
        void print(std::ostream &out) const;
        void ranges(std::ostream &out) const;
        void scannerConstructors(std::ostream &out) const;
        void startCondNames(std::ostream &out) const;

        size_t dfaCols() const;

        void rfs(std::ostream &out) const;
        static void outRF(RuleFlag const &rfc, std::ostream &out,
                                                     size_t &idx);
        static void dfa(DFAs::Pair const &dfaPair, std::ostream &out, 
                        std::vector<RuleFlag> &tailCounts,
                        std::vector<std::string> &startStates,
                        std::vector<size_t> &dfaOffsets);
        static void dfaRow(DFARow const &row, size_t &index, 
                        std::ostream &out, std::vector<RuleFlag> &rf);
        static void dfaTransitions(DFARow const &row, std::ostream &out);
        static void dfaRFs(DFARow const &row, std::ostream &out,
                            std::vector<RuleFlag> &rf);
        static void storeRF(std::pair<size_t, size_t> &final,
                             std::vector<RuleFlag> &rf);

        static void outStartState(std::string const &name, std::ostream &out);
        void ruleAction(Block const &block, std::ostream &out, size_t &idx)
                                                                    const;
};

#endif




