#include "Tokenizer.h"

const Tokenizer::MultiCharTokenMap Tokenizer::m_multiLetterTokens =
    Tokenizer::create_map();

Tokenizer::MultiCharTokenMap Tokenizer::create_map() {
  std::unordered_map<std::string, TokenType> map;
  for (const auto& [key, value] : data) {
    map[key] = value;
  }
  return map;
}

static bool isNumber(const std::string& str) {
  if (str.empty())
    return false;

  return std::all_of(str.begin() + 1, str.end(), ::isdigit) &&
         (std::isdigit(str[0]) || str[0] == '-');
}

TokenType Tokenizer::identifySingleCharTokenType(const char character) {
  switch (character) {
    case ' ':
      return TokenType::Space;
    case '(':
      return TokenType::Round_Bracket_Left;
    case ')':
      return TokenType::Round_Bracket_Right;
    case '{':
      return TokenType::Curved_Bracket_Left;
    case '}':
      return TokenType::Curved_Bracket_Right;
    case ';':
      return TokenType::Semicolon;
    case '=':
      return TokenType::Equal;

    default:
      return TokenType::Error;
  }
}

TokenType Tokenizer::identifyMultieCharTokenType(
    const std::string& stringtoken) {
  if (isNumber(stringtoken))
    return TokenType::Value;

  auto it = m_multiLetterTokens.find(stringtoken);
  if (it != m_multiLetterTokens.end()) {
    return it->second;
  }

  if (std::isalpha(stringtoken[0]))
    return TokenType::Symbol;

  return TokenType::Error;
}

Token Tokenizer::getNextToken() {
  size_t last_index = m_index;

  while (m_index < m_stringtoken.length() &&
         identifySingleCharTokenType(m_stringtoken[m_index]) ==
             TokenType::Error) {
    m_index++;
  }

  if (m_index >= m_stringtoken.length())
    return {TokenType::End_of_File};

  if (m_index - last_index == 0) {
    m_index++;
    return {identifySingleCharTokenType(m_stringtoken[m_index - 1])};
  } else {
    std::string substring =
        m_stringtoken.substr(last_index, m_index - last_index);
    TokenType typ = identifyMultieCharTokenType(substring);

    if (typ == TokenType::Symbol || typ == TokenType::Value) {
      return {typ, substring};
    } else {
      return {typ};
    }
  }

  return {TokenType::Error};
}
