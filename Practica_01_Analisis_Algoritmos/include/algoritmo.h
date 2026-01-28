/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Declaración de la clase Algoritmo y sus derivados para operar sobre matrices
 */

#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "matriz.h"

// Clase base abstracta para algoritmos de operación sobre matrices
class Algoritmo {
 public:
  virtual ~Algoritmo() = default; 
  virtual Matriz calcular(Matriz& m1, Matriz& m2) = 0;
};

// Algoritmo de multiplicación por filas
class RowMultAlg : public Algoritmo {
 public:
  Matriz calcular(Matriz& m1, Matriz& m2) override;
};

// Algoritmo de multiplicación por columnas
class ColMultAlg : public Algoritmo {
 public:
  Matriz calcular(Matriz& m1, Matriz& m2) override;
};

#endif