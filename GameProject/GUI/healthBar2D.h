
void draw2DHealthBar();

void draw2DHealthBar(){


	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(width * 0.01, height - width * 0.03, width*0.25, width*0.02);
	gluPerspective(0, 0, 0.1, 1000);

	glBegin(GL_QUADS);

	//health = 500;
	//glColor3f(1.0, camAngY*0.1, 0.0);
	glColor3f(1.0, health*0.0005, 0.0);
	glVertex3f(-0.975, -0.80, -0.2);
	glVertex3f(-0.975+health*0.001956, -0.80, -0.2);
	glColor3f(1.0, 0.5+ health * 0.00025, 0.5);
	glVertex3f(-0.975+health*0.001956, 0.80, -0.2);
	glVertex3f(-0.975, 0.80, -0.2);

	/*
	glColor3f(1.0, health*0.0005, 0.0);
	glVertex3f(-0.992, -0.80, 0.0);
	glVertex3f(-0.992 + health * 0.001986, -0.80, 0.0);
	glColor3f(1.0, 0.5 + health * 0.00025, 0.5);
	glVertex3f(-0.992 + health * 0.001986, 0.80, 0.0);
	glVertex3f(-0.992, 0.80, 0.0);
	*/

	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-0.975, -0.8, -0.1);
	glVertex3f(0.975, -0.8, -0.1);
	glVertex3f(0.975, 0.8, -0.1);
	glVertex3f(-0.975, 0.8, -0.1);
	
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-1, -1, 0.0);
	//glVertex3f(-0.992 + health * 0.001956 +0.035, -1, 0.0);
	//glVertex3f(-0.992 + health * 0.001956 +0.035, 1, 0.0);
	glVertex3f(1, -1, 0.0);
	glVertex3f(1, 1, 0.0);
	glVertex3f(-1, 1, 0.0);

	glEnd();

}