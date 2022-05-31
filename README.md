## Team members
Khalid Barakzai

Daniel Kong

Alexander Zhu

## CSCI 3081 Simulation Project

This directory contains the support code needed to visualize the CSCI 3081 project and run tests. The beta support code explains how to quickly get a drone moving. Most of the logic should be moved into the simulation facade so that the simulation is not dependent on the view. See web_app.cc for more details.
What is in this directory?

    README.md
    .gitignore
    src folder, which contains:
        main.cc
        web_app.h and web_app.cc 
    test folder, which contains:
        example_test.cc to get you started 
    web folder, which contains:
        The javascript visualization code 

**Getting Started**

Here is a quick overview of how to run the visualization (These steps are similar in each build environment. See below for environment details.):

```bash
# Go to the project directory
cd /path/to/repo/project

# Build the project
make -j

# Run the tests
./build/test-app

# Run the project (./build/web-app <port> <web folder>)
/build/bin/transit_service 8081 apps/transit_service/web/
```

Navigate to http://127.0.0.1:8081 and you should see a visualization. You can move a drone around by using the arrow keys and wsda.
Navigate to http://127.0.0.1:8081/schedule.html and you should see a a page to schedule the trips.

Below are instructions that detail how to build and run in several different environments.
Getting Started with Docker
**Pre-requisites**

    Git

**Docker Pre-requisites**

    Windows 10 Home
        Install wsl2 and Ubuntu
    Install Docker Desktop from Docker Hub
    Linux
        Use docker group instead of sudo

**Building and running the project**

    Build docker image

    bin/build-env.sh

    Run docker image

    #Usage bin/run-env.sh <port - optional(default 8081)>
    bin/run-env.sh

    Build project web server (inside docker image) NOTE: You won't be able to cd here yet because the project directory does not exist. If you were able to launch the above commands you should now be inside the docker image. You can exit it with CTRL+D now.

    # Inside docker image
    cd /home/user/repo/project
    make -j

    Run web server (inside docker image)

    # MUST be within project/ directory inside docker image
    cd /home/user/repo/project
    ./build/web-app 8081 web

    Open up Firefox and browse to http://127.0.0.1:8081/

**Getting Started using SSH on CSE Lab machines**

    SSH into a CSE Lab Machine using port forwarding for the UI

    Note: If port 8081 is not available, choose a different port (e.g. 8082, 8083, etc...)

    ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu

    Example:

    # ssh -L 8081:127.0.0.1:8081 x500@csel-kh1250-05.cselabs.umn.edu

    Compile the project (within ssh session)

    cd /path/to/cloned/repository
    cd project
    make -j

    Run project (within ssh session)

    # MUST be within project/ directory
    ./build/web-app 8081 web

    Open up Firefox and browse to http://127.0.0.1:8081/

**Getting Started with CSE Lab Machines, VOLE-3D, or VOLE**

    Log on to CSE Lab Macines, VOLE-3D, or VOLE (VOLE is slower for graphics, but is great for tests, etc...)

    Build project

    cd /path/to/cloned/repository
    cd project
    make -j

    Run project

    # MUST be within project/ directory
    ./build/web-app 8081 web

    Open up Firefox and browse to http://127.0.0.1:8081/



## Additional info
 - writeup is in CSCI3081W_Program_Design.pdf
 - presentation is at https://youtu.be/ZL7KARXVotk

## Modified files:

**NoMove strategy, found at:** 
 - project/libs/transit/include/NoMove.h 
 - project/libs/transit/src/NoMove.cpp

**schedule.html (dropdown changes) found at:** 
 - project/apps/transit_service/web/schedule.html

**Drone entity, found at:**
 - project/libs/transit/src/drone.cc

**Robot with jetpack entity, found at:**
 - project/libs/transit/include/RobotWithJetpack.h 
 - project/libs/transit/src/RobotWithJetpack.cc

**Robot with jetpack factory, found at:**
 - project/libs/transit/include/RobotWithJetpackFactory.h 
 - project/libs/transit/src/RobotWithJetpackFactory.cc

**Simulation model, found at:**
 - project/libs/transit/include/simulation_model.h 
 - project/libs/transit/src/simulation_model.cc

## Sprint Retrospective:
 - see SprintRetro.pdf
