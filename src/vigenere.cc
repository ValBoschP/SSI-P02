#include "vigenere.h"
#include "utils.h"

#include <cctype>

std::string VigenereCipher::Encrypt(const std::string& text) const {
  std::string processed_text = PreProcessText(text);
  std::string encrypted_text;
  for (size_t i = 0; i < processed_text.size(); ++i) {
    encrypted_text += ShiftChar(processed_text[i], key_[i % key_.size()], true);
  }
  return encrypted_text;
}

std::string VigenereCipher::Decrypt(const std::string& text) const {
  std::string processed_text = PreProcessText(text);
  std::string decrypted_text;
  for (size_t i = 0; i < processed_text.size(); ++i) {
    decrypted_text += ShiftChar(processed_text[i], key_[i % key_.size()], false);
  }
  return decrypted_text;
}