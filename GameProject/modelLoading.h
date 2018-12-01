
GLuint2 displayListMaterialTest1;
GLuint2 displayListClockFrame;
GLuint2 displayListClockWhite;
GLuint2 meshSpikes;

GLuint2 meshDoorFrame;
GLuint2 meshDoorLeft;
GLuint2 meshDoorRight;
GLuint2 meshDoorLock;

GLuint2 meshRoomWall1;
GLuint2 meshRoomWall2;

GLuint2 meshBox;

GLuint2 meshGem;
GLuint2 meshKey;
GLuint2 meshPorsche;
GLuint2 meshAL;

GLuint2 meshGear1;
GLuint2 meshGear2;

GLuint2 meshPortal;
GLuint2 meshPortalClosed;

GLuint2 meshFloor;
GLuint2 meshWall;

GLuint2 meshSkyBox;

GLuint2 meshBench;
GLuint2 meshChair;
GLuint2 hangingLamp;
GLuint2 hangingLampE;
GLuint2 meshCouch;
GLuint2 meshDesk;


GLuint2 meshABox;

GLuint2 meshq3MirrorRoom;
GLuint2 meshq3MirrorPlane;

GLuint2 meshTree;
GLuint2 meshGrassCluster;


GLuint2 meshStar;
GLuint2 meshBigRock;
GLuint2 meshQ4Map;

GLuint2 meshLightBulb;

GLuint2 meshBulb;

GLuint2 meshCharacterFrames[31];


// Level S - Forest Grass
GLuint2 meshLV1ForestGrass;
// Level S - Forest Trees
GLuint2 meshLV1ForestTrees;
// Level S - Forest Rocks
GLuint2 meshLV1Rocks;
// Level S - Structures
GLuint2 meshLV1Structures;
// Level S - Floor
GLuint2 meshLV1Floor;
// Level S - Map UI
GLuint2 meshLVSMapUI;
// Level S - Background Rocks
GLuint2 meshLV1BackgroundRocks;
GLuint2 meshLV1WaterMirror;


GLuint2 meshHeartUI[5];

GLuint2 meshHeart;

GLuint2 meshHubWalls;

GLuint2 meshLVHMapUI;


GLuint2 meshLV1MapUI;
GLuint2 meshLV1;
GLuint2 meshLV2MapUI;
GLuint2 meshLV2;
GLuint2 meshLV3MapUI;
GLuint2 meshLV3;

GLuint2 meshMovingPlatform;

GLuint2 meshFireball;

GLuint2 displayParticlePlane, displayParticlePlaneFlames, displayParticlePlaneSnow, displayParticlePlaneBubbles,
displayParticlePlaneAsh, displayParticlePlaneWaterfallSub, displayParticlePlaneLeaves, displayParticlePlaneFlameSparks, displayParticleRain, displayParticlePlaneRing;




int uniqueMeshID = 0;

void loadModels();
void drawGear1();
void drawGear2();


GLuint2 loadObj(char const* file, GLuint textureID);

GLuint blankTexture;

// Function used to simplify loading objects and reduce repetitive code
GLuint2 loadObj(char const* file, GLuint textureID) {
	Mesh* aMesh = loadFile(file);
	if (aMesh == NULL) exit(1);
	uniqueMeshID = uniqueMeshID + 2;
	return meshToDisplayList(aMesh, uniqueMeshID, textureID, blankTexture);
}

// Function used for loading a mesh and returning the mesh instead of the meshID / displayListID
Mesh* loadObjMesh(char const* file) {
	Mesh* aMesh = loadFile(file);
	if (aMesh == NULL) exit(1);
	return aMesh;
}


Mesh* meshParticlePlane;
Mesh* meshParticleRain;


// 3, 22, 23 - null

