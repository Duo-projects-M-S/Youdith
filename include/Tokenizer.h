#pragma once
#include <iostream>

enum class Token : unsigned int
{
  Round_Bracket_Left,
  Round_Bracket_Right,
  Square_Bracket_Left,
  Square_Bracket_Left,
};

class Tokanizer
{
public:
  Token getNextToken(std::string &);
};