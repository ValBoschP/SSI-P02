#include "utils.h"
#include "vigenere.h"

#include <iostream>
#include <cctype>
#include <iomanip>
#include <exception>

void ProcessEncryption() {
  std::string key, text;
  std::cout << "Key: ";
  std::getline(std::cin, key);
  VigenereCipher cipher(key);

  std::cout << "Message: ";
  std::getline(std::cin, text);

  std::string encrypted = cipher.Encrypt(text);

  std::cout << "Key: " << cipher.GetKey() << std::endl;
  std::cout << "Original message: " << text << std::endl;
  std::cout << "Encrypted message: " << encrypted << std::endl;
  
}

void ProcessDecryption() {
  std::string key, cipher_text;
  std::cout << "Key: ";
  std::getline(std::cin, key);
  VigenereCipher cipher(key);

  std::cout << "Message: ";
  std::getline(std::cin, cipher_text);

  std::string decrypted = cipher.Decrypt(cipher_text);  

  std::cout << "Key: " << cipher.GetKey() << std::endl;;
  std::cout << "Decrypted message: " << decrypted << std::endl;
}

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