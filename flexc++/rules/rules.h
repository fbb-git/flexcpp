#ifndef INCLUDED_RULES_
#define INCLUDED_RULES_

#include <vector>
#include <string>
#include <unordered_map>

#include "../startconditions/startconditions.h"
#include "../rule/rule.h"

class States;

class Rules
{
    typedef std::pair<size_t, size_t> Pair;

    States const &d_states;

    std::vector<Rule> d_rules;
    std::unordered_map<size_t, size_t>  d_reverse;  // from FINAL state to
                                                    // Rule index
    std::unordered_map<size_t, size_t>  d_reverseAccept;  
                                                    // from accept state to
                                                    // Rule index
    StartConditions d_startConditions;

    public:
        Rules(States const &states);

        void add(Pair const &pair, size_t accept,
                                     std::string const &action = "");
        Rule const &operator[](size_t idx) const;

        size_t hasFinalState(size_t stateIdx) const;
        size_t hasAcceptState(size_t stateIdx) const;

        void setType(StartConditions::Type type);
        void addStartCondition(SemVal const &name);
        void resetStartConditions();
        void useAll();
        void activateStartCondition(SemVal const &name);
        std::vector<size_t> const &operator()   // vector of rule nrs
                                    (std::string const &startCondition) const;
        void useInitialSC();
};
        
inline size_t Rules::hasFinalState(size_t stateIdx) const
{
    return d_reverse.find(stateIdx)->second;
}

inline size_t Rules::hasAcceptState(size_t stateIdx) const
{
    return d_reverseAccept.find(stateIdx)->second;
}

inline Rule const &Rules::operator[](size_t idx) const
{
    return d_rules[idx];
}

inline void Rules::setType(StartConditions::Type type)
{
    d_startConditions.setType(type);
}

inline void Rules::addStartCondition(SemVal const &name)
{
    d_startConditions.add(name);
}

inline void Rules::resetStartConditions()
{
    d_startConditions.reset();
}

inline void Rules::useAll()
{
    d_startConditions.useAll();
}

inline void Rules::activateStartCondition(SemVal const &name)
{
    d_startConditions.activate(name);
}

inline void Rules::useInitialSC()
{
    d_startConditions.useInitialSC();
}

inline std::vector<size_t> const &Rules::operator() 
                                    (std::string const &startCondition) const
{
    return d_startConditions(startCondition);
}

#endif
