#include "dfa.ih"

void DFA::keepUniqueRows()
{
    std::vector<size_t> unique;

    inspectRows(unique);

    if (unique.back() == unique.size() - 1)
        return;

//    cerr << "UNIQUE: ";
//    copy(d_unique.begin(), d_unique.end(), 
//            ostream_iterator<size_t>(cerr, ","));
//    cerr << endl;

    for_each(d_row.begin(), d_row.end(), 
                                    FnWrap::unary(translate, unique));
    shrinkDFA(unique);
}

