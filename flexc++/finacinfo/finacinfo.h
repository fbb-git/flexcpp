#ifndef INCLUDED_FINACINFO_
#define INCLUDED_FINACINFO_

#include <iosfwd>

class FinAcInfo
{
    enum Type       // the values are bit-flags
    {   
        INCREMENTING    = 1,
        USES_LOP        = 2,
        FINAL_STATE     = 4
    };
            
    friend std::ostream &operator<<(std::ostream &out, FinAcInfo const &la);

    size_t d_rule;      // which LA rule?
    size_t d_info;      // see above: d_info holds `Type' values
    size_t d_accept;    // accept count

    public:
        explicit FinAcInfo(size_t ruleIdx, bool final = false);
        bool operator==(size_t rule) const;

        void setAccept(int accept);
        void setFinal(int final);
        void setInc();

        bool inc() const;
        bool final() const;

        size_t accept() const;
        size_t info() const;
        size_t rule() const;
};
        
inline bool FinAcInfo::inc() const
{
    return d_info & INCREMENTING;
}

inline size_t FinAcInfo::rule() const
{
    return d_rule;
}

inline bool FinAcInfo::final() const
{
    return d_info & FINAL_STATE;
}

inline size_t FinAcInfo::accept() const
{
    return d_accept;
}

inline size_t FinAcInfo::info() const
{
    return d_info;
}

inline void FinAcInfo::setAccept(int accept)
{
    d_accept = accept;
}

inline void FinAcInfo::setInc()
{
    d_info |= INCREMENTING;
}

inline void FinAcInfo::setFinal(int final)
{
    d_info |= FINAL_STATE;
}

inline bool FinAcInfo::operator==(size_t ruleIdx) const
{
    return d_rule == ruleIdx;
}

std::ostream &operator<<(std::ostream &out, FinAcInfo const &la);

#endif
