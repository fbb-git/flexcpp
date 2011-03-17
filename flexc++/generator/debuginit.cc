#include "generator.ih"

void Generator::debugInit(ostream &out) const
{
    if (!d_debugStep)
        return;

    key(out);

    out << 
    "    d_beginStep__(" << d_options.beginStep() << "U),\n"
    "    d_endStep__(" << d_options.endStep() << "U),\n"
    "    d_step__(0),\n";
}   
