/*
Name		: Project 431 - Midterm Exam Bonus Points
Authors		: Michael Webber, Travis Hawley, Cory Dianovich
Version		: 11/3/18
Copyright	: © 2018


Description	:
	Hermite curves between two boxes


*/


//Sources:
// Lecture Slides
// https://stackoverflow.com/questions/28530798/how-to-make-a-basic-fps-counter
// https://ernesthuntley.wordpress.com/2010/08/20/smooth-keyboard-input-with-glut/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//used for textures in mehsObjConverter.h
#include <windows.h>
#include <wingdi.h>

// Include files
//#include <stdio.h>
#include <math.h>
#include <ctime>
//#include "gl\glut.h"

#include <vector>
#include <ImathVec.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <direct.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define PI 3.14159265358979323846
using namespace std;
using namespace Imath;


void objInit();

// curve variables

float box1X = -16;
float box1Y = 1.5;
float box1Z = -6;

float box2X = -16;
float box2Y = 1.5;
float box2Z = 6;

float Geometry[4][3] = {
	{ box1X, box1Y, box1Z },  //  Point 1
{ box2X,  box2Y, box2Z },	  //	Point2
{ 0,  0, 10 },	  //	Tangent1
{ 0,   0, 10 }		//	Tangent2
};
unsigned int N = 40;



// Custom .h files
#include "gameProjectHeaders.h"




void objLoadInit() {

	// Textures
	//texture_from_file(&texture_array[0], "image.bmp"); // 2Do add this function to imported files

	// Models
	loadModels();
	//quiz6Init(); // Project3
}

// resets the cameras starting position, and other common variables such as health, and timer
// Initializes game objects and noiseGen
void objInit() {

	// reset global variables

	lx = 0.0f; ly = 0.0f; lz = -1.0f;
	timer = 0;
	spikeAngY = 0.0;
	camAngY = -PI / 2.0;
	camAngX = 0.0;

	camxv = 0.0f; camyv = 0.0f; camzv = 0.0f; // x,y,z velocity
											  //x = 26.0f; y = 1.75f; z = 0.0f;
	camx = 0.0f; camy = 1.75f; camz = 0.0f;
	ox = camx; oy = camy; oz = camz; // old x,y,z
	gravity = 0.0;

	health = 20;
	takingDamage = 0;
	mouseMoveX = 0; mouseMoveY = 0;

	// reset the camera orientation
	orientMe(camAngY);
	orientMe2(camAngX);

	clockOffset = clock(); // reset the clock timer

	score = 0; // reset the score
	inventoryKeys = 0; // reset player keys
	levelComplete = false;


	initNoiseGen(); // from noiseGenerator.h


	initButtonUI();


	// load game objects
	initHealthPacks();
	initSpinSpikes();
	initBoxes();
	initCBoxes();
	initDoorway();
	initKeys();
	initGems();
	initPortals();
	//initfurnitures();
	initBoundingBoxes();
	initBaseModels();
	initPointLights();

}

