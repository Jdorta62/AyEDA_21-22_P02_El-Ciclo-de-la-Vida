#include <iostream>
#include "GridClass.h"

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

  Grid grid{rows,columns};
  int number_of_cells{-1};
  std::cout << "Indique cuántas células vivas quiere: ";
  while(number_of_cells < 0) {
    std::cin >> number_of_cells;
    if (number_of_cells < 0) {
      std::cout << "Intente de nuevo. Recuerde que el numero de células vivas no pueden ser negativas.";
    }
  }
  for (size_t i{0}; i < number_of_cells; ++i) {
    int number_row{0};
    int number_column{0};
    while ((number_column <= 0 || number_column > columns)||(number_row <= 0 || number_row > rows)) {
      std::cout << "Inserte el número de fila y columna de la célula [" << i << "]: ";
      std::cin >> number_row;
      std::cin >> number_column;
      if ((number_column <= 0 || number_column > columns)||(number_row <= 0 || number_row > rows)) {
        std::cout << "Intente de nuevo. Recuerde que el número de fila tiene que ser mayor que 0 y menor o igual que " << rows << " y que el número de columan tiene que ser mayor que 0 y menor o igual que " << columns << "." << std::endl;
      }
    }
    State alive{ALIVE};
    grid.StateChanger(number_row, number_column, alive);
  }

  int turns{-1};
  while (turns < 0) {
    std::cout << "Finalmente, indique la cantidad de turnos que tendrá el juego: ";
    std::cin >> turns;
    if (turns < 0) {
      std::cout << "Intente de nuevo. Recuerde que los turnos no pueden ser negativos." << std::endl;
    }
  }
  std::cout << "Iniciando juego..." << std::endl;
  for(int i{0}; i <= turns; ++i) {
    std::cout << "Turno " << i << "." << std::endl;
    if (i == 0) {
      std::cout << grid << std::endl;
    } else {
      grid.NextGeneration();
      std::cout << grid << std::endl;
    }
  }
/*
  State vivo{ALIVE};
  State muerto{DEAD};
  grid.StateChanger(1,1,vivo);
  grid.StateChanger(2,2,vivo);
  grid.StateChanger(3,3,vivo);
  grid.StateChanger(4,4,vivo);
  grid.StateChanger(10,9,vivo);
  grid.StateChanger(9,10,vivo);
  grid.StateChanger(9,9,vivo);
  std::cout << grid << std::endl;
  Cell tmp = grid.GetCell(10,10);
  grid.NextGeneration(/*grid);
  std::cout << grid;*/
  return 0;
}


/*
  int filas, columnas;
  std::cin >> filas;
  std::cin >> columnas;
  int matriz[filas][columnas];

  for(int i{0}; i < filas; ++i) {
    for(int j{0}; j < columnas; ++j) {
      std::cin >> matriz[i][j];
    }
  }

  for(int i{0}; i < filas; ++i) {
    for(int j{0}; j < columnas; ++j) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
*/