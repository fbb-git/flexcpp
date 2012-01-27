#include "pattern.ih"

Pattern Pattern::characterClass(States &states, CharClass const &charClass)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::CHARSET, 
                                        charClass.str(), pair.second);

//    cout << "SET: ";
//    string const &str =  downCast<CharClass>(charClass).str();
//    for (auto iter = str.begin(); iter != str.end(); ++iter)
//        if (isprint(*iter)) 
//            cout << *iter;
//        else
//            cout << ' ' << (int)*iter << ' ';
//    cout << '\n';
    
    Pattern ret(pair);
    return ret;
}
