/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 2: Cifrado de Vigenere
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 5/02/2025
 * Archivo: vigenere.cc: Implementación de la clase VigenereCipher
 */

#include "vigenere.h"
#include "utils.h"

#include <cctype>

/**
 * @brief VigenereCipher constructor
 */
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

/**
 * @brief Encrypts a text using the Vigenere cipher
 * @param text Text to encrypt
 * @return Encrypted text
 */
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

/**
 * @brief Decrypts a text using the Vigenere cipher
 * @param text Text to decrypt
 * @return Decrypted text
 */
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

/** MODIFICACION
 *  Cifrado de clave alterno:
 *  Cifrado donde se suma en las posiciones impares y se resta en las posiciones pares.
 *        Se empieza por index 1
 *        Se invierte la regla para recuperar el mensaje
 * Ejemplo: 
 * Key: planeta
 * Text: el fuego invisible
 * Cipher Text: TAFHINOTYVVOBBAT
 */

std::string VigenereCipher::EncryptAlterno(const std::string& text) const {
  std::string processed = PreProcessText(text);
  if (processed.empty()) return "";

  std::string encrypted;
  for (size_t i = 0, j = 0; i < processed.size(); ++i, j = (j + 1) % key_.size()) {
    int shift = (std::toupper(key_[j]) - 'A');
    if ((i + 1) % 2 == 0) shift = -shift; 
    encrypted += 'A' + (processed[i] - 'A' + shift + 26) % 26;
  }
  return encrypted;
}

std::string VigenereCipher::DecryptAlterno(const std::string& text) const {
  std::string clean_text = PreProcessText(text);
  if (clean_text.empty()) return "";

  std::string decrypted;
  for (size_t i = 0, j = 0; i < clean_text.size(); ++i, j = (j + 1) % key_.size()) {
    int shift = (std::toupper(key_[j]) - 'A');
    if ((i + 1) % 2 == 0) shift = -shift; // Invertimos la regla para recuperar el mensaje
    decrypted += 'A' + (clean_text[i] - 'A' - shift + 26) % 26;
  }
  return decrypted;
}