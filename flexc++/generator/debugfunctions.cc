#include "generator.ih"

void Generator::debugFunctions(std::ostream &out) const
{
    key(out);

    if (!d_debug && !d_options.hasNames())
    {
        out << 
            "void " << d_baseclassScope << "setDebug(bool onOff)\n"
            "{}\n"
            "\n"
            "bool " << d_baseclassScope << "debug() const\n"
            "{\n"
            "    return false;\n"
            "}\n";
        
        return;
    }


    out << 
    "bool    " << d_baseclassScope << "s_debug__ = true;\n"
    "std::ostringstream " << d_baseclassScope << "s_out__;\n"
    "\n" 
    "void " << d_baseclassScope << "setDebug(bool onOff)\n"
    "{\n"
    "    s_debug__ = onOff;\n"
    "}\n" 
    "\n"
    "bool " << d_baseclassScope << "debug() const\n"
    "{\n"
    "    return s_debug__;\n"
    "}\n"
    "\n"
    "std::ostream &" << d_baseclassScope << "dflush__(std::ostream &out)\n"
    "{\n"
    "    std::ostringstream &s_out__ = "
                            "dynamic_cast<std::ostringstream &>(out);\n"
    "\n"
    "    std::cout << \"    \" << s_out__.str() << std::flush;\n"
    "    s_out__.clear();\n"
    "    s_out__.str(\"\");\n"
    "    return out;\n"
    "}\n";
}







