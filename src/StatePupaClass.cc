/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StatePupaClass.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de que contiene la implementación de la clase StatePupa.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#include "StatePupaClass.h"

/**
 * @brief cosntructor de la clase
 */
StatePupa::StatePupa() {
}

/**
 * @brief Destroy the State Pupa:: State Pupa object
 */
StatePupa::~StatePupa() {
}

/**
 * @brief getter que retorna el atributo privado
 * @return char 
 */
char StatePupa::GetState() const {
  return kpupa_state_;
}

/**
 * @brief método que cuenta el número de celulas en estado ____ de la vecindad
 * @param grid rejilla de celulas
 * @param i fila en la que se encuentra la célula a la que se le quieren contar los vecinos.
 * @param j columna en la que se encuentra la célula a la que se le quieren contar los vecinos.
 * @return int 
 */
int StatePupa::Neighbors(Grid const &grid, int i, int j) {
  if (i <= 0 || j <= 0 || i >= grid.GetRows() - 1 || j >= grid.GetColumns() - 1) {
    return -1;
  }
  int number_of_neighbors_larva_state_counter{0};
  int number_of_neighbors_else_state_counter{0};
  for(int k{i-1}; k <= i + 1; ++k) {
    for(int l{j-1}; l <= j + 1; ++l) {
      if (k > 0 && l > 0 && k < grid.GetRows() - 1 && l < grid.GetColumns() - 1 && (k != i || l != j)) {
        Cell temp_cell = grid.GetCell(k,l);
        if(temp_cell.GetState()->GetState() == 'L') {
          ++number_of_neighbors_larva_state_counter;
        } else {
          ++number_of_neighbors_else_state_counter;
        }
      }
    }
  }
  number_of_neighbors_larva_state_ = number_of_neighbors_larva_state_counter;
  number_of_neighbors_else_state_ = number_of_neighbors_else_state_counter;
  return number_of_neighbors_else_state_;
}

/**
 * @brief método que implementa las reglas de transición para calcular el siguiente estado
 * @return State* 
 */
State* StatePupa::NextState() {
  State* next_state = new StateAdult();
  if (number_of_neighbors_else_state_ < number_of_neighbors_larva_state_) {
    next_state = new StateDead();
  }
  return next_state;
}