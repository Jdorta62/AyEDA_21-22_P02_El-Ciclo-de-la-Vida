/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StatePupaClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 12 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase StatePupa.
  * @bug ningún bug conocido.
  * @version 1.0
  * 
  */

#ifndef STATEPUPACLASS_H
#define STATEPUPACLASS_H

#include "StateClass.h"

class StatePupa : public State {
 public:
  StatePupa();
  char GetState() const override;
  int Neighbors(Grid const &grid, int i, int j) override;
  State* NextState() override;

 private: 
  char const kpupa_state_ = 'P';
};

#endif