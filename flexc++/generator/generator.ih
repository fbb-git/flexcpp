#include "generator.h"

#include <iterator>
#include <iomanip>

#include <bobcat/mstream>
#include <bobcat/datetime>
#include <bobcat/arg>
#include <bobcat/stat>
#include <bobcat/indent>
#include <bobcat/ranger>
#include <bobcat/exception>
#include <bobcat/pattern>

#include "../ranges/ranges.h"
#include "../states/states.h"
#include "../state/state.h"
#include "../options/options.h"
#include "../dfarow/dfarow.h"
#include "../dfa/dfa.h"
#include "../startconditions/startconditions.h"
#include "../templates/templates.h"

extern char version[];

using namespace std;
using namespace FBB;

inline size_t Generator::dfaCols() const
{
    return d_ranges.nRanges() + RF_INDICES; 
}

inline void Generator::outStartState(string const &name, ostream &out)
{
    out << "        " << name << ",\n";
}

inline bool Generator::debugCodeRequired() const    // see also insert.cc
{
    return d_debug || d_options('R');
}
