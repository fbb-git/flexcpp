#include "generator.ih"

void Generator::inputImplementation(ostream &out) const
{
    string const &implementation = d_options.inputImplementation();

    key(out);

    if (not implementation.empty())
    {
        out << "#include \"" << implementation << "\"\n";
        return;
    }

    out <<  
        d_baseclassScope << R"(Input::Input()
:
    d_in(0),
    d_lineNr(1)
{}

)" << d_baseclassScope << 
                       R"(Input::Input(std::istream *iStream, size_t lineNr)
:
    d_in(iStream),
    d_lineNr(lineNr)
{}

size_t )" << d_baseclassScope << R"(Input::get()
{
    switch (size_t ch = next())         // get the next input char
    {
        case '\n':
            ++d_lineNr;
        [[fallthrough]]

        default:)";

    if (d_debug)
        out << R"raw(
            if (s_debug__)
            {
                s_out__ << "Input::get() returns ";
                if (isprint(ch))
                    s_out__ << '`' << static_cast<char>(ch) << '\'';
                else
                    s_out__ << "(int)" << static_cast<int>(ch);
                s_out__ << '\n' << dflush__;
            })raw";

    out << R"(
        return ch;
    }
}

size_t )" << d_baseclassScope << R"(Input::next()
{
    size_t ch;

    if (d_deque.empty())                // deque empty: next char fm d_in
    {
        if (d_in == 0)
            return AT_EOF;
        ch = d_in->get();
        return *d_in ? ch : static_cast<size_t>(AT_EOF);
    }

    ch = d_deque.front();
    d_deque.pop_front();

    return ch;
}

void )" << d_baseclassScope << R"(Input::reRead(size_t ch)
{
    if (ch < 0x100)
    {)";

    if (d_debug)
        out << R"(
        if (s_debug__)
            s_out__ << "Input::reRead(" << ch << ")\n" << dflush__;)";

    out << R"(
        if (ch == '\n')
            --d_lineNr;
        d_deque.push_front(ch);
    }
}

void )" << d_baseclassScope << 
                    R"(Input::reRead(std::string const &str, size_t fm)
{
    for (size_t idx = str.size(); idx-- > fm; )
        reRead(str[idx]);
}
)";

}

