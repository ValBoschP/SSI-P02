#include "utils.h"

char ShiftChar(char c, char k, bool encrypt) {
  int shift = k - 'A';
  if (!encrypt) shift = -shift;
  return 'A' + (c - 'A' + shift + 26) % 26;
}

std::string PreProcessText(const std::string& text) {
  std::string processed_text;
  for (char c : text) {
    if (std::isalpha(c)) {
      processed_text += std::toupper(c);
    }
  }
  return processed_text;
}