/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file StateClass.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero de cabezera que contiene la declaración de la clase State.
  * @bug ningún bug conocido.
  * @version 2.0
  * 
  */

#ifndef STATECLASS_H
#define STATECLASS_H

#include <iostream>
#include <string>

class Grid;

class State {
 public:
  virtual char GetState() const = 0;
  virtual int Neighbors(Grid const &grid, int i, int j) = 0;
  virtual State* NextState() = 0;
};

#endif