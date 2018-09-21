/*
Name		: Quiz4
Authors		: Michael Webber, Travis Hawley, Cory Dianovich
Version		: 9/22/18
Copyright	: © 2018


Description	: Building off of last semester projects and quizzes. We now have shadows.
Quiz 4 - Shadows



Controls:
daws moves the player right,left,forwards, and backwards.
arrowkeys moves the player forwards, and backwards, and rotates the camera on the y axis.
space jumps if the player is on the ground.
mouse movement rotates the camera.
mouse click toggles camera movement with the mouse so the mouse isn't always locked.
f11 toggles full screen and windowed modes.


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

// Custom .h files
#include "gameProjectHeaders.h"


void objLoadInit() {

	// Textures
	//texture_from_file(&texture_array[0], "image.bmp"); // 2Do add this function to imported files

	// Models
	loadModels();
	quiz6Init(); // Project3
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

	health = 1000;
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

}

// display
void myDisplay(void) {

	clockTime = clock() - clockOffset;
	clockSeconds = (int)clockTime / 1000;


	// 2D Graphics
	disableLights();

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
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
	// Display debug info
	char msgXYZ[150];
	//camAngY = 1/57.3; //1.57 = 90
	// Debug Text
	//sprintf_s(msgXYZ, "CAY: %f   CAX: %f   MMX: %d   MMY: %d   X: %f   Y: %f   Z: %f", camAngY, camAngX, mouseMoveX, mouseMoveY, camx, camy, camz);
	// Controls
	sprintf_s(msgXYZ, "f11 - toggle fullscreen       asdw & arrowkeys movement       mouse to look       space to jump.");
	//sprintf_s(msgXYZ, "MX: %f, MY: %f, W0.2: %f",(float)mouseX/(float)width, (float)(height-mouseY-width*0.2), (float)width * 0.2);
	//height - mouseY - width * 0.04
	glColor3f(1, 1, 1);
	renderBitmapString(-9.0, -9.0, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
	glColor3f(0.0, 0.0, 0.0);
	renderBitmapString(-8.97, -9.03, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"

	sprintf_s(msgXYZ, "Keys: %d      Score: %d", inventoryKeys, score);

	glColor3f(1, 1, 1);
	renderBitmapString(-4.5, 9.1, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
	glColor3f(0.0, 0.0, 0.0);
	renderBitmapString(-4.47, 9.07, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"

	if (levelComplete == true) {
		sprintf_s(msgXYZ, "Level Complete! Sorry there are no more levels.");

		glColor3f(1, 1, 1);
		renderBitmapString(-2.5, 0.1, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
		glColor3f(0.0, 0.0, 0.0);
		renderBitmapString(-2.47, 0.07, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"
	}


	/*
	sprintf_s(msgXYZ, "TOGGLE SHADING");
	glColor3f(1, 1, 1);
	renderBitmapString(-1.0, 9.0, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
	glColor3f(0.0, 0.0, 0.0);
	renderBitmapString(-0.97, 8.97, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"
	*/

	// UI is Roughly 20-30 % of the screen if the screen is squashed on the horizontal
	// Health Bar GUI
	draw2DHealthBar(); // TODO: Replace with heart sprites

	// Map GUI
	draw2DMap();

	// Toggle Per-Face and Per-Vertex Normal Lighting GUI
	toggleSprint();

	// 3D Graphics
	setUp3DView();

	// Controls & Camera Positioning
	// Updates the camera location and angle based on the users input
	Update(); // Located in controls.h




	// Terrain Collision with the camera
	ImprovedNoise noise; // modified for terrain
	Vec3f pixelColor; // modified for terrain
	pixelColor = marbleMap(t_scale(noise.perlinMarble((camx + 128)*10.0f, (camz + 128)*10.0f))); // terrain height / pixel brightness using marble texture
	if (camy < (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f) {
		camy = (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f;
		canJump = true;
	}

	actionDoorway();
	actionKeys();


	Position pos; pos.x = 0; pos.y = 0; pos.z = 60;
	MirrorDirection mirrorDir; mirrorDir.x = 1.0; mirrorDir.y = 1.0; mirrorDir.z = -1.0;

	reflection(drawMirror1, pos, mirrorDir);

	displaySkyBox(2001, 0, 0);

	// displays the bounding boxes for object collision
	disableLights();
	actionBoundingBoxes();
	actionGems();
	actionSpinSpikes();
	actionHealthPacks(); // Health packs need to be replaced with heart models
	//actionBaseModels(); // no action for baseModels they are only for display in the environment

	// Use Lighting
	setlight();
	if (SmoothingSetting == 1) { glShadeModel(GL_SMOOTH); }
	else { glShadeModel(GL_FLAT); }

	// Displays everything in the environment, and every interactive game object
	displayEnvironment();
	displayGameObjects();

	// Draw boxes and calculate box collision
	actionCBoxes(); // Invisible Collision Boxes


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

	glutCreateWindow("Quiz 4 - SER 431");

	glutFullScreen(); // start in full screen
					  //glutReshapeWindow(800, 600);
					  //glutPositionWindow(64, 64);

	myInit(); // uses "graphicsFunctions.h"

	objLoadInit(); // Only load the objects at the start do not load them when the game resets
	objInit(); // Reset these when the player dies

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

