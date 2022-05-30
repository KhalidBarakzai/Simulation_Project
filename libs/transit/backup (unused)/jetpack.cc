#include "jetpack.h"

Jetpack::Jetpack(JsonObject &obj) : details(obj)
{
    JsonArray pos(obj["position"]);
    position = {pos[0], pos[1], pos[2]};

    JsonArray dir(obj["direction"]);
    direction = {dir[0], dir[1], dir[2]};

    speed = obj["speed"];

    available = true;
}

JsonObject Jetpack::GetDetails() const
{
    return details;
}

// Jetpack::~Jetpack()
// {
//     // Delete dynamically allocated variables
// }

// void Jetpack::GetNearestEntity(std::vector<IEntity*> scheduler)
// {
//     // IEntity* nearestEntity_ = nullptr;
//     float minDis = std::numeric_limits<float>::max();
//     for (auto entity : scheduler) {
//         if (entity->GetAvailability()) {
//             float disToEntity = this->position.Distance(entity->GetPosition());
//             if (disToEntity <= minDis) {
//                 minDis = disToEntity;
//                 nearestEntity = entity;
//             }
//         }
//     }
//     // Set strategy for the nearest entity
//     if (nearestEntity)
//     {
//         // set availability to the entity that the Jetpack is picking up
//         nearestEntity->SetAvailability(false);
//         // set this Jetpack availability as false
//         available = false;
//         SetDestination(nearestEntity->GetPosition());
//         toTargetPosStrategy = new Beeline(this->GetPosition(), nearestEntity->GetPosition());
//         std::string targetStrategyName = nearestEntity->GetStrategyName();
//         if (targetStrategyName.compare("Jetpack") == 0)
//         {
//             toTargetDesStrategy = new Beeline(nearestEntity->GetPosition(), nearestEntity->GetDestination());
//         }
//       }
//       else
//       {
//
//       }
//     }
// }

// void Jetpack::Update(double dt, std::vector<IEntity*> scheduler)
// {
//   if (toTargetDesStrategy)
//     {
//         toTargetDesStrategy->Move(this, dt);
//         nearestEntity->SetPosition(this->GetPosition());
//         nearestEntity->SetDirection(this->GetDirection());
//         if (toTargetDesStrategy->IsCompleted())
//         {
//             delete toTargetDesStrategy;
//             toTargetDesStrategy = NULL;
//             available = true;
//             nearestEntity = NULL;
//         }
//     }
// }
