#include "dfa.h"

#include <iostream>

#include <ostream>
#include <iomanip>

#include <bobcat/tablelines>
#include <bobcat/align>
#include <bobcat/table>
#include <bobcat/mstream>

#include "../rules/rules.h"
#include "../states/states.h"
#include "../ranges/ranges.h"
#include "../options/options.h"

using namespace std;
using namespace FBB;

    // return the index of the DFA row containing 'nextRow'
inline size_t DFA::available(DFARow const &nextRow)
{
    return find(d_row.begin(), d_row.end(), nextRow) - d_row.begin();
}








