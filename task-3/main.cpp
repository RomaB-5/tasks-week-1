#include <iostream>
#include <chrono>
#include <fstream>

#include "ProjectAnalyzer.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <path>\n";
        return 1;
    }

    std::string path = argv[1];

    try {
        auto timer = std::chrono::high_resolution_clock::now();

        ProjectAnalyzer project(path);
        project.PrintResults();
        project.SaveResults("results.txt");

        auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();
        std::cout << "Elapsed time: " << time_elapsed << "ms\n";

        std::ofstream ofs("results.txt", std::ios::app);
        ofs << "Elapsed time: " << time_elapsed << "ms\n";
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
