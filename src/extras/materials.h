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
    CONCRETE,
    METAL,
    WOOD,
};

inline void get_material(CustomMaterial m) {
    switch (m) {
        case ASPHALT: {
            GLfloat ambient_asphalt[] = {
                0.05, // R
                0.05, // G
                0.05, // B
                1.    // Const
            };
            
            GLfloat diffuse_asphalt[] = {
                0.1, // R
                0.1, // G
                0.1, // B
                1.   // Const
            };
            
            GLfloat specular_asphalt[] = {
                0.1, // R
                0.1, // G
                0.1, // B
                1.   // Const
            };
            
            GLint shininess_asphalt = 0.2 * 128;
            
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
        
        case CONCRETE: {
            GLfloat ambient_concrete[] = {
                0.2, // R
                0.2, // G
                0.2, // B
                1.   // Const
            };
            
            GLfloat diffuse_concrete[] = {
                0.6, // R
                0.6, // G
                0.6, // B
                1.   // Const
            };
            
            GLfloat specular_concrete[] = {
                0.2, // R
                0.2, // G
                0.2, // B
                1.   // Const
            };
            
            GLint shininess_concrete = 0.1 * 128;
            
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_concrete);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_concrete);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular_concrete);
            glMaterialf(GL_FRONT, GL_SHININESS, shininess_concrete);
        }
            
        case METAL: {
            GLfloat ambient_metal[] = {
                0.3, // R
                0.3, // G
                0.3, // B
                1.   // Const
            };
            
            GLfloat diffuse_metal[] = {
                0.7, // R
                0.7, // G
                0.7, // B
                1.   // Const
            };
            
            GLfloat specular_metal[] = {
                0.8, // R
                0.8, // G
                0.8, // B
                1.   // Const
            };
            
            GLint shininess_metal = 0.4 * 128;
            
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
