#pragma once
#include <iostream>
#include <optional>
#include <unordered_map>
#include <algorithm>

enum class TokenType : unsigned int {
  Error,
  Space,
  Semicolon,
  Round_Bracket_Left,
  Round_Bracket_Right,
  Square_Bracket_Left,
  Square_Bracket_Right,
  Curved_Bracket_Left,
  Curved_Bracket_Right,
  Symbol,
  Value,
  Var_num,
  Var_char,
  Var_bool,
  Var_void,
  Main,
  Return,
  Assignment,
  Equal,
  Not_Equal,
  Greater,
  Smaller,
  Greater_Equal,
  Smaller_Equal,
  Not,
  And,
  Or,
  End_of_File
};

struct Token {
  TokenType type;
  std::optional<std::string> value{};
};

static constexpr std::pair<const char*, TokenType> data[] = {
    {"num", TokenType::Var_num},
    {"char", TokenType::Var_char},
    {"Youdith", TokenType::Main},
    {"->", TokenType::Return} };

class Tokenizer {
private:
  typedef std::unordered_map<std::string, TokenType> MultiCharTokenMap;

  TokenType m_prevTokenType;
  size_t m_index;
  const std::string& m_stringtoken;
  static const MultiCharTokenMap m_multiLetterTokens;

  [[nodiscard]] TokenType identifySingleCharTokenType(const char);
  [[nodiscard]] TokenType identifyMultieCharTokenType(const std::string&);

public:
  Tokenizer(const std::string& stringtoken)
    : m_stringtoken(stringtoken), m_index(0), m_prevTokenType(TokenType::Error) {
  }
  [[nodiscard]] static MultiCharTokenMap create_map();
  [[nodiscard]] Token getNextToken();
};