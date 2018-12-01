/*
Name		: Project 431 - Milestone 3
Authors		: Michael Webber, Travis Hawley, Cory Dianovich
Version		: 11/30/18
Copyright	: © 2018


Description	:
	This is milestone 3 of our game project
	Building off of last semesters projects and quizzes + quizzes and hw from this class...
	We have build an action adventure platform game
	
Features:
	advanced graphics
	multiple levels
	fast combat gameplay
	moving platforms
	animated character
	enemies
	health packs (hearts)
	health UI
	gems
	portals to other areas/levels
	Textures & Materials: Baked texture lighting, procedural textures, transparent textures
	Sky box
	Realtime reflections
	Advanced particle system
	Box colliders
	Terrain with collision and procedural texture

Controls:
	mouseclick to unlock the cursor for menu use
	daws moves the player right,left,forwards, and backwards.
	e to attack
	space jumps if the player is on the ground.
	mouse movement rotates the camera.
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
#include <irrKlang.h> //Library Source: https://www.ambiera.com/irrklang/
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
using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")
ISoundEngine *SoundEngine = createIrrKlangDevice();

void objInit();
void loadLevel(int mapID);


// Custom .h files
#include "gameProjectHeaders.h"


// display
void myDisplay(void) {

	clockTime = clock() - clockOffset;
	clockSeconds = (int)clockTime / 1000;
	frameTimer = frameTimer + 1;

	// 2D Graphics
	disableLights();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// projection
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glViewport(0, 0, width, height);
	glOrtho(-10, 10, -10, 10, -10, 10);
	// view
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	if (buttons[3].toggle == true) {

		// Display debug info
		char msgXYZ[170];

		// Debug Text
		sprintf_s(msgXYZ, "CAY: %f   CAX: %f   MMX: %d   MMY: %d   X: %f   Y: %f   Z: %f", camAngY, camAngX, mouseMoveX, mouseMoveY, camx, camy, camz);
		// Controls
		//sprintf_s(msgXYZ, "(f11) - toggle fullscreen       (e) - attack       (asdw) - movement       (mouse) - look       (mouseclick) - toggle cursor       (space) - jump  %d", clockTime);
		glColor3f(1, 1, 1);
		renderBitmapString(-7.0, -9.0, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
		glColor3f(0.0, 0.0, 0.0);
		renderBitmapString(-6.97, -9.03, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"

		sprintf_s(msgXYZ, "Keys: %d      Score: %d", inventoryKeys, score);

		glColor3f(1, 1, 1);
		renderBitmapString(-4.5, 9.1, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
		glColor3f(0.0, 0.0, 0.0);
		renderBitmapString(-4.47, 9.07, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"

		if (levelComplete == true) {}
	}


	// Health Bar GUI
	draw2DHealthBar(); // TODO: Replace with heart sprites

	// Map GUI
	draw2DMap();

	// Menu display
	if (displayMenu == true)
	{
		displayButtonUI();
	}

	// 3D Graphics
	setUp3DView();

	// Controls & Camera Positioning
	// Updates the camera location and angle based on the users input

	// offsets camera for a third person perspective
	float number = cos(camAngX)*2.5f;
	if (buttons[15].toggle == false) {
	}
	else {
		number = 1;
	}
	float llx = sin(camAngY)*number;
	float llz = -cos(camAngY)*number;
	float lly = sin(camAngX)*2.0f + 0.15f;
	glTranslatef(llx, lly, llz);


	// Terrain Collision with the camera
	if (currentLevel == 0) {
		ImprovedNoise noise; // modified for terrain
		Vec3f pixelColor; // modified for terrain
		pixelColor = marbleMap(t_scale(noise.perlinMarble((camx + 128)*10.0f, (camz + 128)*10.0f))); // terrain height / pixel brightness using marble texture
		
		if (buttons[13].toggle == true) {
			if (buttons[14].toggle == true) {
				if (camy < (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f) {
					camy = (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f;
					camyv = 0;
					jumpFrame = 0;
					canJump = true;
				}
			}
			else {
				if (camy < -2.05f) {
					camy = -2.05f;
					camyv = 0;
					jumpFrame = 0;
					canJump = true;
				}
			}
		}
	}


	actionDoorway();
	actionKeys();
	actionPortals();


	Position pos; pos.x = 0; pos.y = -80; pos.z = 0;
	MirrorDirection mirrorDir; mirrorDir.x = 1.0; mirrorDir.y = -1.0; mirrorDir.z = 1.0;


	// blue atmospheric fog
	if (buttons[5].toggle == true) {
		glEnable(GL_FOG);
		GLfloat color[4] = { 0.9f, 0.97f, 1.0f, 1.0f };
		glFogfv(GL_FOG_COLOR, color);
		glFogi(GL_FOG_MODE, GL_EXP);
		glFogf(GL_FOG_DENSITY, .003);
	}

	setlight();

	// Reflection menu option
	if (buttons[6].toggle == true) {
		if (currentLevel == -1) {
			reflection(drawMirror1, pos, mirrorDir);
		}
	}

	displaySkyBox(2001, 90, 0);
	

	// Bound Box menu option
	if (buttons[1].toggle == true) {
		disableLights();
		actionBoundingBoxes();
		setlight();
	}
	
	actionGems();
	actionSpinSpikes();
	actionHealthPacks(); // Health packs need to be replaced with heart models

	// Smooth shading menu setting
	if (SmoothingSetting == 1) { glShadeModel(GL_SMOOTH); }
	else { glShadeModel(GL_FLAT); }


	// Displays everything in the environment, and every interactive game object
	displayEnvironment();
	displayGameObjects();

	/*
	// fireball testing
	setMaterialAdvanced(materialEmissive);
	glTranslatef(camx + 3.0, 1, camz);
	glRotatef(frameTimer*10.0, 20, 30, 40);
	glCallList(meshFireball);
	glRotatef(-frameTimer*10.0, 20, 30, 40);
	glTranslatef(-camx - 3.0, -1, -camz);
	*/

	// Draw particles
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	disableLights();
	if (buttons[9].toggle == true) {
		glEnable(GL_LIGHTING); // use simple lighting for particles
	}


	if (buttons[2].toggle == true) {
		glPushMatrix();
		//ps.add(ParID::flame, 0, 1, 0);
		if (currentLevel == 0) {
			ps.add(ParID::fog, camx, -5, camz);
		}
		//ps.add(ParID::bubbles, 0, 0, 0);

		if (currentLevel == -1) {
			//ps.add(ParID::flame2, camx+3.0, 1, camz); // fireball particles
			ps.add(ParID::flame, -189.8, 4.5, -21.6);
			ps.add(ParID::flame, -189.8, 4.5, -18.4);
		}

		actionParticleSystem();
		clearParticles = 0;
		glPopMatrix();
	}
	else {
		glEnable(GL_BLEND);
	}

	

	// Box collision
	actionCBoxes();


	if (frameTimer < N) {
		//camTimer = camTimer + 1;
		UpdateCam();
	}
	else {
		Update(); // Located in controls.h
	}

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
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

	glutCreateWindow("Milestone 2 - SER 431");

	glutFullScreen(); // start in full screen

	myInit();

	objLoadInit(); // Only load the objects at the start do not load them when the game resets
	objInit(); // Reset these when the player dies

	initshadow();

	// Keyboard and mouse input
	glutSpecialFunc(mySpecial);
	glutSpecialUpFunc(mySpecialUp);
	glutKeyboardFunc(keyboardInput);
	glutKeyboardUpFunc(keyboardInputUp);
	glutPassiveMotionFunc(myMouseMotion);
	glutMouseFunc(mouseClicks);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutMainLoop();
	//system("pause");
	return(0);

}

