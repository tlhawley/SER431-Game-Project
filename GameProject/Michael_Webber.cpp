/*
Name		: Michael_Webber.cpp
Authors		: Michael Webber
Version		: 4/27/18
Copyright	: © 2018 Michael Webber

Description	: Building off of projects 1-2 and the quizes
Project 3 & 4 now has textures, a materials, lighting, random ghost furniture, and a short game.

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
#include "globalVariables.h"
#include "materials.h"
#include "lighting.h"
#include "drawingList.h"
#include "checkCollision.h"
#include "sync.h"
#include "input.h"
#include "camera.h"
#include "controls.h"
#include "graphicsFunctions.h"

#include "meshObjConverter.h"
#include "modelLoading.h"
#include "quiz6methods.h"

#include "GUI/map2D.h"
#include "GUI/healthBar2D.h"
#include "GUI/toggleSprint.h"

#include "objPlacement.h"

#include "draw/drawProject1Images.h"
#include "draw/drawSpinSpikes.h"
#include "draw/drawHealthPack.h"
#include "draw/drawClockFastHand.h"
#include "draw/drawClockSlowHand.h"
#include "draw/drawBox.h"
#include "draw/drawDoor.h"
#include "draw/drawRoomWalls.h"
#include "draw/drawKey.h"
#include "draw/drawAL.h"
#include "draw/drawGem.h"
#include "draw/drawPorsche.h"
#include "draw/drawPortal.h"
#include "draw/drawfurniture.h"

#include "gameObjects/gameObjHealthPack.h"
#include "gameObjects/gameObjSpinSpike.h"
#include "gameObjects/gameObjBox.h"
#include "gameObjects/gameObjCollisionBox.h"
#include "gameObjects/gameObjDoorway.h"
#include "gameObjects/gameObjKey.h"
#include "gameObjects/gameObjGem.h"
#include "gameObjects/gameObjPortal.h"
#include "gameObjects/gameObjFurniture.h"


void objLoadInit() {

	// Textures
	//texture_from_file(&texture_array[0], "image.bmp"); // 2Do add this function to imported files

	// Models
	loadModels();
	quiz6Init(); // Project3
}

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

	// load game objects

	initHealthPacks();
	initSpinSpikes();
	initBoxes();
	initCBoxes();
	initDoorway();
	initKeys();
	initGems();
	initPortals();
	initfurnitures();

}

// display
void myDisplay(void) {

	clockTime = clock() - clockOffset;
	clockSeconds = (int)clockTime / 1000;



	// 2D Graphics

	disableLights();

	/*
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	*/

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	glOrtho(-10, 10, -10, 10, -10, 10);
	// view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glColor3f(1, 1, 1);
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
	draw2DHealthBar();

	// Map GUI
	draw2DMap();

	// Toggle Per-Face and Per-Vertex Normal Lighting GUI
	toggleSprint();

	// 3D Graphics
	setUp3DView();

	// Controls & Camera Positioning
	// Updates the camera location and angle based on the users input
	Update(); // Located in controls.h


	float red = 0.15;
	float green = 0.2;
	float blue = 0.22;

	glDisable(GL_FOG);
	// Draw Unlit Background Gradient/SkyBox
	glTranslatef(camx, camy, camz);
	glScalef(2.0, 2.0, 2.0);
	glBegin(GL_QUADS);
	glColor3f(red, green, blue);

	glVertex3f(-100.0, 100.0, 100.0);
	glVertex3f(100.0, 100.0, 100.0);
	glVertex3f(100.0, 100.0, -100.0);
	glVertex3f(-100.0, 100.0, -100.0);

	glVertex3f(-100.0, 100.0, 100.0);
	glVertex3f(100.0, 100.0, 100.0);
	glColor3f(0.2f, 0.22f, 0.2f);
	glVertex3f(100.0, 20.0, 100.0);
	glVertex3f(-100.0, 20.0, 100.0);

	glColor3f(red, green, blue);
	glVertex3f(-100.0, 100.0, -100.0);
	glVertex3f(100.0, 100.0, -100.0);
	glColor3f(0.2f, 0.22f, 0.2f);
	glVertex3f(100.0, 20.0, -100.0);
	glVertex3f(-100.0, 20.0, -100.0);


	glColor3f(red, green, blue);
	glVertex3f(100.0, 100.0, -100.0);
	glVertex3f(100.0, 100.0, 100.0);
	glColor3f(0.2f, 0.22f, 0.2f);
	glVertex3f(100.0, 20.0, 100.0);
	glVertex3f(100.0, 20.0, -100.0);

	glColor3f(red, green, blue);
	glVertex3f(-100.0, 100.0, -100.0);
	glVertex3f(-100.0, 100.0, 100.0);
	glColor3f(0.2f, 0.22f, 0.2f);
	glVertex3f(-100.0, 20.0, 100.0);
	glVertex3f(-100.0, 20.0, -100.0);


	glEnd();
	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(-camx, -camy, -camz);


	// add fog after drawing sky
	glClearColor(0.2f, 0.22f, 0.2f, 1.0f);
	glEnable(GL_FOG);
	GLfloat color[4] = { 0.2f, 0.22f, 0.2f, 1.0f };
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_START, 10);
	glFogf(GL_FOG_END, 80.0);
	glFogi(GL_FOG_MODE, GL_LINEAR);



	// Draw Clock Fast Hand
	objPlacementTRS(drawClockFastHand, -29.9, 8.25, 0, clockSeconds * -6.0, 0.0, 0.0, 3.0, 3.0, 3.0);
	objPlacementTRS(drawClockFastHand, -29.9, -8.25, 0, clockSeconds * 6.0, 0.0, 0.0, 3.0, -3.0, 3.0); // Mirror

																									   // Draw Clock Slow Hand
	objPlacementTRS(drawClockSlowHand, -29.9, 8.25, 0, clockSeconds * -0.5, 0.0, 0.0, 3.0, 3.0, 3.0);
	objPlacementTRS(drawClockSlowHand, -29.9, -8.25, 0, clockSeconds * 0.5, 0.0, 0.0, 3.0, -3.0, 3.0); // Mirror

	objPlacementTRS(drawClockSlowHand, -30.1, 8.25, 0, clockSeconds * 0.5, 180, 0.0, 3.0, 3.0, 3.0);
	objPlacementTRS(drawClockFastHand, -30.1, 8.25, 0, clockSeconds * 6.0, 180, 0.0, 3.0, 3.0, 3.0);

	// Draw & Implement Health packs
	actionHealthPacks();

	// Draw Things on wall
	objPlacementTRS(drawProject1_mawebbe1, 29.82f, 5.0f, 0.0f, 0.0f, 90.0f, 0.0f, 4.0f, 4.0f, 4.0f);
	objPlacementTRS(drawProject1_ppnguye2, 0.0f, 5.0f, 29.88f, 0.0f, 0.0f, 0.0f, 0.35f, 0.35f, 0.35f);
	objPlacementTRS(drawProject1_ppnguye2, 6.5f, 5.0f, 29.88f, 0.0f, 0.0f, 0.0f, 0.25f, 0.25f, 0.25f);
	objPlacementTRS(drawProject1_ppnguye2, -6.5f, 5.0f, 29.88f, 0.0f, 0.0f, 0.0f, 0.25f, 0.25f, 0.25f);

	//objPlacementTRS(drawProject1_ppnguye2, 0.0f, 5.0f, -29.9f, 0.0f, 0.0f, 0.0f, 0.35f, 0.35f, 0.35f);
	objPlacementTRS(drawProject1_ppnguye2, 6.5f, 5.0f, -29.9f, 0.0f, 0.0f, 0.0f, 0.25f, 0.25f, 0.25f);
	objPlacementTRS(drawProject1_ppnguye2, -6.5f, 5.0f, -29.9f, 0.0f, 0.0f, 0.0f, 0.25f, 0.25f, 0.25f);

	objPlacementTRS(drawProject1_tlhawley, 0.0f, 4.0f, 29.8f, 0.0f, -180.0f, 0.0f, 6.0f, 6.0f, -6.0f);
	//objPlacementTRS(drawProject1_tlhawley, 0.0f, 4.0f, -29.8f, 0.0f, 180.0f, 0.0f, 6.0f, 6.0f, 6.0f);
	glTranslatef(0.0f, -0.1f, 0.0f);

	// Draw Things on the wall mirrored
	objPlacementTRS(drawProject1_mawebbe1, 29.82f, -5.0f, 0.0f, 0.0f, 90.0f, 0.0f, 4.0f, -4.0f, 4.0f);
	objPlacementTRS(drawProject1_ppnguye2, 0.0f, -5.0f, 29.88f, 0.0f, 0.0f, 0.0f, 0.35f, -0.35f, 0.35f);
	objPlacementTRS(drawProject1_ppnguye2, 6.5f, -5.0f, 29.88f, 0.0f, 0.0f, 0.0f, 0.25f, -0.25f, 0.25f);
	objPlacementTRS(drawProject1_ppnguye2, -6.5f, -5.0f, 29.88f, 0.0f, 0.0f, 0.0f, 0.25f, -0.25f, 0.25f);

	objPlacementTRS(drawProject1_ppnguye2, 0.0f, -5.0f, -29.9f, 0.0f, 0.0f, 0.0f, 0.35f, -0.35f, 0.35f);
	objPlacementTRS(drawProject1_ppnguye2, 6.5f, -5.0f, -29.9f, 0.0f, 0.0f, 0.0f, 0.25f, -0.25f, 0.25f);
	objPlacementTRS(drawProject1_ppnguye2, -6.5f, -5.0f, -29.9f, 0.0f, 0.0f, 0.0f, 0.25f, -0.25f, 0.25f);

	objPlacementTRS(drawProject1_tlhawley, 0.0f, -4.0f, 29.8f, 0.0f, -180.0f, 0.0f, 6.0f, -6.0f, -6.0f);
	objPlacementTRS(drawProject1_tlhawley, 0.0f, -4.0f, -29.8f, 0.0f, 180.0f, 0.0f, 6.0f, -6.0f, 6.0f);
	glTranslatef(0.0f, 0.1f, 0.0f);


	// Use Lighting for other objects
	setlight();
	if (SmoothingSetting == 1) {
		glShadeModel(GL_SMOOTH);
	}
	else {
		glShadeModel(GL_FLAT);
	}

	// Quiz 6 functions
	quiz6Display(); // Plane, Cube, Cylinder, Sphere, Cone, Dome


					// Draw & Animate doorways & keys
	actionDoorway();

	setMaterialAdvanced(materialGold);
	actionKeys();

	setMaterialAdvanced(materialRuby);
	actionGems();

	//setMaterialAdvanced(materialChrome);
	setMaterialAdvanced(materialRuby);
	actionPortals();

	actionfurnitures();

	// Golden Key
	/*
	setMaterialAdvanced(materialGold);
	objPlacementTRS(drawKey, -20, 1, 0, 0, (float)clockTime/20.0f, 0, 1, 1, 1);
	objPlacementTRS(drawKey, -20, -1, 0, -180, (float)-clockTime / 20.0f+180, 0, 1, 1, 1); // Key mirror
	*/

	// Jade Gem
	/*
	setMaterialAdvanced(materialJade);
	objPlacementTRS(drawGem, 0, 1, -20, 0, (float)clockTime / 20.0f, 0, 1, 1, 1);
	objPlacementTRS(drawGem, 0, -1, -20, -180, (float)-clockTime / 20.0f + 180, 0, 1, 1, 1); // Gem mirror
	*/

	// Rubber Red Al
	setMaterialAdvanced(materialRubberRed);
	objPlacementTRS(drawAL, 0, 4, 20, 0, (float)clockTime / 20.0f, 0, 1.0f, 1.0f, 1.0f);
	objPlacementTRS(drawAL, 0, -4, 20, -180, (float)-clockTime / 20.0f + 180, 0, 1.0f, 1.0f, 1.0f); // Al mirror

																									// Chrome Porsche
	setMaterialAdvanced(materialChrome);
	objPlacementTRS(drawPorsche, 20, 1, 0, 0, (float)clockTime / 20.0f, 0, 1.0f, 1.0f, 1.0f);
	objPlacementTRS(drawPorsche, 20, -1, 0, -180, (float)-clockTime / 20.0f + 180, 0, 1.0f, 1.0f, 1.0f); // Porsche mirror




																										 // Emissive Objs
	setMaterialAdvanced(materialEmissiveRed);
	objPlacementTRS(drawGear1, 0, 15, -20, 0, (float)clockTime / 20.0f, 0, 1.0f, 1.0f, 1.0f);
	objPlacementTRS(drawGear1, 0, -15, -20, 0, (float)clockTime / 20.0f, 0, 1.0f, 1.0f, 1.0f);

	setMaterialAdvanced(materialEmissiveGreen);
	objPlacementTRS(drawGear2, 0, 15, 20, 0, (float)clockTime / 20.0f, 0, 1.0f, 1.0f, 1.0f);
	objPlacementTRS(drawGear2, 0, -15, 20, 0, (float)clockTime / 20.0f, 0, 1.0f, 1.0f, 1.0f);



	// Draw & Implement Spin Spikes
	//setmaterial2(0.01f, 0.12, 0.1, 0.1, 2);
	setMaterialAdvanced(materialSpinSpike);
	actionSpinSpikes();


	// Draws the room/environment
	//setmaterial2(0.1f, 0.35, 0.34, 0.3, 0.1);
	setMaterialAdvanced(materialCastle);
	//glCallList(displayListMaterialTest1);

	glCallList(meshFloor);
	glCallList(meshWall);

	//setMaterialAdvanced(materialGold);

	// Draws colored Walls
	// Bronze
	//float materialBronze[] = { 0.2125f,0.1275f,0.054f,1.0f,0.714f,0.4284f,0.18144f,1,0.393548f,0.271906f,0.166721f,1,0,0,0,1,25.6f };
	setMaterialAdvanced(materialBronze);
	objPlacementTRS(drawRoomWall1, 0, 0, 0, 0, 0, 0, 1, 1, 1);
	// Emerald
	//float materialEmerald[] = { 0.0215f,0.1745f,0.0215f,1.0f,0.07568f,0.61424f,0.07568f,1,0.633f,0.727811f,0.633f,1,0,0,0,1,76.8f };
	setMaterialAdvanced(materialEmerald);
	objPlacementTRS(drawRoomWall1, 0, 0, 0, 0, -90, 0, 1, 1, 1);
	// Plastic (White)
	//float materialPlasticWhite[] = { 0,0,0,1.0f,0.55f,0.55f,0.55f,1,0.7f,0.7f,0.7f,1,0,0,0,1,32.0f };
	setMaterialAdvanced(materialPlasticWhite);
	objPlacementTRS(drawRoomWall2, 0, 0, 0, 0, -90, 0, 1, 1, 1);
	// Obsidian
	//float materialObsidian[] = { 0.05375f,0.05f,0.06625f,1.0f,0.18275f,0.17f,0.22525f,1,0.332741f,0.328634f,0.346435f,1,0,0,0,1,38.4f };
	setMaterialAdvanced(materialObsidian);
	objPlacementTRS(drawRoomWall2, 0, 0, 0, 0, 180, 0, 1, 1, 1);




	// Draw boxes and calculate box collision
	setmaterial2(0.0f, 0.35, 0.34, 0.3, 0.0);
	actionBoxes(); // Visible Collision Boxes
	actionCBoxes(); // Invisible Collision Boxes

					// Draws the Clocks
	setmaterial2(0.1f, 0.1f, 0.1f, 0.1f, 0.5);
	glTranslatef(-30.0f, 8.25f, 0.0f);
	glCallList(displayListClockFrame);

	glTranslatef(0.0f, -16.5f, 0.0f);
	glCallList(displayListClockFrame); // Mirror
	glTranslatef(0.0f, 16.5f, 0.0f);

	glRotatef(180, 0, 1, 0);
	glCallList(displayListClockFrame);
	glRotatef(-180, 0, 1, 0);

	setmaterial2(0.1f, 0.4f, 0.4f, 0.4f, 0.9);
	glCallList(displayListClockWhite);

	glTranslatef(0.0f, -16.5f, 0.0f);
	glCallList(displayListClockWhite); // mirror
	glTranslatef(0.0f, 16.5f, 0.0f);

	glRotatef(180, 0, 1, 0);
	glCallList(displayListClockWhite);
	glRotatef(-180, 0, 1, 0);

	glTranslatef(30.0f, -8.25f, 0.0f);



	// Checker Floor
	//glCallList(drawList6);



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
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA); //glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA);

	glutInitWindowPosition(0, 0);

	glutInitWindowSize(screenWidth, screenHeight); //glutInitWindowSize(800, 800);

	glutCreateWindow("Ghost Furnature");

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
	glutReshapeFunc(myReshape);

	glutMainLoop();
	return(0);
}

