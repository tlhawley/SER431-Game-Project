

void displayEnvironment();
void displayGameObjects();
void displaySkyBox(float scale, float yAngle, int skyboxID);



/**
* Modified from:
* Javier Gonzalez-Sanchez
* Fall 2018
*
* http://javiergs.com/teaching/ser431
*/



// Shadows
GLfloat light_position[4];
GLfloat shadow_matrix[4][4];
Vec3f floor_normal;
vector<Vec3f> dot_vertex_floor;
float lightAngle = 0.0, lightHeight = 100;
int renderShadow = 1;

//float crateX = 0;
//float crateY = 100;



// calculate floor normal
void calculate_floor_normal(Vec3f *plane, vector<Vec3f> dot_floor) {
	Vec3<GLfloat> AB = dot_floor[1] - dot_floor[0];
	Vec3<GLfloat> AC = dot_floor[2] - dot_floor[0];
	*plane = AB.cross(AC);
}

// Create a matrix that will project the desired shadow

void shadowMatrix(GLfloat shadowMat[4][4], Vec3f plane_normal, GLfloat lightpos[4]) {
	GLfloat dot;
	Vec3f lightpos_v; lightpos_v.x = lightpos[0]; lightpos_v.y = lightpos[1]; lightpos_v.z = lightpos[2];
	dot = plane_normal.dot(lightpos_v);
	//Vec3f plane_normal_copy = plane_normal;
	//plane_normal[2] = plane_normal_copy[1];
	//plane_normal[1] = plane_normal_copy[2];
	shadowMat[0][0] = dot - lightpos[0] * plane_normal[0];
	shadowMat[1][0] = 0.f - lightpos[0] * plane_normal[1];
	shadowMat[2][0] = 0.f - lightpos[0] * plane_normal[2];
	shadowMat[3][0] = 0.f - lightpos[0] * plane_normal[3];
	shadowMat[0][1] = 0.f - lightpos[1] * plane_normal[0];
	shadowMat[1][1] = dot - lightpos[1] * plane_normal[1];
	shadowMat[2][1] = 0.f - lightpos[1] * plane_normal[2];
	shadowMat[3][1] = 0.f - lightpos[1] * plane_normal[3];
	shadowMat[0][2] = 0.f - lightpos[2] * plane_normal[0];
	shadowMat[1][2] = 0.f - lightpos[2] * plane_normal[1];
	shadowMat[2][2] = dot - lightpos[2] * plane_normal[2];
	shadowMat[3][2] = 0.f - lightpos[2] * plane_normal[3];
	shadowMat[0][3] = 0.f - lightpos[3] * plane_normal[0];
	shadowMat[1][3] = 0.f - lightpos[3] * plane_normal[1];
	shadowMat[2][3] = 0.f - lightpos[3] * plane_normal[2];
	shadowMat[3][3] = dot - lightpos[3] * plane_normal[3];
}


/*
void shadowMatrix(GLfloat shadowMat[4][4], Vec3f plane_normal, GLfloat lightpos[4]) {
	GLfloat dot;
	Vec3f lightpos_v; lightpos_v.x = lightpos[0]; lightpos_v.y = lightpos[1]; lightpos_v.z = lightpos[2];
	dot = plane_normal.dot(lightpos_v);
	shadowMat[0][0] = dot - lightpos[0] * plane_normal[0];
	shadowMat[1][0] = 0.f - lightpos[0] * plane_normal[1];
	shadowMat[2][0] = 0.f - lightpos[0] * plane_normal[2];
	shadowMat[3][0] = 0.f - lightpos[0] * plane_normal[3];
	shadowMat[0][1] = 0.f - lightpos[2] * plane_normal[0];
	shadowMat[1][1] = 0.f - lightpos[2] * plane_normal[1];
	shadowMat[2][1] = dot - lightpos[2] * plane_normal[2];
	shadowMat[3][1] = 0.f - lightpos[2] * plane_normal[3];
	shadowMat[0][2] = 0.f - lightpos[1] * plane_normal[0];
	shadowMat[1][2] = dot - lightpos[1] * plane_normal[1];
	shadowMat[2][2] = 0.f - lightpos[1] * plane_normal[2];
	shadowMat[3][2] = 0.f - lightpos[1] * plane_normal[3];
	shadowMat[0][3] = 0.f - lightpos[3] * plane_normal[0];
	shadowMat[1][3] = 0.f - lightpos[3] * plane_normal[1];
	shadowMat[2][3] = 0.f - lightpos[3] * plane_normal[2];
	shadowMat[3][3] = dot - lightpos[3] * plane_normal[3];
}
*/



