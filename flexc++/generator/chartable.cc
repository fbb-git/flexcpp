#include "generator.ih"

void Generator::charTable()
{
    d_out <<
            "   // s_ranges: use (unsigned) characters as index to obtain\n"
            "   //           that character's range-number.\n"
            "   //           Ranges of BOL and EOF are in variables below.\n"
            "   //           Range values 0 indicate `not used'\n"
            "    size_t const ScannerBase::s_ranges[] =\n" 
            "    {";

    size_t const *charRange = d_ranges.ranges();
    for (size_t begin = 0; begin != 256; ++begin)
    {
        if (begin % 20 == 0)
            d_out << "\n"
                     "        ";
        d_out << setw(2) << *charRange++ << ',';
    }
    
    d_out << "\n"
         "    };\n"
         "    size_t const ScannerBase::s_rangeOfBOL = " << 
                                            d_ranges.rangeOfBOL() << ";\n"
         "    size_t const ScannerBase::s_rangeOfEOF = " << 
                                            d_ranges.rangeOfEOF() << ";\n";
}





