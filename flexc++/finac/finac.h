#ifndef INCLUDED_FINAC_
#define INCLUDED_FINAC_

#include <iosfwd>

class FinAc
{
    enum Type       // the values are bit-flags
    {   
        INCREMENTING    = 1,
        USES_LOP        = 2,
        FINAL_STATE     = 4
    };
            
    friend std::ostream &operator<<(std::ostream &out, FinAc const &la);

    size_t d_rule;      // which LA rule?
    size_t d_info;      // see above: d_info holds `Type' values
    size_t d_accept;    // accept count

    public:
        explicit FinAc(size_t ruleIdx, bool final = false);
        bool operator==(size_t rule) const;

        void setAccept(int accept);
        void setFinal();
        void setInc();
        void setLOP();

        bool inc() const;
        bool final() const;

        size_t accept() const;
        size_t info() const;
        size_t rule() const;
};
        
inline bool FinAc::inc() const
{
    return d_info & INCREMENTING;
}

inline size_t FinAc::rule() const
{
    return d_rule;
}

inline bool FinAc::final() const
{
    return d_info & FINAL_STATE;
}

inline size_t FinAc::accept() const
{
    return d_accept;
}

inline size_t FinAc::info() const
{
    return d_info;
}

inline void FinAc::setAccept(int accept)
{
    d_accept = accept;
}

inline void FinAc::setInc()
{
    d_info |= INCREMENTING;
}

inline void FinAc::setLOP()
{
    d_info |= USES_LOP;
}

inline void FinAc::setFinal()
{
    d_info |= FINAL_STATE;
}

inline bool FinAc::operator==(size_t ruleIdx) const
{
    return d_rule == ruleIdx;
}

std::ostream &operator<<(std::ostream &out, FinAc const &la);

#endif
