#ifndef INCLUDED_USAGE_
#define INCLUDED_USAGE_

#include <string>
#include <vector>

#include <bobcat/fswap>

class States;
class State;
class Usage
{
    size_t *d_usage;
    size_t d_size;

    size_t d_subsets;

    public:
        enum Type
        {
            NOT_ORDERED,
            ORDERED
        };
        
        Usage(size_t size = 256);       // default:   1 << (sizeof(char) * 8)
        Usage(Usage const &other);
        Usage(Usage const &&tmp);
        ~Usage();

        Usage &operator=(Usage const &other);
        Usage &operator=(Usage const &&tmp);

        void swap(Usage &other);
        void add(Type type, std::string const &str);
        void add(States const &states);
        void add(size_t ch);

        void display(char const *hdr) const;

    private:
        static void incIf(char const &ch, size_t *next);

        static bool collision(std::string const &str, size_t const *next);
        static bool chCollision(unsigned char ch, unsigned char &pre, 
                                                        size_t const *next);
        static void countRanges(size_t &count, std::vector<size_t> &ranges);


        void updateUsage(std::string const &str, size_t const *next);
        void reduce(std::vector<size_t> &lowest);
        static void reassign(size_t &count, std::vector<size_t> &ranges);

        static void inspectState(State const &state, Usage &usage);

};

inline void Usage::swap(Usage &other)
{
    FBB::fswap(*this, other);
}
        
#endif
