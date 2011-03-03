#include <iostream>
#include "scanner.h"

using namespace std;

int main()
{
	Scanner scanner;
	while (scanner.lex())
		cout << "[Identifier: " << scanner.match() << "]";

	return 0;
}
