/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateAdultClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase StateAdult.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */
#ifndef STATEADULTCLASS_H
#define STATEADULTCLASS_H

#include "StateClass.h"
#include "CellClass.h"
#include "GridClass.h"

class Grid;
class State;

class StateAdult : public State {
 public:
  StateAdult();
  ~StateAdult();
  char GetState() const override;
  int Neighbors(Grid const &grid, int i, int j) override;
  State* NextState() override;

 private: 
  char const kadult_state_ = 'A';
  bool another_adult_;
};

#endif