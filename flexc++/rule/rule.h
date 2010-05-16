#ifndef INCLUDED_RULE_
#define INCLUDED_RULE_

#include <vector>
#include <string>
#include <set>

class States;

class Rule
{
    friend std::ostream &operator<<(std::ostream &out, Rule const &rule);


    typedef std::pair<size_t, size_t> Pair;     // first/final state nrs.

    size_t d_start;             // index in States
    size_t d_final;             // index in States
    std::string d_action;       // action block
    bool d_LAdone;              // set to true when LA propagation has been 
                                // completed (not relevant for rules not
                                // using the LA operator

                                    // for rules using LA operators:
    std::vector<size_t> d_preAstates;  // all pre-A states
    std::vector<size_t> d_postAstates; // all post-A states

    public:
        Rule() = default;               // for vector operations by Rules
        Rule(States const &states,
             Pair fstfin, size_t accept, std::string action);
        size_t startState() const;
        size_t finalState() const;
        size_t accept() const;
        std::string const &action() const;

        std::vector<size_t> const &preAstates() const;
        std::vector<size_t> const &postAstates() const;
        int maxAccept(std::set<size_t> const &stateSet, 
                      States const &states) const;

        void setLAdone();
        bool LAdone() const;

    private:
        void setStates(std::vector<size_t> &prePostA, 
                        States const &states, size_t begin, size_t end);
        static bool cmpAccept(size_t left, size_t right, 
                                                        States const &states);
};

inline void Rule::setLAdone() 
{
    d_LAdone = true;
}

inline bool Rule::LAdone() const
{
    return d_LAdone;
}

inline std::vector<size_t> const &Rule::preAstates() const
{
    return d_preAstates;
}

inline std::vector<size_t> const &Rule::postAstates() const
{
    return d_postAstates;
}

inline size_t Rule::startState() const
{
    return d_start;
}

inline size_t Rule::finalState() const
{
    return d_final;
}

inline size_t Rule::accept() const
{
    return d_postAstates[0];
}

inline std::string const &Rule::action() const
{
    return d_action;
}

#endif














