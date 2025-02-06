#include "vigenere.h"
#include <iostream>
#include <iomanip>
#include <exception>

int main() {
  try {
    std::string key, text;
    std::cout << "Ingrese la clave: ";
    std::getline(std::cin, key);

    VigenereCipher cipher(key);

    std::cout << "Ingrese el texto a cifrar: ";
    std::getline(std::cin, text);

    std::string encrypted = cipher.Encrypt(text);
    std::string decrypted = cipher.Decrypt(encrypted);

    std::cout << "Clave: " << cipher.GetKey() << std::endl;
    std::cout << "Texto original: " << text << std::endl;
    std::cout << "Texto cifrado: " << encrypted << std::endl;
    std::cout << "Texto descifrado: " << decrypted << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
