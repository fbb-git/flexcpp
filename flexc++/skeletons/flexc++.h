#ifndef SCANNER_H_INCLUDED_
#define SCANNER_H_INCLUDED_

#include <iosfwd>
#include "$baseClassHeader"

$insert namespace-open

class $className: public $classNameBase
{
    public:
        $className();
        $className($streamInfoClassName *streamInfo);

        int $lexFunctionName();

    private:
        int executeAction(int ruleNr);
		int lex__();
		int executeAction__(int ruleNr);
};

inline $className::$className()
:
    $classNameBase()
{}

inline $className::$className($streamInfoClassName *streamInfo)
:
    $classNameBase(streamInfo)
{}

inline int $className::$lexFunctionName()
{
	return lex__();
}

inline int $className::executeAction(int ruleNr)
{
	return executeAction__(ruleNr);
}

$insert namespace-close

#endif // SCANNER_H_INCLUDED_
