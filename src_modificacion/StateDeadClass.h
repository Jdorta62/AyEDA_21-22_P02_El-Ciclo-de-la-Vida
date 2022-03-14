/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateDeadClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase StateDead.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#ifndef STATEDEADCLASS_H
#define STATEDEADCLASS_H

#include "StateClass.h"
#include "CellClass.h"
#include "GridClass.h"

class StateDead : public State {
 public:
  StateDead();
  ~StateDead();
  char GetState() const override;
  int Neighbors(Grid const &grid, int i, int j) override;
  State* NextState() override;
 private: 
  char const kdead_state_ = 'D';
  int number_of_neighbors_alive_state_;
};

#endif