// init
void initshadow() {
	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_DEPTH_TEST);
	// general
	//ratio = (double)width / (double)height;
	mesh1 = createPlane(2000, 2000, 200);
	mesh2 = createCube();
	mesh3 = createCube();
	mesh4 = createCube();
	calculateNormalPerFace(mesh1);
	calculateNormalPerFace(mesh2);
	calculateNormalPerFace(mesh3);
	calculateNormalPerFace(mesh4);
	calculateNormalPerVertex(mesh1);
	calculateNormalPerVertex(mesh2);
	calculateNormalPerVertex(mesh3);
	calculateNormalPerVertex(mesh4);
	// textures
	//loadBMP_custom(textureArray, "../../BMP files/brick.bmp", 0);
	//loadBMP_custom(textureArray, "../../BMP files/oldbox.bmp", 1);
	display1 = meshToDisplayList(mesh1, 1, 0);
	display2 = meshToDisplayList(mesh2, 2, 1);
	display3 = meshToDisplayList(mesh3, 3, 1);
	display4 = meshToDisplayList(mesh4, 4, 1);
	// shadow
	glClearStencil(0);
	// floor vertex
	dot_vertex_floor.push_back(Vec3<GLfloat>(-20.0, 20.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(20.0, 20.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(20.0, -20.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(-20.0, -20.0, 0.0));

	/*
	dot_vertex_floor.push_back(Vec3<GLfloat>(2000.0, -2000.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(-2000.0, -2000.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(-2000.0, 2000.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(2000.0, 2000.0, 0.0));
	*/
	calculate_floor_normal(&floor_normal, dot_vertex_floor);
	// light
	/*
	GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	*/

}










// Displays most objects in the environment
void displayEnvironment() {
	
	/*
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
	*/

	// floor checkers
	//setMaterialAdvanced(materialCastle);
	//glCallList(meshFloor);
	//glCallList(meshQ4Map);
	setMaterialAdvanced(materialSkyBox);
	if (refectOn == 0) {
		glEnable(GL_CULL_FACE);
		displayBaseModels();
		glDisable(GL_CULL_FACE);
	}
	else {
		displayBaseModels();
	}

	// TODO: Make shadows for this object on the wall
	/*
	glTranslatef(0.0f, 2.0, 5);
	glScalef(0.01f, 0.01f, 0.01f);
	//displayNoiseGenBox1(); // wood box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(0.0f, -2.0, -5);
	*/

	/*
	glTranslatef(2.0f, 2.0, 5);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox2(); // clouds box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(-2.0f, -2.0, -5);

	glTranslatef(-2.0f, 2.0, 5);
	glScalef(0.01f, 0.01f, 0.01f);
	displayNoiseGenBox3(); // lava box
	glScalef(100.0f, 100.0f, 100.0f);
	glTranslatef(2.0f, -2.0, -5);
	*/

	/*
	setMaterialAdvanced(materialBronze);
	glTranslatef(2.0f, 1.0, 3);
	glCallList(meshBigRock);
	glTranslatef(-2.0f, -1.0, -3);
	
	glTranslatef(-2.0f, 1.0, 3);
	glCallList(meshStar);
	glTranslatef(2.0f, -1.0, -3);
	*/

	/*
	setMaterialAdvanced(materialSkyBox);
	glTranslatef(-4.0f, 1.0, 3);
	glRotatef(90.0f, 0, 1.0f, 0);
	glCallList(meshLightBulb);
	glRotatef(-90.0f, 0, 1.0f, 0);
	glTranslatef(4.0f, -1.0, -3);
	*/

	//setMaterialAdvanced(materialCastle);
	//setMaterialAdvanced(materialSkyBox);
	//displayPointLights();
	/*
	glTranslatef(-5.0f, 1.0, 3);
	glCallList(meshBulb);
	glTranslatef(5.0f, -1.0, -3);
	*/















	//glTranslatef(0, 0.1, 0);



	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	// light source position
	/*
	light_position[0] = 500 * cos(lightAngle);
	light_position[1] = lightHeight;
	light_position[2] = 500 * sin(lightAngle);
	light_position[3] = 0.0; // directional light
	*/

	/*
	//glTranslatef(-900, 0, 999);
	lightHeight = pointLights[0].y;
	light_position[0] = -pointLights[0].x*100;
	light_position[1] = pointLights[0].y*100;
	light_position[2] = pointLights[0].z*100;
	light_position[3] = 1.0; // point light

	//lightAngle += 0.0005;
	// Calculate Shadow matrix
	shadowMatrix(shadow_matrix, floor_normal, light_position);
	// projection and view
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glViewport(0, 0, width, height);
	//gluPerspective(40.0, ratio, 1, 1000);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	// lookAt 
	//gluLookAt(0.0f, 40.0f, 320.0, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f);
	// camera


	glScalef(0.01f, 0.01f, 0.01f);

	//glTranslatef(-900, 0, 999);

	//glScalef(scale, scale, scale);
	//glRotatef(x_angle, 1.0f, 0.0f, 0.0f);
	//glRotatef(y_angle, 0.0f, 1.0f, 0.0f);
	//glTranslatef(0.0f, 0.0f, 0.0f);
	// draw
	glPushMatrix();
	// Tell GL new light source position
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	// Shadows
	if (renderShadow) {
		glEnable(GL_STENCIL_TEST);
		glStencilFunc(GL_ALWAYS, 1, 0xFFFFFFFF);
		glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
	}
	//glTranslatef(900, 0, -999);

	// Draw floor using blending to blend in reflection
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//setMaterialAdvanced(matarialAlpha1);
	setMaterialAdvanced(materialCastle);
	//glColor4f(1.0, 1.0, 1.0, 0.3);
	glPushMatrix();
	//glDisable(GL_LIGHTING);
	//glTranslatef(-900, 0, 999);
	glCallList(display1);
	//glTranslatef(900, 0, -999);
	//glEnable(GL_LIGHTING);
	glPopMatrix();
	glDisable(GL_BLEND);
	// Shadows
	*/
	//glTranslatef(900, 0, -999);
	/*

	if (renderShadow) {
		glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
		glStencilOp(GL_ZERO, GL_ZERO, GL_ZERO);
		//glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); 
		//  To eliminate depth buffer artifacts, use glEnable(GL_POLYGON_OFFSET_FILL);
		// Render 50% black shadow color on top of whatever the floor appareance is
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//glDisable(GL_LIGHTING);  // Force the 50% black.
		setMaterialAdvanced(materialAlpha2);
		//glColor4f(0.0, 0.0, 0.0, 0.5); // shadow color
		glPushMatrix();
		// Project the shadow
		//glTranslatef(sin(clock() / 1000.0f)*400.0f, 100, 0);
		glTranslatef(crateX, crateY, 0);
		glMultMatrixf((GLfloat *)shadow_matrix);
		//glTranslatef(-sin(clock() / 1000.0f)*400.0f, -100, 0);
		// boxes
		glDisable(GL_DEPTH_TEST);
		//glTranslatef(sin(clock()/1000.0f)*400.0f, 100, 0);
		//glTranslatef(crateX, crateY, 0);
		glCallList(display2);
		glTranslatef(-crateX, -crateY, 0);
		//glTranslatef(-sin(clock() / 1000.0f)*400.0f, -100, 0);
		*/
		/*
		glTranslatef(200, 0, 0);
		glCallList(display3);
		glTranslatef(-400, 0, 0);
		glCallList(display4);
		*/
/*
		glEnable(GL_DEPTH_TEST);
		glPopMatrix();
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
		// To eliminate depth buffer artifacts, use glDisable(GL_POLYGON_OFFSET_FILL);
		glDisable(GL_STENCIL_TEST);
	}

	setMaterialAdvanced(materialCastle);

	// box 1
	glPushMatrix();
	//glTranslatef(sin(clock() / 1000.0f)*400.0f, 100, 0);
	glTranslatef(crateX, crateY, 0);
	glCallList(display2);
	glTranslatef(-crateX, -crateY, 0);
	//glTranslatef(-sin(clock() / 1000.0f)*400.0f, -100, 0);
	glPopMatrix();
	// box 2
	*/

	


	/*
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
	// draw the light arrow	
	//drawLightArrow();
	//glPopMatrix();
	//glutSwapBuffers();


	//glTranslatef(0, -0.1, 0);

/*
	glScalef(100.0f, 100.0f, 100.0f);
	*/






}







void displayGameObjects() {
	if (refectOn == 0) {
		displayDoorway();

		setMaterialAdvanced(materialGold);
		displayKeys();

		setMaterialAdvanced(materialRuby);
		displayGems();

		setMaterialAdvanced(materialSpinSpike);
		displaySpinSpikes();

		setMaterialAdvanced(materialHeart);
		displayHealthPacks();
	}

}







void displaySkyBox(float scale, float yAngle, int skyboxID) {
	setlight(); // this allows the sky box to be visible
	setMaterialAdvanced(materialSkyBox); // This allows sets the skybox to a bright emissive material displaying no shading
	if (buttons[4].toggle == true) {
		glDisable(GL_FOG); // the sky box should not be affected by fog
		glTranslatef(camx, camy, camz);
		glScalef(scale, -scale, scale); // TODO: Fix skybox UVs to work correctly without inverting the y axis
		glRotatef(yAngle, 0, 1.0, 0);
		glCallList(meshSkyBox); // TODO: skyBoxID for swapping different skybox images
		glRotatef(-yAngle, 0, 1.0, 0);
		glScalef(1.0 / scale, 1.0 / -scale, 1.0 / scale);
		glTranslatef(-camx, -camy, -camz);
		if (buttons[5].toggle == true) {
			glEnable(GL_FOG);
		}
	}

}

