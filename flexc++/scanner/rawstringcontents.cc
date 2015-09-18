#include "scanner.hh"

string Scanner::rawStringContents() const
{
    //          d_rawstring =  )..."
    //          raw string is: R"...( <-- contents --> )..."
    //          so length - (2 x d_rawstring.length() + 1) is the 
    //          contents length

    return matched().substr(
                d_rawString.length() + 1,                   // + 1 for the R
                length() - ((d_rawString.length() << 1) + 1)
            );
}
