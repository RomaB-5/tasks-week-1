/* 
Given path/to/c-cpp/project

Requirments:
Recursivly traverse the directory and examine all files with the .c, .cpp, .h, .hpp extensions.
For each file, count the number of empty lines, comment lines, and code lines 
Give a reasonable representation of the results.
*/

#include <iostream>

#include "Project.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <path>\n";
        return 1;
    }

    std::string path = argv[1];
    Project project(path);
    project.PrintResults();

    std::cout<<"Exited";

}
