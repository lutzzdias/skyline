#pragma once

#include "ofMain.h"
#include "extras/general.h"

//desenha axis 3D
inline void draw_axis() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();
}

inline void draw_mesh(GLint m, GLint n) {
    GLfloat x_start = -0.5;
    GLfloat y_start = -0.5;
    GLfloat x_step = 1.0 / GLfloat(m);
    GLfloat y_step = 1.0 / GLfloat(n);

    glNormal3f(0, 0, 1);
    glBegin(GL_QUADS);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            glVertex3f(i * x_step + x_start, j * y_step + y_start, 0);
            glVertex3f((i+1) * x_step + x_start, j * y_step + y_start, 0);
            glVertex3f((i + 1) * x_step + x_start, (j + 1) * y_step + y_start, 0);
            glVertex3f(i * x_step + x_start, (j + 1) * y_step + y_start, 0);
        }
    }
    glEnd();
}


inline void draw_cube() {
	GLfloat p = 0.5;
	glBegin(GL_QUADS);

	// front
	glVertex3f(-p, -p, p);
    glVertex3f(p, -p, p);
    glVertex3f(p, p, p);
	glVertex3f(-p, p, p);

	// back
	glVertex3f(-p, -p, -p);
	glVertex3f(-p, p, -p);
	glVertex3f(p, p, -p);
	glVertex3f(p, -p, -p);

	// top
	glVertex3f(-p, p, p);
	glVertex3f(p, p, p);
	glVertex3f(p, p, -p);
	glVertex3f(-p, p, -p);

	// bottom
	glVertex3f(-p, -p, p);
	glVertex3f(-p, -p, -p);
	glVertex3f(p, -p, -p);
	glVertex3f(p, -p, p);

	// left
	glVertex3f(-p, -p, p);
	glVertex3f(-p, p, p);
	glVertex3f(-p, p, -p);
	glVertex3f(-p, -p, -p);

	// right
	glVertex3f(p, -p, p);
	glVertex3f(p, -p, -p);
	glVertex3f(p, p, -p);
	glVertex3f(p, p, p);

	glEnd();
}

// Draws a cube with mesh as its faces
inline void draw_cube_mesh(GLint m, GLint n) {
    // front
    glPushMatrix();
    glTranslated(0., 0., 0.5);
    draw_mesh(m, n);
    glPopMatrix();

    // back
    glPushMatrix();
    glTranslated(0., 0., -0.5);
    glRotated(180, 0, 1, 0);
    draw_mesh(m, n);
    glPopMatrix();

    // top
    glPushMatrix();
    glTranslated(0., 0.5, 0.);
    glRotated(-90, 1, 0, 0);
    draw_mesh(m, n);
    glPopMatrix();

    // bottom
    glPushMatrix();
    glTranslated(0., -0.5, 0.);
    glRotated(90, 1, 0, 0);
    draw_mesh(m, n);
    glPopMatrix();

    // left
    glPushMatrix();
    glTranslated(-0.5, 0., 0.);
    glRotated(-90, 0, 1, 0);
    draw_mesh(m, n);
    glPopMatrix();

    // right
    glPushMatrix();
    glTranslated(0.5, 0., 0.);
    glRotated(90, 0, 1, 0);
    draw_mesh(m, n);
    glPopMatrix();
}

// Draws a cilinder, top and bottom are made up of triangles and walls are rectangles
inline void draw_cilinder(GLint n) {
    // Bottom
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);
    for(int i = n; i >= 0; i--) {
        GLfloat angle = (2.0f * M_PI) * (GLfloat(i) / GLfloat(n));
        GLfloat x = cos(angle);
        GLfloat y = sin(angle);
        
        glVertex3f(x, y, 0);
    }
    glEnd();
    
    // Top
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 1);
    for(int i = 0; i <= n; i++) {
        GLfloat angle = (2.0f * M_PI) * (GLfloat(i) / GLfloat(n));
        GLfloat x = cos(angle);
        GLfloat y = sin(angle);
        
        glVertex3f(x, y, 1);
    }
    glEnd();
    
    // Walls
    glBegin(GL_QUAD_STRIP);
    for(int i = n; i >= 0; i--) {
        GLfloat angle = (2.0f * M_PI) * (GLfloat(i) / GLfloat(n));
        GLfloat x = cos(angle);
        GLfloat y = sin(angle);

        glVertex3f(x, y, 0); // Bottom circle
        glVertex3f(x, y, 1); // Top circle
    }
    glEnd();
}

inline void draw_custom_building() {
    // top
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0.5);
    glVertex3f(0, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0, 0.5);
    glEnd();
    
    // bottom
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, -0.5);
    glVertex3f(-0.5, 0, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0, -0.5, -0.5);
    glEnd();
    
    // front-most
    glBegin(GL_QUADS);
    glVertex3f(0, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0, -0.5, 0.5);
    glEnd();
    
    // right
    glBegin(GL_QUADS);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();
    
    // back
    glBegin(GL_QUADS);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glEnd();
    
    // left-back
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0, -0.5);
    glVertex3f(-0.5, 0, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    
    // front-second
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 0, -0.5);
    glVertex3f(0, 0, -0.5);
    glVertex3f(0, 0, 0.5);
    glVertex3f(-0.5, 0, 0.5);
    glEnd();
    
    // left-front
    glBegin(GL_QUADS);
    glVertex3f(0, 0, -0.5);
    glVertex3f(0, -0.5, -0.5);
    glVertex3f(0, -0.5, 0.5);
    glVertex3f(0, 0, 0.5);
    glEnd();
}
