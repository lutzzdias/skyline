#pragma once

#include <vector>

#include "ofMain.h"
#include "building.h"
#include "light.h"
#include "extras/general.h"
#include "extras/drawing.h"
#include "extras/camera.h"
#include "extras/materials.h"

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
    
        // Light
        Light directional;
        Light point;
        Light focus;
        Light any;
        GLfloat mview[4][4];
    
        // is On
        bool is_directional_on;
        bool is_point_on;
    
        
    
};
