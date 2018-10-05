
void toggleSprint();


void toggleSprint() {


	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(width - width * 0.2, height - width * 0.25, width*0.2, width*0.04);
	//glViewport(width - width * 0.2, width * 0.2, width*0.2, width*0.04);
	gluPerspective(0, 0, 0.1, 1000);

	glOrtho(-10, 10, -10, 10, -10, 10);



	// 1.0>x/w>0.8
	// 0.25>y/w>0.2
	/*
	if ((float)mouseX / (float)width < 1.0f && (float)mouseX / (float)width > 8.0f) {
		if ((float)mouseY / (float)width < 0.25f && (float)mouseY / (float)width > 0.2f) {

		}
	}
	*/

	
	char msgXYZ[100];
	//sprintf_s(msgXYZ, "TOGGLE SHADING");
	if (sprint) {
		sprintf_s(msgXYZ, "Fast");
	} else {
		sprintf_s(msgXYZ, "Slow");
	}
	glColor3f(1, 1, 1);
	renderBitmapString(-9.0, -1.0, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h
	glColor3f(0.0, 0.0, 0.0);
	renderBitmapString(-8.97, -1.03, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"



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
	

}