#include "scanner.ih"

void Scanner::maybeSwitchStream()
{
    bool isComment = false;

    string text = String::trim(matched().substr(sizeof("//include")));

    if (text[0] == '"' && *text.rbegin() == '"')    // "s around the name
        text = text.substr(1, text.length() - 2);   // rm the "s
    else                                            // blanks in the name, but
        isComment = text.find_first_of(" \t")       // no surrounding "s
                    != string::npos;

    if (not isComment)
        isComment = access(text.c_str(), R_OK) != 0;// the file must exist
                                                    // or //incl. is comment
    if (isComment)
    {
        wmsg << '`' << matched() << "' considered comment" << endl;
        return;
    }

    setLineTags(text);
    pushStream(text);
}


