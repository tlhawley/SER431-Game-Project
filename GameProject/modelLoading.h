

//GLuint meshFloor;

GLuint displayListMaterialTest1;
GLuint displayListClockFrame;
GLuint displayListClockWhite;
GLuint meshSpikes;

GLuint meshDoorFrame;
GLuint meshDoorLeft;
GLuint meshDoorRight;
GLuint meshDoorLock;

GLuint meshRoomWall1;
GLuint meshRoomWall2;

GLuint meshBox;

//GLuint meshUIMap;
//GLuint meshUIMapH;

GLuint meshGem;
GLuint meshKey;
GLuint meshPorsche;
GLuint meshAL;

GLuint meshGear1;
GLuint meshGear2;

GLuint meshPortal;
GLuint meshPortalClosed;
//GLuint meshPortalE;
//GLuint meshPortalGlow;

GLuint meshFloor;
GLuint meshWall;

GLuint meshSkyBox;

GLuint meshBench;
GLuint meshChair;
GLuint hangingLamp;
GLuint hangingLampE;
GLuint meshCouch;
GLuint meshDesk;


GLuint meshABox;

GLuint meshq3MirrorRoom;
GLuint meshq3MirrorPlane;

GLuint meshTree;
GLuint meshGrassCluster;


GLuint meshStar;
GLuint meshBigRock;
GLuint meshQ4Map;

GLuint meshLightBulb;

GLuint meshBulb;

//GLuint meshCharacterStanding01;
//GLuint meshCharacterForward01;
GLuint meshCharacterFrames[31];


// Level S - Forest Grass
GLuint meshLV1ForestGrass;
// Level S - Forest Trees
GLuint meshLV1ForestTrees;
// Level S - Forest Rocks
GLuint meshLV1Rocks;
// Level S - Structures
GLuint meshLV1Structures;
// Level S - Floor
GLuint meshLV1Floor;
// Level S - Map UI
GLuint meshLVSMapUI;
// Level S - Background Rocks
GLuint meshLV1BackgroundRocks;
GLuint meshLV1WaterMirror;


GLuint meshHeartUI[5];

GLuint meshHeart;

GLuint meshHubWalls;

GLuint meshLVHMapUI;


GLuint meshLV1MapUI;
GLuint meshLV1;

GLuint displayParticlePlane, displayParticlePlaneFlames, displayParticlePlaneSnow, displayParticlePlaneBubbles,
displayParticlePlaneAsh, displayParticlePlaneWaterfallSub, displayParticlePlaneLeaves, displayParticlePlaneFlameSparks, displayParticleRain, displayParticlePlaneRing;




int uniqueMeshID = 0;

void loadModels();
void drawGear1();
void drawGear2();


GLuint loadObj(char const* file, GLuint textureID);

// Function used to simplify loading objects and reduce repetitive code
GLuint loadObj(char const* file, GLuint textureID) {
	Mesh* aMesh = loadFile(file);
	if (aMesh == NULL) exit(1);
	uniqueMeshID = uniqueMeshID + 1;
	return meshToDisplayList(aMesh, uniqueMeshID, textureID);
}

// Function used for loading a mesh and returning the mesh instead of the meshID / displayListID
Mesh* loadObjMesh(char const* file) {
	Mesh* aMesh = loadFile(file);
	if (aMesh == NULL) exit(1);
	return aMesh;
}


Mesh* meshParticlePlane;
Mesh* meshParticleRain;


