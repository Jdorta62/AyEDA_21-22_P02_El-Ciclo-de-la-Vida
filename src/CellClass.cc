/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file CellClass.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero que contiene la implementación de la clase Cell.
  * @bug ningún bug conocido.
  * pair.first = filas
  * pait.secod = columnas
  */

#include "CellClass.h"

/**
 * @brief Constructor por defecto de la clase cell
 */
Cell::Cell() {
}

/**
 * @brief Constructor de la clase cell
 */
Cell::Cell(State const &cell_state, std::pair<int, int> const &cell_position, int const &neighbors_alive) {
  cell_state_ = cell_state;
  cell_position_ = cell_position;
  neighbors_alive_ = neighbors_alive;
}

/**
 * @brief destructor de objetos Cell
 */
Cell::~Cell() {
}

/**
 * @brief getter que retorna el valor del atributo privado cell_state_
 * @return State 
 */
State Cell::GetState() const {
  return cell_state_;
}

/**
 * @brief setter que permite inicializar o modificar el atributo privado cell_state_
 * @param state valor que tendrá el atributo privado cell_state_
 * @return State 
 */
State Cell::SetState(State const &state) {
  cell_state_ = state;
  return cell_state_;
}

/**
 * @brief método que actualiza el estado de la celula en base a las reglas de transición
 */
void Cell::UpdateState() {
  if (cell_state_ == ALIVE) {
    if (neighbors_alive_ == 2 || neighbors_alive_ == 3) {
      State temp_state{ALIVE};
      cell_state_ = temp_state;
    } else {
      State temp_state{DEAD};
      cell_state_ = temp_state;
    }
  } else {
    if (neighbors_alive_ == 3) {
      State temp_state{ALIVE};
      cell_state_ = temp_state;
    } else {
      State temp_state{DEAD};
      cell_state_ = temp_state;
    }
  }
}

/**
 * @brief método que calcula el número de celulas vivas vecinas de la célula invocante
 * @param grid rejilla en la que se encuentran todas las celulas
 * @return int 
 */
int Cell::Neighbors(Grid const &grid) {
  if (cell_position_.first == -1 || cell_position_.second == -1) {
    return -1;
  }
  int number_of_neihbors{0};
  for(int i{cell_position_.first - 1}; i <= (cell_position_.first + 1); ++i) {
    for(int j{cell_position_.second - 1}; j <= (cell_position_.second + 1); ++j) {
      if ((i != cell_position_.first || j != cell_position_.second) && i != 0 && i != grid.GetRows() - 1 && j != 0 && j != grid.GetColumns() - 1) {
        if(grid.GetCell(i,j).GetState() == ALIVE) {
          ++number_of_neihbors;
        }
      }
    }
  }
  neighbors_alive_ = number_of_neihbors;
  return number_of_neihbors;
}

/**
 * @brief setter que permite inicializar o modificar el atributo privado cell_position_
 * @param row fila donde se encuentre la célula
 * @param column columna donde se encuentre la célula
 */
void Cell::SetPosition(int const &row, int const &column) {
  cell_position_.first = row;
  cell_position_.second = column;
}

/**
 * @brief getter que retorna el valor del atributo privado cell_position_
 * @return std::pair<int, int>
 */
std::pair<int, int> Cell::GetPosition() const {
  return cell_position_;
}

/**
 * @brief getter que retorna el atributo privado neighbors_alive_
 * @return int 
 */
int Cell::GetNeighborsAlive() const {
  return neighbors_alive_;
}

/**
 * @brief setter que permite inicializar o modificar el atributo privado
 * @param neighbors_alive nuevo valor para el atributo privado
 * @return int 
 */
int Cell::SetNeighborsAlive(int const &neighbors_alive) {
  neighbors_alive_ = neighbors_alive;
  return neighbors_alive_;
}

/**
 * @brief sobrecarga del operacdor de insersión <<.
 * @param os variable que almacena lo que se quiere insertar en el flujo de salida.
 * @param cell objeto Cell que se va a imprimir por pantalla
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream &os, Cell const &cell) {
  if (cell.GetState() == ALIVE) {
    os << "X";
  } else {
    os << "-"; //<< "[" << cell.GetPosition().first << "]" << "[" << cell.GetPosition().second << "]"
  }
  return os;
}