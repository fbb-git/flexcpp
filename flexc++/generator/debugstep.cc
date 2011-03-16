#include "generator.ih"

void Generator::debugStep(ostream &out) const
{
    if (!d_debugStep)
        return;

    key(out);

    out << 
    "        if (d_beginStep__ <= d_step__ && d_step__ < d_endStep__)\n"
    "        {\n"
    "            std::cout << \"\\nStep: \" << d_step__ << \", state: \" << "
                                            "state__() << \", char = \";\n"
    "            switch (ch)\n"
    "            {\n"
    "                case -2:\n"
    "                    std::cout << \"BOL\";\n"
    "                break;\n"
    "                case -1:\n"
    "                    std::cout << \"EOF\";\n"
    "                break;\n"
    "                default:\n"
    "                    if (isprint(ch))\n"
    "                        std::cout << '\\'' << static_cast<char>(ch) "
                                                            "<< '\\'';\n"
    "                    else\n"
    "                        std::cout << ch;\n"
    "                break;\n"
    "            }\n"
    "            std::cout  << \", range = \" << range << \", matched: " 
                                              "'\" << match() << \"' \";\n"
    "            std::cin.get();\n"
    "        }\n"
    "        ++d_step__;\n"; 
}
