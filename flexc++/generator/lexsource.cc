#include "generator.ih"

void Generator::lexSource() const
{
    ifstream in;
    ofstream out;

    Errno::open(in,  d_options.lexSkeleton());
    Errno::open(out, d_options.lexSourcePath());

    cout << "Reading " << d_options.lexSkeleton() << '\n';
    cout << "Writing " << d_options.lexSourcePath() << '\n';
    filter(in, out);
}
