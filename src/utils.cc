#include "utils.h"

char ShiftChar(char c, char k, bool encrypt) {
  int shift = (std::toupper(k) - 'A');
  if (!encrypt) shift = -shift;
  return 'A' + (c - 'A' + shift + 26) % 26;
}

std::string PreProcessText(const std::string& text) {
  std::string processed;
  for (char c : text) {
    if (std::isalpha(c)) {
      processed += std::toupper(c);
    }
  }
  return processed;
}