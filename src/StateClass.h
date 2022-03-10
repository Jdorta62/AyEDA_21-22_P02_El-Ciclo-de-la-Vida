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
  * 
  */

#ifndef STATECLASS_H
#define STATECLASS_H

#include <iostream>
#include <string>

class State {
 public:
  ~State();
  virtual std::string GetState() const = 0;
  void SetState(std::string const &state) {
    state_ = state;
  }
 protected:
  std::string state_;
};

/**
 * @brief sobrecarga del operador de comparación. Sierve para ver si 2 estados son iguales
 * @param state1 primer objeto State a comparar.
 * @param state2 segundo objeto State a comparar.
 * @return bool 
 */
bool operator==(State const &state1, State const &state2) {
  if (state1.GetState() == state2.GetState()) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief sobrecarga del operador de comparación. Sierve para ver si 2 estados son iguales
 * @param state1 objeto State a comparar con el objeto string.
 * @param state2 string a comparar con el objeto State.
 * @return bool 
 */
bool operator==(State const &state1, std::string const &state2) {
  if (state1.GetState() == state2) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief sobrecarga del operacdor de insersión <<.
 * @param os variable que almacena lo que se quiere insertar en el flujo de salida.
 * @param state objeto State que se va a imprimir por pantalla
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream &os, State const &state) {
  os << state.GetState();
  return os;
}

#endif