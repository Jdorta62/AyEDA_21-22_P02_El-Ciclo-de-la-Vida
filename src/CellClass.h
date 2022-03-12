/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file CellClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase Cell.
  * @bug ningún bug conocido.
  * 
  */

#ifndef CELLCLASS_H
#define CELLCLASS_H

#include "StateClass.h"
#include "GridClass.h"
#include <utility>

#define ALIVE "viva"
#define DEAD "muerta"

class Grid;

class Cell {
 public:
  Cell();
  Cell(State* const &cell_state, std::pair<int, int> const &cell_position, int const &neighbors_alive);
  ~Cell();
  State* GetState() const;
  State* SetState(State* const &state);
  void SetPosition(int const &row, int const &column);
  std::pair<int, int> GetPosition() const;
  int GetNeighborsAlive() const;
  int SetNeighborsAlive(int const &neighbors_alive);
 private:
  State* cell_state_;
  std::pair<int, int> cell_position_{-1,-1};
  int neighbors_alive_{-2};
};

std::ostream& operator<<(std::ostream &os, Cell const &cell);
#endif