void loadModels() {

	printf("Loading\n");

	GLuint texture_array[44];
	loadBMP_custom(texture_array, "./src/textures/nullTexture.bmp", 0, 1, 0);
	blankTexture = texture_array[0];

	loadBMP_custom(texture_array, "./src/textures/nullTexture.bmp", 1, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/Spikes.bmp", 2, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/door.bmp", 5, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/gateTexture.bmp", 6, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/SkyBox.bmp", 9, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/TreeTexture.bmp", 10, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/GrassClusterTexture.bmp", 11, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LightBulbTexture.bmp", 13, 1, 0);

	loadBMP_custom(texture_array, "./src/textures/LVSFloor.bmp", 14, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LVSRocks.bmp", 15, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LVSStructures.bmp", 16, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LVSMapUI.bmp", 17, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LVSBackgroundRocks.bmp", 19, 1, 0);

	loadBMP_custom(texture_array, "./src/textures/HeartsUI.bmp", 18, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/CharacterTexture.bmp", 20, 1, 0);
	

	// particle images
	loadBMP_custom(texture_array, "./src/textures/Particle Images/smoke.bmp", 21, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/flame05.bmp", 23, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/snowflake.bmp", 24, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/bubble.bmp", 25, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/particle3.bmp", 26, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/waterFallSub.bmp", 27, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/leaf.bmp", 28, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/flame01.bmp", 29, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/gradient.bmp", 30, 1, 1);
	loadBMP_custom(texture_array, "./src/textures/Particle Images/ring.bmp", 31, 1, 1);

	loadBMP_custom(texture_array, "./src/textures/HeartTexture.bmp", 32, 1, 0);

	loadBMP_custom(texture_array, "./src/textures/hubWallTexture.bmp", 33, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/PortalTexture.bmp", 34, 1, 0);
	
	loadBMP_custom(texture_array, "./src/textures/HubMapUI.bmp", 35, 1, 0);

	loadBMP_custom(texture_array, "./src/textures/LV01_map512.bmp", 36, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LV1Texture.bmp", 37, 1, 0);


	loadBMP_custom(texture_array, "./src/textures/movingPlatform.bmp", 38, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/Fireball.bmp", 39, 1, 0);


	loadBMP_custom(texture_array, "./src/textures/LV2Texture.bmp", 40, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LV02_map512.bmp", 41, 1, 0);
	

	loadBMP_custom(texture_array, "./src/textures/LV03Texture.bmp", 42, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/LV03_map.bmp", 43, 1, 0);



	// Load particle mesh & images
	meshParticlePlane = loadObjMesh("./src/obj files/ParticlePlane.obj");
	meshParticleRain = loadObjMesh("./src/obj files/ParticleRain.obj");
	
	displayParticlePlane = loadObj("./src/obj files/ParticlePlane.obj", texture_array[21]);
	displayParticlePlaneFlames = loadObj("./src/obj files/ParticlePlane.obj", texture_array[23]);
	displayParticlePlaneSnow = loadObj("./src/obj files/ParticlePlane.obj", texture_array[24]);
	displayParticlePlaneBubbles = loadObj("./src/obj files/ParticlePlane.obj", texture_array[25]);
	displayParticlePlaneAsh = loadObj("./src/obj files/ParticlePlane.obj", texture_array[26]);
	displayParticlePlaneWaterfallSub = loadObj("./src/obj files/ParticlePlane.obj", texture_array[27]);
	displayParticlePlaneLeaves = loadObj("./src/obj files/ParticlePlane.obj", texture_array[28]);
	displayParticlePlaneFlameSparks = loadObj("./src/obj files/ParticlePlane.obj", texture_array[29]);
	displayParticleRain = loadObj("./src/obj files/ParticleRain.obj", texture_array[30]);
	displayParticlePlaneRing = loadObj("./src/obj files/ParticlePlane.obj", texture_array[31]);

	meshSpikes = loadObj("./src/obj files/Spikes2.obj", texture_array[2]);

	meshDoorFrame = loadObj("./src/obj files/Gate.obj", texture_array[6]);

	meshBox = loadObj("./src/obj files/box.obj", texture_array[0]);

	meshGem = loadObj("./src/obj files/Gem.obj", texture_array[0]);

	meshKey = loadObj("./src/obj files/Key.obj", texture_array[0]);

	meshSkyBox = loadObj("./src/obj files/CubeMap.obj",texture_array[9]);

	meshABox = loadObj("./src/obj files/aBox.obj", texture_array[1]);

	meshTree = loadObj("./src/obj files/LowPolyTree.obj", texture_array[10]);

	meshGrassCluster = loadObj("./src/obj files/GrassCluster.obj", texture_array[11]);

	meshLightBulb = loadObj("./src/obj files/LightBulb.obj", texture_array[13]);

	meshMovingPlatform = loadObj("./src/obj files/MovingPlatform.obj", texture_array[38]);

	meshFireball = loadObj("./src/obj files/Fireball.obj", texture_array[39]);

	// Level 1 - Forest Trees
	meshLV1ForestTrees = loadObj("./src/obj files/LV1Trees.obj", texture_array[10]);
	// Level 1 - Forest Rocks
	meshLV1Rocks = loadObj("./src/obj files/LV1Rocks.obj", texture_array[15]);
	// Level 1 - Structures
	meshLV1Structures = loadObj("./src/obj files/LV1Structures.obj", texture_array[16]);
	// Level 1 - Floor
	meshLV1Floor = loadObj("./src/obj files/LV1Floor.obj", texture_array[14]);
	// Level 1 - Map UI
	meshLVSMapUI = loadObj("./src/obj files/LV1MapUI.obj", texture_array[17]);
	// Level 1 - Background Rocks
	meshLV1BackgroundRocks = loadObj("./src/obj files/LV1BackgroundRocks.obj", texture_array[19]);
	meshLV1WaterMirror = loadObj("./src/obj files/LV1WaterMirror.obj", texture_array[0]);

	
	// character animation frames
	meshCharacterFrames[0] = loadObj("./src/obj files/CharacterStanding01.obj", texture_array[20]);
	for (int i = 1; i < 26; i++) {
		std::string str = "./src/obj files/CharacterRun/Main Character _ Pose_Run_B" + std::to_string(i) + ".obj";
		const char * c = str.c_str();
		meshCharacterFrames[i] = loadObj(c, texture_array[20]);
	}
	for (int i = 1; i < 6; i++) {
		std::string str = "./src/obj files/CharacterJump/Main Character _ Pose_Jump_B" + std::to_string(i) + ".obj";
		const char * c = str.c_str();
		meshCharacterFrames[i+25] = loadObj(c, texture_array[20]);
	}
	
	
	// heart UI models
	meshHeartUI[0] = loadObj("./src/obj files/HeartUI01.obj", texture_array[18]);
	meshHeartUI[1] = loadObj("./src/obj files/HeartUI02.obj", texture_array[18]);
	meshHeartUI[2] = loadObj("./src/obj files/HeartUI03.obj", texture_array[18]);
	meshHeartUI[3] = loadObj("./src/obj files/HeartUI04.obj", texture_array[18]);
	meshHeartUI[4] = loadObj("./src/obj files/HeartUI05.obj", texture_array[18]);
	
	// heart model
	meshHeart = loadObj("./src/obj files/Heart.obj", texture_array[32]);

	meshHubWalls = loadObj("./src/obj files/hubWalls.obj", texture_array[33]);

	meshPortal = loadObj("./src/obj files/portal.obj", texture_array[34]);
	meshPortalClosed = loadObj("./src/obj files/portalClosed.obj", texture_array[34]);
	
	meshLVHMapUI = loadObj("./src/obj files/hubMapUI01.obj", texture_array[35]);




	//LV 1 map
	meshLV1MapUI = loadObj("./src/obj files/Level01UIMap.obj", texture_array[36]);
	meshLV1 = loadObj("./src/obj files/Level01.obj", texture_array[37]);


	//LV 2 Map
	meshLV2 = loadObj("./src/obj files/Level02.obj", texture_array[40]);
	meshLV2MapUI = loadObj("./src/obj files/Level02_Map.obj", texture_array[41]);

	//LV 3 Map
	meshLV3 = loadObj("./src/obj files/Level03.obj", texture_array[42]);
	meshLV3MapUI = loadObj("./src/obj files/Level03_Map.obj", texture_array[43]);

}









void swapLists() {

	displayParticlePlane=swapGLuint2(displayParticlePlane);

	displayParticlePlaneFlames=swapGLuint2(displayParticlePlaneFlames);

	displayParticlePlaneSnow=swapGLuint2(displayParticlePlaneSnow);

	displayParticlePlaneBubbles=swapGLuint2(displayParticlePlaneBubbles);

	displayParticlePlaneAsh=swapGLuint2(displayParticlePlaneAsh);

	displayParticlePlaneWaterfallSub=swapGLuint2(displayParticlePlaneWaterfallSub);

	displayParticlePlaneLeaves=swapGLuint2(displayParticlePlaneLeaves);

	displayParticlePlaneFlameSparks=swapGLuint2(displayParticlePlaneFlameSparks);

	displayParticleRain=swapGLuint2(displayParticleRain);

	displayParticlePlaneRing=swapGLuint2(displayParticlePlaneRing);



	meshSpikes=swapGLuint2(meshSpikes);

	meshDoorFrame=swapGLuint2(meshDoorFrame);


	meshBox=swapGLuint2(meshBox);


	meshGem=swapGLuint2(meshGem);

	meshKey=swapGLuint2(meshKey);


	meshSkyBox=swapGLuint2(meshSkyBox);

	meshABox=swapGLuint2(meshABox);

	meshTree=swapGLuint2(meshTree);

	meshGrassCluster=swapGLuint2(meshGrassCluster);

	meshLightBulb=swapGLuint2(meshLightBulb);


	meshMovingPlatform=swapGLuint2(meshMovingPlatform);

	meshFireball=swapGLuint2(meshFireball);


	meshLV1ForestTrees=swapGLuint2(meshLV1ForestTrees);
	meshLV1Rocks=swapGLuint2(meshLV1Rocks);
	// Level 1 - Structures
	meshLV1Structures=swapGLuint2(meshLV1Structures);
	// Level 1 - Floor
	meshLV1Floor=swapGLuint2(meshLV1Floor);
	// Level 1 - Map UI
	meshLVSMapUI=swapGLuint2(meshLVSMapUI);
	// Level 1 - Background Rocks
	meshLV1BackgroundRocks=swapGLuint2(meshLV1BackgroundRocks);
	meshLV1WaterMirror=swapGLuint2(meshLV1WaterMirror);





	meshCharacterFrames[0]=swapGLuint2(meshCharacterFrames[0]);
	for (int i = 1; i < 26; i++) {
		meshCharacterFrames[i]=swapGLuint2(meshCharacterFrames[i]);
	}
	for (int i = 1; i < 6; i++) {
		meshCharacterFrames[i + 25]=swapGLuint2(meshCharacterFrames[i + 25]);
	}



	// heart UI models
	meshHeartUI[0]=swapGLuint2(meshHeartUI[0]);
	meshHeartUI[1]=swapGLuint2(meshHeartUI[1]);
	meshHeartUI[2]=swapGLuint2(meshHeartUI[2]);
	meshHeartUI[3]=swapGLuint2(meshHeartUI[3]);
	meshHeartUI[4]=swapGLuint2(meshHeartUI[4]);

	// heart model
	meshHeart=swapGLuint2(meshHeart);

	meshHubWalls=swapGLuint2(meshHubWalls);

	meshPortal=swapGLuint2(meshPortal);
	meshPortalClosed = swapGLuint2(meshPortalClosed);

	meshLVHMapUI = swapGLuint2(meshLVHMapUI);




	//LV 1 map
	meshLV1MapUI = swapGLuint2(meshLV1MapUI);
	meshLV1 = swapGLuint2(meshLV1);
	//LV 2 map
	meshLV2MapUI = swapGLuint2(meshLV2MapUI);
	meshLV2 = swapGLuint2(meshLV2);
	//LV 3 map
	meshLV3MapUI = swapGLuint2(meshLV3MapUI);
	meshLV3 = swapGLuint2(meshLV3);
	
}

GLuint2 swapGLuint2(GLuint2 list) {
	GLuint temp = list.l1;
	list.l1 = list.l2;
	list.l2 = temp;
	return list;
}


void drawGear1() {
	glCallList(meshGear1.l1);
}

void drawGear2() {
	glCallList(meshGear2.l1);
}