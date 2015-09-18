#include "parser.hh"

Pattern Parser::quotes()
{
    std::string &&str = String::unescape(
                        d_matched.substr(1, d_scanner.length() - 2));

    if (str.length() != 1)
    {
        d_doError = false;
        emsg << "Quoted character constants require one character" << endl;
        ERROR();
    }

    return rawText(str);
}
