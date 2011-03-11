#include "$implementationHeader"

namespace { // anonymous


} // anonymous


$insert namespace-open

$insert ranges


size_t $classNameBase::Input::nextChar()
{
    size_t nextChar;

    if (d_queue.empty())                    // queue empty: next char fm
    {
        nextChar = d_in.get();
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

size_t $classNameBase::Input::nextRange()
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

$className::Transition::Result $className::Transition::operator[](size_t range)
{
    size_t nextState = d_dfa[d_state][range];
}


int $className::lex__()
{
    while (true)
    {
        size_t range = d_input.nextRange();
        
        switch (d_transition[range])
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





