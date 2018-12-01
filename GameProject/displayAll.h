

// used for displaying most of the 3d models

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



// init
void initshadow() {

	/*
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

	display2 = meshToDisplayList(mesh2, 2, 1);
	display3 = meshToDisplayList(mesh3, 3, 1);
	display4 = meshToDisplayList(mesh4, 4, 1);
	*/

	// shadow
	glClearStencil(0);
	// floor vertex
	dot_vertex_floor.push_back(Vec3<GLfloat>(-20.0, 20.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(20.0, 20.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(20.0, -20.0, 0.0));
	dot_vertex_floor.push_back(Vec3<GLfloat>(-20.0, -20.0, 0.0));

	calculate_floor_normal(&floor_normal, dot_vertex_floor);

}










// Displays most objects in the environment
void displayEnvironment() {

	glDisable(GL_BLEND);

	// Character Placement
	if (buttons[15].toggle == false) {
		if (frameTimer >= N) {
			glPushMatrix();
			setMaterialAdvanced(materialPlayer);
			glTranslatef(camx, camy, camz);
			glRotatef(-camAngY * 57.29578f + 180, 0.0, 1.0, 0.0);
			glRotatef(playerAngle * 57.29578f - 90, 0.0, 1.0, 0.0);

			if (pxv == 0 && pzv == 0) {

				if (canJump == true) {
					glCallList(meshCharacterFrames[0].l1); // standing animation
				}
				else {
					if (jumpFrame == 0) {
						glCallList(meshCharacterFrames[26].l1); // jump start frame
					}
					else {
						if (jumpFrame > 0 && jumpFrame < 4) {
							glCallList(meshCharacterFrames[27].l1); // jump attack frame 1
						}
						else {
							if (jumpFrame < 18) {

								glRotatef(jumpFrame*35.0f, 1.0, 0.0, 0.0);
								glTranslatef(0, 0.5f, 0);
								glCallList(meshCharacterFrames[28].l1); // jump attack spin frame
								glTranslatef(0, -0.5f, 0);
								glRotatef(-jumpFrame * 35.0f, 1.0, 0.0, 0.0);
							}
							else {
								if (jumpFrame < 20) {
									glCallList(meshCharacterFrames[29].l1);
								}
								else {
									//jumpFrame = 0;
									camyv = camyv - 0.01f; // doubles y velocity acceleration when in attack mode
									glCallList(meshCharacterFrames[30].l1);
								}
							}
						}
					}
				}
				runFrame = 1;
				if (itemTimer > 0 && heartPickUp) {
					setMaterialAdvanced(materialHeart);
					glScalef(0.5f, 0.5f, 0.5f);
					glCallList(meshHeart.l1);
					glScalef(2.0f, 2.0f, 2.0f);
				}
				else if (itemTimer > 0 && gemPickUp) {
					setMaterialAdvanced(materialRuby);
					glScalef(0.5f, 0.5f, 0.5f);
					glCallList(meshGem.l1);
					glScalef(2.0f, 2.0f, 2.0f);
				}
			}
			else {
				runFrame = runFrame + 1;
				if (runFrame > 25) { runFrame = 1; }
				if (canJump == true) {
					glCallList(meshCharacterFrames[runFrame].l1);
				}
				else {
					if (jumpFrame == 0) {
						glCallList(meshCharacterFrames[26].l1); // jump start frame
					}
					else {
						if (jumpFrame > 0 && jumpFrame < 4) {
							glCallList(meshCharacterFrames[27].l1); // jump attack frame 1
						}
						else {
							if (jumpFrame < 18) {
								glRotatef(jumpFrame*35.0f, 1.0, 0.0, 0.0);
								glTranslatef(0, 0.5f, 0);
								glCallList(meshCharacterFrames[28].l1); // jump attack spin frame
								glTranslatef(0, -0.5f, 0);
								glRotatef(-jumpFrame * 35.0f, 1.0, 0.0, 0.0);
							}
							else {
								if (jumpFrame < 20) {
									glCallList(meshCharacterFrames[29].l1);
								}
								else {
									//jumpFrame = 0;
									camyv = camyv - 0.01f; // doubles y velocity acceleration when in attack mode
									glCallList(meshCharacterFrames[30].l1);
								}
							}
						}
					}
				}
				if (itemTimer > 0 && heartPickUp) {
					setMaterialAdvanced(materialHeart);
					glScalef(0.5f, 0.5f, 0.5f);
					glCallList(meshHeart.l1);
					glScalef(2.0f, 2.0f, 2.0f);
				}
				else if (itemTimer > 0 && gemPickUp) {
					setMaterialAdvanced(materialRuby);
					glScalef(0.5f, 0.5f, 0.5f);
					glCallList(meshGem.l1);
					glScalef(2.0f, 2.0f, 2.0f);
				}
				else if (itemTimer > 0 && keyPickUp) {
					setMaterialAdvanced(materialGold);
					glScalef(0.25f, 0.25f, 0.25f);
					glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
					glCallList(meshKey.l1);
					glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
					glScalef(4.0f, 4.0f, 4.0f);
				}
			}

			glRotatef(-playerAngle * 57.29578f + 90, 0.0, 1.0, 0.0);
			glRotatef(camAngY * 57.29578f + 180, 0.0, 1.0, 0.0);
			glTranslatef(-camx, -camy, -camz);
			glPopMatrix();
		}
		else {
			setMaterialAdvanced(materialPlayer);
			glTranslatef(0, 1.5f, 0);
			glRotatef(-90, 0, 1, 0);
			glCallList(meshCharacterFrames[0].l1);
			glRotatef(90, 0, 1, 0);
			glTranslatef(0, -1.5f, 0);
		}
	}
	else {
	}
	


	if (buttons[10].toggle == true) {
		setMaterialAdvanced(materialEmissive);
	}
	else {
		setMaterialAdvanced(materialEnvironment);
	}
	if (refectOn == 0) {
		glEnable(GL_CULL_FACE);
		displayBaseModels(); // static environment objects
		if (currentLevel == 0) { //hub world terrain
			setMaterialAdvanced(materialSand);
			displayNoiseGenPlane();
		}
		glDisable(GL_CULL_FACE);
	}
	else {
		displayBaseModels();
	}




}






// displays interactive objects
void displayGameObjects() {
	if (refectOn == 0) {

		actionMovingPlatforms();

		displayDoorway();

		setMaterialAdvanced(materialGold);
		displayKeys();

		
		setMaterialAdvanced(materialRuby);
		displayGems();

		setMaterialAdvanced(materialSpinSpike);
		displaySpinSpikes();


		setMaterialAdvanced(materialHeart);
		displayHealthPacks();

		displayFlags();

		displayFractals();
	}

}






// displays the skybox
void displaySkyBox(float scale, float yAngle, int skyboxID) {
	setlight();
	setMaterialAdvanced(materialSkyBox);
	if (buttons[4].toggle == true) {
		glDisable(GL_FOG);
		glTranslatef(camx, camy, camz);
		glScalef(scale, -scale, scale);
		glRotatef(yAngle, 0, 1.0, 0);
		glCallList(meshSkyBox.l1);
		glRotatef(-yAngle, 0, 1.0, 0);
		glScalef(1.0 / scale, 1.0 / -scale, 1.0 / scale);
		glTranslatef(-camx, -camy, -camz);
		if (buttons[5].toggle == true) {
			glEnable(GL_FOG);
		}
	}

}

