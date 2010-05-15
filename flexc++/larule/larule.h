#ifndef INCLUDED_LARULE_
#define INCLUDED_LARULE_

#include <iosfwd>

class LARule
{
    friend std::ostream &operator<<(std::ostream &out, LARule const &la);

    size_t d_rule;  // which LA rule?
    int d_accept;   // accept count at this point (-1: pre-A state)
    int d_final;    // -1: undetermined Final state accept count
                    // -2: not a Finalstate
                    // >= 0:  Final state accept count
    bool d_inc;     // incrementing A-state

    public:
        enum Final
        {
            NOT_FINAL = -2,
            FINAL_NOT_SET,
        };

        LARule(size_t ruleIdx);
        bool operator==(size_t rule) const;

        void setAccept(int accept);
        void setFinal(int final);
        void setInc();
        bool inc() const;
        int final() const;
        int accept() const;

        size_t rule() const;
};
        
inline bool LARule::inc() const
{
    return d_inc;
}

inline size_t LARule::rule() const
{
    return d_rule;
}

inline int LARule::final() const
{
    return d_final;
}

inline int LARule::accept() const
{
    return d_accept;
}

inline void LARule::setAccept(int accept)
{
    d_accept = accept;
}

inline void LARule::setInc()
{
    d_inc = true;
}

inline void LARule::setFinal(int final)
{
    d_final = final;
}

inline bool LARule::operator==(size_t ruleIdx) const
{
    return d_rule == ruleIdx;
}

std::ostream &operator<<(std::ostream &out, LARule const &la);

#endif
