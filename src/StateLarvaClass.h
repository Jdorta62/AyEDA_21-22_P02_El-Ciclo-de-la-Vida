#include "StateClass.h"

class Larva : public State {
 public:
  Larva();
  std::string GetState() const override;
  
};