#include "state.ih"

#include <ostream>
#include <algorithm>
#include <iterator>

namespace
{
    char const *flagName[] = 
    {
        "NO_LOP ",
        "ACCEPT ",
        "PRE    ",
        "POST   "
    };
}

ostream &operator<<(ostream &out, State const &state)
{
    size_t type = state.type();

    if (type == State::UNDETERMINED__)
        return(out);

    out << flagName[state.flag()];

    if (type < State::UNDETERMINED__)
        out << type;
    else if (type == State::EMPTY)
        out << 'E';
    else if (type == State::FINAL)
        out << 'F';
    else if (type == State::CHARSET)
        out << 'S';
    else
        out << '*' << type << '*';

    out  << " -> " << state.next1() << ", " << state.next2();

    if (type == State::CHARSET)
    {
        string const &str = SemVal::downCast<StateString>(state.data()).str();
        out << " [ ";
        for (auto iter = str.begin(), end = str.end(); iter != end; ++iter)
            out << 
                static_cast<size_t>(static_cast<unsigned char>(*iter)) << ' ';
        out << ']';
    }

    return out;
}



