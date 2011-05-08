#ifndef INCLUDED_LOGIC_
#define INCLUDED_LOGIC_

#include "../semval/semval.h"

class Logic: public SemVal
{
    bool d_value;

    public:
        Logic(Logic const &other) = delete;
        static spSemVal value(bool logic);

        bool value() const;

    private:
        Logic(bool value);
};
        
inline bool Logic::value() const
{
    return d_value;
}

#endif
