#ifndef INCLUDED_GENERATOR_
#define INCLUDED_GENERATOR_

#include <vector>
#include <string>
#include <fstream>
#include <set>

#include <bobcat/linearmap>

#include "../flextypes/flextypes.h"
#include "../dfas/dfas.h"

class Block;
class DFARow;
class Options;
class Ranges;
class Rules;
class States;

class Generator: public FlexTypes
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

    typedef void (Generator::*Inserter)(std::ostream &) const;
    typedef FBB::LinearMap<std::string, Inserter>   Map;
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

    mutable bool d_lineDirectives;          // manipulated by 'actions'
    bool d_debug;
    bool d_lopUsed;

    mutable std::vector<std::string> d_startStates;
    mutable std::string d_key;          // extracted at $insert statements
    mutable std::string d_line;
    mutable std::string d_field;

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
        void lopf(std::ostream &out) const;
        void lop1(std::ostream &out) const;
        void lop2(std::ostream &out) const;
        void lop3(std::ostream &out) const;
        void lop4(std::ostream &out) const;
        void getLOP(std::ostream &out) const;

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
        void lopImplementation(std::ostream &out) const;
        void namespaceClose(std::ostream &out) const;
        void namespaceOpen(std::ostream &out) const;
        void namespaceUse(std::ostream &out) const;
        void print(std::ostream &out) const;
        void ranges(std::ostream &out) const;
        void scannerConstructors(std::ostream &out) const;
        void startCondNames(std::ostream &out) const;

        size_t dfaCols() const;

        static void dfa(DFAs::Pair const &dfaPair, std::ostream &out, 
                        std::vector<std::string> &startStates,
                        std::vector<size_t> &dfaOffsets);
        static void dfaRow(DFARow const &row, size_t &idx, std::ostream &out);
        static void dfaTransitions(DFARow const &row, std::ostream &out);
        static void dfaRules(DFARow const &row, std::ostream &out);

        static void outStartState(std::string const &name, std::ostream &out);
        void ruleAction(Block const &block, std::ostream &out, size_t idx)
                                                                    const;
};

#endif




