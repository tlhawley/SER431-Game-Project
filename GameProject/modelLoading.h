

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

void loadModels();
void drawGear1();
void drawGear2();

void loadModels() {

	GLuint texture_array[10];
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
	
	//Mesh* mesh1 = loadFile("./src/obj files/Object Thing2.obj");
	Mesh* mesh1 = loadFile("./src/obj files/Map20.obj");
	if (mesh1 == NULL) exit(1);
	displayListMaterialTest1 = meshToDisplayList(mesh1, 1, texture_array[0]);

	Mesh* mesh2 = loadFile("./src/obj files/ClockFrame.obj");
	if (mesh2 == NULL) exit(1);
	displayListClockFrame = meshToDisplayList(mesh2, 2, texture_array[0]);

	Mesh* mesh3 = loadFile("./src/obj files/ClockWhite.obj");
	if (mesh3 == NULL) exit(1);
	displayListClockWhite = meshToDisplayList(mesh3, 3, texture_array[0]);


	Mesh* mesh4 = loadFile("./src/obj files/Spikes2.obj");
	if (mesh4 == NULL) exit(1);
	meshSpikes = meshToDisplayList(mesh4, 4, texture_array[2]);



	Mesh* mesh5 = loadFile("./src/obj files/DoorFrame3.obj");
	if (mesh5 == NULL) exit(1);
	meshDoorFrame = meshToDisplayList(mesh5, 5, texture_array[6]);

	Mesh* mesh6 = loadFile("./src/obj files/DoorRight3.obj");
	if (mesh6 == NULL) exit(1);
	meshDoorLeft = meshToDisplayList(mesh6, 6, texture_array[5]);

	Mesh* mesh7 = loadFile("./src/obj files/DoorLeft3.obj");
	if (mesh7 == NULL) exit(1);
	meshDoorRight = meshToDisplayList(mesh7, 7, texture_array[5]);

	Mesh* mesh8 = loadFile("./src/obj files/DoorLock3.obj");
	if (mesh8 == NULL) exit(1);
	meshDoorLock = meshToDisplayList(mesh8, 8, texture_array[0]);


	//RoomWall1Colored
	Mesh* mesh21 = loadFile("./src/obj files/RoomWall1Colored.obj");
	if (mesh21 == NULL) exit(1);
	meshRoomWall1 = meshToDisplayList(mesh21, 21, texture_array[0]);

	Mesh* mesh22 = loadFile("./src/obj files/RoomWall2Colored.obj");
	if (mesh22 == NULL) exit(1);
	meshRoomWall2 = meshToDisplayList(mesh22, 22, texture_array[0]);




	Mesh* mesh9 = loadFile("./src/obj files/box.obj");
	if (mesh9 == NULL) exit(1);
	meshBox = meshToDisplayList(mesh9, 9, texture_array[0]);

	//Mesh* mesh10 = loadFile("./src/obj files/TheMap.obj");
	Mesh* mesh10 = loadFile("./src/obj files/Map18_map.obj");
	if (mesh10 == NULL) exit(1);
	meshUIMap = meshToDisplayList(mesh10, 10, texture_array[0]);






	Mesh* mesh31 = loadFile("./src/obj files/Gem.obj");
	if (mesh31 == NULL) exit(1);
	meshGem = meshToDisplayList(mesh31, 31, texture_array[0]);

	Mesh* mesh32 = loadFile("./src/obj files/Key.obj");
	if (mesh32 == NULL) exit(1);
	meshKey = meshToDisplayList(mesh32, 32, texture_array[0]);

	Mesh* mesh33 = loadFile("./src/obj files/porsche.obj");
	if (mesh33 == NULL) exit(1);
	meshPorsche = meshToDisplayList(mesh33, 33, texture_array[0]);

	Mesh* mesh34 = loadFile("./src/obj files/al.obj");
	if (mesh34 == NULL) exit(1);
	meshAL = meshToDisplayList(mesh34, 34, texture_array[0]);





	Mesh* mesh35 = loadFile("./src/obj files/Gear1.obj");
	if (mesh35 == NULL) exit(1);
	meshGear1 = meshToDisplayList(mesh35, 35, texture_array[0]);

	Mesh* mesh36 = loadFile("./src/obj files/Gear2.obj");
	if (mesh36 == NULL) exit(1);
	meshGear2 = meshToDisplayList(mesh36, 36, texture_array[0]);

	Mesh* mesh40 = loadFile("./src/obj files/Portal.obj");
	if (mesh40 == NULL) exit(1);
	meshPortal = meshToDisplayList(mesh40, 40, texture_array[0]);

	/*
	Mesh* mesh41 = loadFile("./src/obj files/PortalE.obj");
	if (mesh41 == NULL) exit(1);
	meshPortalE = meshToDisplayList(mesh41, 41);

	Mesh* mesh42 = loadFile("./src/obj files/PortalGlow.obj");
	if (mesh42 == NULL) exit(1);
	meshPortalGlow = meshToDisplayList(mesh42, 42);
	*/

	
	Mesh* mesh41 = loadFile("./src/obj files/Map18_Floor.obj");
	if (mesh41 == NULL) exit(1);
	meshFloor = meshToDisplayList(mesh41, 41, texture_array[3]);
	
	Mesh* mesh42 = loadFile("./src/obj files/Map18Wall.obj");
	if (mesh42 == NULL) exit(1);
	meshWall = meshToDisplayList(mesh42, 42, texture_array[4]);



	Mesh* mesh43 = loadFile("./src/obj files/furniture/Bench.obj");
	if (mesh43 == NULL) exit(1);
	meshBench = meshToDisplayList(mesh43, 43, texture_array[7]);

	Mesh* mesh44 = loadFile("./src/obj files/furniture/Chair.obj");
	if (mesh44 == NULL) exit(1);
	meshChair = meshToDisplayList(mesh44, 44, texture_array[7]);

	Mesh* mesh45 = loadFile("./src/obj files/furniture/hangingLamp.obj");
	if (mesh45 == NULL) exit(1);
	hangingLamp = meshToDisplayList(mesh45, 45, texture_array[0]);

	Mesh* mesh46 = loadFile("./src/obj files/furniture/hangingLampE.obj");
	if (mesh46 == NULL) exit(1);
	hangingLampE = meshToDisplayList(mesh46, 46, texture_array[0]);

	Mesh* mesh47 = loadFile("./src/obj files/furniture/Couch.obj");
	if (mesh47 == NULL) exit(1);
	meshCouch = meshToDisplayList(mesh47, 47, texture_array[0]);

	Mesh* mesh48 = loadFile("./src/obj files/furniture/Desk.obj");
	if (mesh48 == NULL) exit(1);
	meshDesk = meshToDisplayList(mesh48, 48, texture_array[7]);




	Mesh* mesh49 = loadFile("./src/obj files/CubeMap.obj");
	if (mesh49 == NULL) exit(1);
	meshSkyBox = meshToDisplayList(mesh49, 49, texture_array[9]);


}


void drawGear1() {
	glCallList(meshGear1);
}

void drawGear2() {
	glCallList(meshGear2);
}