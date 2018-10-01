

// The reflection function takes a model for the stencil, position, and direction data.
// It is designed to simplify creating reflective objects in game
// Note: not designed to work with multiple mirrors or complex angles.

struct MirrorDirection {
	float x;
	float y;
	float z;
};

struct Position {
	float x;
	float y;
	float z;
};

void reflection(void(*objFunction)(), Position pos, MirrorDirection mirrorDir);

void reflection(void(*objFunction)(), Position pos, MirrorDirection mirrorDir) {
	refectOn = 1;

	glEnable(GL_STENCIL_TEST); //Start using the stencil
	glDisable(GL_DEPTH_TEST);
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); //Disable writing colors in frame buffer
	glStencilFunc(GL_ALWAYS, 1, 0xFFFFFFFF); //Place a 1 where rendered
	glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE); 	//Replace where rendered
														// PLAIN for the stencil
	glPushMatrix();

	//objPlacementTRS(objFunction(),0,0,0,0,0,0,0,0,0) // assumes the 
	//glTranslatef(50, 0, 0);
	objFunction(); // assumes the location, angle, and scale are predefined in the model
	//glTranslatef(-50, 0, 0);
	//psudo code for getting the rotation of a plane from the direction vector provided
	//yang = tan(z/x)
	//xang = tan(y/(sqrt(z*z+x*x)))
	//zang = rollVariable - would need to be added to the function

	glPopMatrix();
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); //Reenable color
	glEnable(GL_DEPTH_TEST);
	glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Keep the pixel




	/*
	// blue atmospheric fog
	glEnable(GL_FOG);
	GLfloat color[4] = { 0.75f, 0.8f, 1.0f, 1.0f };
	glFogfv(GL_FOG_COLOR, color);
	//glFogf(GL_FOG_START, 1);
	//glFogf(GL_FOG_END, 50.0);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, .007);
	*/

	setlight();




	// mirrored display
	glTranslatef(pos.x, pos.y, pos.z);
	glScalef(mirrorDir.x, mirrorDir.y, mirrorDir.z);
		
		displayEnvironment();
		displayGameObjects();
		
	glScalef(1.0 / mirrorDir.x, 1.0 / mirrorDir.y, 1.0 / mirrorDir.z);
	glTranslatef(-pos.x, -pos.y, -pos.z);



	// TODO: replace with a displaySkybox function

	// Mirrored Sky box
	glScalef(mirrorDir.x, mirrorDir.y, mirrorDir.z);
	displaySkyBox(2000, 90, 0);
	glScalef(1.0 / mirrorDir.x, 1.0 / mirrorDir.y, 1.0 / mirrorDir.z);











	
	// STENCIL-STEP 4. disable it
	glDisable(GL_STENCIL_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setMaterialAdvanced(matarialAlpha1); // sets a transparent material

	glPushMatrix();

	//glTranslatef(50, 0, 0);
	objFunction(); // assumes the location, angle, and scale are predefined in the model
	//glTranslatef(-50, 0, 0);

	glPopMatrix();

	refectOn = 0;




}