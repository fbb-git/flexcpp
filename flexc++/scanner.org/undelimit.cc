#include "scanner.ih"

// From bisonc++
void Scanner::undelimit()
{
	if (strchr("\"", d_match[0]) == 0)
		return;

    d_match = d_match.substr(1, d_match.size() - 2);
}
