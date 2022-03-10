#include "StateClass.h"

class Larva : public State {
 public:
  std::string GetState() const override;
  
};