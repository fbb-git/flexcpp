#ifndef INCLUDED_STARTCONDITIONS_
#define INCLUDED_STARTCONDITIONS_

#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>

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
            std::vector<size_t> d_rules;        // rules of this SC.

            StartCondition() = default;
            StartCondition(Type type);
        };
                                                // Hash associates SC name
                                                // and its rules
        typedef std::unordered_map<std::string, StartCondition> Hash;
        
        Type d_type;
        Hash d_hash;

        std::vector<StartCondition *> d_active;
        bool d_inclusive;
        StartCondition *d_initialSC;

    public:

        class const_iterator;
        class NameVector                        // used and returned by
        {                                       // const_iterator below
            friend class const_iterator;

            std::string const *d_name;
            std::vector<size_t> const *d_rules;

            NameVector();
            NameVector(std::string const &str, 
                            std::vector<size_t> const &vect);

            public:
                std::string const &name() const;
                std::vector<size_t> const &rules() const;
        };

        class const_iterator: 
                    public std::iterator<std::input_iterator_tag, NameVector>
        {
            friend class StartConditions;

            Hash::const_iterator d_iter;
            mutable NameVector d_nameVector;

            public:
                bool operator!=(const_iterator const &rhs);
                const_iterator &operator++();
                NameVector const &operator*() const;

            private:
                                        // initialize a const iterator with
                                        // an iterator to the name and rules
                                        // of a SC.
                const_iterator(Hash::const_iterator const &iter);
        };

        StartConditions();
        void add(SemVal const &name);   // add a name to the active 
        void add(size_t);
        void setType(Type type);
        void reset();
        void useAll();
        void activate(SemVal const &name);
        void useInitialSC();
        const_iterator begin() const;
        const_iterator end() const;
        std::vector<size_t> const &operator()(std::string const &name) const;

    private:
        static void addVector(Hash::value_type &mini, 
                              std::vector<StartCondition *> &active);
        static void addRule(StartCondition *sc, size_t ruleIdx);
        static std::string const &strOf(SemVal const &nameVal);
};


    // set by the parser at the section change (%%)
inline void StartConditions::useInitialSC() 
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

inline std::vector<size_t> const &StartConditions::operator()
                                            (std::string const &name) const
{
    return d_hash.find(name)->second.d_rules;
}

inline StartConditions::const_iterator::const_iterator(
                                      Hash::const_iterator const &iter)
:
    d_iter(iter)
{}

inline  bool StartConditions::const_iterator::operator!=(
                                                const_iterator const &rhs)
{
    return d_iter != rhs.d_iter;
}

inline StartConditions::const_iterator 
        &StartConditions::const_iterator::operator++()
{
    ++d_iter;
    return *this;
}
            
inline StartConditions::const_iterator StartConditions::begin() const
{
    return const_iterator(d_hash.begin());
}

inline StartConditions::const_iterator StartConditions::end() const
{
    return const_iterator(d_hash.end());
}

inline StartConditions::NameVector::NameVector()
:
    d_name(0),
    d_rules(0)
{}

inline StartConditions::NameVector::NameVector(std::string const &str, 
                            std::vector<size_t> const &vect)
:
    d_name(&str),
    d_rules(&vect)
{}

inline std::string const &StartConditions::NameVector::name() const
{
    return *d_name;
}

inline std::vector<size_t> const &StartConditions::NameVector::rules() const
{
    return *d_rules;
}

#endif

