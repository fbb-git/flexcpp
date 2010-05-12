#ifndef INCLUDED_RULES_
#define INCLUDED_RULES_

#include <iosfwd>
#include <vector>
#include <string>
#include <unordered_map>

#include "../startconditions/startconditions.h"
#include "../rule/rule.h"

class States;

class Rules
{
    friend std::ostream &operator<<(std::ostream &out, Rules const &rules);

    typedef std::pair<size_t, size_t> Pair;

    States &d_states;

    std::vector<Rule> d_rules;
    std::unordered_map<size_t, size_t>  d_reverse;  // from FINAL state to
                                                    // Rule index
    std::unordered_map<size_t, size_t>  d_reverseAccept;  
                                                    // from accept state to
                                                    // Rule index
    StartConditions d_startConditions;

    public:
        Rules(States &states);

        void add(Pair const &pair, size_t accept,
                                     std::string const &action = "");
        Rule const &operator[](size_t idx) const;

        size_t hasFinalState(size_t stateIdx) const;
        int hasAcceptState(size_t stateIdx) const;      // -1 if not

        void setType(StartConditions::Type type);
        void addStartCondition(SemVal const &name);
        void resetStartConditions();
        void useAll();
        void activateStartCondition(SemVal const &name);
        std::vector<size_t> const &operator()   // vector of rule nrs
                                    (std::string const &startCondition) const;
        void useInitialSC();

        typedef StartConditions::const_iterator const_iterator;
        typedef StartConditions::NameVector NameVector;
        const_iterator begin() const;
        const_iterator end() const;

        size_t size() const;

        void propagateAccept();

    private:
        static void propagate(Rule const &rule, States &states);

};

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
        
inline size_t Rules::hasFinalState(size_t stateIdx) const
{
    return d_reverse.find(stateIdx)->second;
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
