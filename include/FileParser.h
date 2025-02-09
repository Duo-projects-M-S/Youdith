#pragma once
#include <filesystem>
#include <fstream>

class FileParser {
 private:
  std::filesystem::path m_path;

 public:
  FileParser(std::filesystem::path& filePath) : m_path(filePath) {}
  [[nodiscard]] std::string GetAsString();
};