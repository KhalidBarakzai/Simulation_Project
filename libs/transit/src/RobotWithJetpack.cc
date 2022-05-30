
// Copyright 2022 CSCITA
#define _USE_MATH_DEFINES
#include "RobotWithJetpack.h"
#include <cmath>
#include <limits>

RobotWithJetpack::RobotWithJetpack(JsonObject obj) : details(obj)
{
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};

    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};

    speed = obj["speed"];
}

RobotWithJetpack::~RobotWithJetpack()
{
    // Delete dynamically allocated variables
}

void RobotWithJetpack::Update(double dt, std::vector<IEntity*> scheduler)
{
  if(toTargetDesStrategy == NULL && !arrived && 
     GetDestination()[0] != 0 &&
     GetDestination()[1] != 0 &&
     GetDestination()[2] != 0) {
    toTargetDesStrategy = new Beeline(GetPosition(), GetDestination());
  }
  else if(toTargetDesStrategy != NULL) {
    // std::cout << position[0] << ", " << position[1] << ", " << position[2] << "\n";
    // std::cout << destination[0] << ", " << destination[1] << ", " << destination[2] << "\n";
    toTargetDesStrategy->Move(this, dt);
    if(toTargetDesStrategy->IsCompleted()) {
      delete toTargetDesStrategy;
      toTargetDesStrategy = NULL;
      arrived = true;
    }
  }
}
