#include "charrange.h"

#include <cctype>
#include <algorithm>

#include <bobcat/iterator>

#include "../flextypes/flextypes.h"

using namespace std;
using namespace FBB;

struct CharRange::AllString: public string
{
    AllString()
    :
        string(Iterator<char>::min(), Iterator<char>::max())
    {
        *this += *Iterator<char>::max();
    };

};
