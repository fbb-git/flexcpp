#include <iostream>
#include <string>

#include "../charclass.h"

using namespace std;

int main(int argc, char **argv)
{
    while (true)
    {
        cout << "Enter chars do define a set, [ starts named. "
                            "Return to signal 'done'\n";
        string str;
        getline(cin, str);
        if (str.empty())
            break;
        cout << "Entered: `" << str << "'\n";
        spSemVal sp = str[0] == '[' ? CharClass::predefined(str) : 
                                            CharClass::escape(str);
        cout << '`' << dynamic_cast<CharClass &>(*sp).str() << "'\n";
    }
}








