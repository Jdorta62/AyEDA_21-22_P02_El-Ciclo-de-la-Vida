/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateEggClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase StateEgg.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#ifndef STATEEGGCLASS_H
#define STATEEGGCLASS_H

#include "StateClass.h"
#include "StateLarvaClass.h"
#include "StateDeadClass.h"

class StateEgg : public State {
 public:
  StateEgg();
  char GetState() const override;
  int Neighbors(Grid const &grid, int i, int j) override;
  State* NextState() override;

 private: 
  char const kegg_state_ = 'E';
  int number_of_neighbors_egg_state_ = 0;
  int number_of_neighbors_larva_state_ = 0;
};

#endif