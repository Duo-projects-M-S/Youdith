#pragma once
#include <fstream>
#include <filesystem>

class FileParser{
   private:
    std::filesystem::path m_path;
   public:
     FileParser(std::filesystem::path &filePath) : m_path(filePath) {}
     std::string GetAsString();
};