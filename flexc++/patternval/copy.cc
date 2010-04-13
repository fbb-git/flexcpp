#include "patternval.ih"

spSemVal PatternVal::copy(States &states, SemVal &semval, size_t lower, 
                                                            size_t upper)
{
    PatternVal &pattern = downCast<PatternVal>(semval);

    size_t orgBegin = pattern.begin();
    size_t begin = orgBegin;
    size_t end   = pattern.end();

        // first copy the current pattern `lower' times
        // each time the latest pattern becomes the current pattern
        // thus ensuring that a `final' state is reached.
        //
    for (size_t idx = 0; idx < lower; ++idx)
    {
        size_t nextEnd = patternCopy(states, begin, end);
        begin = end;
        end = nextEnd;
    }

    spSemVal ret;

    if (upper == UINT_MAX)
    {
        size_t final = states.next();
        states[end] = State::factory(State::EMPTY, begin, final);
        ret = spSemVal(new PatternVal( {orgBegin, final} ));

        return ret ;
    }

        // then copy the current pattern until `upper' patterns have been
        // copied, each time remembering the last state of the copied pattern
        //
    vector<size_t> exitTransition;

    for (size_t idx = lower; idx < upper; ++idx)
    {
        exitTransition.push_back(end);
        size_t nextEnd = patternCopy(states, begin, end);
        begin = end;
        end = nextEnd;
    }

        // finally make an exit EMPTY transition from each of the last copied
        // patterns to the final state
        //
    for_each(exitTransition.begin(), exitTransition.end(),
        FnWrap::unary(exitPath, states, end));

    ret = spSemVal(new PatternVal( {orgBegin, end} ));
    return ret;
}
