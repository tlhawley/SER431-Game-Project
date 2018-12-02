//Source: https://github.com/javiergs/SER431/blob/master/Lecture22/fractals.cpp

#define random_number2() (((float) rand())/((float) RAND_MAX))
#define MAXLEVEL 8
int Level = 4;
long TreeSeed;
int TREE = 0, STEM = 1, LEAF = 2, LEAF_MAT = 3, TREE_MAT = 4, STEMANDLEAVES = 5, FULLTREE = 10;

// create a tree as fractal
void FractalTree(int level) {
	long savedseed;
	if (level == Level) {
		glPushMatrix();
		glRotatef(random_number2() * 180, 0, 1, 0);
		glCallList(STEMANDLEAVES);
		glPopMatrix();
	}
	else {
		glCallList(STEM);
		glPushMatrix();
		glRotatef(random_number2() * 180, 0, 1, 0);
		glTranslatef(0, 1, 0);
		glScalef(0.7, 0.7, 0.7);
		glPushMatrix();
		glRotatef(110 + random_number2() * 40, 0, 1, 0);
		glRotatef(30 + random_number2() * 20, 0, 0, 1);
		FractalTree(level + 1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-130 + random_number2() * 40, 0, 1, 0);
		glRotatef(30 + random_number2() * 20, 0, 0, 1);
		FractalTree(level + 1);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-20 + random_number2() * 40, 0, 1, 0);
		glRotatef(30 + random_number2() * 20, 0, 0, 1);
		FractalTree(level + 1);
		glPopMatrix();
		glPopMatrix();
	}
}

// Create display lists for a leaf, a set of leaves, and a stem
void CreateTreeLists(void) {
	GLUquadricObj *cylquad = gluNewQuadric();
	int i;
	// materials
	GLfloat tree_ambuse[] = { 0.05f, 0.05f, 0.05f, 1.0f };
	GLfloat tree_diffuse[] = { 0.8f, 0.5f, 0.2f, 1.0f };
	GLfloat tree_emission[] = { 0.4f, 0.25f, 0.1f, 1.0f };
	GLfloat tree_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat tree_shininess[] = { 0 };
	GLfloat leaf_ambuse[] = { 0.05f, 0.05f, 0.05f, 1.0f };
	GLfloat leaf_diffuse[] = { 0.6f, 0.8f, 0.4f, 1.0f };
	GLfloat leaf_emission[] = { 0.2f, 0.4f, 0.1f, 1.0f };
	GLfloat leaf_specular[] = { 0.0f, 0.8f, 0.0f, 1.0f };
	GLfloat leaf_shininess[] = { 10 };
	if (buttons[12].toggle == false) {
		GLfloat tree_ambuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat tree_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat tree_emission[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat tree_specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat tree_shininess[] = { 0 };
		GLfloat leaf_ambuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat leaf_diffuse[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat leaf_emission[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat leaf_specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat leaf_shininess[] = { 00 };
	}
	// tree material
	glNewList(TREE_MAT, GL_COMPILE);
	if (buttons[12].toggle == true) {
		glMaterialfv(GL_FRONT, GL_AMBIENT, tree_ambuse);
		glMaterialfv(GL_FRONT, GL_EMISSION, tree_emission);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, tree_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, tree_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, tree_shininess);
	}
	glEndList();
	// leaf material
	glNewList(LEAF_MAT, GL_COMPILE);
	if (buttons[12].toggle == true) {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, leaf_ambuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, leaf_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, leaf_emission);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, leaf_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, leaf_shininess);
	}
	glEndList();
	// steam
	glNewList(STEM, GL_COMPILE);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cylquad, 0.1, 0.08, 1, 10, 2);
	glPopMatrix();
	glEndList();
	// leaf
	glNewList(LEAF, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	glNormal3f(-0.1, 0, 0.25);
	glVertex3f(0, 0, 0);
	glVertex3f(0.25, 0.25, 0.1);
	glVertex3f(0, 0.5, 0);
	glNormal3f(0.1, 0, 0.25);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.5, 0);
	glVertex3f(-0.25, 0.25, 0.1);
	glEnd();
	glEndList();
	// steam&leaf
	glNewList(STEMANDLEAVES, GL_COMPILE);
	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
	glCallList(STEM);
	glCallList(LEAF_MAT);
	for (i = 0; i < 3; i++) {
		glTranslatef(0, 0.333, 0);
		glRotatef(90, 0, 1, 0);
		glPushMatrix();
		glRotatef(0, 0, 1, 0);
		glRotatef(50, 1, 0, 0);
		glCallList(LEAF);
		glPopMatrix();
		glPushMatrix();
		glRotatef(180, 0, 1, 0);
		glRotatef(60, 1, 0, 0);
		glCallList(LEAF);
		glPopMatrix();
	}
	glPopAttrib();
	glPopMatrix();
	glEndList();
	//
	glNewList(FULLTREE, GL_COMPILE);
	glPushMatrix();
	glPushAttrib(GL_LIGHTING_BIT);
	glCallList(TREE_MAT);
	glTranslatef(0, -1, 0);
	FractalTree(0);
	glPopAttrib();
	glPopMatrix();
	glEndList();
}

void drawFractals() {
}

struct fractal {
	bool active;
	float x;
	float y;
	float z;
};

fractal newFractal(float x, float y, float z);
void initFractals();
void displayFractals();

#define maxFractals 20
fractal fractals[maxFractals];
int fractalAmount;

fractal newFractal(float x, float y, float z) {
	fractalAmount++;
	fractal theFractal;
	theFractal.active = true;
	theFractal.x = x;
	theFractal.y = y;
	theFractal.z = z;
	return theFractal;
}

void initFractals() {
	fractalAmount = 0;
	if (currentLevel == -1) {
		fractals[fractalAmount - 1] = newFractal(-28.5f, 0.0f, 20.0f);
	}

}

void displayFractals() {
	if (buttons[8].toggle == true) {
		for (int i = 0; i < fractalAmount; i++) {
			if (fractals[i].active == true) {
				if (abs(camx - fractals[i].x) < 120 && abs(camz - fractals[i].z) < 120) {
					glPushMatrix();
					glTranslatef(fractals[i].x, fractals[i].y, fractals[i].z);
					//glRotatef(90.0, 0.0, 0.0, 1.0);
					glScalef(20.0, 20.0, 20.0);
					glCallList(FULLTREE);
					//drawFractals();
					glScalef(1.0 / 20.0, 1.0 / 20.0, 1.0 / 20.0);
					//glRotatef(-90.0, 0.0, 0.0, 1.0);
					glTranslatef(-fractals[i].x, -fractals[i].y, -fractals[i].z);
					glPopMatrix();
					//objPlacementTRS(drawFractals, fractals[i].x, fractals[i].y, fractals[i].z, 0.0, 0.0, 90.0, 0.5, 0.5, 0.5);
				}
			}
		}
	}
}