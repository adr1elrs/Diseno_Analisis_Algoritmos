/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Declaración de la clase Matriz para manejar matrices de enteros con inicialización aleatoria
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <vector>


class Matriz {
 public:
  // Constructor que inicializa una matriz de tamaño rows x cols con números aleatorios entre 0 y 10
  Matriz(int rows, int cols);
  Matriz(int rows, int cols, int valor);
  
  // Getters
  inline int getRows() const { return rows_; }
  inline int getCols() const { return cols_;}
  inline int getValue(int row, int col) const { return data_[row][col]; }

  // Setter
  inline void setValue(int row, int col, int value) { data_[row][col] = value; }
  
  // Método para imprimir la matriz
  friend std::ostream& operator<<(std::ostream& os, const Matriz& matriz);

 private:
  int rows_;
  int cols_;
  std::vector<std::vector<int>> data_;

};

#endif 
