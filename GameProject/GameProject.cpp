/*
Name		: Quiz3
Authors		: Michael Webber, Travis Hawley, Cory Dianovich
Version		: 9/15/18
Copyright	: © 2018


Description	: Building off of last semester projects and quizzes. We now have a skybox, terrain, and a reflection.
Quiz 3 - Mirror



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
	initfurnitures();
	initBoundingBoxes();

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



















	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


	glEnable(GL_STENCIL_TEST); //Start using the stencil
	glDisable(GL_DEPTH_TEST);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); //Disable writing colors in frame buffer
	glStencilFunc(GL_ALWAYS, 1, 0xFFFFFFFF); //Place a 1 where rendered
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE); 	//Replace where rendered
														// PLAIN for the stencil
	glPushMatrix();
	//glTranslatef(-900, 0, -900);
	//glCallList(display1);
	glCallList(meshq3MirrorPlane);

	glPopMatrix();
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); //Reenable color
	glEnable(GL_DEPTH_TEST);
	glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Keep the pixel









	
	// blue atmospheric fog
	glEnable(GL_FOG);
	GLfloat color[4] = { 0.75f, 0.8f, 1.0f, 1.0f };
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_START, 1);
	glFogf(GL_FOG_END, 50.0);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, .02);

	

	//glEnable(GL_LIGHTING);
	setlight();




	// Start of mirrored objects display

	// mirrored room and floor tiles
	glTranslatef(0, 0, 60.0f);
	glScalef(1.0f, 1.0f, -1.0f);


	setMaterialAdvanced(materialCastle);

	// camera box mirrored
	glTranslatef(camx, camy - 1.0f, camz);
	glScalef(0.5f, 0.5f, 0.5f);
	glCallList(meshABox);
	glScalef(2.0f, 2.0f, 2.0f);
	glTranslatef(-camx, -camy + 1.0f, -camz);


	// TERRAIN Display mirrored
	setMaterialAdvanced(materialSpinSpike); // this shading works ok for the terrain
	glTranslatef(0.0f, -15, 0.0f);
	displayNoiseGenPlane(); //Displays the terrain
	glTranslatef(0.0f, 15, 0.0f);

	// LAVA MOUNTAIN Display mirrored
	setMaterialAdvanced(materialSkyBox); //emissive lava
	glTranslatef(0.0f, -150.0f, 0.0f);
	glScalef(100.0f, 100.0f, 100.0f);
	displayNoiseGenLavaPlane(); // displays lava
	glScalef(0.01f, 0.01f, 0.01f);
	glTranslatef(0.0f, 150.0f, 0.0f);


	setMaterialAdvanced(materialObsidian);
	glCallList(meshq3MirrorRoom);

	setMaterialAdvanced(materialCastle);
	glCallList(meshFloor);




	glTranslatef(0.0f, 1.0, 25);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox1(); // wood box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(0.0f, -1.0, -25);

	glTranslatef(2.0f, 1.0, 25);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox2(); // clouds box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(-2.0f, -1.0, -25);

	glTranslatef(-2.0f, 1.0, 25);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox3(); // lava box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(2.0f, -1.0, -25);



	glScalef(1.0f, 1.0f, -1.0f);
	glTranslatef(0, 0, -60.0f);


	// Mirrored Sky box
	glDisable(GL_FOG); // the sky box should not be affected by fog
	setMaterialAdvanced(materialSkyBox); // This allows sets the skybox to a bright emissive material displaying no shading

	glTranslatef(camx, camy, camz);
	glScalef(2000, -2000, -2000);
	glCallList(meshSkyBox);
	glScalef(1.0 / 2000, -1.0 / 2000, -1.0 / 2000);
	glTranslatef(-camx, -camy, -camz);
	glEnable(GL_FOG);

	// End of mirrored objects display

	


	











	//glDisable(GL_FOG);

	// STENCIL-STEP 4. disable it
	glDisable(GL_STENCIL_TEST);

	glEnable(GL_BLEND);
	//glDisable(GL_LIGHTING);
	//disableLights();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);


	//glDepthMask(GL_DEPTH_WRITEMASK);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, rgba);
	//glColor4f(0.7, 0.0, 0.0, 0.3);
	//glColor4f(1.0, 1.0, 1.0, 0.3);
	setMaterialAdvanced(matarialAlpha1); // sets a transparent material
	//glColor4f(0.0, 0.0, 0.0, 0.9);
	glPushMatrix();

	//glTranslatef(0, 0, 60);
	//glScalef(1.0, 1.0, -1.0);
	//glTranslatef(-900, 0, -900);
	glCallList(meshq3MirrorPlane);
	//glScalef(1.0, 1.0, -1.0);
	//glTranslatef(0, 0, -60);

	//glCallList(display1);
	glPopMatrix();
	//glEnable(GL_LIGHTING);
	//glDisable(GL_BLEND); // fixed map



	//glPushMatrix();

	// ===== 3D ENVIRONMENT AS USUAL ==================================================================

	/*
	//plane
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.7, 0.0, 0.0, 0.3);
	glColor4f(1.0, 1.0, 1.0, 0.3);
	glPushMatrix();
	glTranslatef(-900, 0, -900);
	glCallList(display1);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	// box 1
	glPushMatrix();
	glCallList(display2);
	glPopMatrix();
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
	// end

	/*
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
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	*/


















	





	// New Skybox 8/28 - Quiz 1 SER 431
	glDisable(GL_FOG); // the sky box should not be affected by fog
	setlight(); // this allows the sky box to be visible
	setMaterialAdvanced(materialSkyBox); // This allows sets the skybox to a bright emissive material displaying no shading

	glTranslatef(camx, camy, camz);
	glScalef(2002, -2002, 2002);
	glCallList(meshSkyBox);
	glScalef(1.0 / 2002, -1.0 / 2002, 1.0 / 2002);
	glTranslatef(-camx, -camy, -camz);


	// blue atmospheric fog
	glEnable(GL_FOG);
	/*
	GLfloat color[4] = { 0.75f, 0.8f, 1.0f, 1.0f };
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_START, 1);
	glFogf(GL_FOG_END, 50.0);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, .02);
	*/



	disableLights();

	// displays the bounding boxes for object collision
	actionBoundingBoxes();

	// Draw & Implement Health packs
	actionHealthPacks(); // TODO: Replace health packs with heart model



	// Use Lighting for other objects
	setlight();
	if (SmoothingSetting == 1) {
		glShadeModel(GL_SMOOTH);
	}
	else {
		glShadeModel(GL_FLAT);
	}


	// TODO: Replace door models with higher quality dungeon doors
	// Draw & Animate doorways & keys
	actionDoorway();

	setMaterialAdvanced(materialGold);
	actionKeys();

	setMaterialAdvanced(materialRuby);
	actionGems();

	//setMaterialAdvanced(materialChrome);
	// Replace portals with better models, and add special effects/particles
	setMaterialAdvanced(materialRuby);
	actionPortals();



	// Draw & Implement Spin Spikes
	//setmaterial2(0.01f, 0.12, 0.1, 0.1, 2);
	setMaterialAdvanced(materialSpinSpike);
	actionSpinSpikes();


	// Draws the room/environment
	//setmaterial2(0.1f, 0.35, 0.34, 0.3, 0.1);
	setMaterialAdvanced(materialCastle); // Intro to graphics 332 map
	//glCallList(displayListMaterialTest1);

	 // Intro to graphics 332 map
	glCallList(meshFloor);
	//glCallList(meshWall);
	

	


	// Quiz 2- SER 431 - Terrain, Perlin Noise, and rotating box

	ImprovedNoise noise; // modified for terrain
	Vec3f pixelColor; // modified for terrain

	// Oribit box on terrain
	float aBoxX = sin(clock() / 1000.0f) * 10.0f+50.0f;
	float aBoxZ = cos(clock() / 1000.0f) * 10.0f;


	pixelColor = marbleMap(t_scale(noise.perlinMarble((aBoxX + 128)*10.0f, (aBoxZ + 128)*10.0f)));
	glTranslatef(aBoxX, (pixelColor[0] * 400.0f - 100.0f)*0.01f - 5.0f, aBoxZ);
	glCallList(meshABox);
	glTranslatef(-aBoxX, -((pixelColor[0] * 400.0f - 100.0f)*0.01f - 5.0f), -aBoxZ);



	// Terrain Collision with the camera
	pixelColor = marbleMap(t_scale(noise.perlinMarble((camx + 128)*10.0f, (camz + 128)*10.0f))); // terrain height / pixel brightness using marble texture
	if (camy < (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f) {
		camy = (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f;
		canJump = true;
	}

	// camera box
	glTranslatef( camx,  camy - 1.0f,  camz);
	glScalef(0.5f, 0.5f, 0.5f);
	glCallList(meshABox);
	glScalef(2.0f, 2.0f, 2.0f);
	glTranslatef(-camx, -camy + 1.0f, -camz);


	// TERRAIN Display
	setMaterialAdvanced(materialSpinSpike); // this shading works ok for the terrain
	glTranslatef(0.0f, -15, 0.0f);
	displayNoiseGenPlane(); //Displays the terrain
	glTranslatef(0.0f, 15, 0.0f);


	// LAVA MOUNTAIN Display
	setMaterialAdvanced(materialSkyBox); //emissive lava
	glTranslatef(0.0f, -150.0f, 0.0f);
	glScalef(100.0f, 100.0f, 100.0f);
	displayNoiseGenLavaPlane(); // displays lava
	glScalef(0.01f, 0.01f, 0.01f);
	glTranslatef(0.0f, 150.0f, 0.0f);


	setMaterialAdvanced(materialCastle); // material for boxes
	glTranslatef(0.0f, 1.0, 25);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox1(); // wood box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(0.0f, -1.0, -25);

	glTranslatef(2.0f, 1.0, 25);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox2(); // clouds box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(-2.0f, -1.0, -25);

	glTranslatef(-2.0f, 1.0, 25);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox3(); // lava box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(2.0f, -1.0, -25);

	/*
	glTranslatef(200.0f, 0, 0);
	displayNoiseGenBox2(); // clouds box
	glTranslatef(-400.0f, 0, 0);
	displayNoiseGenBox3(); // lava box
	glScalef(100.0f, 100.0f, 100.0f);
	*/
	


	/*
	setMaterialAdvanced(materialCastle); // material for boxes
	glScalef(0.01f, 0.01f, 0.01f);
	glTranslatef(0.0f, 100.0f, 2950-500);
	displayNoiseGenBox1(); // wood box
	glTranslatef(200.0f, 0, 0);
	displayNoiseGenBox2(); // clouds box
	glTranslatef(-400.0f, 0, 0);
	displayNoiseGenBox3(); // lava box
	glTranslatef(200.0f, -100.0f, -2950+500);
	glScalef(100.0f, 100.0f, 100.0f);
	*/
	


	// Displays the room walls
	setMaterialAdvanced(materialObsidian);
	glCallList(meshq3MirrorRoom);
	





















	// Mirrored Camera Box
	/*
	glTranslatef(camx, camy - 1.0f, -camz+60.0f);
	glScalef(0.5f, 0.5f, -0.5f);
	glCallList(meshABox);
	glScalef(2.0f, 2.0f, -2.0f);
	glTranslatef(-camx, -camy + 1.0f, camz - 60.0f);
	*/

	// mirrored boxes
	/*
	glScalef(0.01f, 0.01f, -0.01f);
	glTranslatef(0.0f, 100.0f, -2950-500);
	displayNoiseGenBox1(); // wood box
	glTranslatef(200.0f, 0, 0);
	displayNoiseGenBox2(); // clouds box
	glTranslatef(-400.0f, 0, 0);
	displayNoiseGenBox3(); // lava box
	glTranslatef(200.0f, -100.0f, 2950+500);
	glScalef(100.0f, 100.0f, -100.0f);
	*/


























	/*
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	*/

	/*
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
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	*/



	/*
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	*/


	// needs transparency and stencil stuff
	//glCallList(meshq3MirrorPlane);





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

	glutCreateWindow("Quiz 3 - SER 431");

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

