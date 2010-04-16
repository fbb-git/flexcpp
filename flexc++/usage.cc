#include "flexc++.ih"

    // Cf bisonc++'s usage.cc for an example of how to write usage().

void usage(string const &program_name)
{
	cout << 
	"\n" <<
	program_name << " by Richard Berendsen (rwberendsen@gmail.com),\n"
	"        Frank B. Brokken (f.b.brokken@rug.nl) and\n"
	"        Jean-Paul van Oosten (jpoosten@ai.rug.nl)\n"
	"\n"
	"Lexical Scanner Generator V "  << version << "\n"
	"Copyright (c) GPL " << year << ". NO WARRANTY.\n"
	"\n"
	"Usage: " << program_name << " [OPTIONS] FILENAME\n"
	"Where:\n"
	"  [OPTIONS] - zero or more optional arguments, where [OPTIONS] are:\n"
	"   --baseclassheader=<filename> (-b):\n"
	"           filename for the base class definition.\n"
	"   --baseclassskeleton=<path> (-B):\n"
	"            location of the baseclass header skeleton.\n"
	"   --classheader=<filename> (-c):\n"
	"           filename for the class definition.\n"
	"   --classskeleton=<path> (-C):\n"
	"            location of the class header skeleton.\n"
	"   --debug (-d):\n"
	"           generates debug output statements in the lex function\n"
	"   --dot:\n"
	"           no code is generated but graphviz-style graphs are produced\n"
    "           (by default NFA graphs).\n"
	"   --dfa:\n"
	"           this produces a DFA graph. The NFA graph is suppressed.\n"
	"   --forceclassheader:\n"
	"           overwrite an existing class header file.\n"
	"   --forceimplementationheader:\n"
	"           overwrite an existing implementation header file.\n"
	"   --help (-h):\n"
	"           display this help-message.\n"
	"   --implementationheader=<filename> (-i):\n"
	"           filename for the implementation header.\n"
	"   --implementationskeleton=<path> (-I):\n"
	"            location of the implementation header skeleton.\n"
    "   --interactive:\n"
    "           generates an interactive scanner\n"
	"   --lexskeleton=<path> (-P):\n"
	"            location of the lex function's skeleton.\n"
	"   --lexsource=<filename> (-l):\n"
	"           filename for the lex function's source.\n"
	"   --skeletondirectory=<path> (-S):\n"
	"            location of the skeleton directory.\n"
	"   --verbose (-V):\n"
	"           output information about DFA-creation and code generation,\n"
    "           specify repeatedly for more output\n"
	"   --version (-v):\n"
	"           display " << program_name << "'s version and terminate.\n"
    "\n"
	"  FILENAME  - name of the file containing the scanner specifications\n"

	<< '\n';

	// TODO: dot, dfa, nfa
}