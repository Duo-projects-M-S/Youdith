#include <filesystem>
#include <iostream>

#include <list>
#include "FileParser.h"
#include "Tokenizer.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::filesystem::path fileToCompile = argv[1];
    if (std::filesystem::exists(fileToCompile)) {
      FileParser parse(fileToCompile);
      const std::string file = parse.GetAsString();

      std::cout << "string: " << file << std::endl;

      // Test
      Tokenizer tok(file);
      Token a = Token::Error;
      std::list<Token> tokens;
      do {
        a = tok.getNextToken();
        tokens.push_back(a);
      } while (a != Token::Error);

      // Test print
      std::cout << "List elements: ";
      for (Token t : tokens) {
        std::cout << (unsigned int)t << " ";  // Directly print the element
      }
      std::cout << std::endl;

    } else {
      std::cerr << "Error: File does not exist!" << std::endl;
    }
  } else {
    std::cerr << "Error: Please specify a file to compile!" << std::endl;
  }
}