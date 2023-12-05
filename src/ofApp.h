#pragma once

#include <vector>

#include "ofMain.h"
#include "building.h"
#include "cg_extras.h"
#include "cg_drawing_extras.h"
#include "cg_cam_extras_solution.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        bool show_axis;
    
        // Building variables
        ofVec2f position;
        ofVec3f size;
    
        SimpleCuboidBuilding cuboid;
        MeshBuilding mesh;
        ElevatorBuilding elevator;
        TowerBuilding tower;
        CustomBuilding custom;
    
        // floor variables
        GLfloat width_step = gw() / 25;
        GLfloat height_step = gh() / 23;
		
		// View
		int view;
        GLfloat camera_radius;
        GLfloat camera_height;
        GLfloat camera_angle;
        GLfloat running_camera;
        bool is_going_backwards;

        // view mode
        bool is_perspective;
};
