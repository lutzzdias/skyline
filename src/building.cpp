//
//  building.cpp
//  skyline
//
//  Created by Thiago Lütz Dias on 07/11/23.
//

#include "building.h"

Building::Building(ofVec2f p, ofVec3f s) {
    position = p;
    size = s;
}

Building::Building() {}

CustomBuilding::CustomBuilding(ofVec2f p, ofVec3f s) : Building(p, s) {}

SimpleCuboidBuilding::SimpleCuboidBuilding(ofVec2f p, ofVec3f s) : Building(p, s) {}

MeshBuilding::MeshBuilding(ofVec2f p, ofVec3f s) : Building(p, s) {}

ElevatorBuilding::ElevatorBuilding(ofVec2f p, ofVec3f s) : Building(p, s) {}

TowerBuilding::TowerBuilding(ofVec2f p, ofVec3f s) : Building(p, s) {}

void CustomBuilding::draw() {
    glTranslatef(position.x, position.y, size.z * 0.5);
    glScalef(size.x, size.y, size.z);
    get_material(WOOD);
    draw_custom_building();
}

void SimpleCuboidBuilding::draw() {
    glTranslatef(position.x, position.y, size.z * 0.5);
    glScalef(size.x, size.y, size.z);
    get_material(WOOD);
    draw_cube();
}

void MeshBuilding::draw() {
    glTranslatef(position.x, position.y, size.z * 0.5);
    glScalef(size.x, size.y, size.z);
    get_material(CONCRETE);
    draw_cube_mesh(10, 10);
}

void ElevatorBuilding::draw() {
    // Right section
    glPushMatrix();
    glTranslatef(position.x + (size.x * 0.25) + (size.x * 0.1), position.y, size.z * 0.5);
    glScalef(size.x * 0.5, size.y, size.z);
    get_material(CONCRETE);
    draw_cube_mesh(10, 10);
    glPopMatrix();
    
    // Left section
    glPushMatrix();
    glTranslatef(position.x - (size.x * 0.25) - (size.x * 0.1), position.y, size.z * 0.5);
    glScalef(size.x * 0.5, size.y, size.z);
    get_material(CONCRETE);
    draw_cube_mesh(10, 10);
    glPopMatrix();
    
    // Middle section
    glPushMatrix();
    glTranslatef(position.x, position.y, size.z * 0.5);
    
    // Elevator - bottom
    glPushMatrix();
    glTranslatef(0, (-middle_size.y * 0.5) - (elevator_size.y * 0.5), elevator_position);
    glScalef(elevator_size.x, -elevator_size.y, elevator_size.z);
    get_material(METAL);
    draw_cube_mesh(10, 10);
    glPopMatrix();
    
    // Elevator - top
    glPushMatrix();
    glTranslatef(0, (middle_size.y * 0.5) + (elevator_size.y * 0.5), elevator_position);
    glScalef(elevator_size.x, elevator_size.y, elevator_size.z);
    get_material(METAL);
    draw_cube_mesh(10, 10);
    glPopMatrix();
    
    glScalef(middle_size.x, middle_size.y, middle_size.z);
    get_material(CONCRETE);
    draw_cube_mesh(10, 10);
    glPopMatrix();
}

void TowerBuilding::draw() {
    // Tower core
    glPushMatrix();
    glTranslatef(position.x, position.y, size.z * 0.5);
    glScalef(size.x, size.y, size.z);
    get_material(BRICK);
    draw_cube_mesh(10, 10);
    glPopMatrix();
    
    // Lookout
    glPushMatrix();
    glTranslatef(position.x, position.y, size.z * 0.8);
    glScalef(lookout_radius, lookout_radius, lookout_height);
    glRotatef(lookout_rotation_angle, 0, 0, 1);
    get_material(CONCRETE);
    draw_cilinder(25);
    glPopMatrix();
}

void TowerBuilding::update(){
    lookout_rotation_angle -= 0.2;
}

void ElevatorBuilding::update(){
    if (is_going_up) {
        elevator_position += elevator_speed;
        if (elevator_position >= (size.z * 0.5) - (elevator_size.z * 0.5)) {
            is_going_up = false;
        }
    } else {
        elevator_position -= elevator_speed;
        if (elevator_position <= -(size.z * 0.5) + (elevator_size.z * 0.5)) {
            is_going_up = true;
        }
    }
}
