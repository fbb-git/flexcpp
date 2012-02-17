#include "generator.ih"

void Generator::print(ostream &out) const
{
    if (!d_options.print())
        return;

    key(out);

    out << 
        "    std::cout << \"Token: \" << d_token__;\n"
        "    if (isprint(d_token__))\n"
        "        std::cout << \" (`\" << "
                                "static_cast<char>(d_token__) << \"')\";\n"
        "    std::cout << \", matched: `\" << d_matched << \"'\\n\";\n";
}
