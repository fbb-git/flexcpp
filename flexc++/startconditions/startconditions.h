#ifndef INCLUDED_STARTCONDITIONS_
#define INCLUDED_STARTCONDITIONS_

#include <unordered_map>
#include <vector>
#include <string>

class SemVal;

class StartConditions
{
    public:
        enum Type
        {
            EXCLUSIVE,
            INCLUSIVE
        };

    private:
        struct StartCondition
        {
            Type d_type;
            std::vector<size_t> d_rules;

            StartCondition() = default;
            StartCondition(Type type);
        };
        
        Type d_type;
        typedef std::unordered_map<std::string, StartCondition> Hash;

        Hash d_hash;
        std::vector<StartCondition *> d_active;
        bool d_inclusive;
        StartCondition *d_initialSC;

    public:
        StartConditions();
        void add(SemVal const &name);   // add a name to the active 
        void add(size_t);
        void setType(Type type);
        void reset();
        void useAll();
        void activate(SemVal const &name);
        void setInitialSC();

    private:
        static void addVector(Hash::value_type &mini, 
                              std::vector<StartCondition *> &active);
        static void addRule(StartCondition *sc, size_t ruleIdx);
        static std::string const &strOf(SemVal const &nameVal);
};


    // set by the parser at the section change (%%)
inline void StartConditions::setInitialSC() 
{
    d_initialSC = &d_hash.find("INITIAL")->second;
}

inline void StartConditions::setType(Type type)
{
    d_type = type;
}

inline void StartConditions::reset()
{
    d_active.clear();
    d_inclusive = false;
}

#endif

