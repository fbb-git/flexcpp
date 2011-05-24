#include "generator.ih"

void Generator::showFilenames() const
{
    if (not d_arg.option('F'))
        return;

    imsg << 
        "Input file name:                     " << 
                                    d_arg[0] << endl;
                                              
    if (d_constructionFilename.length())      
        imsg <<                               
        "Construction details:                " << 
                                    d_constructionFilename << endl;
    imsg <<                                   
        "\n"
        "Baseclass header skeleton file:      " << 
                                    d_options.baseclassSkeleton() << "\n"
        "Class header skeleton file:          " << 
                                    d_options.classSkeleton() << "\n"
        "Implementation header skeleton file: " << 
                                    d_options.classSkeleton() << "\n"
        "Lex function skeleton file:          " << 
                                    d_options.lexSkeleton() << "\n"
        "\n"
        "Baseclass header file:               " << 
                                    d_options.baseclassHeaderPath() << "\n"
        "Class header file:                   " << 
                                    d_options.classHeaderPath() << "\n"
        "Implementation header file:          " << 
                                    d_options.classHeaderPath() << "\n"
        "Lex function source file:            " << 
                                    d_options.lexSourcePath() << endl;
}
