/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateDeadClass.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de que contiene la implementación de la clase StateDead.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#include "StateDeadClass.h"

/**
 * @brief cosntructor de la clase
 */
StateDead::StateDead() {
}

/**
 * @brief Destroy the State Dead:: State Dead object
 */
StateDead::~StateDead() {

}

/**
 * @brief getter que retorna el atributo privado
 * @return char 
 */
char StateDead::GetState() const {
  return kdead_state_;
}

/**
 * @brief método que cuenta el número de celulas en estado ____ de la vecindad
 * @param grid rejilla de celulas
 * @param i fila en la que se encuentra la célula a la que se le quieren contar los vecinos.
 * @param j columna en la que se encuentra la célula a la que se le quieren contar los vecinos.
 * @return int 
 */
int StateDead::Neighbors(Grid const &grid, int i, int j) {
  if (i <= 0 || j <= 0 || i >= grid.GetRows() - 1 || j >= grid.GetColumns() - 1) {
    return -1;
  }
  int number_of_neighbors_adult_state_counter{0};
  for(int k{i-1}; k <= i + 1; ++k) {
    for(int l{j-1}; l <= j + 1; ++l) {
      if (k > 0 && l > 0 && k < grid.GetRows() - 1 && l < grid.GetColumns() - 1 && (k != i || l != j)) {
        Cell temp_cell = grid.GetCell(k,l);
        if(temp_cell.GetState()->GetState() == 'A') {
          ++number_of_neighbors_adult_state_counter;
        }
      }
    }
  }
  number_of_neighbors_adult_state_ = number_of_neighbors_adult_state_counter;
  return number_of_neighbors_adult_state_;
}

/**
 * @brief método que implementa las reglas de transición para calcular el siguiente estado
 * @return State* 
 */
State* StateDead::NextState() {
  State* next_state = new StateEgg();
  if (number_of_neighbors_adult_state_ < 2) {
    next_state = new StateDead();
  }
  return next_state;
}