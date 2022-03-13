/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file Functions.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero de cabezera que contiene la declaración de las distintas funciones usadas en el programa Ciclo de la vida.
  * @bug ningún bug conocido.
  * 
  */

#include "string"
#include "GridClass.h"

void GridUserModificator(Grid &grid, int const &rows, int const &columns);
void PositionUserSelector(Grid &grid, int const &rows, int const &columns, State* const &new_state, std::string const &state_type);
void MessageErrorPrinter(std::string error_message);
void TurnPrinter(Grid &grid, int const &number_of_turns);