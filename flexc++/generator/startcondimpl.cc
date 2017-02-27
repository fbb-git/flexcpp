#include "generator.ih"

void Generator::startCondImpl(ostream &out) const
{
    key(out);

    string const &scName = d_options.startConditionName();
    string const &className = d_options.className();

                    // inserted in flexc++base.h
    out << 

"inline " << className << "Base::" << scName << " constexpr " << className << 
                                                        "Base::SC(int sc)\n"
"{\n"
"    return as<" << scName << ">(sc);\n"
"}\n"
"\n"
"inline int constexpr " << className << "Base::SC(" << scName << " sc)\n"
"{\n"
"    return as<int>(sc);\n"
"}\n"
"\n"
"inline " << className << "Base::" << scName << " " << className << 
                                            "Base::startCondition() const\n"
"{\n"
"    return SC(d_startCondition);\n"
"}\n"
"\n"
"inline void " << className << "Base::begin(" << scName << 
                                            " startCondition)\n"
"{\n";

    if (debugTest())
    {
        out << "    if (s_debug__)\n"
               "        s_out__ << \"Switching to " << scName << 
                                   " # \" << as<int>(startCondition) << "
                                                                "\\n;\n";
    
                     // s_out__ << "Switching to <scName> # 5\n";
    }

    out <<
"    // d_state is reset to 0 by reset__()\n"
"    d_dfaBase__ = s_dfaBase__[d_startCondition = SC(startCondition)];\n"
"}\n";

}




