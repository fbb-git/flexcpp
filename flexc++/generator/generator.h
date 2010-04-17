#ifndef INCLUDED_GENERATOR_
#define INCLUDED_GENERATOR_

#include <iosfwd>

class Ranges;

class Generator
{
    std::ostream &d_out;

    public:
        Generator(std::ostream &out);
        void charTable(Ranges const &ranges) const;

    private:
};
        
#endif
