#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	glEnable(GL_DEPTH_TEST);
    
    is_perspective = true;
    show_axis = true;
    
    camera_radius = gh() * 1.25;
    camera_height = gh() * 0.75;
    camera_angle = 0;
    
    running_camera = -gw() * 0.5;
    is_going_backwards = false;
    
    ofVec2f cuboid_position = ofVec2f(-width_step, height_step);
    ofVec3f cuboid_size = ofVec3f(width_step, height_step, 2 * width_step);
    cuboid = SimpleCuboidBuilding(cuboid_position, cuboid_size);
    
    ofVec2f mesh_position = ofVec2f(2 * width_step, -height_step);
    ofVec3f mesh_size = ofVec3f(width_step, height_step, 4 * width_step);
    mesh = MeshBuilding(mesh_position, mesh_size);

    
    ofVec2f elevator_position = ofVec2f(0, -height_step);
    ofVec3f elevator_size = ofVec3f(width_step, height_step, 6 * width_step);
    elevator = ElevatorBuilding(elevator_position, elevator_size);
    
    ofVec2f tower_position = ofVec2f(width_step, height_step);
    ofVec3f tower_size = ofVec3f(width_step, height_step, 8 * width_step);
    tower = TowerBuilding(tower_position, tower_size);
    
    ofVec2f custom_position = ofVec2f(-2 * width_step, -height_step);
    ofVec3f custom_size = ofVec3f(width_step, height_step, 5 * width_step);
    custom = CustomBuilding(custom_position, custom_size);
}



//--------------------------------------------------------------
void ofApp::update(){
    camera_angle -= 0.005;
    elevator.update();
    tower.update();
    
    if (running_camera == gw() * 0.5){
        is_going_backwards = true;
    } else if(running_camera == -gw() * 0.5){
        is_going_backwards = false;
    }
    
    if(!is_going_backwards) {
        running_camera += 0.5;
    } else {
        running_camera -= 0.5;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Viewport
	glViewport(0, 0, gw(), gh());
    
    // Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (is_perspective){
        perspective(60, 100, 100);
    } else {
        glOrtho(-gw() * 0.5, gw() * 0.5, -gh() * 0.5, gh() * 0.5, -100000, 100000);
    }
    
    // Model
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	// Camera
	switch (view) {
	case 0:
        lookat(0, -gh() * 1.25, gh() * 0.75, 0, 0, 0, 0, 0, 1);
		break;
	case 1:
        lookat(0, 0, gh() * 1.25, 0, 0, 0, 0, 1, 0);
		break;
	case 2:
		lookat(gw()*0.5, -gh() * 1.25, gh() * 0.75, 0, 0, 0, 0, 0, 1);
        break;
    case 3:
        lookat(0, -gh() * 1.25, 0, 0, 0, 0, 0, 0, 1);
        break;
    case 4:
        lookat(camera_radius * cos(camera_angle), -camera_radius * sin(camera_angle), camera_height, 0, 0, 0, 0, 0, 1);
        break;
    case 5:
        lookat(running_camera, 0, 1, 0, 0, width_step * 4, 0, 0, 1);
        break;
	}
    
    // Axis
    if (show_axis == true) {
        glPushMatrix();
            glScalef(gw(), gw(), gw());
            draw_axis();
        glPopMatrix();
    }

    // Floor
	glColor3f(0, 0, 0);
	glPushMatrix();
        glTranslatef(0, 0, 0);
        glScalef(gw(), gh(), 0);
        draw_mesh(25, 23);
	glPopMatrix();
    
    // Cube building
    glPushMatrix();
        cuboid.draw();
    glPopMatrix();
    
    // Simple building
    glPushMatrix();
        mesh.draw();
    glPopMatrix();
    
    // Elevator building
    glPushMatrix();
        elevator.draw();
    glPopMatrix();
    
    // Tower building
    glPushMatrix();
        tower.draw();
    glPopMatrix();
    
    // Custom building
    glPushMatrix();
        custom.draw();
    glPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
    case '0':
        is_perspective = !is_perspective;
        break;
	case '1':
		glDisable(GL_CULL_FACE);
		break;
	case '2':
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		break;
	case '3':
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		break;
	case '4':
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT_AND_BACK);
		break;
	case 'g':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 'f':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	case 'a':
        show_axis = !show_axis;
		break;
	case 'v':
		view++;
		if (view > 5) {
			view = 0;
		}
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	setup();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
