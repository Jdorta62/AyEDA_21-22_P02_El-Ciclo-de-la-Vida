#include "Functions.h"

int main() {
  int rows{0}, columns{0};
  while (rows <= 0 && columns <= 0) {
    std::cout << "Inserte el número de filas y columnas que tendrá la rejilla: ";
    std::cin >> rows;
    std::cin >> columns;
    if (rows <= 0 || columns <= 0) {
      std::cout << "Intente de nuevo. Recuerde que las filas y/o columnas tienen que se mayores que 0." << std::endl;
    }
  } 
  Grid my_grid{rows,columns};
  GridUserModificator(my_grid, rows, columns);
  int number_of_turns{0};
  std::cout << "¿Cuantos turnos tendrá el juego? ";
  std::cin >> number_of_turns;
  while(number_of_turns <= 0) {
    MessageErrorPrinter("Error: número de turnos no válido, tiene que ser mayor que 0. Intente de nuevo: ");
    std::cin >> number_of_turns;
  }
  TurnPrinter(my_grid, number_of_turns);
  return 0;
}