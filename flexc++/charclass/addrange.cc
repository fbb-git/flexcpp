#include "charclass.ih"

void CharClass::addRange(char from, char to)
{
    if (from > to)
        lineMsg() << '`' << from << "' beyond `" << to << 
                    "' in character set" << err;
    else
    {
        for (; from <= to; ++from)
            d_set.insert(from);
    }

    d_last.erase();
}
