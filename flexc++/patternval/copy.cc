/*
#include "patternval.ih"

////////////////////////////////
#include <iostream>

spSemVal PatternVal::copy(States &states, SemVal &semval, size_t lower, 
                                                            size_t upper)
{
    PatternVal &pattern = downCast<PatternVal>(semval); // the pattern to copy

cout << "Pattern to copy:\n";
cout  << states << '\n';

    size_t orgBegin = pattern.begin();
    size_t begin = orgBegin;
    size_t end   = pattern.end();

    
        // copy the current pattern `lower - 1' times and concatenate it 
        // to the existing pattern

    for (size_t idx = 1; idx < lower; ++idx)
    {
        size_t nextEnd = patternCopy(states, begin, end);
        begin = end;
        end = nextEnd;
    }

cout << "Multiplied pattern copy:\n";
cout  << states << '\n';


    spSemVal ret;

    if (upper == UINT_MAX)          // no upper limit: optionally cycle back
    {
        size_t final = states.next();
        states[end] = State::factory(State::EMPTY, begin, final);
        ret = spSemVal(new PatternVal( {orgBegin, final} ));

        return ret;
    }

    // There is an upper limit: (upper - lower) optional repetitions

        // copy the current pattern until `upper' patterns have been
        // copied, each time remembering the last state of the copied pattern
        // in the vector `exitTransition'

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
    for_each(
        exitTransition.begin(), exitTransition.end(),
        [&](size_t from)
        {
            states[from].data().set2nd(end);
        }
    );

    ret = spSemVal(new PatternVal( {orgBegin, end} ));
    return ret;
}
*/


