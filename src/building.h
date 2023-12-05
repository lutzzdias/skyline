//
//  building.h
//  skyline
//
//  Created by Thiago Lütz Dias on 07/11/23.
//

#pragma once
#include "ofMain.h"
#include "extras/general.h"
#include "extras/drawing.h"

class Building {
public:
    ofVec2f position;
    ofVec3f size;
    GLfloat floor_height = (gh() / 23) * 0.6; // height_step * 0.6
    
    Building();
    Building(ofVec2f position, ofVec3f size);
    virtual void draw() {}
    virtual void update() {}
};

class CustomBuilding : public Building {
public:
    CustomBuilding() {}
    CustomBuilding(ofVec2f p, ofVec3f s);
    void draw() override;
};

class SimpleCuboidBuilding : public Building {
public:
    SimpleCuboidBuilding() {}
    SimpleCuboidBuilding(ofVec2f p, ofVec3f s);
    void draw() override;
};

class MeshBuilding : public Building {
public:
    MeshBuilding() {}
    MeshBuilding(ofVec2f p, ofVec3f s);
    void draw() override;
};

class ElevatorBuilding : public Building {
public:
    ElevatorBuilding() {}
    ElevatorBuilding(ofVec2f p, ofVec3f s);
    void draw() override;
    void update() override;
    
private:
    ofVec3f middle_size = ofVec3f(size.x * 0.2, size.y * 0.6, size.z);
    ofVec3f elevator_size = ofVec3f(size.x * 0.2, size.y * 0.2, floor_height);
    
    GLfloat elevator_position = -(size.z * 0.5) + (elevator_size.z * 0.5);
    GLfloat elevator_speed = 0.2;
    bool is_going_up = true;
};
    
class TowerBuilding : public Building {
public:
    TowerBuilding() {}
    TowerBuilding(ofVec2f p, ofVec3f s);
    void draw() override;
    void update() override;

private:
    GLfloat lookout_radius = size.z * 0.25;
    GLfloat lookout_height = floor_height;
    
    GLfloat lookout_rotation_angle = 0;
};
