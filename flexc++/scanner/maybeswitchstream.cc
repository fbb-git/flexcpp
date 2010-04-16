#include "scanner.ih"

void Scanner::maybeSwitchStream()
{
    string text = String::trim(d_match.substr(sizeof("//include")));

    if (text[0] == '"' && *text.rbegin() == '"')    // "s around the name
        text = text.substr(1, text.length() - 2);   // rm the "s
    
    else if (text.find_first_of(" \t") != string::npos) // blanks need "s
    {
        lineMsg() << '`' << d_match << "' considered comment" << warning;
        return;
    }

    pushStreamInfo(new StreamInfoType(text));
}