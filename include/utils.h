#ifndef UTILS_H
#define UTILS_H

#include <string>

void ProcessEncryption();
void ProcessDecryption();

char ShiftChar(char c, char k, bool encrypt);
std::string PreProcessText(const std::string& text);

#endif // UTILS_H 