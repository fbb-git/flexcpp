#include "generator.ih"

void Generator::debugFunctions(std::ostream &out) const
{
    key(out);

    if (not debugCodeRequired())
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
    "bool    " << d_baseclassScope << "s_debug_ = true;\n"
    "std::ostringstream " << d_baseclassScope << "s_out_;\n"
    "\n" 
    "void " << d_baseclassScope << "setDebug(bool onOff)\n"
    "{\n"
    "    s_debug_ = onOff;\n"
    "}\n" 
    "\n"
    "bool " << d_baseclassScope << "debug() const\n"
    "{\n"
    "    return s_debug_;\n"
    "}\n"
    "\n"
    "std::ostream &" << d_baseclassScope << "dflush_(std::ostream &out)\n"
    "{\n"
    "    std::ostringstream &s_out_ = "
                            "dynamic_cast<std::ostringstream &>(out);\n"
    "\n"
    "    std::cout << \"    \" << s_out_.str() << std::flush;\n"
    "    s_out_.clear();\n"
    "    s_out_.str(\"\");\n"
    "    return out;\n"
    "}\n";
}







