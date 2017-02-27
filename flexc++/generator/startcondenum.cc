#include "generator.ih"

void Generator::startCondEnum(ostream &out) const
{
    key(out);

    out << indent << "enum class " << d_options.startConditionName() << "{\n";

    for (auto it = d_rules.begin(), end = d_rules.endUserSC(); it != end; ++it)
        out <<  indent << "    " << it->first << ",\n";

    out << indent << "};\n";
}
