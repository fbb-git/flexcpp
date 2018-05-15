#include "generator.ih"

void Generator::ranges(ostream &out) const
{
    string const &className = d_options.className();

    out <<
        "size_t const " << className << "Base::s_ranges_[] =\n" 
        "{";

    size_t const *charRange = d_ranges.alphabet();
    for (size_t begin = 0; begin != 256; ++begin)
    {
        if (begin % 25 == 0)
            out << "\n"
                     "    ";
        out << setw(2) << *charRange++ << ',';
    }
    
    out << "\n"
           "};\n";
}





