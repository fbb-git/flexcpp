#include "generator.hh"

void Generator::warnOldImpHeader(string const &newIH)
{
    size_t pos = newIH.find_last_of("./");          // find dot or /

    string oldIH = 
        (pos != string::npos && newIH[pos] == '/' ? // no dot
            newIH                                   // use  old IH
        :
            newIH.substr(0, pos)                    // or cut the extension
        ) + ".ih";


    if (Stat(oldIH) and not Stat(newIH))
        wmsg << "Old style internal header file found: " << oldIH << "\n"
                "New style internal header file is generated: " << newIH << 
                                                                        "\n"
                "You may want to move " << oldIH << " to " << newIH << "\n"
                "and change #include \"" << oldIH << "\" into "
                        "#include \"" << newIH << "\" in C++ source files.\n"
                "Consider running `convert2hh'. Refer to section "
                        "PRECOMPILED HEADERS in the flexc++(1) man-page " 
                        "for additional information " << endl;
}
