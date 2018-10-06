


// font
void renderBitmapString (float x, float y, float z, void *font, char *string) {
	char *c;
	glRasterPos3f(x, y, z);   // fonts position
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(font, *c);
}


// reshape
void myReshape(int w, int h) {
	width = w;
	height = h;
	if (h == 0) h = 1;
	ratio = 1.0f * w / h;
}

// init
void myInit() {
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	drawingList();
	orientMe(camAngY);
	//glutSetCursor(GLUT_CURSOR_NONE);
}

void setUp3DView(){
	// projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height); // uses the entire screen for 3D
	gluPerspective(45, ratio, 0.1, 2000); // (aspect, field of view, camera close range, camera long range)

										  // view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0, 0, 0, lx, ly, lz, 0.0f, 1.0f, 0.0f);
	//glTranslatef(-camx, -camy - sin(camAngX)*(sqrt(camx*camx+camz*camz)*0.03), -camz);
	//gluLookAt(camx, camy, camz, camx + lx, camy + ly*0.0, camz + lz, 0.0f, 1.0f, 0.0f);
	//gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
	gluLookAt(camx, camy, camz, camx + lx, camy + ly, camz + lz, 0.0f, 1.0f, 0.0f);
	//glRotatef(camAngX, 1.0, 0.0, 0.0);


	//glClearColor(0.2f, 0.25f, 0.1f, 1.0f);
	/*
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_FOG);
	//GLfloat color[4] = { 0.2f, 0.25f, 0.1f, 1.0f };
	GLfloat color[4] = { 0.2f, 0.22f, 0.2f, 1.0f };
	glFogfv(GL_FOG_COLOR, color);
	glFogf(GL_FOG_START, 10);
	glFogf(GL_FOG_END, 100.0);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	*/

}