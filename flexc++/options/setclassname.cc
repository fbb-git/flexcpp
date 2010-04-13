#include "options.ih"

void Options::setClassName(string const &name)
{
	if (d_className.size())
		cerr << "%option classname (--class-name) specified multiple times\n";
	else
        d_className = undelimit(name);
}
