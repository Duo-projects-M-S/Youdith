#include "Tokenizer.h"

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
  auto it = multiLetterTokens.find(stringtoken);

  if (it != multiLetterTokens.end()) {
    return it->second;
  }

  return Token::Error;
}

Token Tokenizer::getNextToken() {
  size_t last_index = index;

  while (index < stringtoken.length() &&
         identifySingleCharToken(stringtoken[index]) == Token::Error) {
    index++;
  }

  if (index - last_index == 0) {
    index++;
    return identifySingleCharToken(stringtoken[index - 1]);
  } else {
    return identifyMultieCharToken(
        stringtoken.substr(last_index, index - last_index));
  }

  return Token::Error;
}
