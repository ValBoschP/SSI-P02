#include "vigenere.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <exception>

int main() {
  int option;
  do {
    system("clear");
    std::cout << std::setw(40) << std::setfill('=') << '\n';
    std::cout << "Vigenere Cipher" << std::endl;
    std::cout << std::setw(40) << std::setfill('=') << '\n';
    std::cout << "1. Encrypt" << std::endl;
    std::cout << "2. Decrypt" << std::endl;
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
      case 0:
        return 0;
      default:
        std::cout << "Invalid option" << std::endl;
    }
  } while (option != 0);
  return 0;
}
