#include "generator.ih"

void Generator::inputMembers(ostream &out) const
{
    key(out);
    bool hasInput = d_debug || d_options.has("input");

    out <<  
        "ScannerBase::Input::Input(std::istream &iStream)\n"
        ":\n"
        "    d_in(&iStream),\n"
        "    d_lineNr(1)";

    if (d_useBOL)
        out <<  ",\n"
                "    d_returnBOL(true)";

    out << "\n"        
        "{}\n"
        "\n"
        "size_t ScannerBase::Input::get()\n"
        "{\n";

    if (d_useBOL)
    {
        out <<
            "    if (d_returnBOL)                    // check for BOL\n"
            "    {\n";

        if (hasInput)
            out <<
            "        if (s_debug__)\n"
            "            s_out__ << \"Input::get() returns AT_BOL, returnBOL"
                                            " now false\\n\" << dflush__;\n";
        out <<
            "        d_returnBOL = false;\n"
            "        return AT_BOL;\n"
            "    }\n";
    }


    out <<
        "    switch (size_t ch = next())         // get the next input char\n"
        "    {\n"
        "        case '\\n':\n";

    if (d_useBOL)
    {
        out << "            d_returnBOL = true;\n";
        if (hasInput)
            out <<
            "        if (s_debug__)\n"
            "            s_out__ << \"Input::get() returnBOL now true\\n\"" 
                                                        " << dflush__;\n";
    }

    out << 
        "            ++d_lineNr;\n"
        "        // FALLING THROUGH\n"
        "\n"
        "        default:\n";

    if (hasInput)
        out <<
        "            if (s_debug__)\n"
        "                s_out__ << \"Input::get() returns \" << ch << " 
                                            "'\\n' << dflush__;\n";
    out <<
        "        return ch;\n"
        "    }\n"
        "}\n";
}
