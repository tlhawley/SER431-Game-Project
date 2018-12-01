

// Functions used for loading environments
// Reset and load level data

void objInit();
void loadLevel(int mapID);
void objLoadInit();




// Loads Models & Textures & Intro music
void objLoadInit() {

	loadModels();

	// Source: http://soundbible.com/1818-Rainforest-Ambience.html
	SoundEngine->play2D("./src/audio/rainforest_ambience-GlorySunz-1938133500.mp3", GL_TRUE);
	SoundEngine->setSoundVolume(0.5);
}




// resets the cameras starting position, and other common variables such as health, and timer
// Initializes game objects and noiseGen
void objInit() {


	if (lockMouse == true) { 
		glutSetCursor(GLUT_CURSOR_NONE);
		mouseOX = width / 2;
		mouseOY = height / 2;
		mouseX = mouseOX;
		mouseY = mouseOY;
		glutWarpPointer(width / 2, height / 2);
	}

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
	initFractals();
	initFlags();
	initHealthPacks();
	initSpinSpikes();
	initCBoxes();
	initDoorway();
	initKeys();
	initGems();
	initPortals();
	initBoundingBoxes();
	initBaseModels();
	initPointLights();
	initMovingPlatforms();

}

// loads a new level
void loadLevel(int mapID) {

	if (mapID == -1) {
		frameTimer = 0; // camera hermite curve animation on startup
	}
	else {
		frameTimer = 10000;
	}

	SoundEngine->stopAllSounds();
	SoundEngine->removeAllSoundSources();
	SoundEngine->update();
	SoundEngine->setSoundVolume(0.5);


	// Loads sound background music based on what level environment
	if (mapID == -1) {
		// Source: http://soundbible.com/1818-Rainforest-Ambience.html
		SoundEngine->play2D("./src/audio/rainforest_ambience-GlorySunz-1938133500.mp3", GL_TRUE);
	}
	if (mapID == 0) {
		// Source: https://opengameart.org/content/hypnotic-chill-extended-4-minute-mix
		SoundEngine->play2D("./src/audio/2010_June_HypnoticChill_17.mp3", GL_TRUE);
	}
	if (mapID >= 1) {
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
	initFractals();
	initFlags();
	initHealthPacks();
	initSpinSpikes();
	initCBoxes();
	initDoorway();
	initKeys();
	initGems();
	initPortals();
	initBoundingBoxes();
	initBaseModels();
	initPointLights();
	initMovingPlatforms();

}