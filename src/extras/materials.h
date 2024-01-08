//
//  materials.cpp
//  skyline
//
//  Created by Thiago Lütz Dias on 05/01/24.
//

#pragma once

#include <stdio.h>

enum CustomMaterial {
    ASPHALT,
    BRICK,
    EMERALD,
    METAL,
    WOOD,
};

inline void get_material(CustomMaterial m) {
    switch (m) {
        case ASPHALT: {
            GLfloat ambient_asphalt[] = {
                0.05375, // R
                0.05, // G
                0.06625, // B
                1.0  // Const
            };
            
            GLfloat diffuse_asphalt[] = {
                0.18275, // R
                0.17, // G
                0.22525, // B
                1.0  // Const
            };
            
            GLfloat specular_asphalt[] = {
                0.332741, // R
                0.328634, // G
                0.346435, // B
                1.0  // Const
            };
            
            GLint shininess_asphalt = 0.1 * 128;
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_asphalt);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_asphalt);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_asphalt);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_asphalt);
            break;
        }
            
        case BRICK: {
            GLfloat ambient_brick[] = {
                0.4, // R
                0.2, // G
                0.1, // B
                1.   // Const
            };
            
            GLfloat diffuse_brick[] = {
                0.8, // R
                0.4, // G
                0.2, // B
                1.   // Const
            };
            
            GLfloat specular_brick[] = {
                0.3, // R
                0.3, // G
                0.3, // B
                1.   // Const
            };
            
            GLint shininess_brick = 0.2 * 128;
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_brick);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_brick);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_brick);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_brick);
            break;
        }
        
        case EMERALD: {
            GLfloat ambient_emerald[] = {
                0.02, // R
                0.17, // G
                0.02, // B
                1.   // Const
            };
            
            GLfloat diffuse_emerald[] = {
                0.08, // R
                0.61, // G
                0.08, // B
                1.   // Const
            };
            
            GLfloat specular_emerald[] = {
                0.63, // R
                0.73, // G
                0.63, // B
                1.   // Const
            };
            
            GLint shininess_emerald = 0.2 * 128;
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_emerald);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_emerald);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_emerald);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_emerald);
            break;
        }
            
        case METAL: {
            GLfloat ambient_metal[] = {
                0.19, // R
                0.19, // G
                0.19, // B
                1.   // Const
            };
            
            GLfloat diffuse_metal[] = {
                0.51, // R
                0.51, // G
                0.51, // B
                1.   // Const
            };
            
            GLfloat specular_metal[] = {
                0.9, // R
                0.9, // G
                0.9, // B
                1.   // Const
            };
            
            GLint shininess_metal = 1 * 128;
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_metal);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_metal);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_metal);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_metal);
            break;
        }
            
        case WOOD: {
            GLfloat ambient_wood[] = {
                0.6, // R
                0.3, // G
                0.1, // B
                1.   // Const
            };
            
            GLfloat diffuse_wood[] = { 
                0.8, // R
                0.4, // G
                0.2, // B
                1.   // Const
            };
            
            GLfloat specular_wood[] = {
                0.1, // R
                0.1, // G
                0.1, // B
                1.   // Const
            };
            
            GLint shininess_wood = 0.2 * 128;
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_wood);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_wood);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_wood);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_wood);
            break;
        }
            
        default:
            break;
    }
}
