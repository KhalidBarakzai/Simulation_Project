#include "JetpackFactory.h"

IEntity* JetpackFactory::CreateEntity(JsonObject& entity)
{
  std::string type = entity["type"];
  if (type.compare("jetpack") == 0) {
    Jetpack* JetpackTemp = new Jetpack(entity);
    std::cout << "Jetpack Created" << std::endl;
    return JetpackTemp;
  }
  return nullptr;
}
