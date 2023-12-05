//
//  light.cpp
//  skyline
//
//  Created by Thiago Lütz Dias on 05/12/23.
//

#include "light.h"

Light::Light() {};

Light::Light(GLenum l, GLfloat p[4], GLfloat a[4], GLfloat d[4], GLfloat s[4], bool on, bool moving) {
    light = l;
    position[0] = p[0]; // x
    position[1] = p[1]; // y
    position[2] = p[2]; // z
    position[3] = p[3]; // direction
    
    ambient[0] = a[0]; // r
    ambient[1] = a[1]; // g
    ambient[2] = a[2]; // b
    ambient[3] = a[3]; // const
    
    diffuse[0] = d[0]; // r
    diffuse[1] = d[1]; // g
    diffuse[2] = d[2]; // b
    diffuse[3] = d[3]; // const
    
    specular[0] = s[0]; // r
    specular[1] = s[1]; // g
    specular[2] = s[2]; // b
    specular[3] = s[3]; // const
    
    is_on = on;
    is_moving = moving;

    glLightfv(l, GL_POSITION, position);
    glLightfv(l, GL_AMBIENT, ambient);
    glLightfv(l, GL_DIFFUSE, diffuse);
    glLightfv(l, GL_SPECULAR, specular);
}

void Light::toggle() {
    if (is_on) {
        glDisable(light);
    } else {
        glEnable(light);
    }
    
    is_on = !is_on;
}
