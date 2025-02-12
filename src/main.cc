/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 2: Cifrado de Vigenere
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 5/02/2025
 * Archivo: main.cc: Programa principal que permite al 
 * usuario cifrar y descifrar mensajes utilizando el cifrado 
 * de Vigènere.
 */

#include "vigenere.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <exception>

/**
 * @brief Main function
 */
int main() {
  int option;
  do {
    system("clear");
    std::cout << std::setw(40) << std::setfill('=') << '\n';
    std::cout << "Vigenere Cipher" << std::endl;
    std::cout << std::setw(40) << std::setfill('=') << '\n';
    std::cout << "1. Encrypt" << std::endl;
    std::cout << "2. Decrypt" << std::endl;
    std::cout << "3. Encrypt (alternate)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Option: ";
    std::cin >> option;
    std::cin.ignore();
    switch (option) {
      case 1:
        ProcessEncryption();
        std::cout << std::endl << "Press ENTER to continue...";
        std::cin.get();
        break;
      case 2:
        ProcessDecryption();
        std::cout << std::endl << "Press ENTER to continue...";
        std::cin.get();
        break;
      case 3:
        ProcessEncryptionAlterno();
        std::cout << std::endl << "Press ENTER to continue...";
        std::cin.get();
        break;
      case 0:
        return 0;
      default:
        std::cout << "Invalid option" << std::endl;
    }
  } while (option != 0);
  return 0;
}
