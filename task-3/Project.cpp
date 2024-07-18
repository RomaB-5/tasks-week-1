#include "Project.h"

#include <fstream>
#include <iostream>
#include <thread>
#include <memory>
#include <concepts>
#include <algorithm>

Project::Project(const std::filesystem::path& root) : m_root(root) {
    ScanForFiles(m_root);
    AnalyzeFiles();
}

void Project::ScanForFiles(const std::filesystem::path& root) {
    for (const auto& entry : std::filesystem::directory_iterator(root)) {
        if (entry.is_directory()) {
            ScanForFiles(entry.path());
        } else {
            if (std::ranges::count(std::vector<std::string>{".c", ".cpp", ".h", ".hpp"}, entry.path().extension().string()) != 0) {
                 m_files.push_back(entry.path());
            }
           
        }
    }
}


void Project::AnalyzeFiles() {
    std::vector<std::thread> threads(m_files.size());

    for (std::uint32_t i = 0;
         const auto& file : m_files) 
         {
        
        threads[i] = std::thread([this, &file]() 
        {
            std::ifstream ifs(file);
            if (!ifs.is_open()) {
                std::lock_guard<std::mutex> lock(m_mutex);
                std::cerr << "Failed to open file: " << file << '\n';
                return;
            }
            std::uint32_t empty_lines = 0;
            std::uint32_t comment_lines = 0;
            std::uint32_t code_lines = 0;

            std::string line;
            bool is_comment = false;
            while (std::getline(ifs, line)) {
                if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) {
                    empty_lines++;
                } else {
                    if (line.find("/*") != std::string::npos) {
                        is_comment = true;
                        comment_lines++;
                    } else if (line.find("*/") != std::string::npos) {
                        is_comment = false;
                        comment_lines++;
                    } else if (line.find("//") != std::string::npos) {
                        comment_lines++;
                    } else if (is_comment) {
                        comment_lines++;
                    } else {
                        code_lines++;
                    }
                }
            }

            std::lock_guard<std::mutex> lock(m_mutex);
            m_empty_lines += empty_lines;
            m_comment_lines += comment_lines;
            m_code_lines += code_lines;

        });
        i++;
    }

    for (auto& thread : threads) 
        thread.join();
}



void Project::PrintResults() const {
    std::cout << "Total files: " << m_files.size() << '\n';
    std::cout << "Empty lines: " << m_empty_lines << '\n';
    std::cout << "Comment lines: " << m_comment_lines << '\n';
    std::cout << "Code lines: " << m_code_lines << '\n';
}
