/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Implementación de los algoritmos de multiplicación de matrices por filas y por columnas
 */

#include "algoritmo.h"
#include "matriz_exception.h"

/**
 * @brief Implementación del algoritmo de multiplicación de matrices por filas
 * 
 * @param m1 
 * @param m2 
 * @return Matriz 
 */
Matriz RowMultAlg::calcular(Matriz& m1, Matriz& m2) {
  // Obtener dimensiones de las matrices
  int rows1 = m1.getRows();
  int cols1 = m1.getCols();
  int rows2 = m2.getRows();
  int cols2 = m2.getCols();
  
  // Verificar compatibilidad de dimensiones
  if (cols1 != rows2) {
    throw DimensionesIncompatibles();
  }

  // Crear matriz resultado con dimensiones adecuadas
  Matriz resultado(rows1, cols2, 0);

  // Realizar multiplicación por filas
  for (int i{0}; i < rows1; ++i) {
    for (int j{0}; j < cols2; ++j) {
      int suma{0};
      for (int k{0}; k < cols1; ++k) {
        suma += m1.getValue(i, k) * m2.getValue(k, j);
      }
      resultado.setValue(i, j, suma);
    }
  }

  return resultado;
}

/**
 * @brief Implementación del algoritmo de multiplicación de matrices por columnas
 * 
 * @param m1 
 * @param m2 
 * @return Matriz 
 */
Matriz ColMultAlg::calcular(Matriz& m1, Matriz& m2) {
  // Obtener dimensiones de las matrices
  int rows1 = m1.getRows();
  int cols1 = m1.getCols();
  int rows2 = m2.getRows();
  int cols2 = m2.getCols();
  
  // Verificar compatibilidad de dimensiones
  if (cols1 != rows2) {
    throw DimensionesIncompatibles();
  }

  // Crear matriz resultado con dimensiones adecuadas
  Matriz resultado(rows1, cols2, 0);

  // Realizar multiplicación por columnas
  for (int j{0}; j < cols2; ++j) {
    for (int i{0}; i < rows1; ++i) {
      int suma{0};
      for (int k{0}; k < cols1; ++k) {
        suma += m1.getValue(i, k) * m2.getValue(k, j);
      }
      resultado.setValue(i, j, suma);
    }
  }

  return resultado;
}


