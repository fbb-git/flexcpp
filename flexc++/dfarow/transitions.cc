#include "dfarow.ih"

// visit all input character ranges
// for each input character range visit all states of the current set
// if a transition add the state to transit to to the next set and add (for
// each input character the next set of states to the stateSets, unless it is
// already there.

void DFARow::transitions()
{
    StateSet &thisSet = (*d_stateSets)[d_thisIdx];

    for (size_t nr = 0; nr++ != d_nRanges; )
    {
        StateSet nextSet;
                                        // determine all non-e transitions 
                                        // from this set of states
        for_each(thisSet.begin(), thisSet.end(), 
                                 FnWrap::unary(transit, *this, nr, nextSet));

        nextSet = d_states->eClosure(nextSet);

        auto iter = find(d_stateSets->begin(), d_stateSets->end(), nextSet);

                                        // if not yet in d_stateSets add it.
        if (iter == d_stateSets->end())
            d_stateSets->push_back(nextSet);

                                        // add the transition
        d_map[nr] = iter - d_stateSets->begin();
    }
}
