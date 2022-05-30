#ifndef ROBOTWITHJETPACK_H_
#define ROBOTWITHJETPACK_H_

#include "entity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "Beeline.h"

#include <vector>

// Represents a RobotWithJetpack in a physical system.
// RobotWithJetpack only moves using Beeline strategy
class RobotWithJetpack : public IEntity
{
public:
    // RobotsWithJetpacks are created with a name
    RobotWithJetpack(JsonObject obj);
    // Destructor
    ~RobotWithJetpack();

    float GetSpeed() const {return speed;}

    // Gets the RobotWithJetpack position
    Vector3 GetPosition() const { return position; }

    Vector3 GetDirection() const { return direction; }

    Vector3 GetDestination() const { return destination; }

    JsonObject GetDetails() const { return details; }

    bool GetAvailability() const {return available;}

    std::string GetStrategyName() const {return strategyName;}

    // Updates the RobotWithJetpack's position
    void Update(double dt, std::vector<IEntity*> scheduler);

    void SetPosition(Vector3 pos_) { position = pos_; }

    // Sets the RobotWithJetpack's direction
    void SetDirection(Vector3 dir_) { direction = dir_; }

    void SetDestination(Vector3 des_) { destination = des_;}

    void SetStrategyName(std::string strategyName_) { strategyName = strategyName_;}

private:
    JsonObject details;
    Vector3 position;
    Vector3 direction;
    Vector3 destination;
    float speed;
    bool available=false;
    std::string strategyName;
    bool arrived = false;

    IStrategy* toTargetDesStrategy = NULL;
};

#endif
