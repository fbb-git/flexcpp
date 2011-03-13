$insert class.ih

$insert namespace-open

$insert ranges

$insert DFAs

$insert finAcs

$insert DFAbases


size_t \@Base::Input::nextChar()
{
    size_t nextChar;

    if (d_queue.empty())                    // queue empty: next char fm
    {
        nextChar = d_in->get();
        if (nextChar > 0xff)
            nextChar = AT_EOF;
    }
    else
    {
        nextChar = d_queue.front();
        d_queue.pop();
    }

    return nextChar;
}

size_t \@Base::Input::get()
{
    if (d_returnBOL)                        // check for BOL
    {
        d_returnBOL = false;
        return s_rangeOfBOL;
    }

    switch (size_t ch = nextChar())        // get the next input char
    {
        case AT_EOF:
        return s_rangeOfEOF;

        case '\n':
            d_returnBOL = true;             // the next range will
                                            // be rangeOfBOL
        // FALLING THROUGH
        default:
            d_lastRead = ch;
        return s_ranges[ch];
    }
}

\@Base::\@Base()
:
    d_out(&std::cout),
    d_input(std::cin),
    d_state(0),
    d_dfaBase(s_dfa)
{}


\@Base::\@Base(std::istream &iStream)
:
    d_out(&std::cout),
    d_input(iStream),
    d_state(0),
    d_dfaBase(s_dfa)
{}


\@Base::Input::Input(std::istream &iStream)
:
    d_in(&iStream),
    d_returnBOL(true),
    d_lastRead(~0U)
{}

void \@Base::echoFirst()
{}

int \@Base::matched()
{
    return 1;
}

\@Base::Range \@Base::transition(size_t range)
{
    int nextState = d_dfaBase[d_state][range];
    if (nextState == -1 && range == s_rangeOfBOL
}

int \@::lex__()
{
    d_state = 0;
    
    while (true)
    {
        size_t range = d_input.get();
        
        switch (transition(range))
        {
            case UNDEFINED:
                echoFirst();
            break;

            case MATCH:
            return matched();

            case CONTINUE:
            continue;

            case EXHAUSTED:
            return 0;
        }
    }
}

$insert namespace-close





