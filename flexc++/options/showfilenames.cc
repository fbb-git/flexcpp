#include "options.ih"

void Options::showFilenames() const
{
    if (not d_arg.option('F'))
        return;

    imsg << 
        "Input file name:                     " << 
                                    infile() << endl;
    if (d_arg.option('K'))      
        imsg <<                               
        "Construction details:                " << 
                                    constructionPath() << endl;
    imsg <<                                   
        "\n"
        "Baseclass header skeleton file:      " << 
                                    baseclassSkeleton() << "\n"
        "Class header skeleton file:          " << 
                                    classSkeleton() << "\n"
        "Implementation header skeleton file: " << 
                                    implementationSkeleton() << "\n"
        "Lex function skeleton file:          " << 
                                    lexSkeleton() << "\n"
        "\n"
        "Baseclass header file:               " << 
                                    baseclassHeaderPath() << "\n"
        "Class header file:                   " << 
                                    classHeaderPath() << "\n"
        "Implementation header file:          " << 
                                    implementationHeaderPath() << "\n"
        "Lex function source file:            " << 
                                    lexSourcePath() << endl;
}


