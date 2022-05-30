#include "simulation_model.h"
#include "DroneFactory.h"
#include "RobotFactory.h"
//#include "JetpackFactory.h"
#include "RobotWithJetpackFactory.h"
#include "Beeline.h"
#include "AstarStrategy.h"

SimulationModel::SimulationModel(IController& controller)
: controller(controller) {
  compFactory = new CompositeFactory();
  compFactory->AddFactory(new DroneFactory());
  compFactory->AddFactory(new RobotFactory());
  // compFactory->AddFactory(new JetpackFactory());
  compFactory->AddFactory(new RobotWithJetpackFactory());
}

/// Creates a simulation entity
void SimulationModel::CreateEntity(JsonObject& entity) {
    // int id = entity["entityId"];
    std::string type = entity["type"];
    std::string name = entity["name"];
    JsonArray position = entity["position"];
    std::cout << name << ": " << position << std::endl;

    IEntity* myNewEntity = compFactory->CreateEntity(entity);
    myNewEntity->SetGraph(graph);
    // Add to the drone dictionary
    Drone* drone = dynamic_cast<Drone*>(myNewEntity);
    if (drone) {
      drones.push_back(drone);
    }
    // Add to the robot dictionary
    Robot* robot = dynamic_cast<Robot*>(myNewEntity);
    if (robot) {
      robots.push_back(robot);
    }
    // Add to the jetpack dictionary
    // Jetpack* jetpack = dynamic_cast<Jetpack*>(myNewEntity);
    // if (jetpack) {
    //   jetpacks.push_back(jetpack);
    // }
    // Add to the robot with jetpack dictionary
    RobotWithJetpack* robotwithjetpack = dynamic_cast<RobotWithJetpack*>(myNewEntity);
    if (robotwithjetpack) {
      robotswithjetpacks.push_back(robotwithjetpack);
    }
    // Call AddEntity to add it to the view
    controller.AddEntity(*myNewEntity);
    entities.push_back(myNewEntity);
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
    std::string name = details["name"];
    JsonArray start = details["start"];
    JsonArray end = details["end"];
    std::cout << name << ": " << start << " --> " << end << std::endl;
    for (auto entity : entities) {  // Add the entity to the scheduler
      JsonObject detailsTemp = entity->GetDetails();
      std::string nameTemp = detailsTemp["name"];
      std::string typeTemp = detailsTemp["type"];
      std::string strategyName = details["search"];
      // std::cout << strategyName << "\n";
      if (name.compare(nameTemp) == 0 && 
          typeTemp.compare("robot") == 0 && 
          entity->GetAvailability()) {
        //std::string strategyName = details["search"];
        entity->SetStrategyName(strategyName);
        entity->SetDestination(Vector3(end[0], end[1], end[2]));
        scheduler.push_back(entity);
        break;
      }
    }
    controller.SendEventToView("TripScheduled", details);

    // Add a route to visualize the path
    // controller.AddPath(pathId, path);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
    // std::cout << "Update: " << dt << std::endl;
    // Call controller to update changed entities
    for (int i = 0; i < entities.size(); i++) {
      entities[i]->Update(dt, scheduler);
      controller.UpdateEntity(*entities[i]);
    }

    // Remove entites you no longer need
    // Since drone is always instantiated first, it is always at 0 in the entities array
    if(entities.size() > 0 && entities[0]->GetAvailability()) {
      for (int i = 1; i < entities.size(); i++) {
        // JsonObject detailsTemp = entities[i]->GetDetails();
        // std::string nameTemp = detailsTemp["name"];
        // std::cout << nameTemp << "\n";
        std::string strategyName = entities[i]->GetStrategyName();
        std::string typeTemp = entities[i]->GetDetails()["type"];
        // std::cout << strategyName << "\n";
        if((strategyName == "slow" ||
            strategyName == "normal" || 
            strategyName == "fast") && 
            !(entities[i]->GetAvailability()) &&
            typeTemp == "robot") {
          Vector3 position = entities[i]->GetPosition();
          Vector3 destination = entities[i]->GetDestination();
          controller.RemoveEntity(i+j);
          j++;
          entities.erase(entities.begin()+i);
          JsonObject tempNewRobot = entities[i]->GetDetails();
          // // tempNewRobot["name"] = detailsTemp["name"];
          // // tempNewRobot["position"] = detailsTemp["position"];
          // // tempNewRobot["scale"] = detailsTemp["scale"];
          // // tempNewRobot["direction"] = detailsTemp["direction"];
          // // tempNewRobot["radius"] = detailsTemp["radius"];
          // // tempNewRobot["rotation"] = tempNewRobot["rotation"];
          tempNewRobot["type"] = "robotwithjetpack";
          std::string typeTemp = entities[i]->GetDetails()["type"];
          // std::cout << typeTemp << "\n";
          tempNewRobot["mesh"] = "assets/model/robotwithjetpack.glb";
          if(strategyName == "slow") {
            tempNewRobot["speed"] = 15.0;
          }
          else if(strategyName == "normal") {
            tempNewRobot["speed"] = 30.0;
          }
          else if(strategyName == "fast") {
            tempNewRobot["speed"] = 60.0;
          }
          CreateEntity(tempNewRobot);
          // JsonObject detailsTemp = entities[i]->GetDetails();
          // std::string nameTemp = detailsTemp["type"];
          // std::cout << nameTemp << "\n";
          entities[i]->SetDestination(destination);
        }
        // std::cout << i << " " << entities[i]->GetDetails()["name"] << "\n";
      }
    }
    // controller.RemoveEntity(myDeletedEntityId);

    // Remove paths you no longer want to see:
    // controller.RemovePath(myDeletedPathId);
}

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}
