#include "generator.ih"

void Generator::debugStep(ostream &out) const
{
    if (!d_debug)
        return;

    key(out);

    out << 
    indent << "if (d_beginStep__ <= d_step__ && d_step__ < d_endStep__)\n" <<
    indent << "{\n" <<
    indent << "    std::cout << \"\\nState: \" << state__() << \", "
                                                            "char = \";\n" <<
    indent << "    switch (ch)\n" <<
    indent << "    {\n" <<
    indent << "        case -2:\n" <<
    indent << "            std::cout << \"BOL\";\n" <<
    indent << "        break;\n" <<
    indent << "        case -1:\n" <<
    indent << "            std::cout << \"EOF\";\n" <<
    indent << "        break;\n" <<
    indent << "        default:\n" <<
    indent << "            if (isprint(ch))\n" <<
    indent << "                std::cout << '\\'' << static_cast<char>(ch) "
                                                            "<< '\\'';\n" <<
    indent << "            else\n" <<
    indent << "                std::cout << ch;\n" <<
    indent << "        break;\n" <<
    indent << "    }\n" <<
    indent << "    std::cout  << \", range = \" << range << \", matched: " 
                                              "'\" << match() << \"' \";\n" <<
    indent << "}\n" <<
    indent << "++d_step++;\n"; 
}
