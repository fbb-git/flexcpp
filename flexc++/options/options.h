#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <iostream>
#include <string>
#include <set>

#include "../flextypes/flextypes.h"

namespace FBB
{
    class Arg;
}

class Options: private FlexTypes
{
    enum PathType
    {
        FILENAME,
        PATHNAME
    };

    FBB::Arg const &d_arg;

    std::string const *d_matched = 0;   // text matched by the scanner,
    std::string const *d_rawString = 0; // initialized by the Parser
    std::string d_undelimit;            // used by textOf to remove the "
                                        // around a *d_matched string

        // The next four variables cannot have path-specifications with their
        // option/directive values. After their values have been obtained,
        // the setPathStrings member, called from Parser::cleanup, prefixes 
        // their values with the target directory's value
    std::string d_baseClassHeader;      // these options/directives cannot 
    std::string d_classHeader;          // have path names. See 
    std::string d_implementationHeader; // setPathStrings and assign/accept
    std::string d_lexSource;

    std::string d_baseClassSkeleton;
    std::string d_className;
    std::string d_classSkeleton;
    std::string d_constructionPath;
    std::string d_filenames;
    std::string d_implementationSkeleton;
    std::string d_inputImplementation;
    std::string d_inputInterfacePath;
    std::string d_lexFunctionName;
    std::string d_lexSkeleton;
    std::string d_nameSpace;
    std::string d_skeletonDirectory;
    std::string d_targetDirectory;
    std::string d_infile;

    bool d_interactive = false;
    bool d_lines;
    bool d_print = false;
    bool d_debug = false;
    bool d_matchedRules;
    bool d_verbose;
    bool d_caseSensitive;

        // contains the names of used options/directives.  
        // Generator may warn if specified for already existing .h or .ih
        // files 
        // Warnings are issued for:
        //  class header:           class-name mismatch
        //                          namespace mismatch
        //                          not including the baseclass-header
        // implementation header:   not including the class header

    static std::set<std::string> s_warnOptions;    

    enum 
    {
        MAX_DEPTH = 10 
    };
    size_t d_maxDepth = MAX_DEPTH;

            // strings containing default file and other names
    static char s_defaultLexFunctionName[];
    static char s_defaultSkeletonDirectory[];
    static char s_defaultClassName[];
    static char s_defaultLexfunSource[];

    static Options *s_options;
    static void (*s_regexCall)(char const *funName);

    public:
        bool specified(std::string const &option) const;
        
        static Options &instance();

        Options(Options const &other) = delete;

        void setParserInfo(std::string const &matched, 
                           std::string const &rawString);

        void setAccessorVariables();
        void showFilenames() const;
        void setPathStrings();

        bool caseSensitive() const;
        bool debug() const;
        bool interactive() const;
        bool lines() const;
        bool print() const;
        bool verbose() const;
        bool operator()(int opt) const;
        bool operator()(char const *opt) const;

        std::size_t maxDepth() const;

        std::string const &classHeaderPath() const;
        std::string classHeaderName() const;

        std::string const &baseclassHeaderPath() const;
        std::string baseclassHeaderName() const;

        std::string const &implementationHeaderPath() const;

        std::string const &lexSourcePath() const;

        std::string const &baseclassSkeleton() const;
        std::string const &classSkeleton() const;
        std::string const &className() const;
        std::string const &filenames() const;
        std::string const &implementationSkeleton() const;
        std::string const &inputImplementation() const;
        std::string const &inputInterface() const;
        std::string const &lexFunctionName() const;
        std::string const &lexSkeleton() const;
        std::string const &nameSpace() const;
        std::string const &infile() const;
        std::string const &constructionPath() const;
        std::string implementationHeaderName() const;

        void setBaseClassHeader(TextType textType);
        void setClassHeader(TextType textType);
        void setClassName(TextType textType);
        void setCaseInsensitive();
        void setDebug();
        void setFilenames(TextType textType);
        void setImplementationHeader(TextType textType);
        void setInputImplementationPath(TextType textType);
        void setInputInterfacePath(TextType textType);
        void setInteractive();
        void setLexFunctionName(TextType textType);
        void setLexSource(TextType textType);
        void setLines(bool yesNo);
        void setNameSpace(TextType textType);
        void setPrint();
        void setSkeletonDirectory(TextType textType);
        void setTargetDirectory(TextType textType);

        static void regexCall(char const *funname);

        static char const *classHeaderSpec();       // long option/directive 
        static char const *baseclassHeaderSpec();   // specs. used repeatedly
        static char const *implementationHeaderSpec();
        static char const *lexSourceSpec();
        
    private:
        Options();  // FBB::Arg const &arg);

        std::string const &textOf(TextType type);

