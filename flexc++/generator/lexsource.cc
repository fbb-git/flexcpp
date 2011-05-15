#include "generator.ih"

void Generator::lexSource() const
{
    ifstream in;
    ofstream out;

    Errno::open(in,  d_options.lexSkeleton());
    Errno::open(out, d_options.lexSourcePath());

    if (d_arg.option('V'))
        cout << "lex-function source file: " << 
                                        d_options.lexSourcePath() << '\n';

    filter(in, out);
}
