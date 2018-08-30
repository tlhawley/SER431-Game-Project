
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
	//glViewport(width - width * 0.2, height - width * 0.2, width*0.2, width*0.2);
	glViewport(width - width * 0.2,  0, width*0.2, width*0.2);
	gluPerspective(0, 0, 0.1, 1000);
	//glLoadIdentity();
	//glRotatef(camAngX, 1.0, 0.0, 0.0);
	//gluLookAt(0, 0, 0, 0, 0, 1, 0.0f, 1.0f, 0.0f);
	//gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, -1.0f, 0.0f);
	//gluLookAt(x, y, z, x - lx, y - ly, z - lz, 0.0f, 1.0f, 0.0f);
	//glRotatef(lx, ly, lz);
	//gluLookAt(0, 0, 0, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
	//gluLookAt(x, y, z, x, y, z, 0.0f, 1.0f, 0.0f);
	//gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
	//gluLookAt(
	// projection
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glViewport(0, 0, width, height);
	glOrtho(-10, 10, -10, 10, -10, 10);
	//glRotatef(timer, 0, 0, 300.5);
	// view
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
	//glOrtho(-10, 10, -10, 10, -10, 10);
	//glLoadIdentity();
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_CLEAR);
	//glClearDepth(100.0);
	
	//gluLookAt(0, 0, 0, 0, 0, 0, 0.0f, 1.0f, 0.0f);

	//gluLookAt(0, 0, 0, 0, 0, 1, 0.0f, 1.0f, 0.0f);


	//glLoadIdentity();




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

	//glVertex3f(-0.2, 0.2, 0.0);
	glEnd();

	//glTranslatef(0.0,0.0, -9.5);
	glRotatef(camAngY*angOffset+ 180, 0.0, 0.0, 1.0);
	glTranslatef(camx*.2, -camz*.2, 0.0);
	
	
	// Draw the new map
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glScalef(0.2, 0.2, 0.2);
	glColor3f(0.4, 0.4, 0.4);
	setlight();
	setmaterial2(1.0, 0.2, 0.2, 0.2, 0.0);
	glCallList(meshUIMap);
	glScalef(5, 5, 5);
	glRotatef(-180, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	/*
	glBegin(GL_TRIANGLES);

	// center
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-2, 2, 0);
	glVertex3f(2, -2, 0);
	glVertex3f(2, 2, 0);

	glVertex3f(2, -2, 0);
	glVertex3f(-2, -2, 0);
	glVertex3f(-2, 2, 0);

	// front
	//glColor3f(0.9, 0.9, 0.4);
	glVertex3f(-2,-2, 0);
	glVertex3f(2,-6, 0);
	glVertex3f(2,-2, 0);

	glVertex3f(2,-6, 0);
	glVertex3f(-2,-6, 0);
	glVertex3f(-2,-2, 0);

	//back
	//glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-2, 2, 0);
	glVertex3f(2, 6, 0);
	glVertex3f(2, 2, 0);

	glVertex3f(2, 6, 0);
	glVertex3f(-2, 6, 0);
	glVertex3f(-2, 2, 0);


	//left
	//glColor3f(0.4, 0.4, 0.9);
	glVertex3f(6, 2, 0);
	glVertex3f(2, -2, 0);
	glVertex3f(2, 2, 0);

	glVertex3f(2, -2, 0);
	glVertex3f(6, -2, 0);
	glVertex3f(6, 2, 0);

	//right
	//glColor3f(0.9, 0.4, 0.4);
	glVertex3f(-6, 2, 0);
	glVertex3f(-2, -2, 0);
	glVertex3f(-2, 2, 0);

	glVertex3f(-2, -2, 0);
	glVertex3f(-6, -2, 0);
	glVertex3f(-6, 2, 0);
	


	glEnd();
	*/


	glTranslatef( -camx*.2,  camz*.2, 0.0);
	glRotatef(camAngY*angOffset + 180, 0.0, 0.0, -1.0);

	// main shading
	glBegin(GL_POLYGON);
	glColor4f(.0, .0, .0, 0.5);
	glVertex3f(-9.8, -9.8, 0.0);
	glVertex3f(9.8, -9.8, 0.0);
	//glColor4f(.4, .4, .4, 0.5);
	glVertex3f(9.8, 9.8, 0.0);
	glVertex3f(-9.8, 9.8, 0.0);


	glColor4f(.01, .01, .01, 0.0);
	glVertex3f(-9.8, -9.8, 0.8);
	glVertex3f(9.8, -9.8, 0.8);
	glColor4f(1.4, 1.4, 1.4, 0.25);
	glVertex3f(9.8, 9.8, 0.8);
	glColor4f(1.4, 1.4, 1.4, 0.5);
	glVertex3f(-9.8, 9.8, 0.8);

	glEnd();


	glBegin(GL_QUADS);
	glColor4f(.7, .7, .7, 1.0);
	/*
	glColor4f(.9, .9, .9, 1.0);
	glVertex3f(-10, -10, 0.8);
	glVertex3f(10, -10, 0.8);
	glVertex3f(10, 10, 0.8);
	glVertex3f(-10, 10, 0.8);
	*/

	// borders
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

	// shadows
	glColor4f(0.0, 0.0, 0.0, 0.5);
	glVertex3f(-9.8, -10, 0.8);
	glVertex3f(-9.4, -10, 0.8);
	glVertex3f(-9.4, 10, 0.8);
	glVertex3f(-9.8, 10, 0.8);


	glVertex3f(-10, 9.8, 0.8);
	glVertex3f(10, 9.8, 0.8);
	glVertex3f(10, 9.4, 0.8);
	glVertex3f(-10, 9.4, 0.8);

	glEnd();

	//glTranslatef(0.0, 0.0, -9.0);

	//glClear(GL_CLEAR);

	//glClear(GLbitfield(2));
	//glClearAccum(0.0, 0.0, 0.0, 0.0);
	
	/*
	glBegin(GL_POLYGON);
	glColor4f(.4, .4, .4, 0.5);
	glVertex3f(-10, -10, -0.8);
	glVertex3f(10, -10, -0.8);
	glColor4f(.9, .9, .9, 0.5);
	glVertex3f(10, 10, -0.8);
	glVertex3f(-10, 10,-0.8);
	glEnd();
	*/
	
}