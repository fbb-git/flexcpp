#include "block.ih"

std::string const &Block::str() const
{
    if (not d_lineAdded && Options::instance().lines())
    {
        ostringstream out;
        out << "#line " << d_line  << " \"" << d_source << "\"\n" 
                "            " << d_block;
        d_block = out.str();
        d_lineAdded = true;
    }

    return d_block;
}

