#ifndef INCLUDED_FINACINFO_
#define INCLUDED_FINACINFO_

#include <iosfwd>

class FinAcInfo
{
    friend std::ostream &operator<<(std::ostream &out, FinAcInfo const &la);

    size_t d_rule;  // which LA rule?
    int d_accept;   // accept count at this point (-1: pre-A state)
    int d_final;    // -1: undetermined Final state accept count
                    // -2: not a Finalstate
                    // >= 0:  Final state accept count
    bool d_inc;     // incrementing A-state

    public:
        enum Accept
        {
            PRE_A_STATE = -1,
        };

        enum Final
        {
            NOT_FINAL = -2,
            FINAL_NOT_SET,
        };

        explicit FinAcInfo(size_t ruleIdx, Final final = NOT_FINAL);
        bool operator==(size_t rule) const;

        void setAccept(int accept);
        void setFinal(int final);
        void setInc();
        bool inc() const;
        int final() const;
        int accept() const;

        size_t rule() const;
};
        
inline bool FinAcInfo::inc() const
{
    return d_inc;
}

inline size_t FinAcInfo::rule() const
{
    return d_rule;
}

inline int FinAcInfo::final() const
{
    return d_final;
}

inline int FinAcInfo::accept() const
{
    return d_accept;
}

inline void FinAcInfo::setAccept(int accept)
{
    d_accept = accept;
}

inline void FinAcInfo::setInc()
{
    d_inc = true;
}

inline void FinAcInfo::setFinal(int final)
{
    d_final = final;
}

inline bool FinAcInfo::operator==(size_t ruleIdx) const
{
    return d_rule == ruleIdx;
}

std::ostream &operator<<(std::ostream &out, FinAcInfo const &la);

#endif
