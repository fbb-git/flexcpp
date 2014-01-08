#ifndef INCLUDED_STARTCONDITIONS_
#define INCLUDED_STARTCONDITIONS_

#include <iosfwd>
// #include <unordered_map>
#include <vector>
#include <string>
#include <iterator>

class SemVal;

class StartConditions
{
    friend std::ostream &operator<<(std::ostream &out, 
                                    StartConditions const &startConditions);

    public:
        enum Type
        {
            EXCLUSIVE,
            INCLUSIVE,
        };

    private:
        struct StartCondition
        {
            Type d_type;
            std::vector<size_t> d_rules;        // rules of this SC.
    
            StartCondition() = default;
            StartCondition(Type type);
        };
    
        typedef std::pair<std::string, StartCondition> KeyValue;
        typedef std::vector<KeyValue> SCVector;
        
        Type d_type = EXCLUSIVE;
        SCVector d_scVector;
        SCVector::iterator d_endUserSC;

        std::vector<StartCondition *> d_active;
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

            SCVector::const_iterator d_iter;
            mutable NameVector d_nameVector;

            public:
                bool operator!=(const_iterator const &rhs);
                const_iterator &operator++();
                NameVector const &operator*() const;

            private:
                                        // initialize a const iterator with
                                        // an iterator to the name and rules
                                        // of a SC.
                const_iterator(SCVector::const_iterator const &iter);
        };

        StartConditions();
        void add(std::string const &name, bool underscoreOK);
                                            // add a name to the set of SCs
        void add(size_t);
        void setType(Type type);
        void reset();
        void useAll();
        void activate(std::string const &name);
        void useInitialSC();
        const_iterator begin() const;
        const_iterator end() const;
        std::vector<size_t> const &operator()(std::string const &name) const;

        size_t size() const;                // # start conditions so far

        void setEndUserSC();

    private:
        SCVector::iterator find(std::string const &key);
        SCVector::const_iterator find(std::string const &key) const;

        KeyValue *findKV(std::string const &key) const;

//        static std::string const &strOf(SemVal const &nameVal);
};

inline void StartConditions::setEndUserSC()
{
    d_endUserSC = d_scVector.end();
}

inline StartConditions::SCVector::const_iterator 
        StartConditions::find(std::string const &key) const
{
    return SCVector::const_iterator(findKV(key));
}

inline StartConditions::SCVector::iterator 
        StartConditions::find(std::string const &key)
{
    return SCVector::iterator(findKV(key));
}

    // set by the parser at the section change (%%)
inline void StartConditions::useInitialSC() 
{
    d_initialSC = &(find("INITIAL")->second);
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
    return find(name)->second.d_rules;
}

inline StartConditions::const_iterator::const_iterator(
                                      SCVector::const_iterator const &iter)
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
    return const_iterator(d_scVector.begin());
}

inline StartConditions::const_iterator StartConditions::end() const
{
    return const_iterator(d_endUsedStartConditions);
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

inline size_t StartConditions::size() const
{
    return d_scVector.size();
}

#endif

