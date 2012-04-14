#include "generator.ih"

void Generator::construction(States const &states)
{
    if (not d_options('K')) 
        return;

    ofstream out;

    Errno::open(out, d_options.constructionPath());
    
    out <<  "RANGES:\n" << 
            d_ranges << "\n"
            "\n"
            "RULES:\n" << 
            d_rules << "\n"
            "\n"
            "STATES:\n" 
            << states << "\n"
            "\n" <<
            d_dfas << '\n';
}
