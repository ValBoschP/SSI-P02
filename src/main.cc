#include "vigenere.h"

#include <iostream>

int main() {
  std::string key, text;
  std::cout << "Ingrese la clave: ";
  std::getline(std::cin, key);

  VigenereCipher cipher(key);

  std::cout << "Ingrese el texto a cifrar: ";
  std::getline(std::cin, text);

  std::string encrypted = cipher.Encrypt(text);
  std::cout << "Texto cifrado: " << encrypted << std::endl;

  std::string decrypted = cipher.Decrypt(encrypted);
  std::cout << "Texto descifrado: " << decrypted << std::endl;

  return 0;
}