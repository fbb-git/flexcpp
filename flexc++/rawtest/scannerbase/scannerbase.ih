#include "scannerbase.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

ostream &msg(size_t level);

inline bool ScannerBase::plainChar() const
{
    return d_range < s_rangeOfEOF;
}

inline int ScannerBase::acceptRule() const
{
    return d_dfa[d_state][s_acceptIdx];
}

inline ScannerBase::Accept &ScannerBase::acceptRecord()
{
    return d_accept[d_dfa[d_state][s_acceptIdx]];
}

inline int ScannerBase::acceptStateType() const
{
    return d_dfa[d_state][s_acceptIdx + 1];
}

