#ifndef _INCLUDED_BLOCK_
#define _INCLUDED_BLOCK_

#include <iosfwd>
#include <vector>
#include <string>
#include <limits>

class Block
{
    size_t  d_line;
    std::string d_filename;               // the filename in which the block 
                                        // was found. The block's text itself
                                        // is in the Block's base class
    int     d_level;
    std::string d_str;
    
    public:
//        Block();
        Block(size_t lineno, std::string const &filename);
        
        void clear();
    
        void setOrAction();
        bool orAction() const;          // if true, Generator uses this
                                        // to let cases fall through

                                        // clears the previous block contents
        void open(size_t lineno, std::string const &filename);
        bool close();
        void indent();
        void operator+=(std::string const &text);
  
        size_t level() const;
        std::string const &str() const; // the block's contents
        size_t lineNr() const;
        std::string const &filename() const;
};

//inline Block::Block()
//:
//    d_level(0)
//{}

inline Block::Block(size_t lineno, std::string const &filename)
:
    d_line(lineno),
    d_filename(filename),
    d_level(0)
{}

inline void Block::setOrAction()
{
    d_level = std::numeric_limits<int>::max();
}

inline bool Block::orAction() const
{
    return d_level == std::numeric_limits<int>::max();
}

inline size_t Block::lineNr() const
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





