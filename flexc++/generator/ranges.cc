#include "generator.ih"

void Generator::ranges(ostream &out) const
{
    string const &className = d_options.className();

    out <<
        "// s_ranges: use (unsigned) characters as index to obtain\n"
        "//           that character's range-number.\n"
        "//           Ranges for BOL and EOF are in constants in the\n"
        "//           class header file\n"
        "size_t const " << className << "Base::s_ranges[] =\n" 
        "{";

    size_t const *charRange = d_ranges.ranges();
    for (size_t begin = 0; begin != 256; ++begin)
    {
        if (begin % 20 == 0)
            out << "\n"
                     "    ";
        out << setw(2) << *charRange++ << ',';
    }
    
    out << "\n"
           "};";

//        "\n"
//        "    size_t const rangeOfBOL = " << d_ranges.rangeOfBOL() << ";\n"
//        "    size_t const rangeOfEOF = " << d_ranges.rangeOfEOF() << ";\n"
//        "\n";
}





