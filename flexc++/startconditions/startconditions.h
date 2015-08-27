#ifndef INCLUDED_STARTCONDITIONS_
#define INCLUDED_STARTCONDITIONS_

#include <iosfwd>
#include <vector>
#include <string>
#include <iterator>
#include <bobcat/linearmap>

struct StartConditions
{
    friend std::ostream &operator<<(std::ostream &out, 
                                    StartConditions const &startConditions);
    enum Type
    {
        EXCLUSIVE,
        INCLUSIVE,
    };

    class StartCondition
    {
        friend struct StartConditions;  // To satisfy Clang...
        friend std::ostream &operator<<(std::ostream &out, 
                                    StartConditions const &startConditions);

        Type d_type;
        std::vector<size_t> d_rules;        // rules of this SC.

        StartCondition() = default;
        StartCondition(Type type);

        public:
            std::vector<size_t> const &rules() const;            
    };
    
    private:
        Type d_type = EXCLUSIVE;
        FBB::LinearMap<std::string, StartCondition> d_sc;
        size_t d_endUserSC;

        std::vector<StartCondition *> d_active; // first is INITIAL per def.

        bool d_acceptRules = true;

    public:
        StartConditions();

        void acceptRules(bool ok);          // may suppres additions of rules
                                            // by add members

        void define(std::string const &name);   // define a new SC
                                            
        void add(size_t);
        void setType(Type type);

        void reset();                       // clear the set of active start
                                            // conditions. 

        void useAll();

        void addSC(std::string const &name); // adds name to a set of SCs
        void activate(size_t scIndex);          // activates just this SC

        typedef FBB::LinearMap<std::string, StartCondition>::const_iterator
                                                            const_iterator;

        const_iterator begin() const;
        const_iterator end() const;
        const_iterator endUserSC() const;
        std::vector<size_t> const &operator()(std::string const &name) const;

        size_t size() const;                // # start conditions so far

        void setEndUserSC();

        void remove(size_t ruleIndex);  // remove ruleIndex from all the SC
                                        // vectors
        size_t nUserSCs() const;
};

inline size_t StartConditions::nUserSCs() const
{
    return d_endUserSC;
}

inline void StartConditions::acceptRules(bool ok)
{
    d_acceptRules = ok;
}

inline void StartConditions::setEndUserSC()
{
    d_endUserSC = d_sc.size();
}

inline void StartConditions::setType(Type type)
{
    d_type = type;
}

inline void StartConditions::reset()
{
    d_active.clear();
}

inline std::vector<size_t> const &StartConditions::operator()
                                            (std::string const &name) const
{
    return d_sc.find(name)->second.d_rules;
}

inline StartConditions::const_iterator StartConditions::begin() const
{
    return d_sc.cbegin();
}

inline StartConditions::const_iterator StartConditions::end() const
{
    return d_sc.cend();
}

inline StartConditions::const_iterator StartConditions::endUserSC() const
{
    return d_sc.cbegin() + d_endUserSC;
}

inline size_t StartConditions::size() const
{
    return d_sc.size();
}

inline std::vector<size_t> const &StartConditions::StartCondition::rules() 
                                                                        const
{
    return d_rules;
}

#endif

