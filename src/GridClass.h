/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file GridClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase Grid.
  * @bug ningún bug conocido.
  * 
  */

#ifndef GRIDCLASS_H
#define GRIDCLASS_H

#include "CellClass.h"

class Cell;

class Grid {
 public:
  Grid(int const &rows, int const &columns);
  Grid(Cell **grid_pointer, int const &rows, int const &columns);
  ~Grid();
  const Cell& GetCell(int const &row, int const &column) const;
  void NextGeneration(/*Grid temp_grid*/);
  void StateChanger(int const &row, int const &column, State const &new_state);
  int GetRows() const;
  int GetColumns() const;
 private:
  Cell **grid_pointer_;
  int rows_;
  int columns_;
};

std::ostream& operator<<(std::ostream &os, Grid const &grid);
#endif
