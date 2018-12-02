




/**
* Javier Gonzalez-Sanchez
* Fall 2018
*
* http://javiergs.com/teaching/ser431
*/

#pragma once
#include <vector>
#include <Imath/imathvec.h>
#include <GL/glut.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using namespace Imath;

// global 
int width = 1200;
int height = 600;
float ratio = 1.0;
GLuint display1, display2, display3, display4;

// meshes
Mesh* mesh1;
Mesh* mesh2;
Mesh* mesh3;
Mesh* mesh4;

// controling parameters
int mouse_button;
int mouse_x = 0;
int mouse_y = 0;
float scale = 0.3;
float x_angle = 0.0;
float y_angle = 0.0;

// textures
GLuint textureArray[8];

// mesh to display list
GLuint meshToDisplayList(Mesh* m, int id, int textureId) {
	GLuint listID = glGenLists(id);
	glNewList(listID, GL_COMPILE);
	//

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, textureArray[textureId]);

	//
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < m->face_index_vertex.size(); i++) {
		// PER VERTEX NORMALS
		if ((!m->dot_normalPerVertex.empty() && !m->face_index_normalPerVertex.empty())) {
			glNormal3fv(&m->dot_normalPerVertex[m->face_index_normalPerVertex[i]].x);
		}
		// TEXTURES
		if (!m->dot_texture.empty() && !m->face_index_texture.empty()) {
			glTexCoord2fv(&m->dot_texture[m->face_index_texture[i]].x);
		}
		// COLOR
		//Vec3f offset = (m->dot_vertex[m->face_index_vertex[i]]);
		// VERTEX
		//glColor3f(fabs(sin(offset.x)), fabs(cos(offset.y)), fabs(offset.z));
		glVertex3fv(&m->dot_vertex[m->face_index_vertex[i]].x);
	}
	glEnd();
	//
	glDisable(GL_TEXTURE_2D);
	//
	glEndList();
	return listID;
}
