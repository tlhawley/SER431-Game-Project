
void draw2DMap();

#define angOffset 57.32484076433121

void draw2DMap(){
	// Map GUI
	glDisable(GL_FOG);
	disableLights();
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(width - width * 0.2, height - width * 0.2, width*0.2, width*0.2);
	gluPerspective(0, 0, 0.1, 1000);

	glOrtho(-10, 10, -10, 10, -10, 10);



	// Green Triangle Cursor
	glBegin(GL_TRIANGLES);

	glColor4f(.1, .9, .1, 0.9);
	glVertex3f(-0.5, -0.5, 0.9);
	glColor4f(.1, .6, .1, 0.9);
	glVertex3f(0.5, -0.5, 0.9);
	glColor4f(.7, .9, .7, 0.9);
	glVertex3f(0.0, 0.5, 0.9);


	glColor4f(.1, .4, .1, 0.9);
	glVertex3f(-0.5 + 0.1, -0.5 - 0.1, 0.9);
	glVertex3f(0.5 + 0.1, -0.5 - 0.1, 0.9);
	glVertex3f(0.0 + 0.1, 0.5 - 0.1, 0.9);


	glEnd();


	glRotatef(camAngY*angOffset+ 180, 0.0, 0.0, 1.0);
	glTranslatef(camx*.2, -camz*.2, 0.0);
	


	// Draw the new map
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glScalef(0.2, 0.2, 0.2);
	glColor3f(1.0, 1.0, 1.0);
	setlight();

	setMaterialAdvanced(materialSkyBox);

	if (currentLevel == -1) {
		glCallList(meshLVSMapUI.l1);
	}
	if (currentLevel == 0) {
		glCallList(meshLVHMapUI.l1);
	}
	if (currentLevel == 1) {
		glCallList(meshLV1MapUI.l1);
	}
	if (currentLevel == 2) {
		glCallList(meshLV2MapUI.l1);
	}
	if (currentLevel == 3) {
		glCallList(meshLV3MapUI.l1);
	}
	glScalef(5, 5, 5);
	glRotatef(-180, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);



	glTranslatef( -camx*.2,  camz*.2, 0.0);
	glRotatef(camAngY*angOffset + 180, 0.0, 0.0, -1.0);

	// main shading
	glBegin(GL_POLYGON);
	glColor4f(.2, .3, .5, 0.15);
	glVertex3f(-9.8, -9.8, 0.0);
	glVertex3f(9.8, -9.8, 0.0);
	glVertex3f(9.8, 9.8, 0.0);
	glVertex3f(-9.8, 9.8, 0.0);


	glColor4f(.21, .41, .51, 0.0);
	glVertex3f(-9.8, -9.8, 0.8);
	glVertex3f(9.8, -9.8, 0.8);
	glColor4f(1.4, 1.4, 1.4, 0.15);
	glVertex3f(9.8, 9.8, 0.8);
	glColor4f(1.4, 1.4, 1.4, 0.15);
	glVertex3f(-9.8, 9.8, 0.8);

	glEnd();


	glBegin(GL_QUADS);


	// borders
	glColor4f(.0, .0, .0, 1.0);
	glVertex3f(-10, -10, 0.8);
	glVertex3f(-9.8, -10, 0.8);
	glVertex3f(-9.8, 10, 0.8);
	glVertex3f(-10, 10, 0.8);

	glVertex3f(9.8, -10, 0.8);
	glVertex3f(10, -10, 0.8);
	glVertex3f(10, 10, 0.8);
	glVertex3f(9.8, 10, 0.8);

	glVertex3f(-10, 9.8, 0.8);
	glVertex3f(10, 9.8, 0.8);
	glVertex3f(10, 10, 0.8);
	glVertex3f(-10, 10, 0.8);

	glVertex3f(-10, -10, 0.8);
	glVertex3f(10, -10, 0.8);
	glVertex3f(10, -9.8, 0.8);
	glVertex3f(-10, -9.8, 0.8);



	glEnd();

	
}