// display
void myDisplay(void) {

	camAngY = -PI / 2.0;
	camAngX = 0.0;
	camx = 0.0f; camy = 1.75f; camz = 0.0f;
	ox = camx; oy = camy; oz = camz;
	orientMe(camAngY);
	orientMe2(camAngX);

	clockTime = clock() - clockOffset;
	clockSeconds = (int)clockTime / 1000;


	// 2D Graphics
	disableLights();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


	

	// projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	glOrtho(-10, 10, -10, 10, -10, 10);
	// view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	char msgXYZ[150];
	sprintf_s(msgXYZ, "asdw to move box1,    arrowkeys to move box2,    esc to quit");
	glColor3f(1, 1, 1);
	renderBitmapString(-9.5, -9.0, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h


	// 3D Graphics
	setUp3DView();

	// Controls & Camera Positioning
	// Updates the camera location and angle based on the users input


	Update(); // Located in controls.h
	


	setlight();

	glShadeModel(GL_SMOOTH);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);


	// Displays everything in the environment, and every interactive game object
	displayEnvironment();
	displayGameObjects();


	glPushMatrix();

	setMaterialAdvanced(materialCastle);

	
	glTranslatef(box1X, box1Y, box1Z-0.1f);
	glScalef(0.2, 0.2, 0.2);
	glCallList(meshBox);
	glScalef(5,5,5);
	glTranslatef(-box1X, -box1Y, -box1Z+0.1f);

	glPopMatrix();

	//GL Triangles for Curve and points

	Geometry[0][0] = box1X;
	Geometry[0][1] = box1Y;
	Geometry[0][2] = box1Z;
	Geometry[1][0] = box2X;
	Geometry[1][1] = box2Y;
	Geometry[1][2] = box2Z;
	/*
	Geometry[2][0] = 0;
	Geometry[2][1] = 0;
	Geometry[2][2] = 10;
	Geometry[3][0] = 0;
	Geometry[3][1] = 0;
	Geometry[3][2] = 10;
	*/

	disableLights();
	//Source: https://raw.githubusercontent.com/javiergs/SER431/0fa5db7714bc117e9443e9661f3c927103c1b431/Lecture15/hermite.cpp
	
	/*
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0.5, 0.0);
	// use the parametric time value 0 to 1
	for (int i = 0; i != N; ++i) {
		float t = (float)i / (N - 1);
		// calculate blending functions
		float b0 = 2 * t*t*t - 3 * t*t + 1;
		float b1 = -2 * t*t*t + 3 * t*t;
		float b2 = t * t*t - 2 * t*t + t;
		float b3 = t * t*t - t * t;
		// calculate the x, y and z of the curve point
		float x = b0 * Geometry[0][0] + b1 * Geometry[1][0] + b2 * Geometry[2][0] + b3 * Geometry[3][0];
		float y = b0 * Geometry[0][1] + b1 * Geometry[1][1] + b2 * Geometry[2][1] + b3 * Geometry[3][1];
		float z = b0 * Geometry[0][2] + b1 * Geometry[1][2] + b2 * Geometry[2][2] + b3 * Geometry[3][2];
		// specify the point
		glVertex3f(x, y, z);
	}
	glEnd();
	*/


	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 1.0, 0.0);
	// use the parametric time value 0 to 1
	for (int i = 0; i != N-1; i++) {
		float t = (float)i / (N - 1);
		// calculate blending functions
		float b0 = 2 * t*t*t - 3 * t*t + 1;
		float b1 = -2 * t*t*t + 3 * t*t;
		float b2 = t * t*t - 2 * t*t + t;
		float b3 = t * t*t - t * t;
		// calculate the x, y and z of the curve point
		float x = b0 * Geometry[0][0] + b1 * Geometry[1][0] + b2 * Geometry[2][0] + b3 * Geometry[3][0];
		float y = b0 * Geometry[0][1] + b1 * Geometry[1][1] + b2 * Geometry[2][1] + b3 * Geometry[3][1];
		float z = b0 * Geometry[0][2] + b1 * Geometry[1][2] + b2 * Geometry[2][2] + b3 * Geometry[3][2];


		float t2 = (float)(i+1) / (N - 1);
		// calculate blending functions
		float b02 = 2 * t2*t2*t2 - 3 * t2*t2 + 1;
		float b12 = -2 * t2*t2*t2 + 3 * t2*t2;
		float b22 = t2 * t2*t2 - 2 * t2*t2 + t2;
		float b32 = t2 * t2*t2 - t2 * t2;
		// calculate the x, y and z of the curve point
		float x2 = b02 * Geometry[0][0] + b12 * Geometry[1][0] + b22 * Geometry[2][0] + b32 * Geometry[3][0];
		float y2 = b02 * Geometry[0][1] + b12 * Geometry[1][1] + b22 * Geometry[2][1] + b32 * Geometry[3][1];
		float z2 = b02 * Geometry[0][2] + b12 * Geometry[1][2] + b22 * Geometry[2][2] + b32 * Geometry[3][2];


		// specify the points
		glVertex3f(x, y-0.1f, z);
		glVertex3f(x2, y2-0.1f, z2);
		glVertex3f(x, y + 0.1f, z);

		glVertex3f(x, y + 0.1f, z);
		glVertex3f(x2, y2 - 0.1f, z2);
		glVertex3f(x2, y2 + 0.1f, z2);
	}
	glEnd();



	glBegin(GL_POINTS);
	glPointSize(3);
	glColor3f(1, 0, 0);
	// use the parametric time value 0 to 1
	for (int i = 0; i != N; ++i) {
		float t = (float)i / (N - 1);
		// calculate blending functions
		float b0 = 2 * t*t*t - 3 * t*t + 1;
		float b1 = -2 * t*t*t + 3 * t*t;
		float b2 = t * t*t - 2 * t*t + t;
		float b3 = t * t*t - t * t;
		// calculate the x, y and z of the curve point
		float x = b0 * Geometry[0][0] + b1 * Geometry[1][0] + b2 * Geometry[2][0] + b3 * Geometry[3][0];
		float y = b0 * Geometry[0][1] + b1 * Geometry[1][1] + b2 * Geometry[2][1] + b3 * Geometry[3][1];
		float z = b0 * Geometry[0][2] + b1 * Geometry[1][2] + b2 * Geometry[2][2] + b3 * Geometry[3][2];
		// specify the point
		glVertex3f(x, y, z);
	}
	glEnd();

	
	// Points
	glColor3f(1, 0, 0);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex3fv(Geometry[0]);
	glVertex3fv(Geometry[1]);
	glEnd();
	// Control Graph
	glColor3f(0, 0, 1);
	//glPushMatrix();
	//glTranslatef(Geometry[0][0], Geometry[0][1], Geometry[0][2]);
	//glBegin(GL_LINES);
	//glVertex3f(0, 0, 0);
	//glVertex3fv(Geometry[2]);
	//glEnd();
	//glPopMatrix();
	//glPushMatrix();
	//glTranslatef(Geometry[1][0], Geometry[1][1], Geometry[1][2]);
	//glBegin(GL_LINES);
	//glVertex3f(0, 0, 0);
	//glVertex3fv(Geometry[3]);
	//glEnd();
	//glPopMatrix();
	

	setlight();


	glPushMatrix();

	glTranslatef(box2X, box2Y, box2Z+0.1f);
	glScalef(0.2, 0.2, 0.2);
	glCallList(meshBox);
	glScalef(5, 5, 5);
	glTranslatef(-box2X, -box2Y, -box2Z-0.1f);

	glPopMatrix();
	
	
					// Sync frame rate to roughly 60 fps & update mouse input & glutSwapBuffers();
	sync();

}







// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// MMMMM  AAAAA  IIIII  N   N
// M M M  A   A    I    NN  N
// M M M  AAAAA    I    N N N
// M M M  A   A    I    N  NN
// M   M  A   A  IIIII  N   N

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA); //glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL | GLUT_ALPHA);

	glutInitWindowPosition(0, 0);

	glutInitWindowSize(screenWidth, screenHeight); //glutInitWindowSize(800, 800);

	glutCreateWindow("Midterm Exam Bonus Points - SER 431");

	glutFullScreen(); // start in full screen
					  //glutReshapeWindow(800, 600);
					  //glutPositionWindow(64, 64);

	myInit(); // uses "graphicsFunctions.h"

	objLoadInit(); // Only load the objects at the start do not load them when the game resets
	objInit(); // Reset these when the player dies

	initshadow();

			   // Keyboard and mouse input
	glutSpecialFunc(mySpecial);
	glutSpecialUpFunc(mySpecialUp);
	glutKeyboardFunc(keyboardInput);
	glutKeyboardUpFunc(keyboardInputUp);
	glutMouseFunc(mouseClicks);
	glutPassiveMotionFunc(myMouseMotion);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutMainLoop();
	//system("pause");
	return(0);

}

