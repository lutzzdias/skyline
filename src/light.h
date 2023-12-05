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
    
    bool is_on;
    bool is_moving;
    
    Light();
    Light(GLenum l, GLfloat p[4], GLfloat a[4], GLfloat d[4], GLfloat s[4], bool on, bool moving);
    void setup();
    void toggle();
};
