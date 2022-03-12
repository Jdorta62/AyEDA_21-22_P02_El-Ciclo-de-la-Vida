#include "GridClass.h"

int main() {
  Grid my_grid{7,7};
  State* state_egg = new StateEgg();
  State* state_larva = new StateLarva();
  State* state_pupa = new StatePupa();
  State* state_adult = new StateAdult();
  my_grid.StateChanger(3,3,state_larva);
  my_grid.StateChanger(2,3,state_larva);
  my_grid.StateChanger(2,2,state_pupa);
  my_grid.StateChanger(3,1,state_egg);
  my_grid.StateChanger(3,2,state_adult);
  my_grid.StateChanger(4,1,state_adult); 
  my_grid.StateChanger(4,2,state_pupa); 

  


  std::cout << my_grid;
  State* temp = my_grid.GetCell(3,2).GetState();
  temp->Neighbors(my_grid,3,2);
  temp->NextState();
  return 0;
}