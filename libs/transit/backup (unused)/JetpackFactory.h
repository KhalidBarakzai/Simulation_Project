#ifndef JETPACK_FACTORY_H_
#define JETPACK_FACTORY_H_

#include "entity.h"
#include "IEntityFactory.h"
#include "jetpack.h"

#include <vector>

class JetpackFactory : public IEntityFactory
{
  public:
    virtual ~JetpackFactory() {}
    IEntity* CreateEntity(JsonObject& entity);
};

#endif
