/* Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Seguridad en Sistemas Informáticos
 * Curso: 3º
 * Práctica 2: Cifrado de Vigenere
 * Autor: Valeria Bosch Pérez
 * Correo: alu0101485287@ull.edu.es
 * Fecha: 5/02/2025
 * Archivo: utils.h: Declaración de las funciones auxiliares
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>

void ProcessEncryption();
void ProcessDecryption();

char ShiftChar(char character, char key, bool encrypt);
std::string PreProcessText(const std::string& text);

void ProcessEncryptionAlterno();

#endif // UTILS_H 