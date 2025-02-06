#include "vigenere.h"
#include "utils.h"

#include <cctype>

VigenereCipher::VigenereCipher(const std::string& key) {
  for (char c : key) {
    if (std::isalpha(c)) {
      this->key_ += std::toupper(c);
    }
  }
  if (this->key_.empty()) {
    throw std::invalid_argument("Key must contain at least one alphabetic character");
  }
}

std::string VigenereCipher::Encrypt(const std::string& text) const {
  std::string processed = PreProcessText(text);
  if (processed.empty()) return "";

  std::string encrypted;
  for (size_t i = 0, j = 0; i < processed.size(); ++i, j = (j + 1) % key_.size()) {
    encrypted += ShiftChar(processed[i], key_[j], true);
    if ((i + 1) % key_.size() == 0) encrypted += ' '; // Formato en bloques de tamaño de la clave
  }
  return encrypted;
}

std::string VigenereCipher::Decrypt(const std::string& text) const {
  std::string clean_text;
  for (char c : text) {
    if (std::isalpha(c)) clean_text += c; // Remueve espacios en el descifrado
  }
  
  std::string decrypted;
  for (size_t i = 0, j = 0; i < clean_text.size(); ++i, j = (j + 1) % key_.size()) {
    decrypted += ShiftChar(clean_text[i], key_[j], false);
  }
  return decrypted;
}