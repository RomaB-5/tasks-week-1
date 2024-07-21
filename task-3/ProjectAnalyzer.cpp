#include "ProjectAnalyzer.h"

#include <fstream>
#include <iostream>
#include <thread>
#include <memory>
#include <concepts>
#include <algorithm>

#include "ThreadPool.h"

ProjectAnalyzer::ProjectAnalyzer(const std::filesystem::path& root) : m_root(root) 
{
    ScanForFiles(m_root);
    AnalyzeFiles();
}

void ProjectAnalyzer::ScanForFiles(const std::filesystem::path& root) 
{
    for (const auto& entry : std::filesystem::recursive_directory_iterator(root)) 
    {
        if (entry.is_regular_file()) 
        {
            if (std::find(m_extensions.begin(), m_extensions.end(), entry.path().extension()) != m_extensions.end())
            {
                 m_files.push_back(entry.path());
            }
        }
    }
}


void ProjectAnalyzer::AnalyzeFiles() 
{
    ThreadPool pool(std::thread::hardware_concurrency());

    for (const auto& file : m_files) 
    {
        
        pool.enqueue([this, &file]() 
        {
            auto [empty_lines, comment_lines, code_lines] = AnalyzeFile(file);

            std::lock_guard lock(m_mutex);
            m_empty_lines += empty_lines;
            m_comment_lines += comment_lines;
            m_code_lines += code_lines;

        });
    }

}

std::tuple<uint32_t, uint32_t, uint32_t> ProjectAnalyzer::AnalyzeFile(const std::filesystem::path& file) 
{
    std::ifstream ifs(file);
    if (!ifs.is_open()) 
    {
        std::cerr << "Failed to open file: " << file << '\n';
        return { 0, 0, 0 };
    }

    std::uint32_t empty_lines = 0, comment_lines = 0, code_lines = 0;

    std::string line;
    bool is_comment = false;
    while (std::getline(ifs, line)) 
    {
        if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) 
        {
            empty_lines++;
        } 
        else 
        {
            if (line.find("/*") != std::string::npos) 
            {
                is_comment = true;
                comment_lines++;
            } 
            else if (line.find("*/") != std::string::npos) 
            {
                is_comment = false;
                comment_lines++;
            } 
            else if (line.find("//") != std::string::npos) 
            {
                comment_lines++;
            } 
            else if (is_comment) 
            {
                comment_lines++;
            } 
            else 
            {
                code_lines++;
            }
        }
    }

    return { empty_lines, comment_lines, code_lines };
}



void ProjectAnalyzer::PrintResults() const {
    std::cout << "Total files: " << m_files.size() << '\n';
    std::cout << "Empty lines: " << m_empty_lines << '\n';
    std::cout << "Comment lines: " << m_comment_lines << '\n';
    std::cout << "Code lines: " << m_code_lines << '\n';
}

void ProjectAnalyzer::SaveResults(const std::filesystem::path& path) const {
    std::ofstream ofs(path);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open file: " << path << '\n';
        return;
    }

    ofs << "Total files: " << m_files.size() << '\n';
    ofs << "Empty lines: " << m_empty_lines << '\n';
    ofs << "Comment lines: " << m_comment_lines << '\n';
    ofs << "Code lines: " << m_code_lines << '\n';
}

