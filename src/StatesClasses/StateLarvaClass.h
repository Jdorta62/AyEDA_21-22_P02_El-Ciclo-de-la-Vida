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

class StateLarva : public State {
 public:
  StateLarva();
  char GetState() const override;
  int Neighbors(Grid const &grid, int i, int j) override;
  State* NextState() override;

 private: 
  char const klarva_state_ = 'L';
};

#endif