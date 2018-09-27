// Added to fix error in coor.h - GLubyte *LoadDIBitmap(const char *filename, BITMAPINFO **info) {
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <GL/glut.h>
#include "ParticleSystemH/keyboardInput.h"
#include "ParticleSystemH/timer.h"
#include "ParticleSystemH/core.h"
#include "ParticleSystemH/particles.h"
#include "ParticleSystemH/particleColorData.h"
#include "ParticleSystemH/particleData.h"
#include "ParticleSystemH/noise.h"


// Moved drawParticles() to particles.h

// display
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// projection
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45, ratio, 1, 1000);
	// view
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	// lookAt
	gluLookAt(0.0f, 40.0f, 320.0,
		0.0f, 1.0f, -1.0f,
		0.0f, 1.0f, 0.0f);
	// camera
	glScalef(scale, scale, scale);
	glRotatef(x_angle, 1.0f, 0.0f, 0.0f);
	glRotatef(y_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.0f);

	//plane
	glPushMatrix();
	glTranslatef(-900, 0, -900);
	glCallList(display1);
	glPopMatrix();

	/*
	// box 2
	glPushMatrix();
	glTranslatef(200, 0, 0);
	glCallList(display3);
	glPopMatrix();

	// box 3
	glPushMatrix();
	glTranslatef(-200, 0, 0);
	glCallList(display4);
	glPopMatrix();
	*/

	// NOTE: Draw particles last to reduce transparency glitches
	//glEnable(GL_DEPTH_TEST);
	// Particles
	switch (particleSystemType) {
	case 0:
		ps.add(smokeParticles());
		break;
	case 1:
		ps.add(flameParticles());
		break;
	case 2:
		ps.add(snowParticles());
		break;
	}
	//ps.add();
	float time = calculate_frame_time();
	ps.update(time);
	ps.remove();
	glPushMatrix();
	drawParticles();
	glPopMatrix();
	setMaterialAdvanced(materialEmissive); // Material color

	// end
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	// texto
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);
	renderBitmapString(0.0, height - 13.0f, 0.0f, "Use [Mouse Left Key] to rotate");
	renderBitmapString(0.0, height - 26.0f, 0.0f, "Use [Mouse Right Key] to scale");
	renderBitmapString(0.0, height - 39.0f, 0.0f, "Use [Left & Right Arrowkeys] to toggle particle systems");
	switch (particleSystemType) {
	case 0 :
		renderBitmapString(0.0, height - 52.0f, 0.0f, "Particle system: smoke particles");
		break;
	case 1:
		renderBitmapString(0.0, height - 52.0f, 0.0f, "Particle system: flame particles");
		break;
	case 2:
		renderBitmapString(0.0, height - 52.0f, 0.0f, "Particle system: snow particles");
		break;
	}
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glutSwapBuffers();
}

// reshape
void reshape(int w, int h) {
	width = w;
	height = h;
	if (h == 0) h = 1;
	ratio = 1.0f * w / h;
}

// init
void init() {
	// particles
	init_frame_timer();

	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // NOTE: Added for transparency
	glEnable(GL_BLEND); // NOTE: Added for transparency
	ratio = (double)width / (double)height;
	// mesh
	mesh1 = createPlane(2000, 2000, 200);
	mesh2 = createCube();
	mesh3 = createCube();
	mesh4 = createCube();
	calculateNormalPerFace(mesh1);
	calculateNormalPerFace(mesh2);
	calculateNormalPerFace(mesh3);
	calculateNormalPerFace(mesh4);
	calculateNormalPerVertex(mesh1);
	calculateNormalPerVertex(mesh2);
	calculateNormalPerVertex(mesh3);
	calculateNormalPerVertex(mesh4);
	// textures
	bmpTexture(textureArray, "./BMP files/brick.bmp", 0, 0); // NOTE: File directory changed from ../../BMP files to ./BMP files
	bmpTexture(textureArray, "./BMP files/smoke.bmp", 1, 1); // NOTE: There are a lot more particle images to choose from in the BMP files folder
	bmpTexture(textureArray, "./BMP files/oldbox.bmp", 2, 0);
	bmpTexture(textureArray, "./BMP files/flame01.bmp", 3, 1);
	bmpTexture(textureArray, "./BMP files/snowflake.bmp", 4, 1);

	mesh5 = loadFile("./OBJ files/ParticlePlane.obj");
	mesh6 = loadFile("./OBJ files/ParticlePlane.obj");
	mesh7 = loadFile("./OBJ files/ParticlePlane.obj");

	display1 = meshToDisplayList(mesh1, 1, 0);
	display2 = meshToDisplayList(mesh2, 2, 2);
	display3 = meshToDisplayList(mesh3, 3, 2);
	display4 = meshToDisplayList(mesh4, 4, 2);
	displayParticlePlane = meshToDisplayList(mesh5, 5, 1);
	displayParticlePlaneFlames = meshToDisplayList(mesh6, 6, 3);
	displayParticlePlaneSnow = meshToDisplayList(mesh7, 7, 4);
	// light
	GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

void main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA); //Note: Added GLUT_ALPHA for transparent particles
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(width, height);
	glutCreateWindow("Particles");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(mouse);
	glutSpecialFunc(mySpecial); // special functions for arrowkey input
	glutSpecialUpFunc(mySpecialUp);
	glutMotionFunc(motion);
	glutMainLoop();
}