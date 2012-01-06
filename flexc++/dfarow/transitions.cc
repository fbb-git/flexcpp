#include "dfarow.ih"

// Visit all ranges of input characters
// For each range value visit all states of the current set
// If a transition exists, add the state to transit to to the next set 
// Having visited all states for the current input char, compute the e-closure
// of the new set and determine its index in the stateSets.
// Add the input character and the just determined index to the current row's
// d_map. 

void DFARow::transitions()
{
        // visit all ranges of input characters
    for (size_t nr = 0, end = d_ranges->size(); nr++ != end; )    
    {
        StateSet &thisSet = (*d_stateSets)[d_thisIdx];

        StateSet nextSet;               // start a new set

            // visit all states of thisSet. Add the sets to transit to on the
            // current input character `nr' to the next set
        for (auto stateIdx: thisSet)
            transit(stateIdx, nr, nextSet);

        nextSet = d_states->eClosure(nextSet);

        if (nextSet.empty())
            continue;

        d_ranges->setUsed(nr);

        auto iter = find(d_stateSets->begin(), d_stateSets->end(), nextSet);

            // if not yet in d_stateSets add it.
        size_t idx;
        if (iter != d_stateSets->end()) 
            idx = iter - d_stateSets->begin();
        else
        {
            idx = d_stateSets->size();
            d_stateSets->push_back(nextSet);
        }
        d_map[nr] = idx;                // add the transition
    }
}








