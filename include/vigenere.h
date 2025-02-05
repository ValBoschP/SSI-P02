#ifndef VIGENERE_H
#define VIGENERE_H 

#include <string>

class VigenereCipher {
 public:
  VigenereCipher(const std::string& key) : key_{key} {}

  // Getter
  std::string GetKey() const { return key_; }

  std::string Encrypt(const std::string& text) const;
  std::string Decrypt(const std::string& text) const;
 private:
  std::string key_;
};

#endif // VIGENERE_H