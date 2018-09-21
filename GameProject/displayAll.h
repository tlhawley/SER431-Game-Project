

void displayEnvironment();
void displayGameObjects();
void displaySkyBox(float scale, float yAngle, int skyboxID);






void displayEnvironment() {


	setMaterialAdvanced(materialCastle);




	ImprovedNoise noise; // modified for terrain
	Vec3f pixelColor; // modified for terrain

	// Oribit box on terrain
	float aBoxX = sin(clock() / 1000.0f) * 10.0f + 50.0f;
	float aBoxZ = cos(clock() / 1000.0f) * 10.0f;

	pixelColor = marbleMap(t_scale(noise.perlinMarble((aBoxX + 128)*10.0f, (aBoxZ + 128)*10.0f)));
	glTranslatef(aBoxX, (pixelColor[0] * 400.0f - 100.0f)*0.01f - 5.0f, aBoxZ);
	glCallList(meshABox);
	glTranslatef(-aBoxX, -((pixelColor[0] * 400.0f - 100.0f)*0.01f - 5.0f), -aBoxZ);






	// camera box
	glTranslatef(camx, camy - 1.0f, camz);
	glScalef(0.5f, 0.5f, 0.5f);
	glCallList(meshABox);
	glScalef(2.0f, 2.0f, 2.0f);
	glTranslatef(-camx, -camy + 1.0f, -camz);


	// TERRAIN
	setMaterialAdvanced(materialSpinSpike); // this shading works ok for the terrain
	glTranslatef(0.0f, -15, 0.0f);
	displayNoiseGenPlane(); //Displays the terrain
	glTranslatef(0.0f, 15, 0.0f);

	// LAVA MOUNTAIN
	setMaterialAdvanced(materialSkyBox); //emissive lava
	glTranslatef(0.0f, -150.0f, 0.0f);
	glScalef(100.0f, 100.0f, 100.0f);
	displayNoiseGenLavaPlane(); // displays lava
	glScalef(0.01f, 0.01f, 0.01f);
	glTranslatef(0.0f, 150.0f, 0.0f);


	// mirror room
	setMaterialAdvanced(materialObsidian);
	glCallList(meshq3MirrorRoom);

	// floor checkers
	setMaterialAdvanced(materialCastle);
	glCallList(meshFloor);


	displayBaseModels();

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


	


}







void displayGameObjects() {
	displayDoorway();

	setMaterialAdvanced(materialGold);
	displayKeys();

	setMaterialAdvanced(materialRuby);
	displayGems();

	setMaterialAdvanced(materialSpinSpike);
	displaySpinSpikes();

	displayHealthPacks();

}







void displaySkyBox(float scale, float yAngle, int skyboxID) {

	glDisable(GL_FOG); // the sky box should not be affected by fog
	setlight(); // this allows the sky box to be visible
	setMaterialAdvanced(materialSkyBox); // This allows sets the skybox to a bright emissive material displaying no shading

	glTranslatef(camx, camy, camz);
		glScalef(scale, -scale, scale); // TODO: Fix skybox UVs to work correctly without inverting the y axis
			glRotatef(yAngle, 0, 1.0, 0);
				glCallList(meshSkyBox); // TODO: skyBoxID for swapping different skybox images
			glRotatef(-yAngle, 0, 1.0, 0);
		glScalef(1.0 / scale, 1.0 / -scale, 1.0 / scale);
	glTranslatef(-camx, -camy, -camz);
	glEnable(GL_FOG);

}

