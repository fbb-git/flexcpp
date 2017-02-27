#include "generator.ih"

void Generator::startCondDecl(ostream &out) const
{
    key(out);

    string const &scName = d_options.startConditionName();

                    // inserted in flexc++base.h
    out << 
"    " << scName << " startCondition() const;   // current start condition\n"
"    void            begin(" << scName << " startCondition);\n"
"\n"
"private:\n"
"    static " << scName << " constexpr SC(int sc);\n"
"    static int constexpr SC(" << scName << " sc);\n";

}
