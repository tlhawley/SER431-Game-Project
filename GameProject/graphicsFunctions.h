


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
	gluLookAt(camx, camy, camz, camx + lx, camy + ly, camz + lz, 0.0f, 1.0f, 0.0f);

}