#include "generator.ih"

void Generator::pushFront(ostream &out) const
{
    if (d_useBOL)
    {
        key(out);
        out << 
        "   // when this function is called there is no continuation, "
                                                    "but transitions\n"
        "   // originally started at BOL. Maybe a match not starting at BOL "
                                                    "is possible\n"
        "   // and so all characters read so far are returned to the input,\n"
        "   // startsAtBOL is cleared later on and lex__ continues\n"
        "void " << d_baseclassScope << "pushFront__(size_t ch)\n"
        "{\n";

        if (d_debug || d_options.has("action"))
            out <<  "    s_out__ << \"PUSH_FRONT\\n\" << dflush__;\n";

        out <<
        "    d_input.push_front(ch);\n"
        "    d_input.push_front(d_matched, 0);\n"
        "}\n";
    }
}
