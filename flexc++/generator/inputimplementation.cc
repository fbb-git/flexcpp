#include "generator.ih"

void Generator::inputImplementation(ostream &out) const
{
    string const &implementation = d_options.inputImplementation();

    key(out);

    if (not implementation.empty())
    {
        out << "#include \"" << implementation << "\"\n";
        return;
    }


    bool hasInput = d_debug || d_options.has("input");

    out <<  
        d_baseclassScope << "Input::Input()\n"
        ":\n"
        "    d_in(0),\n"
        "    d_lineNr(1)";

    out << "\n"        
        "{}\n"
        "\n" <<
        d_baseclassScope << "Input::Input(std::istream *iStream)\n"
        ":\n"
        "    d_in(iStream),\n"
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
        "}\n"
        "\n"
        "size_t " << d_baseclassScope << "Input::next()\n"
        "{\n"
        "    size_t ch;\n"
        "\n"
        "    if (d_deque.empty())                    // deque empty: next char fm d_in\n"
        "    {\n"
        "        ch = d_in->get();\n"
        "        return *d_in ? ch : AT_EOF;\n"
        "    }\n"
        "\n"
        "    ch = d_deque.front();\n"
        "    d_deque.pop_front();\n"
        "\n"
        "    return ch;\n"
        "}\n"
        "\n"
        "void " << d_baseclassScope << "Input::reRead(size_t ch)\n"
        "{\n"
        "    if (ch < 0x100)\n"
        "    {\n";

    if (hasInput)
        out <<
        "            if (s_debug__)\n"
        "                s_out__ << \"Input::reRead(\" << ch << \")\\n\" <<\n"
        "                                                       dflush__;\n";

    out <<
        "        if (ch == '\\n')\n"
        "            --d_lineNr;\n"
        "        d_deque.push_front(ch);\n"
        "    }\n"
        "}\n"
        "\n"
        "void " << d_baseclassScope << 
                    "Input::reRead(std::string const &str, size_t fm)\n"
        "{\n"
        "    for (size_t idx = str.size(); idx-- > fm; )\n"
        "        reRead(str[idx]);\n"
        "}\n";
}
