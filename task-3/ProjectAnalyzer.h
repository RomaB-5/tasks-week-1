#pragma once

#include <filesystem>
#include <vector>
#include <mutex>

class ProjectAnalyzer {
public:
    ProjectAnalyzer(const std::filesystem::path& root);

    void PrintResults() const;
    void SaveResults(const std::filesystem::path& path) const;
private:
    std::uint32_t m_empty_lines = 0;
    std::uint32_t m_comment_lines = 0;
    std::uint32_t m_code_lines = 0;

    std::mutex m_mutex;


    std::filesystem::path m_root;
    std::vector<std::filesystem::path> m_files;
    std::vector<std::string> m_extensions{ ".cpp", ".h", ".hpp", ".c", ".cc" };
    void ScanForFiles(const std::filesystem::path& m_root);
    void AnalyzeFiles();
    std::tuple<uint32_t, uint32_t, uint32_t> AnalyzeFile(const std::filesystem::path& file);
};
