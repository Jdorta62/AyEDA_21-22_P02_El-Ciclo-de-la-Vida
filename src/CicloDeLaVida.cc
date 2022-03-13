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

/*
  Grid grid{5,15};
  std::cout << grid;
  grid.StateChanger(2,1,new StateEgg());
  grid.StateChanger(2,2,new StateEgg());
  grid.StateChanger(3,9,new StateEgg());
  grid.StateChanger(3,1,new StateLarva());
  grid.StateChanger(4,6,new StateLarva());
  grid.StateChanger(3,8,new StateLarva());
  grid.StateChanger(2,4,new StatePupa());
  grid.StateChanger(3,6,new StatePupa());
  grid.StateChanger(3,2,new StateAdult());
  grid.StateChanger(2,5,new StateAdult());
  grid.StateChanger(3,4,new StateAdult());
  grid.StateChanger(3,10,new StateAdult());
  std::cout << grid;
  grid.NextGeneration();
  std::cout << grid;
  grid.NextGeneration();
  std::cout << grid;
  grid.NextGeneration();
  std::cout << grid;
  grid.NextGeneration();
  std::cout << grid;
  grid.NextGeneration();
  std::cout << grid;
  grid.NextGeneration();
  std::cout << grid;  
*/