        void assign(TextType textType, std::string *target, PathType pathType, 
                    char const *declTxt);
        void accept(std::string const &text, 
                    PathType pathType, char const *declTxt);


//        static void setPath(std::string *target, std::string const &name);
//        static void setPath(std::string *target, std::string const &name,
//                            char const *warnOption);
        void setOptionPath(std::string *dest, int optChar, 
                           std::string const &defaultFile, 
                           char const *defaultSuffix,
                           char const *optionName);

        static void nop(char const *funName);
        static void show(char const *funName);

};

inline char const *Options::classHeaderSpec()
{
    return "class-header";
}

inline char const *Options::baseclassHeaderSpec()
{
    return "baseclass-header";
}

inline char const *Options::implementationHeaderSpec()
{
    return "implementation-header";
}

inline char const *Options::lexSourceSpec()
{
    return "lex-source";
}

inline void Options::show(char const *funName)
{
    std::cout << '\t' << funName << '\n';
}

inline void Options::regexCall(char const *funName)
{
    (*s_regexCall)(funName);
}

inline size_t Options::maxDepth() const
{
    return d_maxDepth;
}

inline bool Options::caseSensitive() const
{
    return d_caseSensitive;
}

inline std::string const &Options::constructionPath() const
{
    return d_constructionPath;
}

inline std::string const &Options::inputInterface() const
{
    return d_inputInterfacePath;
}

inline std::string const &Options::filenames() const
{
    return d_filenames;
}

inline std::string const &Options::inputImplementation() const
{
    return d_inputImplementation;
}

inline std::string const &Options::baseclassSkeleton() const
{
    return d_baseClassSkeleton;
}

inline std::string const &Options::classSkeleton() const
{
    return d_classSkeleton;
}

inline std::string const &Options::implementationSkeleton() const
{
    return d_implementationSkeleton;
}

inline std::string const &Options::lexSkeleton() const
{
    return d_lexSkeleton;
}

inline std::string const &Options::baseclassHeaderPath() const
{
    return d_baseClassHeader;
}

inline std::string const &Options::classHeaderPath() const
{
    return d_classHeader;
}

inline std::string const &Options::implementationHeaderPath() const
{
    return d_implementationHeader;
}

inline std::string const &Options::lexSourcePath() const
{
    return d_lexSource;
}

inline std::string const &Options::lexFunctionName() const
{
    return d_lexFunctionName;
}

inline std::string const &Options::className() const
{
    return d_className;
}

inline std::string const &Options::nameSpace() const
{
    return d_nameSpace;
}

inline std::string const &Options::infile() const
{
    return d_infile;
}

inline void Options::setSkeletonDirectory(TextType textType)
{
    assign(textType, &d_skeletonDirectory, PATHNAME, "skeleton-directory");
}

inline void Options::setTargetDirectory(TextType textType)
{
    assign(textType, &d_targetDirectory, PATHNAME, "target-directory");
}

inline void Options::setNameSpace(TextType textType)
{
    assign(textType, &d_nameSpace, FILENAME, "namespace");
}


inline void Options::setInputImplementationPath(TextType textType)
{
    assign(textType, &d_inputImplementation, PATHNAME, "input-implementation");
}
   
inline void Options::setInputInterfacePath(TextType textType)
{
    assign(textType, &d_inputInterfacePath, PATHNAME, "input-interface");
}
   
inline void Options::setBaseClassHeader(TextType textType)
{
    assign(textType, &d_baseClassHeader, FILENAME, baseclassHeaderSpec());
}
   
inline void Options::setClassHeader(TextType textType)
{
    assign(textType, &d_classHeader, FILENAME, classHeaderSpec());
}
   
inline void Options::setImplementationHeader(TextType textType)
{
    assign(textType, &d_implementationHeader, FILENAME, 
           implementationHeaderSpec());
}
   
inline void Options::setLexSource(TextType textType)
{
    assign(textType, &d_lexSource, FILENAME, "lex-source");
}
   
inline void Options::setInteractive()
{   
    d_interactive = true;
}

inline void Options::setCaseInsensitive()
{   
    d_caseSensitive = false;
}

inline void Options::setLines(bool yesNo)
{   
    d_lines = yesNo;
}

inline void Options::setDebug()
{
    d_debug = true;
}

inline void Options::setPrint()
{
    d_print = true;
}

inline bool Options::interactive() const
{   
    return d_interactive;
}


inline bool Options::verbose() const
{   
    return d_verbose;
}

inline bool Options::print() const
{   
    return d_print;
}

inline bool Options::lines() const
{   
    return d_lines;
}

inline bool Options::debug() const
{
    return d_debug;
}

inline bool Options::specified(std::string const &option) const
{
    return s_warnOptions.find(option) != s_warnOptions.end();
}


#endif






