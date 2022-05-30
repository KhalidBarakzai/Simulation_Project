#include "RobotWithJetpackFactory.h"

IEntity* RobotWithJetpackFactory::CreateEntity(JsonObject& entity)
{
  std::string type = entity["type"];
  if (type.compare("robotwithjetpack") == 0) {
    RobotWithJetpack* RobotWithJetpackTemp = new RobotWithJetpack(entity);
    std::cout << "Robot with jetpack Created" << std::endl;
    return RobotWithJetpackTemp;
  }
  return nullptr;
}