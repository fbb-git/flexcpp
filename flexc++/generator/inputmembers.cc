#include "generator.ih"

void Generator::inputMembers(ostream &out) const
{
    key(out);
    bool hasInput = d_debug || d_options.has("input");

    out <<  
        d_baseclassScope << "Input::Input()\n"
        ":\n"
        "    d_in(0),\n"
        "    d_lineNr(1)";

    out << "\n"        
        "{}\n"
        "\n" <<
        d_baseclassScope << "Input::Input(std::istream &iStream)\n"
        ":\n"
        "    d_in(&iStream),\n"
        "    d_lineNr(1)";

    out << "\n"        
        "{}\n"
        "\n"
        "size_t " << d_baseclassScope << "Input::get()\n"
        "{\n";

    out <<
        "    switch (size_t ch = next())         // get the next input char\n"
        "    {\n"
        "        case '\\n':\n";

    out << 
        "            ++d_lineNr;\n"
        "        // FALLING THROUGH\n"
        "\n"
        "        default:\n";

    if (hasInput)
        out <<
        "            if (s_debug__)\n"
        "            {\n"
        "                s_out__ << \"Input::get() returns \";\n"
        "                if (isprint(ch))\n"
        "                    s_out__ << '`' << static_cast<char>(ch) << "
                                                                "'\\\'';\n"
        "                else\n"
        "                    s_out__ << '#' << static_cast<int>(ch);\n"
        "                s_out__ << '\\n' << dflush__;\n"
        "            }\n";

    out <<
        "        return ch;\n"
        "    }\n"
        "}\n";
}