void loadModels() {

	printf("Loading\n");

	GLuint texture_array[38];
	loadBMP_custom(texture_array, "./src/textures/nullTexture.bmp", 0, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/oldbox.bmp", 1, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/Spikes.bmp", 2, 1, 0);
	//loadBMP_custom(texture_array, "./src/textures/CheckerTiles.bmp", 3, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/door.bmp", 5, 1, 0);
	loadBMP_custom(texture_array, "./src/textures/doorFrame.bmp", 6, 1, 0);
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
	//loadBMP_custom(texture_array, "./BMP files/oldbox.bmp", 22, 0);
	//loadBMP_custom(texture_array, "./src/textures/oldbox.bmp", 23, 1, 1);
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
	

	// Load particle mesh & images
	meshParticlePlane = loadObjMesh("./src/obj files/ParticlePlane.obj");
	meshParticleRain = loadObjMesh("./src/obj files/ParticleRain.obj");


	/*
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlane = meshToDisplayList(meshParticlePlane, uniqueMeshID, 21);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneFlames = meshToDisplayList(meshParticlePlane, uniqueMeshID, 23);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneSnow = meshToDisplayList(meshParticlePlane, uniqueMeshID, 24);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneBubbles = meshToDisplayList(meshParticlePlane, uniqueMeshID, 25);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneAsh = meshToDisplayList(meshParticlePlane, uniqueMeshID, 26);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneWaterfallSub = meshToDisplayList(meshParticlePlane, uniqueMeshID, 27);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneLeaves = meshToDisplayList(meshParticlePlane, uniqueMeshID, 28);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneFlameSparks = meshToDisplayList(meshParticlePlane, uniqueMeshID, 29);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticleRain = meshToDisplayList(meshParticleRain, uniqueMeshID, 30);
	uniqueMeshID = uniqueMeshID + 1;
	displayParticlePlaneRing = meshToDisplayList(meshParticlePlane, uniqueMeshID, 31);
	*/

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



	/* // images currently not in use
	//texture_from_file(&texture_array[4], "./src/textures/bricks.bmp");
	//texture_from_file(&texture_array[7], "./src/textures/wood.bmp");
	//texture_from_file(&texture_array[8], "./src/textures/RoughTexture.bmp");
	//texture_from_file(&texture_array[12], "./src/textures/DirtGrass.bmp");
	*/


	//displayListMaterialTest1 = loadObj("./src/obj files/Map20.obj", texture_array[0]);

	/*
	displayListClockFrame = loadObj("./src/obj files/ClockFrame.obj", texture_array[0]);

	displayListClockWhite = loadObj("./src/obj files/ClockWhite.obj", texture_array[0]);
	*/

	meshSpikes = loadObj("./src/obj files/Spikes2.obj", texture_array[2]);

	meshDoorFrame = loadObj("./src/obj files/DoorFrame3.obj", texture_array[6]);

	meshDoorLeft = loadObj("./src/obj files/DoorRight3.obj", texture_array[5]);

	meshDoorRight = loadObj("./src/obj files/DoorLeft3.obj", texture_array[5]);

	meshDoorLock = loadObj("./src/obj files/DoorLock3.obj", texture_array[0]);

	/*
	meshRoomWall1 = loadObj("./src/obj files/RoomWall1Colored.obj", texture_array[0]);

	meshRoomWall2 = loadObj("./src/obj files/RoomWall2Colored.obj", texture_array[0]);
	*/

	meshBox = loadObj("./src/obj files/box.obj", texture_array[0]);

	//meshUIMap = loadObj("./src/obj files/Map18_map.obj", texture_array[0]);
	//meshUIMap = loadObj("./src/obj files/q4_Map.obj", texture_array[3]);

	meshGem = loadObj("./src/obj files/Gem.obj", texture_array[0]);

	meshKey = loadObj("./src/obj files/Key.obj", texture_array[0]);

	//meshPorsche = loadObj("./src/obj files/porsche.obj", texture_array[0]);

	//meshAL = loadObj("./src/obj files/al.obj", texture_array[0]);

	//meshGear1 = loadObj("./src/obj files/Gear1.obj", texture_array[0]);

	//meshGear2 = loadObj("./src/obj files/Gear2.obj", texture_array[0]);

	//meshPortal = loadObj("./src/obj files/Portal.obj", texture_array[0]);

	//meshFloor = loadObj("./src/obj files/Map18_Floor.obj", texture_array[3]);
	
	//meshWall = loadObj("./src/obj files/Map18Wall.obj", texture_array[4]);

	//meshBench = loadObj("./src/obj files/furniture/Bench.obj", texture_array[7]);

	//meshChair = loadObj("./src/obj files/furniture/Chair.obj", texture_array[7]);

	//hangingLamp = loadObj("./src/obj files/furniture/hangingLamp.obj", texture_array[0]);
	
	//hangingLampE = loadObj("./src/obj files/furniture/hangingLampE.obj", texture_array[0]);

	//meshCouch = loadObj("./src/obj files/furniture/Couch.obj", texture_array[0]);

	//meshDesk = loadObj("./src/obj files/furniture/Desk.obj", texture_array[7]);

	meshSkyBox = loadObj("./src/obj files/CubeMap.obj",texture_array[9]);

	meshABox = loadObj("./src/obj files/aBox.obj", texture_array[1]);

	//meshq3MirrorRoom = loadObj("./src/obj files/q3MirrorRoom.obj", texture_array[3]);

	//meshq3MirrorPlane = loadObj("./src/obj files/q3MirrorPlane.obj", texture_array[3]);

	meshTree = loadObj("./src/obj files/LowPolyTree.obj", texture_array[10]);

	meshGrassCluster = loadObj("./src/obj files/GrassCluster.obj", texture_array[11]);


	// Quiz 4 models
	//meshStar = loadObj("./src/obj files/star.obj", texture_array[0]);

	//meshBigRock = loadObj("./src/obj files/bigRock.obj", texture_array[0]);

	//meshQ4Map = loadObj("./src/obj files/q4_02.obj", texture_array[3]);

	meshLightBulb = loadObj("./src/obj files/LightBulb.obj", texture_array[13]);

	//meshBulb = loadObj("./src/obj files/bulb.obj", texture_array[0]);








	// Level 1 - Forest Grass
	//meshLV1ForestGrass = loadObj("./src/obj files/LV1Grass.obj", texture_array[11]);
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


	//meshCharacterStanding01 = loadObj("./src/obj files/CharacterStanding01.obj", texture_array[20]);
	//meshCharacterForward01 = loadObj("./src/obj files/CharacterForward01.obj", texture_array[20]);

	
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




}


void drawGear1() {
	glCallList(meshGear1);
}

void drawGear2() {
	glCallList(meshGear2);
}