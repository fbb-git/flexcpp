#include "generator.ih"

void Generator::construction(States const &states)
{
    if (not d_arg.option('K'))      // construction not requested
        return;

    d_constructionFilename = d_arg[0];
    size_t pos = d_constructionFilename.rfind('.');
    if (pos != string::npos)
        d_constructionFilename.resize(pos);
    d_constructionFilename += ".output";

    ofstream out;
    Errno::open(out, d_constructionFilename);

    out << "RANGES:\n" << 
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
