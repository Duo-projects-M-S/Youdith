#include "Tokenizer.h"

const Tokenizer::MultiCharTokenMap Tokenizer::m_multiLetterTokens = Tokenizer::create_map();

Tokenizer::MultiCharTokenMap Tokenizer::create_map() {
  std::unordered_map<std::string, Token> map;
  for (const auto& [key, value] : data) {
      map[key] = value;
  }
  return map;
}

Token Tokenizer::identifySingleCharToken(const char character) {
  switch (character) {
    case ' ':
      return Token::Space;
    case '(':
      return Token::Round_Bracket_Left;
    case ')':
      return Token::Round_Bracket_Right;
    case '{':
      return Token::Curved_Bracket_Left;
    case '}':
      return Token::Curved_Bracket_Right;
    case ';':
      return Token::Semicolon;

    default:
      return Token::Error;
  }
}

Token Tokenizer::identifyMultieCharToken(const std::string& stringtoken) {
  auto& it = m_multiLetterTokens.find(stringtoken);

  if (it != m_multiLetterTokens.end()) {
    return it->second;
  }

  return Token::Error;
}

Token Tokenizer::getNextToken() {
  size_t last_index = m_index;

  while (m_index < m_stringtoken.length() &&
         identifySingleCharToken(m_stringtoken[m_index]) == Token::Error) {
    m_index++;
  }

  if (m_index - last_index == 0) {
    m_index++;
    return identifySingleCharToken(m_stringtoken[m_index - 1]);
  } else {
    return identifyMultieCharToken(
        m_stringtoken.substr(last_index, m_index - last_index));
  }

  return Token::Error;
}
