/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 2: Cifrado de Vigenere
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 5/02/2025
 * Archivo: utils.cc: Implementación de las funciones auxiliares
 */

#include "utils.h"
#include "vigenere.h"

#include <iostream>
#include <cctype>
#include <iomanip>
#include <exception>

/**
 * @brief Process the encryption of a message using the Vigenere cipher
 */
void ProcessEncryption() {
  std::string key, text;
  system("clear");
  std::cout << "Key: ";
  std::getline(std::cin, key);
  VigenereCipher cipher(key);

  std::cout << "Message: ";
  std::getline(std::cin, text);

  std::string encrypted = cipher.Encrypt(text);

  std::cout << "Key: " << cipher.GetKey() << std::endl;
  std::cout << "Original message: " << text << std::endl;
  std::cout << "Encrypted message: " << encrypted << std::endl;
  std::cout << "Decrypted message: " << cipher.Decrypt(encrypted) << std::endl;
}

/**
 * @brief Process the decryption of a message using the Vigenere cipher
 */
void ProcessDecryption() {
  std::string key, cipher_text;
  system("clear");
  std::cout << "Key: ";
  std::getline(std::cin, key);
  VigenereCipher cipher(key);

  std::cout << "Message: ";
  std::getline(std::cin, cipher_text);

  std::string decrypted = cipher.DecryptAlterno(cipher_text);  

  std::cout << "Key: " << cipher.GetKey() << std::endl;;
  std::cout << "Decrypted message: " << decrypted << std::endl;
}

/**
 * @brief Shifts a character by a given key
 * @param character Character to shift
 * @param key Key to shift the character
 * @param encrypt True if the character is being encrypted, false if it is being decrypted
 * @return Shifted character
 */
char ShiftChar(char character, char key, bool encrypt) {
  int shift = (std::toupper(key) - 'A');
  if (!encrypt) shift = -shift;
  return 'A' + (character - 'A' + shift + 26) % 26;
}

/**
 * @brief Preprocesses a text by removing non-alphabetic characters and converting it to uppercase
 * @param text Text to preprocess
 * @return Processed text
 */
std::string PreProcessText(const std::string& text) {
  std::string processed;
  for (char character : text) {
    if (std::isalpha(character)) {
      processed += std::toupper(character);
    }
  }
  return processed;
}

void ProcessEncryptionAlterno() {
  std::string key, text;
  system("clear");
  std::cout << "Key: ";
  std::getline(std::cin, key);
  VigenereCipher cipher(key);

  std::cout << "Message: ";
  std::getline(std::cin, text);

  std::string encrypted = cipher.EncryptAlterno(text);

  std::cout << "Key: " << cipher.GetKey() << std::endl;
  std::cout << "Original message: " << text << std::endl;
  std::cout << "Encrypted message: " << encrypted << std::endl;
  std::cout << "Decrypted message: " << cipher.DecryptAlterno(encrypted) << std::endl;
}