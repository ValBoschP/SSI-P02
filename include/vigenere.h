#ifndef VIGENERE_H
#define VIGENERE_H 

#include <string>
#include <cctype>
#include <iostream>

class VigenereCipher {
 public:
  // Constructor
  VigenereCipher(const std::string& key);
  // Getter
  std::string GetKey() const { return key_; }
  // Methods
  std::string Encrypt(const std::string& text) const;
  std::string Decrypt(const std::string& text) const;
  
 private:
  std::string key_;
};

#endif // VIGENERE_H