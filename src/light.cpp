//
//  light.cpp
//  skyline
//
//  Created by Thiago Lütz Dias on 05/12/23.
//

#include "light.h"

Light::Light() {};

Light::Light(GLenum l, ofVec4f p, bool moving) {
    light = l;
    
    position[0] = p[0]; // x
    position[1] = p[1]; // y
    position[2] = p[2]; // z
    position[3] = p[3]; // direction
    
    is_moving = moving;

    glLightfv(l, GL_POSITION, position);
}

DirectionalLight::DirectionalLight(GLenum l, ofVec4f p, bool moving) : Light(l, p, moving) {
    ambient[0] = 0.0; // R
    ambient[1] = 0.0; // G
    ambient[2] = 0.0; // B
    ambient[3] = 1.0; // const
    
    diffuse[0] = 1.0; // R
    diffuse[1] = 1.0; // G
    diffuse[2] = 1.0; // B
    diffuse[3] = 1.0; // const
    
    specular[0] = 1.0; // R
    specular[1] = 1.0; // G
    specular[2] = 1.0; // B
    specular[3] = 1.0; // const
    
    glLightfv(l, GL_AMBIENT, ambient);
    glLightfv(l, GL_DIFFUSE, diffuse);
    glLightfv(l, GL_SPECULAR, specular);
}

PointLight::PointLight(GLenum l, ofVec4f p, bool moving) : Light(l, p, moving) {
    ambient[0] = 0.0; // R
    ambient[1] = 0.0; // G
    ambient[2] = 0.0; // B
    ambient[3] = 1.0; // const
    
    diffuse[0] = 1.0; // R
    diffuse[1] = 1.0; // G
    diffuse[2] = 1.0; // B
    diffuse[3] = 1.0; // const
    
    specular[0] = 1.0; // R
    specular[1] = 1.0; // G
    specular[2] = 1.0; // B
    specular[3] = 1.0; // const
    
    glLightfv(l, GL_AMBIENT, ambient);
    glLightfv(l, GL_DIFFUSE, diffuse);
    glLightfv(l, GL_SPECULAR, specular);
}
