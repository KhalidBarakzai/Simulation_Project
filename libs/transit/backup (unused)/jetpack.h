#ifndef JETPACK_H_
#define JETPACK_H_

#include "util/json.h"
#include "entity.h"
#include "math/vector3.h"
#include "IStrategy.h"

#include <vector>

// Represents a jetpack in a physical system.
// jetpack move using euler integration based on a specified
// velocity and direction.
class Jetpack : public IEntity {
public:
    Jetpack(JsonObject& obj);

    ~Jetpack() override = default;

    Vector3 GetPosition() const { return position; }

    Vector3 GetDirection() const { return direction; }

    Vector3 GetDestination() const { return destination; }

    bool GetAvailability() const {return available;}

    JsonObject GetDetails() const override;

    float GetSpeed() const {return speed;}

    std::string GetStrategyName() const {return strategyName;}

    void SetPosition(Vector3 pos_) { position = pos_; }

    void SetDirection(Vector3 dir_) { direction = dir_; }

    void SetDestination(Vector3 des_) { destination = des_;}

    void SetStrategyName(std::string strategyName_) { strategyName = strategyName_;}

protected:
    JsonObject details;
    Vector3 position;
    Vector3 direction;
    Vector3 destination;
    float speed;
    bool available=false;
    IStrategy* strategy = nullptr;
    std::string strategyName;
};

#endif
