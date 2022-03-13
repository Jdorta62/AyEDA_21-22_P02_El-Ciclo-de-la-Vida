/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  *
  * @file Functions.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 04 March 2022.
  * @brief fichero que contiene la implementación de las distintas funciones usadas en el programa Ciclo de la vida.
  * @bug ningún bug conocido.
  * 
  */

#include "Functions.h"

/**
 * @brief función que modifica la rejilla en base a las preferencias del usuario
 * @param grid rejilla que se modificará
 * @param rows número de filas de la rejilla
 * @param columns número de columnas de la rejilla
 */
void GridUserModificator(Grid &grid, int const &rows, int const &columns) {
  bool flag{true};
  while (flag) {
    char option;
    std::cout << "Digite el tipo de célula que desea ingresar en la rejilla (D/E/L/P/A): ";
    std::cin >> option;
    bool valid_option{false};
    while (!valid_option) {
      switch (option) {
      case 'D':
        valid_option = true;
        { 
          State* new_state = new StateDead();
          PositionUserSelector(grid, rows, columns, new_state,"muerta");
        }
        break;
      case 'E':
        valid_option = true;
        { 
          State* new_state = new StateEgg();
          PositionUserSelector(grid, rows, columns, new_state,"huevo");
        }
        break;
      case 'L':
        valid_option = true;
        { 
          State* new_state = new StateLarva();
          PositionUserSelector(grid, rows, columns, new_state,"larva");
        }
        break;
      case 'P':
        valid_option = true;
        { 
          State* new_state = new StatePupa();
          PositionUserSelector(grid, rows, columns, new_state,"pupa");
        }
        break;
      case 'A':
        valid_option = true;
        { 
          State* new_state = new StateAdult();
          PositionUserSelector(grid, rows, columns, new_state,"adulta");
        }
        break;   

      default:
        MessageErrorPrinter("Error: opción no válida. Por favor digite el tipo de célula que desea ingresar en la rejilla (D/E/L/P/A): ");
        std::cin >> option;
        break;
      }
    }
    char user_choice;
    std::cout << "Ingrese s si desea seguir ingresando células: ";
    std::cin >> user_choice;
    if (user_choice != 's') {
      flag = false;
    } 
  }
  
}

/**
 * @brief función que se encargará pedir al usuario la posición en la que desea colocar las distintas celulas
 * @param grid rejilla que será modificada
 * @param rows filas que tiene la rejilla
 * @param columns columnas que tiene la rejilla
 * @param new_state estado al que pasaran las células escogidas por el usuario
 * @param state_type tipo de estado escogido por el usuario
 */
void PositionUserSelector(Grid &grid, int const &rows, int const &columns, State* const &new_state, std::string const &state_type) {
  int number_of_cells{0};
  std::cout << "Indique el número de células en estado " << state_type << " que desea [0," << rows*columns << "]: ";
  std::cin >> number_of_cells;
  while (number_of_cells < 0 || number_of_cells > rows*columns) {
    MessageErrorPrinter("Error: número de células no válido, intente de nuevo.");
    std::cout << "Indique el número de células en estado " << state_type << " que desea [0," << rows*columns << "]: ";
    std::cin >> number_of_cells;
  }
  int user_row_cell, user_column_cell;
  for (size_t i{0}; i < number_of_cells; ++i) {
    std::cout << "Ingrese la fila que ocupará la célula " << i << "[1," << rows << "]: ";
    std::cin >> user_row_cell;
    while(user_row_cell <= 0 || user_row_cell > rows) {
      MessageErrorPrinter("Error: fila no válida, intente de nuevo");
      std::cout << "Ingrese la fila que ocupará la célula " << i << "[1," << rows << "]: ";
      std::cin >> user_row_cell;
    }
    std::cout << "Ingrese la columna que ocupará la célula " << i << "[1," << columns << "]: ";
    std::cin >> user_column_cell;
    while(user_column_cell <= 0 || user_column_cell > columns) {
      MessageErrorPrinter("Error: fila no válida, intente de nuevo");
      std::cout << "Ingrese la fila que ocupará la célula " << i << "[1," << columns << "]: ";
      std::cin >> user_column_cell;
    }
    grid.StateChanger(user_row_cell, user_column_cell, new_state);
  }
}

/**
 * @brief función que muestra un mensaje de error pasado por parametros
 * @param error_message mensaje de error que se quiere mostrar
 */
void MessageErrorPrinter(std::string error_message) {
  std::cout << error_message;
}

/**
 * @brief función que imprime por pantalla los distintos turno del juego del ciclo de la vida
 * @param number_of_turns número de turnos que tiene el juego
 */
void TurnPrinter(Grid &grid, int const &number_of_turns) {
  std::cout << "Turn 0:" << std::endl << grid;
  for(size_t i{1}; i <= number_of_turns; ++i) {
    std::cout << std::endl << "Turn " << i << ":";
    grid.NextGeneration();
    std::cout << std::endl << grid;
  }
}