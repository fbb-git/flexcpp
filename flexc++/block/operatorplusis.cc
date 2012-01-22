#include "block.ih"

void Block::operator+=(string const &text)
{
    if (text[0] == '\n')
        d_str += '\n';
    else
        d_str += text == " " ? text : String::trim(text);
}

