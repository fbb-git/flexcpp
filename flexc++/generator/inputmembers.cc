#include "generator.ih"

void Generator::inputMembers(ostream &out) const
{
    key(out);
    out <<  
        "ScannerBase::Input::Input(std::istream &iStream)\n"
        ":\n"
        "    d_in(&iStream)";

    if (d_useBOL)
        out <<  ",\n"
                "    d_returnBOL(s_rangeOfBOL != s_finacIdx)\n";

    out <<
        "{}\n"
        "\n"
        "size_t ScannerBase::Input::get()\n"
        "{\n";

    if (d_useBOL)
        out <<
            "    if (d_returnBOL)                    // check for BOL\n"
            "    {\n"
            "        d_returnBOL = false;\n"
            "        return AT_BOL;\n"
            "    }\n";

    out <<
        "\n"
        "    switch (size_t ch = next())         // get the next input char\n"
        "    {\n"
        "        case '\\n':\n";

    if (d_useBOL)
        out << "            d_returnBOL = s_rangeOfBOL != s_finacIdx;\n";

    out << 
        "        // FALLING THROUGH\n"
        "\n"
        "        default:\n"
        "        return ch;\n"
        "    }\n"
        "}\n";
}
