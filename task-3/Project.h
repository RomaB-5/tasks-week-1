#include <filesystem>
#include <vector>
#include <mutex>

class Project {
public:
    Project(const std::filesystem::path& root);

    void PrintResults() const;
private:
    std::uint32_t m_empty_lines = 0;
    std::uint32_t m_comment_lines = 0;
    std::uint32_t m_code_lines = 0;

    std::mutex m_mutex;


    std::filesystem::path m_root;
    std::vector<std::filesystem::path> m_files;
    void ScanForFiles(const std::filesystem::path& m_root);
    void AnalyzeFiles();
};