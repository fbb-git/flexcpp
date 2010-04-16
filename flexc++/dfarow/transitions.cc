#include "dfarow.ih"

// visit all ranges of input characters
//
// for each range value visit all states of the current set
// 
// if a transition exists, add the state to transit to to the next set 
// 
// having visited all states for the current input char, compute the e-closure
// of the new set and determine its index in the stateSets.
//
// add the input character and the just determined index to the current row's
// d_map. 

#include <iostream>
#include <algorithm>
#include <iterator>

void DFARow::transitions()
{
        // visit all ranges of input characters
    for (size_t nr = 0, end = d_ranges->size(); nr++ != end; )    
    {
        StateSet &thisSet = (*d_stateSets)[d_thisIdx];

        StateSet nextSet;               // start a new set

            // visit all states of thisSet. Add the sets to transit to on the
            // current input character `nr' to the next set
        for_each(thisSet.begin(), thisSet.end(), 
                                 FnWrap::unary(transit, *this, nr, nextSet));

        bool twoEdges = false;
        bool inheriting = false;
        nextSet = d_states->eClosure(nextSet, twoEdges, inheriting);

        if (inheriting)
            setInheriting();
            // cout << "INHERITING ACCEPT STATE\n";

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









