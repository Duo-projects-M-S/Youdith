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

static constexpr std::pair<const char*, Token> data[] = {
  {"num", Token::var_num},
  {"char", Token::var_char},
  {"Youdith", Token::Main},
  {"->", Token::Return}
};
// Make two funcion static?
class Tokenizer {
 private:
  typedef std::unordered_map<std::string, Token> MultiCharTokenMap;
  size_t m_index;
  const std::string& m_stringtoken;
  static const MultiCharTokenMap m_multiLetterTokens;

  [[nodiscard]] Token identifySingleCharToken(const char);
  [[nodiscard]] Token identifyMultieCharToken(const std::string&);

 public:
  Tokenizer(const std::string& stringtoken) : m_stringtoken(stringtoken), m_index(0){}
  [[nodiscard]] static MultiCharTokenMap create_map();
  [[nodiscard]] Token getNextToken();
};

const Tokenizer::MultiCharTokenMap Tokenizer::m_multiLetterTokens = Tokenizer::create_map();