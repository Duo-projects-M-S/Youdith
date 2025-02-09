#include "FileParser.h"
#include <string>

std::string FileParser::GetAsString(){
  if(std::filesystem::exists(m_path)){
    std::ifstream fileHandler(m_path);
    std::string line;
    std::string ret;
    while(std::getline(fileHandler, line)){
      ret.append(line);
    }
    return ret;
  }
  return "";
}