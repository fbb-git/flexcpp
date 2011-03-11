#include "generator.ih"

void Generator::lexSource() const
{
    ifstream in;
    ofstream out;

    Errno::open(in,  d_options.lexSkeleton());
    Errno::open(out, d_options.lexSourcePath());

    filter(in, out);
}
