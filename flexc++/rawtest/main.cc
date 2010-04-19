#include "main.ih"

namespace 
{
    size_t g_lo;
    size_t g_hi;

    ostream null(0);
}

ostream &msg(size_t level)
{
    return g_lo <= level && level <= g_hi ? cerr : null;
}
        

int main(int argc, char **argv)
try
{
    if (argc > 1)
    {
        g_lo = A2x(argv[1]);
        g_hi = g_lo;
    }
    if (argc > 2)
        g_hi = A2x(argv[2]);

    cout << "usage: read stdin. use numeric argument: higher = more info\n"
            "       two numeric args: all msg in 1st-2nd levels are shown\n"
            "\n";


    Scanner scanner;

    while (scanner.lex() != -1)
        ;

}
catch (...)
{
    return 1;
}
