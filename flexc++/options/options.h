#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <iostream>
#include <string>

namespace FBB
{
    class Arg;
}

class Options
{
    FBB::Arg const &d_arg;
    std::string d_baseClassHeaderPath;
    std::string d_baseClassSkeleton;
    std::string d_classHeaderPath;
    std::string d_className;
    std::string d_classSkeleton;
    std::string d_constructionPath;
    std::string d_filenames;
    std::string d_implementationHeaderPath;
    std::string d_implementationSkeleton;
    std::string d_inputImplementation;
    std::string d_inputInterface;
    std::string d_lexFunctionName;
    std::string d_lexSkeleton;
    std::string d_lexSourcePath;
    std::string d_nameSpace;
    std::string d_skeletonDirectory;
    std::string d_targetDirectory;
    std::string d_infile;

    bool d_interactive;
    bool d_lines;
    bool d_print;
    bool d_debug;
    bool d_matchedRules;
    bool d_verbose;
    bool d_caseSensitive;

    enum 
    {
        MAX_DEPTH = 10 
    };
    size_t d_maxDepth;

            // strings containing default file and other names
    static char s_defaultLexFunctionName[];
    static char s_defaultSkeletonDirectory[];
    static char s_defaultClassName[];
    static char s_defaultLexfunSource[];
    static char s_defaultTargetDirectory[];

    static Options *s_options;
    static void (*s_regexCall)(char const *funName);

    public:
        static Options &init(FBB::Arg const &arg);
        static Options &instance();

        Options(Options const &other) = delete;

        bool caseSensitive() const;
        bool debug() const;
        bool interactive() const;
        bool lines() const;
        bool print() const;
        bool verbose() const;
        bool operator()(int opt) const;
        bool operator()(char const *opt) const;

        std::size_t maxDepth() const;

        std::string baseclassHeaderName() const;
        std::string classHeaderName() const;
        std::string const &baseclassHeaderPath() const;
        std::string const &baseclassSkeleton() const;
        std::string const &classHeaderPath() const;
        std::string const &className() const;
        std::string const &classSkeleton() const;
        std::string const &filenames() const;
        std::string const &implementationHeaderPath() const;
        std::string const &implementationSkeleton() const;
        std::string const &inputImplementation() const;
        std::string const &inputInterface() const;
        std::string const &lexFunctionName() const;
        std::string const &lexSkeleton() const;
        std::string const &lexSourcePath() const;
        std::string const &nameSpace() const;
        std::string const &infile() const;
        std::string const &constructionPath() const;
        std::string implementationHeaderName() const;
        void setBaseClassHeaderPath(std::string const &name);
        void setClassHeaderPath(std::string const &name);
        void setClassName(std::string const &name);
        void setCaseInsensitive();
        void setDebug();
        void setFilenames(std::string const &name);
        void setImplementationHeaderPath(std::string const &name);
        void setInputImplementationPath(std::string const &name);
        void setInputInterfacePath(std::string const &name);
        void setInteractive();
        void setLexFunctionName(std::string const &name);
        void setLexSourcePath(std::string const &name);
        void setLines(bool yesNo);
        void setNameSpace(std::string const &name);
        void setPrint();
        void setSkeletonDirectory(std::string const &name);
        void setTargetDirectory(std::string const &name);

        static void regexCall(char const *funname);

        void setAccessorVariables();

    private:
        Options(FBB::Arg const &arg);

        std::string undelimit(std::string const &str);
        void setPath(std::string *target, std::string const &name);
        void setPath(std::string *dest, int optChar, bool targetDirOption, 
                      char const *optionName, std::string const &className, 
                      char const *suffix);

        static void nop(char const *funName);
        static void show(char const *funName);

};

inline Options &Options::instance()
{
    return *s_options;
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
    return d_inputInterface;
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
    return d_baseClassHeaderPath;
}

inline std::string const &Options::classHeaderPath() const
{
    return d_classHeaderPath;
}

inline std::string const &Options::implementationHeaderPath() const
{
    return d_implementationHeaderPath;
}

inline std::string const &Options::lexSourcePath() const
{
    return d_lexSourcePath;
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

inline void Options::setInputImplementationPath(std::string const &name)
{
    setPath(&d_inputImplementation, name);
}
   
inline void Options::setInputInterfacePath(std::string const &name)
{
    setPath(&d_inputInterface, name);
}
   
inline void Options::setBaseClassHeaderPath(std::string const &name)
{
    setPath(&d_baseClassHeaderPath, name);
}
   
inline void Options::setClassHeaderPath(std::string const &name)
{
    setPath(&d_classHeaderPath, name);
}
   
inline void Options::setImplementationHeaderPath(std::string const &name)
{
    setPath(&d_implementationHeaderPath, name);
}
   
inline void Options::setLexSourcePath(std::string const &name)
{
    setPath(&d_lexSourcePath, name);
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

#endif






