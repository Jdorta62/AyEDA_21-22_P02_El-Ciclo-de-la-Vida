/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateAdultClass.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de que contiene la implementación de la clase StateAdult.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#include "StateAdultClass.h"

/**
 * @brief cosntructor de la clase
 */
StateAdult::StateAdult() {
}

/**
 * @brief Destroy the State Adult:: State Adult object
 */
StateAdult::~StateAdult() {
}

/**
 * @brief getter que retorna el atributo privado
 * @return char 
 */
char StateAdult::GetState() const {
  return kadult_state_;
}

/**
 * @brief método que cuenta el número de celulas en estado ____ de la vecindad
 * @param grid rejilla de celulas
 * @param i fila en la que se encuentra la célula a la que se le quieren contar los vecinos.
 * @param j columna en la que se encuentra la célula a la que se le quieren contar los vecinos.
 * @return int 
 */
int StateAdult::Neighbors(Grid const &grid, int i, int j) {
  if (i <= 0 || j <= 0 || i >= grid.GetRows() - 1 || j >= grid.GetColumns() - 1) {
    return -1;
  }
  bool another_adult{false};
  for(int k{i-1}; k <= i + 1 && another_adult == false; ++k) {
    for(int l{j-1}; l <= j + 1 && another_adult == false; ++l) {
      if (k > 0 && l > 0 && k < grid.GetRows() - 1 && l < grid.GetColumns() - 1 && (k != i || l != j)) {
        Cell temp_cell = grid.GetCell(k,l);
        if(temp_cell.GetState()->GetState() == 'A') {
          another_adult = true;
        }
      }
    }
  }
  another_adult_ = another_adult;
  //std::cout << "Soy del estado adulta. " << another_adult_ << std::endl;
  if (another_adult_) {
    return 1;
  }
  return 0;
}

/**
 * @brief método que implementa las reglas de transición para calcular el siguiente estado
 * @return State* 
 */
State* StateAdult::NextState() {
  State* next_state = new StateDead();
  if (another_adult_ == true) {
    next_state = new StateEgg();
  }
  return next_state;
}