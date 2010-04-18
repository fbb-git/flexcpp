#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

class Options
{
    std::string d_skeletonDirectory;
    std::string d_className;
    std::string d_lexFunctionName;
    std::string d_baseClassHeaderPath;
    std::string d_classHeaderPath;
    std::string d_implementationHeaderPath;
    std::string d_lexSourcePath;
    std::string d_nameSpace;
    std::string d_streamInfoClassName;
    std::string d_streamInfoInclude;

    bool d_interactive;

    // skeletons
    std::string d_baseClassSkeleton;
    std::string d_classSkeleton;
    std::string d_lexSkeleton;
    std::string d_implementationSkeleton;

    static std::string s_defaultClassName;
    static std::string s_defaultLexFunctionName;
    static std::string s_defaultSkeletonDirectory;
    static std::string s_defaultStreamInfoClassName;

    static Options s_options;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        void setClassName(std::string const &name);
        void setSkeletonDirectory(std::string const &name);
        void setLexFunctionName(std::string const &name);
        void setNameSpace(std::string const &name);
        void setStreamInfoClassName(std::string const &name);
        void setStreamInfoInclude(std::string const &name);

        void setBaseClassHeaderPath(std::string const &name);
        void setClassHeaderPath(std::string const &name);
        void setImplementationHeaderPath(std::string const &name);
        void setLexSourcePath(std::string const &name);
        void setInteractive();

        void setAccessorVariables();

        bool interactive() const;

    private:
        Options();

        std::string undelimit(std::string const &str);
        void setPath(std::string *target, std::string const &name);
};

inline void Options::setPath(std::string *target, std::string const &name)
{
    if (target->empty())
        *target = undelimit(name);
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

inline bool Options::interactive() const
{   
    return d_interactive;
}


#endif





