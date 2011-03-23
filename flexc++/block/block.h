#ifndef _INCLUDED_BLOCK_
#define _INCLUDED_BLOCK_

#include <iosfwd>
#include <vector>
#include <string>

class Block
{
    size_t  d_line;
    std::string d_source;               // the source in which the block 
                                        // was found. The block's text itself
                                        // is in the Block's base class
    int     d_level;
    std::string d_block;
    
    public:
        Block();

        void clear();
                                        // clears the previous block contents
        void open(size_t lineno, std::string const &source);
        bool close();

        void operator+=(int ch);
        void operator+=(std::string const &text);
  
        operator bool() const;          // return true if a block is active

                                        // add text if a block is active,
        bool operator()(std::string const &text); 
        bool operator()(int ch);        // returning true if active

        size_t level() const;
        std::string const &str() const; // the block's contents

        std::string const &source() const;
        size_t line() const;
};

inline Block::Block()
:
    d_level(0)
{}

inline void Block::operator+=(std::string const &text)
{
    d_block += text;
}

inline void Block::operator+=(int ch)
{
    d_block += static_cast<char>(ch);
}

inline Block::operator bool() const
{
    return d_level;
}

inline size_t Block::line() const
{
    return d_line;
}

inline std::string const &Block::source() const
{
    return d_source;
}

inline size_t Block::level() const
{
    return d_level;
}

inline std::string const &Block::str() const
{
    return d_block;
}


#endif

