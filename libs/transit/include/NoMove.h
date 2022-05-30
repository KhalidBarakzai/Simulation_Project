#ifndef NOMOVE_H_
#define NOMOVE_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "entity.h"

class NoMove : public IStrategy {
public:
    // NoMove(Vector3 pos_, Vector3 des_);
    ~NoMove();
    void Move(IEntity* entity, double dt) {}
    bool IsCompleted() { return true; }

protected:
    Vector3 des;
    Vector3 pos;
    Vector3 lastPos;
};
#endif