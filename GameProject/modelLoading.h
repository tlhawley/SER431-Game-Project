

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

GLuint meshUIMap;


GLuint meshGem;
GLuint meshKey;
GLuint meshPorsche;
GLuint meshAL;

GLuint meshGear1;
GLuint meshGear2;

GLuint meshPortal;
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



void loadModels() {

	GLuint texture_array[12];
	texture_from_file(&texture_array[0], "./src/textures/nullTexture.bmp");
	texture_from_file(&texture_array[1], "./src/textures/oldbox.bmp");
	texture_from_file(&texture_array[2], "./src/textures/Spikes.bmp");
	texture_from_file(&texture_array[3], "./src/textures/CheckerTiles.bmp");
	texture_from_file(&texture_array[4], "./src/textures/bricks.bmp");
	texture_from_file(&texture_array[5], "./src/textures/door.bmp");
	texture_from_file(&texture_array[6], "./src/textures/doorFrame.bmp");
	texture_from_file(&texture_array[7], "./src/textures/wood.bmp");
	texture_from_file(&texture_array[8], "./src/textures/RoughTexture.bmp");
	texture_from_file(&texture_array[9], "./src/textures/SkyBox.bmp"); //Skybox texture source : https://github.com/zogi/ocean_demo
	texture_from_file(&texture_array[10], "./src/textures/TreeTexture.bmp");
	texture_from_file(&texture_array[11], "./src/textures/GrassClusterTexture.bmp");


	displayListMaterialTest1 = loadObj("./src/obj files/Map20.obj", texture_array[0]);

	displayListClockFrame = loadObj("./src/obj files/ClockFrame.obj", texture_array[0]);

	displayListClockWhite = loadObj("./src/obj files/ClockWhite.obj", texture_array[0]);

	meshSpikes = loadObj("./src/obj files/Spikes2.obj", texture_array[2]);

	meshDoorFrame = loadObj("./src/obj files/DoorFrame3.obj", texture_array[6]);

	meshDoorLeft = loadObj("./src/obj files/DoorRight3.obj", texture_array[5]);

	meshDoorRight = loadObj("./src/obj files/DoorLeft3.obj", texture_array[5]);

	meshDoorLock = loadObj("./src/obj files/DoorLock3.obj", texture_array[0]);

	meshRoomWall1 = loadObj("./src/obj files/RoomWall1Colored.obj", texture_array[0]);

	meshRoomWall2 = loadObj("./src/obj files/RoomWall2Colored.obj", texture_array[0]);

	meshBox = loadObj("./src/obj files/box.obj", texture_array[0]);

	meshUIMap = loadObj("./src/obj files/Map18_map.obj", texture_array[0]);

	meshGem = loadObj("./src/obj files/Gem.obj", texture_array[0]);

	meshKey = loadObj("./src/obj files/Key.obj", texture_array[0]);

	meshPorsche = loadObj("./src/obj files/porsche.obj", texture_array[0]);

	meshAL = loadObj("./src/obj files/al.obj", texture_array[0]);

	meshGear1 = loadObj("./src/obj files/Gear1.obj", texture_array[0]);

	meshGear2 = loadObj("./src/obj files/Gear2.obj", texture_array[0]);

	meshPortal = loadObj("./src/obj files/Portal.obj", texture_array[0]);

	meshFloor = loadObj("./src/obj files/Map18_Floor.obj", texture_array[3]);
	
	meshWall = loadObj("./src/obj files/Map18Wall.obj", texture_array[4]);

	meshBench = loadObj("./src/obj files/furniture/Bench.obj", texture_array[7]);

	meshChair = loadObj("./src/obj files/furniture/Chair.obj", texture_array[7]);

	hangingLamp = loadObj("./src/obj files/furniture/hangingLamp.obj", texture_array[0]);
	
	hangingLampE = loadObj("./src/obj files/furniture/hangingLampE.obj", texture_array[0]);

	meshCouch = loadObj("./src/obj files/furniture/Couch.obj", texture_array[0]);

	meshDesk = loadObj("./src/obj files/furniture/Desk.obj", texture_array[7]);

	meshSkyBox = loadObj("./src/obj files/CubeMap.obj",texture_array[9]);

	meshABox = loadObj("./src/obj files/aBox.obj", texture_array[1]);

	meshq3MirrorRoom = loadObj("./src/obj files/q3MirrorRoom.obj", texture_array[3]);

	meshq3MirrorPlane = loadObj("./src/obj files/q3MirrorPlane.obj", texture_array[3]);

	meshTree = loadObj("./src/obj files/LowPolyTree.obj", texture_array[10]);

	meshGrassCluster = loadObj("./src/obj files/GrassCluster.obj", texture_array[11]);


}


void drawGear1() {
	glCallList(meshGear1);
}

void drawGear2() {
	glCallList(meshGear2);
}