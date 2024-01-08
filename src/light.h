//
//  light.hpp
//  skyline
//
//  Created by Thiago Lütz Dias on 05/12/23.
//

#pragma once
#include "ofMain.h"

class Light {
public:
    GLenum light;
    GLfloat position[4];
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    
    bool is_moving;
    
    Light();
    Light(GLenum l, ofVec4f p, bool moving);
};

class DirectionalLight: public Light {
public:
    DirectionalLight();
    DirectionalLight(GLenum l, ofVec4f p, bool moving);
};

class PointLight: public Light {
public:
    PointLight();
    PointLight(GLenum l, ofVec4f p, bool moving);
};

class FocusLight: public Light {
public:
    FocusLight();
    FocusLight(GLenum l, ofVec4f p, ofVec4f d, bool moving);
    
    GLfloat direction[4];
};
