#include "generator.ih"

void Generator::debugInit(ostream &out) const
{
    key(out);
    if (d_debug)
        out << 
        "    d_debug__(" << boolalpha << d_options.debug() << "),\n" <<
        "    d_beginStep__(" << d_options.beginStep() << "U),\n"
        "    d_endStep__(" << d_options.endStep() << "U),\n"
        "    d_step__(0),\n";
}   
