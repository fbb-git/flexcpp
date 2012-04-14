#include "generator.ih"

void Generator::showFilenames() const
{
    if (not d_options('F'))
        return;

    imsg << 
        "Input file name:                     " << 
                                    d_options.infile() << endl;
                                              
    if (d_options('K'))      
        imsg <<                               
        "Construction details:                " << 
                                    d_options.constructionPath() << endl;
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






