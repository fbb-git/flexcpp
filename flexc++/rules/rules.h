#ifndef INCLUDED_RULES_
#define INCLUDED_RULES_

#include <iosfwd>
#include <vector>
#include <string>
#include <unordered_map>

#include "../semval/semval.h"
#include "../startconditions/startconditions.h"
#include "../rule/rule.h"

class States;

class Rules
{
    friend std::ostream &operator<<(std::ostream &out, Rules const &rules);

    typedef std::pair<size_t, size_t> Pair; // 1st: start-, 2nd: final-state

    States &d_states;

    std::vector<Rule> d_rules;
    std::unordered_map<size_t, size_t>  d_finalToRule;  // from FINAL state to
                                                        // Rule index
    StartConditions d_startConditions;

    public:
        typedef StartConditions::const_iterator const_iterator;
        typedef StartConditions::NameVector NameVector;
        typedef std::vector<Rule>::const_iterator rule_const_iterator;

        Rules(States &states);
        void add(bool bol, spSemVal const &patternVal, Block const &block,
                 std::string const &fileName, size_t lineNr);

        Rule const &operator[](size_t idx) const;
        Rule &operator[](size_t idx);

        size_t ruleFromFinalState(size_t stateIdx) const;
        void setType(StartConditions::Type type);
        void addStartCondition(std::string const &name);
        void resetStartConditions();
        void useAll();
        void activateStartCondition(std::string const &name);
        std::vector<size_t> const &operator()   // vector of rule nrs
                                    (std::string const &startCondition) const;
        void useInitialSC();

        const_iterator begin() const;
        const_iterator end() const;

        rule_const_iterator ruleBegin() const;
        rule_const_iterator ruleEnd() const;

        size_t size() const;

        void warnNonViable() const;

    private:
        void setRule(size_t state, size_t index);
        static bool nonViable(Rule const &rule);
};

inline bool Rules::nonViable(Rule const &rule)
{
    return not rule.viable();
}

inline size_t Rules::size() const
{
    return d_rules.size();
}
        
inline Rules::const_iterator Rules::begin() const
{
    return d_startConditions.begin();
}
        
inline Rules::const_iterator Rules::end() const
{
    return d_startConditions.end();
}
        
inline Rules::rule_const_iterator Rules::ruleBegin() const
{
    return d_rules.begin();
}
        
inline Rules::rule_const_iterator Rules::ruleEnd() const
{
    return d_rules.end();
}
        
inline size_t Rules::ruleFromFinalState(size_t stateIdx) const
{
    return d_finalToRule.find(stateIdx)->second;
}

inline Rule const &Rules::operator[](size_t idx) const
{
    return d_rules[idx];
}

inline Rule &Rules::operator[](size_t idx)
{
    return d_rules[idx];
}

inline void Rules::setType(StartConditions::Type type)
{
    d_startConditions.setType(type);
}

inline void Rules::addStartCondition(std::string const &name)
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

inline void Rules::activateStartCondition(std::string const &name)
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
