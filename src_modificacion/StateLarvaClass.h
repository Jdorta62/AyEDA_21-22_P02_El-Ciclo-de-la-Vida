/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateLarvaClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase StateLarva.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#ifndef STATELARVACLASS_H
#define STATELARVACLASS_H

#include "StateClass.h"
#include "CellClass.h"
#include "GridClass.h"

class StateLarva : public State {
 public:
  StateLarva();
  ~StateLarva();
  char GetState() const override;
  int Neighbors(Grid const &grid, int i, int j) override;
  State* NextState() override;

 private: 
  char const klarva_state_ = 'L';
  int number_of_neighbors_larva_state_;
  int number_of_neighbors_egg_pupa_adult_state_;
};

#endif