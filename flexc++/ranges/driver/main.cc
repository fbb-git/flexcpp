#include <iostream>
#include <climits>

#include "../usage.h"

using namespace std;

int main()
{
    string str;

    cout << "Enter text on lines, sorted chars or not\n";

    Usage usage;

    while (getline(cin, str))
    {
        usage.add(str);
        usage.display("Final counts:");
        cout << "? ";
    }
}

    


