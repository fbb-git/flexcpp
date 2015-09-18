#include "generator.hh"

void Generator::lexSource() const
{
    ifstream in;
    ofstream out;

    Exception::open(in,  d_options.lexSkeleton());
    Exception::open(out, d_options.lexSourcePath());

    filter(in, out);
}
