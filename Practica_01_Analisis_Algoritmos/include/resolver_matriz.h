/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Declaración de la clase ResolverMatriz para resolver la multiplicación de matrices usando diferentes algoritmos
 */

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <memory>
#include "algoritmo.h"
#include "matriz.h"

class ResolverMatriz {
 public:
  // Constructor
  ResolverMatriz();
  ResolverMatriz(std::unique_ptr<Algoritmo> algoritmo);
  
  // Setter para cambiar el algoritmo en tiempo de ejecución
  void setAlgoritmo(std::unique_ptr<Algoritmo> algoritmo);
  
  // Método para resolver la multiplicación de matrices usando el algoritmo actual
  Matriz resolver(Matriz& m1, Matriz& m2);
 
  private:
  std::unique_ptr<Algoritmo> algoritmo_;
};

#endif