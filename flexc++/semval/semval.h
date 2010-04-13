#ifndef INCLUDED_SEMVAL_
#define INCLUDED_SEMVAL_

#include <memory>

class SemVal
{
    public:
        virtual ~SemVal();
    
        template <typename Dest>
        static Dest &downCast(SemVal &src);

        template <typename Dest>
        static Dest const &downCast(SemVal const &src);
};

template <typename Dest>
inline Dest &SemVal::downCast(SemVal &src)
{
    return dynamic_cast<Dest &>(src);
}

template <typename Dest>
inline Dest const &SemVal::downCast(SemVal const &src)
{
    return dynamic_cast<Dest const &>(src);
}

typedef std::shared_ptr<SemVal> spSemVal;
        
#endif
