#include "pattern.ih"

Pattern Pattern::characterClass(States &states, CharClass const &charClass)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::CHARSET, 
                                        charClass.str(), pair.second);

//    cout << "Pattern::characterClass: ";
//    for (auto ch: charClass.str())
//    {
//        if (isprint(ch)) 
//            cout << ch;
//        else
//            cout << ' ' << (int)ch << ' ';
//    }
//    cout << "\n"
//            "States: " << pair.first << " .. " << pair.second << '\n';

    Pattern ret(pair);
    return ret;
}
