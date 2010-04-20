#include "block.ih"

void Block::open(size_t lineno, string const &source)
{
    if (d_level)            // existing block ?
        *this += '{';       // add open curly bracket to the block's code
    else
    {                       // assign line if no braces were open yet
        clear();
        d_line = lineno;
        d_source = source;
    }
        
    ++d_level;                  // here, as clear() will reset d_level
}
