#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>
#include <set>
#include <bobcat/a2x>

class Options
{
    std::string d_baseClassHeaderPath;
    std::string d_classHeaderPath;
    std::string d_implementationHeaderPath;
    std::string d_lexSourcePath;

    std::string d_skeletonDirectory;
    std::string d_className;
    std::string d_lexFunctionName;
    std::string d_nameSpace;
    std::string d_streamInfoClassName;
    std::string d_streamInfoInclude;

    bool d_interactive;
    bool d_lines;

    // skeletons
    std::string d_baseClassSkeleton;
    std::string d_classSkeleton;
    std::string d_lexSkeleton;
    std::string d_implementationSkeleton;

    // debug data
    size_t d_beginStep;
    size_t d_endStep;
    bool d_debugAll;
    std::set<std::string> d_debugNames;

            // strings containing default file and other names
    static char s_defaultLexFunctionName[];
    static char s_defaultSkeletonDirectory[];
    static char s_defaultClassName[];
    static char s_defaultLexfunSource[];

    static Options s_options;

    public:
        static Options &instance();

        Options(Options const &other) = delete;

        void setBaseClassHeaderPath(std::string const &name);
        void setClassHeaderPath(std::string const &name);
        void setImplementationHeaderPath(std::string const &name);
        void setLexSourcePath(std::string const &name);

        void setClassName(std::string const &name);
        void setSkeletonDirectory(std::string const &name);
        void setLexFunctionName(std::string const &name);
        void setNameSpace(std::string const &name);

        void setInteractive();
        void setLines(bool yesNo);

        void setDebug();
        void setDebug(std::string const &name);
        void setStepRange();
        void setStepRange(std::string const &name);
        void setLastStep(std::string const &name);
        
        std::string const &baseclassSkeleton() const;
        std::string const &classSkeleton() const;
        std::string const &implementationSkeleton() const;
        std::string const &lexSkeleton() const;

        std::string const &baseclassHeaderPath() const;
        std::string const &classHeaderPath() const;
        std::string const &implementationHeaderPath() const;
        std::string const &lexSourcePath() const;

        std::string baseclassHeaderName() const;
        std::string classHeaderName() const;
        std::string implementationHeaderName() const;

        std::string const &className() const;
        std::string const &lexFunctionName() const;
        std::string const &nameSpace() const;

        bool debug() const;
        size_t beginStep() const;
        size_t endStep() const;
        bool has(std::string const &field) const;
        bool hasNames() const;

        void setAccessorVariables();

        bool interactive() const;
        bool lines() const;

    private:
        Options();

        std::string undelimit(std::string const &str);
        void setPath(std::string *target, std::string const &name);
};

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

inline void Options::setLines(bool yesNo)
{   
    d_lines = yesNo;
}

inline void Options::setDebug()
{
    d_debugAll = true;
}

inline void Options::setDebug(std::string const &name)
{
    d_debugNames.insert(name);
}

inline void Options::setStepRange()
{
    d_beginStep = 0;
}

inline void Options::setStepRange(std::string const &name)
{
    d_beginStep = FBB::A2x(name);
}

inline void Options::setLastStep(std::string const &name)
{
    d_endStep = 1 + FBB::A2x(name).to<size_t>();
}

inline bool Options::interactive() const
{   
    return d_interactive;
}

inline bool Options::lines() const
{   
    return d_lines;
}

inline bool Options::debug() const
{
    return d_debugAll;
}

inline bool Options::has(std::string const &field) const
{
    return d_debugNames.find(field) != d_debugNames.end();
}

inline bool Options::hasNames() const
{
    return d_debugNames.size();
}

inline size_t Options::beginStep() const
{
    return d_beginStep;
}

inline size_t Options::endStep() const
{
    return d_endStep;
}

#endif





