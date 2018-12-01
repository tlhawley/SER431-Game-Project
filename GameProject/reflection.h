

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

	objFunction(); // assumes the location, angle, and scale are predefined in the model

	glPopMatrix();
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); //Reenable color
	glEnable(GL_DEPTH_TEST);
	glStencilFunc(GL_EQUAL, 1, 0xFFFFFFFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Keep the pixel

	setlight();

	// mirrored display
	glTranslatef(pos.x, pos.y, pos.z);
	glScalef(mirrorDir.x, mirrorDir.y, mirrorDir.z);
		
		displayEnvironment();
		displayGameObjects();
		
	glScalef(1.0 / mirrorDir.x, 1.0 / mirrorDir.y, 1.0 / mirrorDir.z);
	glTranslatef(-pos.x, -pos.y, -pos.z);


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
	objFunction(); // assumes the location, angle, and scale are predefined in the model
	glPopMatrix();

	refectOn = 0;




}