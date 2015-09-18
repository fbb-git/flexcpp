#include "generator.hh"

bool Generator::conflicts() const
{
    bool ret = false;

    emsg.noLineNr();
    emsg.setLineTag("");

    string const &classHeaderPath = d_options.classHeaderPath();

    if (Stat(classHeaderPath))
    {
        ret = errExisting(classHeaderPath, "class-name",
                                "^class " + d_options.className() + "\\b")
              or ret;

        if (not d_options.nameSpace().empty())
            ret = errExisting(classHeaderPath, "namespace",
                            "^namespace " + d_options.nameSpace() + "\\b")
                  or ret;

        ret = errExisting(classHeaderPath, Options::baseclassHeaderSpec(), 
                    "^#include \"" + d_options.baseclassHeaderName() + '"')
              or ret;
    }

    string const &implementationHeader = d_options.implementationHeaderPath();

    if (Stat(implementationHeader))
        ret = errExisting(implementationHeader, d_options.classHeaderSpec(), 
                        "^#include \"" + d_options.classHeaderName() + '"')
              or ret;

    return ret;
}

