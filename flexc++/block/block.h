#ifndef _INCLUDED_BLOCK_
#define _INCLUDED_BLOCK_

#include <iosfwd>
#include <vector>
#include <string>

class Block
{
    size_t  d_line;
    std::string d_filename;               // the filename in which the block 
                                        // was found. The block's text itself
                                        // is in the Block's base class
    int     d_level;
    std::string d_str;
    
    public:
        Block();

        void clear();
                                        // clears the previous block contents
        void open(size_t lineno, std::string const &filename);
        bool close();
        void indent();
        void operator+=(std::string const &text);
  
//        operator bool() const;          // return true if a block is active
        size_t level() const;
        std::string const &str() const; // the block's contents
        size_t line() const;
        std::string const &filename() const;
};

inline Block::Block()
:
    d_level(0)
{}

inline size_t Block::line() const
{
    return d_line;
}

inline std::string const &Block::filename() const
{
    return d_filename;
}

inline size_t Block::level() const
{
    return d_level;
}

inline void Block::indent()
{
    d_str += std::string((d_level - 1) * 4, ' ');
}

inline std::string const &Block::str() const
{
    return d_str;
}

inline std::ostream &operator<<(std::ostream &out, Block const &block)
{
    return out << block.str();
}

#endif





