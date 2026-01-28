/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Implementación de la clase ResolverMatriz para resolver la multiplicación de matrices usando diferentes algoritmos
 */

#include "resolver_matriz.h"

/**
 * @brief Constructor por defecto
 * 
 */
ResolverMatriz::ResolverMatriz() : algoritmo_(nullptr) {}


/**
 * @brief Constructor
 * 
 * @param algoritmo 
 */
ResolverMatriz::ResolverMatriz(std::unique_ptr<Algoritmo> algoritmo) : algoritmo_(std::move(algoritmo)) {}

/**
 * @brief Setter para cambiar el algoritmo en tiempo de ejecución
 * 
 * @param algoritmo 
 */
void ResolverMatriz::setAlgoritmo(std::unique_ptr<Algoritmo> algoritmo) {
  algoritmo_ = std::move(algoritmo);
}

/**
 * @brief Método para resolver la multiplicación de matrices usando el algoritmo actual
 * 
 * @param m1 
 * @param m2 
 * @return Matriz 
 */
Matriz ResolverMatriz::resolver(Matriz& m1, Matriz& m2) {
  return algoritmo_->calcular(m1, m2);
}