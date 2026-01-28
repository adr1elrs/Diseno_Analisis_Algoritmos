/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Implementación de la clase Matriz para manejar matrices de enteros con inicialización aleatoria
 */

#include "matriz.h"
#include <cstdlib>

/**
 * @brief Constructor que inicializa una matriz de tamaño rows x cols con números aleatorios entre 0 y 10
 * 
 * @param rows 
 * @param cols 
 */
Matriz::Matriz(int rows, int cols) : rows_(rows), cols_(cols), data_(rows, std::vector<int>(cols)) {
  // Inicializar la matriz con números aleatorios entre 0 y 10
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < cols_; ++j) {
      data_[i][j] = rand() % 10;
    }
  }
}

/**
 * @brief Constructor que inicializa una matriz de tamaño rows x cols con un valor específico
 * 
 * @param rows 
 * @param cols 
 * @param valor 
 */
Matriz::Matriz(int rows, int cols, int valor) : rows_(rows), cols_(cols), data_(rows, std::vector<int>(cols, valor)) {}

/**
 * @brief Sobrecarga del operador de salida para imprimir la matriz
 * 
 * @param os 
 * @param matriz 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Matriz& matriz) {
  for (int i{0}; i < matriz.getRows(); ++i) {
    os << "| ";
    for (int j{0}; j < matriz.getCols(); ++j) {
      os << matriz.getValue(i, j) << " ";
    }
    os << "| ";
    os << "\n";
  }
  return os;
}