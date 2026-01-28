/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Declaración de la clase de excepción para manejar errores de dimensiones incompatibles en matrices
 */

#ifndef MATRIZ_EXCEPTION_H
#define MATRIZ_EXCEPTION_H

#include <exception>

// Heredamos de la clase base 'std::exception'
class DimensionesIncompatibles : public std::exception {
 public:
  // Sobrescribimos el método 'what()', que es el estándar para obtener el mensaje de error
  const char* what() const noexcept override {
    return "ERROR: Las dimensiones de las matrices no coinciden. No se puede multiplicar.";
  }
};

#endif