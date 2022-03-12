/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file GridClass.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero que contiene la implementación de la clase Grid.
  * @bug ningún bug conocido.
  * 
  */

#include "GridClass.h"

/**
 * @brief constructor de la clase Grid
 * @param rows número de filas que tendrá la rejilla
 * @param colums número de columnas que tendrá la rejilla
 */
Grid::Grid(int const &rows, int const &columns) {
  if (rows <= 0 || columns <= 0) {
    std::cerr << "Rows and columns have to be over 0" << std::endl;
    exit(EXIT_FAILURE);
  }
  rows_ = rows+2;
  columns_ = columns+2;
  grid_pointer_ = new Cell*[rows_];
  for (size_t i{0}; i < rows_; ++i) {
    grid_pointer_[i] = new Cell[columns_];
  }
  for (size_t i{1}; i < rows_; ++i) {
    for (size_t j{1}; j < columns_; ++j) {
      Cell temp_cell = *(*(grid_pointer_+i)+j);
      temp_cell.SetPosition(i,j);
      *(*(grid_pointer_+i)+j) = temp_cell;
    }
  }
}

/**
 * @brief Construct a new Grid:: Grid object
 * @param grid_pointer 
 * @param rows 
 * @param columns 
 */
Grid::Grid(Cell **grid_pointer, int const &rows, int const &columns) {
  grid_pointer_ = grid_pointer;
  rows_ = rows;
  columns_ = columns;
}

/**
 * @brief destructor de la clase Grid
 */
Grid::~Grid() {
  for(int i{0}; i < rows_; ++i) {
    delete[] grid_pointer_[i];
  }
  delete[] grid_pointer_;
}

/**
 * @brief método que da acceso de solo lectura a las células de la rejilla
 * @param row fila destino de la célula
 * @param column 
 * @return const Cell& 
 */
const Cell& Grid::GetCell(int const &row, int const &column) const {
  if (row == 0 || row == (rows_ - 1) || column == 0 || column == (columns_ - 1)) {
    std::cout << row << " " << column << std::endl;
    std::cerr << "Error: not valid coordenate" << std::endl;
    exit(EXIT_FAILURE);
  }
  return *(*(grid_pointer_+row)+column);
}

/**
 * @brief método que actualiza el número estados de las células a partir del estado previo de las células.
 */
/*
void Grid::NextGeneration() {
  for(int i{1}; i < (rows_ - 1); ++i) {
    for(int j{1}; j < (columns_ - 1); ++j) {
      Cell temp_cell = GetCell(i,j);
      temp_cell.Neighbors(*this);
      *(*(grid_pointer_+i)+j) = temp_cell;
    }
  }
  for(int i{1}; i < (rows_ - 1); ++i) {
    for(int j{1}; j < (columns_ - 1); ++j) {
      Cell temp_cell = GetCell(i,j); 
      temp_cell.UpdateState(); 
      *(*(grid_pointer_+i)+j) = temp_cell;
    }
  }
}
*/
/**
 * @brief método que permite cambiar el estado de una célula específica dentro de la rejilla
 * @param row numero de la fila
 * @param column numero de la columna
 * @param new_state estado al que va a cambiar
 */


void Grid::StateChanger(int const &row, int const &column, State* const &new_state) {
  /*if (row == 0 || row == (rows_-1) || column == 0 || column == (columns_-1)) {
    std::cerr << "Error: not valid coordenate" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (new_state.GetState() != ALIVE && new_state.GetState() != DEAD) {
    std::cerr << "Error: not valid cell state" << std::endl;
    exit(EXIT_FAILURE);     
  }*/
  Cell new_cell = GetCell(row,column);
  new_cell.SetState(new_state);
  *(*(grid_pointer_+row)+column) = new_cell;
}

/**
 * @brief getter del atributo privado rows_
 * @return int 
 */
int Grid::GetRows() const {
  return rows_;
}

/**
 * @brief getter del atributo privado columns_
 * @return int 
 */
int Grid::GetColumns() const {
  return columns_;
}

/**
 * @brief sobrecarga del operacdor de insersión <<.
 * @param os variable que almacena lo que se quiere insertar en el flujo de salida.
 * @param grid objeto Grid que se va a imprimir por pantalla
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream &os, Grid const &grid) {
  os << " ";
  for(size_t i{1}; i < grid.GetColumns()-1; ++i) {
    os << "_";
  }
  os << std::endl;
  for (size_t i{1}; i < grid.GetRows()-1; ++i) {
    os << "|";
    for (size_t j{1}; j < grid.GetColumns()-1; ++j) {
      os << grid.GetCell(i,j);
    }
    os << "|" << std::endl;
  }
  os << " ";
  for(size_t i{1}; i < grid.GetRows()-1; ++i) {
    os << "¯";
  }
  os << std::endl;
  return os;
}