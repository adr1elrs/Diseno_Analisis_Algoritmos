/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Adriel Reyes Suárez
 * @since  Enero 28, 2026
 * @description Declaración de funciones para la interfaz de usuario relacionadas con la multiplicación de matrices
 */

#ifndef FUNCIONES_INTERFAZ_H
#define FUNCIONES_INTERFAZ_H

#include <iostream>
#include <chrono>
#include "resolver_matriz.h"
#include "matriz_exception.h"

/**
 * @brief Muestra el menú de opciones al usuario
 * 
 */
void MostrarMenu() {
  std::cout << "Seleccione el algoritmo de multiplicación de matrices:\n\n";
  std::cout << "  1. Multiplicación por filas\n";
  std::cout << "  2. Multiplicación por columnas\n";
  std::cout << "  0. Salir\n\n";
}

/**
 * @brief Procesa la opción ingresada por el usuario
 * 
 * @return int 
 */
int ProcesarOpcion() {
  int opcion{0};
  std::cout << "Ingrese la opción deseada: ";
  std::cin >> opcion;
  std::cout << "\n";
  return opcion;
}

/**
 * @brief Pide al usuario las dimensiones de las matrices
 * 
 * @param rows1 
 * @param cols1 
 * @param rows2 
 * @param cols2 
 */
void PedirDimensiones(int& rows1, int& cols1, int& rows2, int& cols2) {
  std::cout << "Ingrese el número de filas y columnas de la primera matriz (separados por espacio): ";
  std::cin >> rows1 >> cols1;
  std::cout << "Ingrese el número de filas y columnas de la segunda matriz (separados por espacio): ";
  std::cin >> rows2 >> cols2;
  std::cout << "\n";
}

/**
 * @brief Programa principal que maneja la interacción con el usuario
 * 
 */
void ProgramaPrincipal() {

  while (true) {
    // Mostrar el menú
    MostrarMenu();

    // Procesar la opción del usuario
    int opcion = ProcesarOpcion();
    
    if (opcion == 0) {
      std::cout << "Saliendo del programa.\n";
      break;
    } else if (opcion < 0 || opcion > 2) {
      std::cout << "Opción no válida. Intente de nuevo.\n\n";
      continue;
    }

    // Pedir dimensiones de las matrices
    int rows1, cols1, rows2, cols2;
    PedirDimensiones(rows1, cols1, rows2, cols2);
    
    // Crear las matrices
    Matriz m1(rows1, cols1);
    Matriz m2(rows2, cols2);
    std::cout << "Matriz 1:\n" << m1 << "\n";
    std::cout << "Matriz 2:\n" << m2 << "\n";

    // Crear el resolvedor de matrices
    ResolverMatriz solver;

    switch (opcion) {
      // Multiplicación por filas
      case 1: {
        solver.setAlgoritmo(std::make_unique<RowMultAlg>());
        break;
      }
      // Multiplicación por columnas
      case 2: {
        solver.setAlgoritmo(std::make_unique<ColMultAlg>());
        break;
      }
      default: {
        std::cout << "Opción no válida. Intente de nuevo.\n";
        continue;;
      }
    }
    // Realizar la multiplicación y mostrar el resultado
    try {
      auto start = std::chrono::high_resolution_clock::now();
      Matriz resultado = solver.resolver(m1, m2);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
      std::cout << "Resultado de la multiplicación: \n" << resultado << "\n";
      std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos.\n";
    } catch (const DimensionesIncompatibles& e) {
      std::cerr << e.what() << "\n\n";
    }
  }
}


#endif