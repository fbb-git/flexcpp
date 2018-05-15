#include "options.ih"

void Options::setNameSpaceIdentifier()
{
    for (int ch: d_nameSpace)
    {
        if (isalnum(ch) || ch == '_')
            d_nameSpaceIdentifier += ch;
    }
}
