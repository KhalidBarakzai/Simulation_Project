#ifndef ROBOT_WITH_JETPACK_FACTORY_H_
#define ROBOT_WITH_JETPACK_FACTORY_H_

#include "entity.h"
#include "IEntityFactory.h"
#include "RobotWithJetpack.h"

#include <vector>

class RobotWithJetpackFactory : public IEntityFactory
{
  public:
    virtual ~RobotWithJetpackFactory() {}
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
