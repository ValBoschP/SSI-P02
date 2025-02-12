/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 2: Cifrado de Vigenere
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 5/02/2025
 * Archivo: vigenere.h: Declaración de la clase VigenereCipher
 */

#ifndef VIGENERE_H
#define VIGENERE_H 

#include <string>
#include <cctype>
#include <iostream>

/**
 * @brief VigenereCipher class
 */
class VigenereCipher {
 public:
  // Constructor
  VigenereCipher(const std::string& key);
  // Getter
  std::string GetKey() const { return key_; }
  // Methods
  std::string Encrypt(const std::string& text) const;
  std::string Decrypt(const std::string& text) const;
  
  std::string EncryptAlterno(const std::string& text) const;
  std::string DecryptAlterno(const std::string& text) const;
 private:
  std::string key_;
};

#endif // VIGENERE_H