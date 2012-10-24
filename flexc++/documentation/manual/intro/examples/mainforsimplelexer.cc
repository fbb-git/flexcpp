#include <iostream>
#include "Scanner.h"

using namespace std;

int main()
{
	Scanner scanner;
	while (scanner.lex())
		cout << "[Identifier: " << scanner.matched() << "]";
}
