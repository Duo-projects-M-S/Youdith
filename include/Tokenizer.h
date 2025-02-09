#pragma once
#include <iostream>
#include <unordered_map>  //?here

enum class Token : unsigned int {
  Error,
  Space,
  Round_Bracket_Left,
  Round_Bracket_Right,
  Square_Bracket_Left,
  Square_Bracket_Right,
  Curved_Bracket_Left,
  Curved_Bracket_Right,
  Semicolon,
  Main,
  Return,
  var_num,
  var_char,
  var_bool,
  var_void

};

// Make two funcion static?
class Tokenizer {
 public:
  Tokenizer(const std::string& stringtoken) : stringtoken(stringtoken) {
    index = 0;
  }

  Token getNextToken();

 private:
  size_t index;
  const std::string& stringtoken;
  std::unordered_map<std::string, Token> multiLetterTokens = {
      {"num", Token::var_num},
      {"char", Token::var_char},
      {"Youdith", Token::Main},
      {"->", Token::Return}};

  Token identifySingleCharToken(const char);
  Token identifyMultieCharToken(const std::string&);
};