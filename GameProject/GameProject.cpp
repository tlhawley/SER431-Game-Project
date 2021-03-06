/*
Name		: Project 431 - Milestone 2
Authors		: Michael Webber, Travis Hawley, Cory Dianovich
Version		: 11/10/18
Copyright	: © 2018


Description	:
	This is milestone 2 of our game project
	Building off of last semesters projects and quizzes + quizzes and hw from this class...
	We have build a third person platform adventure game.
	
Current Features:
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
	
Future Goals:
	more levels with platform & combat gameplay
	enemies with simple AI
	moving platforms
	bug fixes
	video demo


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








// curve variables
float box1X = -15;
float box1Y = 10;
float box1Z = 80;

float box2X = 0;
float box2Y = 1.5;
float box2Z = 0;

float Geometry[4][3] = {
	{ box1X, box1Y, box1Z },  //  Point 1
{ box2X,  box2Y, box2Z },	  //	Point2
{ 0,  0, -50 },	  //	Tangent1
{ -70,   0, 0 }		//	Tangent2
};
unsigned int N = 800;


int camTimer = 0; //used for camera hermite curve animation on startup




// Custom .h files
#include "gameProjectHeaders.h"








void objLoadInit() {

	// Textures
	//texture_from_file(&texture_array[0], "image.bmp"); // 2Do add this function to imported files

	// Models
	loadModels();
	//quiz6Init(); // Project3

	// Source: http://soundbible.com/1818-Rainforest-Ambience.html
	SoundEngine->play2D("./src/audio/rainforest_ambience-GlorySunz-1938133500.mp3", GL_TRUE);
	SoundEngine->setSoundVolume(0.5);

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

	playerAngle = 1.7f;

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

// loads a new level
void loadLevel(int mapID) {

	if (mapID == -1) {
		camTimer = 0; // camera hermite curve animation on startup
	}
	else {
		camTimer = 10000;
	}

	SoundEngine->stopAllSounds();
	SoundEngine->removeAllSoundSources();
	SoundEngine->update();
	SoundEngine->setSoundVolume(0.5);


	if (mapID == -1) {
		// Source: http://soundbible.com/1818-Rainforest-Ambience.html
		SoundEngine->play2D("./src/audio/rainforest_ambience-GlorySunz-1938133500.mp3", GL_TRUE);
	}
	if (mapID == 0) {
		// Source: https://opengameart.org/content/hypnotic-chill-extended-4-minute-mix
		SoundEngine->play2D("./src/audio/2010_June_HypnoticChill_17.mp3", GL_TRUE);
	}
	if (mapID == 1) {
		// Source: https://opengameart.org/content/boss-battle-music
		SoundEngine->play2D("./src/audio/Juhani Junkala - Epic Boss Battle [Seamlessly Looping].wav", GL_TRUE);
	}

	// reset global variables

	currentLevel = mapID;

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

	//health = 20;
	takingDamage = 0;
	mouseMoveX = 0; mouseMoveY = 0;

	playerAngle = 1.7f;

	// reset the camera orientation
	orientMe(camAngY);
	orientMe2(camAngX);

	clockOffset = clock(); // reset the clock timer

	//score = 0; // reset the score
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


int frameTimer = 0;

// display
void myDisplay(void) {

	clockTime = clock() - clockOffset;
	clockSeconds = (int)clockTime / 1000;
	frameTimer = frameTimer + 1;

	// 2D Graphics
	disableLights();

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	if (buttons[3].toggle == false) {

		// Display debug info
		char msgXYZ[150];
		//camAngY = 1/57.3; //1.57 = 90
		// Debug Text
		//sprintf_s(msgXYZ, "CAY: %f   CAX: %f   MMX: %d   MMY: %d   X: %f   Y: %f   Z: %f", camAngY, camAngX, mouseMoveX, mouseMoveY, camx, camy, camz);
		// Controls
		sprintf_s(msgXYZ, "f11 - toggle fullscreen       asdw & arrowkeys movement       mouse to look       space to jump.  %d", clockTime);
		//sprintf_s(msgXYZ, "MX: %f, MY: %f, W0.2: %f",(float)mouseX/(float)width, (float)(height-mouseY-width*0.2), (float)width * 0.2);
		//height - mouseY - width * 0.04
		glColor3f(1, 1, 1);
		renderBitmapString(-7.0, -9.0, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
		glColor3f(0.0, 0.0, 0.0);
		renderBitmapString(-6.97, -9.03, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"

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
	//toggleSprint();
	if (displayMenu == true)
	{
		displayButtonUI();
	}

	// 3D Graphics
	setUp3DView();

	// Controls & Camera Positioning
	// Updates the camera location and angle based on the users input


	//Update(); // Located in controls.h
	float number = cos(camAngX)*2.0f;
	float llx = sin(camAngY)*number;
	float llz = -cos(camAngY)*number;
	float lly = sin(camAngX)*2.0f - 0.15f;
	glTranslatef(llx, lly, llz);


	// Terrain Collision with the camera
	if (currentLevel == 0) {
		ImprovedNoise noise; // modified for terrain
		Vec3f pixelColor; // modified for terrain
		pixelColor = marbleMap(t_scale(noise.perlinMarble((camx + 128)*10.0f, (camz + 128)*10.0f))); // terrain height / pixel brightness using marble texture
		if (camy < (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f) {
			camy = (pixelColor[0] * 400.0f - 100.0f)*0.01f - 4.0f;
			camyv = 0;
			jumpFrame = 0;
			canJump = true;
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
		//glFogf(GL_FOG_START, 1);
		//glFogf(GL_FOG_END, 50.0);
		glFogi(GL_FOG_MODE, GL_EXP);
		glFogf(GL_FOG_DENSITY, .003);
	}

	/*
	pointLights[0].x = sin(clock()/1000.0f)*4.0f;
	pointLights[0].y = 4.0f;
	pointLights[0].z = -5.0f;
	*/
	/*
	pointLights[0].x = camx; // +sin(clock() / 1000.0f)*4.0f;
	pointLights[0].y = camy;
	pointLights[0].z = camz+4.0f; // +cos(clock() / 1000.0f)*4.0f;
	*/
	setlight();

	//glShadeModel(GL_SMOOTH);
	//glDepthFunc(GL_LEQUAL);
	//glEnable(GL_DEPTH_TEST);

	// Reflections
	if (buttons[6].toggle == true) {
		if (currentLevel == -1) {
			reflection(drawMirror1, pos, mirrorDir);
		}
	}

	displaySkyBox(2001, 90, 0);

	
	if (buttons[1].toggle == true) {
		disableLights();
		actionBoundingBoxes(); // displays the bounding boxes for object collision
		setlight();
	}
	
	actionGems();
	actionSpinSpikes();
	actionHealthPacks(); // Health packs need to be replaced with heart models
	//actionBaseModels(); // no action for baseModels they are only for display in the environment
	

	// Use Lighting
	
	if (SmoothingSetting == 1) { glShadeModel(GL_SMOOTH); }
	else { glShadeModel(GL_FLAT); }

	if (camTimer >= N) {
		glPushMatrix();
		setMaterialAdvanced(materialPlayer);
		glTranslatef(camx, camy, camz);
		//glRotatef(rotateX, 1.0, 0.0, 0.0);
		glRotatef(-camAngY * 57.29578f + 180, 0.0, 1.0, 0.0);
		glRotatef(playerAngle * 57.29578f - 90, 0.0, 1.0, 0.0);
		//glRotatef(rotateZ, 0.0, 0.0, 1.0);
		if (pxv == 0 && pzv == 0) {

			if (canJump == true){
				glCallList(meshCharacterFrames[0]); // standing animation
			}
			else {
				if (jumpFrame == 0) {
					glCallList(meshCharacterFrames[26]); // jump start frame
				}
				else {
					if (jumpFrame > 0 && jumpFrame < 4) {
						glCallList(meshCharacterFrames[27]); // jump attack frame 1
					}
					else {
						if (jumpFrame < 18) {
							
							glRotatef(jumpFrame*35.0f, 1.0, 0.0, 0.0);
							glTranslatef(0, 0.5f, 0);
							glCallList(meshCharacterFrames[28]); // jump attack spin frame
							glTranslatef(0, -0.5f, 0);
							glRotatef(-jumpFrame * 35.0f, 1.0, 0.0, 0.0);
						}
						else {
							if (jumpFrame < 20) {
								glCallList(meshCharacterFrames[29]);
							}
							else {
								//jumpFrame = 0;
								camyv = camyv - 0.01f; // doubles y velocity acceleration when in attack mode
								glCallList(meshCharacterFrames[30]);
							}
						}
					}
				}
			}
			runFrame = 1;
			if (itemTimer > 0 && heartPickUp) {
				setMaterialAdvanced(materialHeart);
				//glTranslatef(0, 0.1, 0);
				glScalef(0.5f, 0.5f, 0.5f);
				glCallList(meshHeart);
				glScalef(2.0f, 2.0f, 2.0f);
				//glTranslatef(0, -0.1, 0);
			}
			else if (itemTimer > 0 && gemPickUp) {
				setMaterialAdvanced(materialRuby);
				//glTranslatef(0, 0.1, 0);
				glScalef(0.5f, 0.5f, 0.5f);
				glCallList(meshGem);
				glScalef(2.0f, 2.0f, 2.0f);
				//glTranslatef(0, -0.1, 0);
			}
		}
		else {
			//glTranslatef(0, sin(clockTime / 360.0f)*0.1f+.1f, 0);
			//if (frameTimer % 2 == 0) { runFrame = runFrame + 1; }
			runFrame = runFrame + 1;
			if (runFrame > 25) { runFrame = 1; }
			if (canJump == true) {
				glCallList(meshCharacterFrames[runFrame]);
			}
			else {
				if (jumpFrame == 0) {
					glCallList(meshCharacterFrames[26]); // jump start frame
				}
				else {
					if (jumpFrame > 0 && jumpFrame < 4) {
						glCallList(meshCharacterFrames[27]); // jump attack frame 1
					}
					else {
						if (jumpFrame < 18) {
							glRotatef(jumpFrame*35.0f, 1.0, 0.0, 0.0);
							glTranslatef(0, 0.5f, 0);
							glCallList(meshCharacterFrames[28]); // jump attack spin frame
							glTranslatef(0, -0.5f, 0);
							glRotatef(-jumpFrame * 35.0f, 1.0, 0.0, 0.0);
						}
						else {
							if (jumpFrame < 20) {
								glCallList(meshCharacterFrames[29]);
							}
							else {
								//jumpFrame = 0;
								camyv = camyv - 0.01f; // doubles y velocity acceleration when in attack mode
								glCallList(meshCharacterFrames[30]);
							}
						}
					}
				}
			}
			if (itemTimer > 0 && heartPickUp) {
				setMaterialAdvanced(materialHeart);
				//glTranslatef(0, 0.1, 0);
				glScalef(0.5f, 0.5f, 0.5f);
				glCallList(meshHeart);
				glScalef(2.0f, 2.0f, 2.0f);
				//glTranslatef(0, -0.1, 0);
			}
			else if (itemTimer > 0 && gemPickUp) {
				setMaterialAdvanced(materialRuby);
				//glTranslatef(0, 0.1, 0);
				glScalef(0.5f, 0.5f, 0.5f);
				glCallList(meshGem);
				glScalef(2.0f, 2.0f, 2.0f);
				//glTranslatef(0, -0.1, 0);
			}
			//glTranslatef(0, -sin(clockTime / 360.0f)*0.1f+.1f, 0);
		}

		//glRotatef(-rotateZ, 0.0, 0.0, 1.0);
		glRotatef(-playerAngle * 57.29578f + 90, 0.0, 1.0, 0.0);
		glRotatef(camAngY * 57.29578f + 180, 0.0, 1.0, 0.0);
		//glRotatef(-rotateX, 1.0, 0.0, 0.0);
		glTranslatef(-camx, -camy, -camz);
		glPopMatrix();
	}
	else {
		setMaterialAdvanced(materialPlayer);
		glTranslatef(0, 1.5f, 0);
		glRotatef(-90, 0, 1, 0);
		glCallList(meshCharacterFrames[0]);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, -1.5f, 0);
	}

	// Displays everything in the environment, and every interactive game object
	displayEnvironment();
	displayGameObjects();

	// Draw particles last to avoid transparncy glitches

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // NOTE: Added for transparency
	//glEnable(GL_BLEND); // NOTE: Added for transparency

	glDisable(GL_CULL_FACE);
	//setMaterialAdvanced(materialEmissive);
	//setlightParticles();
	//setlight();
	disableLights();
	glEnable(GL_LIGHTING);

	if (buttons[2].toggle == true) {
		glPushMatrix();
		//ps.add(ParID::flame, 0, 1, 0);
		if (currentLevel == 0) {
			ps.add(ParID::fog, camx, -5, camz);
		}
		//ps.add(ParID::bubbles, 0, 0, 0);

		if (currentLevel == -1) {
			ps.add(ParID::flame, -189.8, 4.5, -21.6);
			ps.add(ParID::flame, -189.8, 4.5, -18.4);
		}
		actionParticleSystem();
		clearParticles = 0;
		glPopMatrix();
	}
	//glDisable(GL_CULL_FACE);

	// Draw boxes and calculate box collision
	actionCBoxes(); // Invisible Collision Boxes
	


	Geometry[0][0] = box1X;
	Geometry[0][1] = box1Y;
	Geometry[0][2] = box1Z;
	Geometry[1][0] = box2X;
	Geometry[1][1] = box2Y;
	Geometry[1][2] = box2Z;

	if (camTimer < N) {
		camTimer = camTimer + 1;
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

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutDisplayFunc(myDisplay);
	glutIdleFunc(myDisplay);
	glutReshapeFunc(myReshape);

	glutMainLoop();
	//system("pause");
	return(0);

}

