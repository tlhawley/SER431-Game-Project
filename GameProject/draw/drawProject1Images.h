
void drawProject1_mawebbe1();
void drawProject1_ppnguye2();
void drawProject1_tlhawley();

// 2Do: Add project 1 image functions
//void drawProject1_???();
//void drawProject1_???();

void drawProject1_mawebbe1() {

	// Borders
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor4f(0.1, 0.1, 0.1, 1.0);
	glVertex3f((-10 - 250) / 250.0, -(-10 - 250) / 250.0, 0.02);  // vertices of the triangl 1
	glVertex3f((510 - 250) / 250.0, -(-10 - 250) / 250.0, 0.02);
	glColor4f(0.1, 0.1, 0.1, 1.0);
	glVertex3f((510 - 250) / 250.0, -(510 - 250) / 250.0, 0.02);
	glVertex3f((-10 - 250) / 250.0, -(510 - 250) / 250.0, 0.02);
	glEnd();

	// Sky Background
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor4f(0.25, 0.5, 1.0, 1.0);
	glVertex3f((0 - 250) / 250.0, -(0 - 250) / 250.0, 0.01);  // vertices of the triangl 1
	glVertex3f((500 - 250) / 250.0, -(0 - 250) / 250.0, 0.01);
	glColor4f(0.8, 0.9, 1.0, 1.0);
	glVertex3f((500 - 250) / 250.0, -(500 - 250) / 250.0, 0.01);
	glVertex3f((0 - 250) / 250.0, -(500 - 250) / 250.0, 0.01);
	glEnd();

	// Bright Red Shapes
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(192 / 255.0, 0.0, 0.0);
	glVertex2f((167 - 250) / 250.0, -(131 - 250) / 250.0);  // vertices of the triangl 1
	glVertex2f((208 - 250) / 250.0, -(114 - 250) / 250.0);
	glVertex2f((201 - 250) / 250.0, -(306 - 250) / 250.0);
	glVertex2f((156 - 250) / 250.0, -(354 - 250) / 250.0);
	glEnd();

	glBegin(GL_POLYGON);  // fill connected polygon
	glVertex2f((284 - 250) / 250.0, -(289 - 250) / 250.0);
	glVertex2f((284 - 250) / 250.0, -(238 - 250) / 250.0);
	glVertex2f((323 - 250) / 250.0, -(228 - 250) / 250.0);
	glVertex2f((324 - 250) / 250.0, -(326 - 250) / 250.0);
	glEnd();

	glBegin(GL_POLYGON);  // fill connected polygon
	glVertex2f((284 - 250) / 250.0, -(289 - 250) / 250.0);
	glVertex2f((324 - 250) / 250.0, -(326 - 250) / 250.0);
	glVertex2f((156 - 250) / 250.0, -(354 - 250) / 250.0);
	glVertex2f((201 - 250) / 250.0, -(306 - 250) / 250.0);
	glEnd();

	// Dim Red Shapes
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(128 / 255.0, 0.0, 0.0);
	glVertex2f((208 - 250) / 250.0, -(114 - 250) / 250.0);
	glVertex2f((201 - 250) / 250.0, -(306 - 250) / 250.0);
	glVertex2f((243 - 250) / 250.0, -(298 - 250) / 250.0);
	glVertex2f((246 - 250) / 250.0, -(188 - 250) / 250.0);
	glEnd();

	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(128 / 255.0, 0.0, 0.0);
	glVertex2f((208 - 250) / 250.0, -(114 - 250) / 250.0);
	glVertex2f((246 - 250) / 250.0, -(188 - 250) / 250.0);
	glVertex2f((323 - 250) / 250.0, -(227 - 250) / 250.0);
	glVertex2f((350 - 250) / 250.0, -(197 - 250) / 250.0);
	glEnd();

	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(128 / 255.0, 0.0, 0.0);
	glVertex2f((323 - 250) / 250.0, -(227 - 250) / 250.0);
	glVertex2f((350 - 250) / 250.0, -(197 - 250) / 250.0);
	glVertex2f((351 - 250) / 250.0, -(334 - 250) / 250.0);
	glVertex2f((324 - 250) / 250.0, -(326 - 250) / 250.0);
	glEnd();

	// Red shape dark shading
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f((246 - 250) / 250.0, -(188 - 250) / 250.0);
	glVertex2f((325 - 250) / 250.0, -(228 - 250) / 250.0);
	glVertex2f((285 - 250) / 250.0, -(238 - 250) / 250.0);
	glVertex2f((245 - 250) / 250.0, -(220 - 250) / 250.0);
	glEnd();

	// Red shape dark shading
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f((156 - 250) / 250.0, -(354 - 250) / 250.0);
	glVertex2f((324 - 250) / 250.0, -(325 - 250) / 250.0);
	glVertex2f((351 - 250) / 250.0, -(334 - 250) / 250.0);
	glVertex2f((185 - 250) / 250.0, -(361 - 250) / 250.0);
	glEnd();

	// Bright Green Shape
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 192 / 255.0, 0.0);
	glVertex2f((364 - 250) / 250.0, -(70 - 250) / 250.0);
	glVertex2f((428 - 250) / 250.0, -(42 - 250) / 250.0);
	glVertex2f((428 - 250) / 250.0, -(115 - 250) / 250.0);
	glVertex2f((364 - 250) / 250.0, -(135 - 250) / 250.0);
	glEnd();

	// Dim Green shading
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 128 / 255.0, 0.0);
	glVertex2f((428 - 250) / 250.0, -(42 - 250) / 250.0);
	glVertex2f((428 - 250) / 250.0, -(115 - 250) / 250.0);
	glVertex2f((490 - 250) / 250.0, -(134 - 250) / 250.0);
	glVertex2f((490 - 250) / 250.0, -(66 - 250) / 250.0);
	glEnd();

	// Green shape Dark Shading
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f((428 - 250) / 250.0, -(115 - 250) / 250.0);
	glVertex2f((490 - 250) / 250.0, -(134 - 250) / 250.0);
	glVertex2f((429 - 250) / 250.0, -(148 - 250) / 250.0);
	glVertex2f((364 - 250) / 250.0, -(135 - 250) / 250.0);
	glEnd();

	// Bright Blue Shape
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 0.0, 192 / 255.0);
	glVertex2f((364 - 350 - 250) / 250.0, -(70 - 220) / 250.0);
	glVertex2f((428 - 350 - 250) / 250.0, -(42 - 220) / 250.0);
	glVertex2f((428 - 350 - 250) / 250.0, -(115 - 220) / 250.0);
	glVertex2f((364 - 350 - 250) / 250.0, -(135 - 220) / 250.0);
	glEnd();

	// Dim Blue shading
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 0.0, 128 / 255.0);
	glVertex2f((428 - 350 - 250) / 250.0, -(42 - 220) / 250.0);
	glVertex2f((428 - 350 - 250) / 250.0, -(115 - 220) / 250.0);
	glVertex2f((490 - 350 - 250) / 250.0, -(134 - 220) / 250.0);
	glVertex2f((490 - 350 - 250) / 250.0, -(66 - 220) / 250.0);
	glEnd();

	// Blue shape Dark Shading
	glBegin(GL_POLYGON);  // fill connected polygon
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f((428 - 350 - 250) / 250.0, -(115 - 220) / 250.0);
	glVertex2f((490 - 350 - 250) / 250.0, -(134 - 220) / 250.0);
	glVertex2f((429 - 350 - 250) / 250.0, -(148 - 220) / 250.0);
	glVertex2f((364 - 350 - 250) / 250.0, -(135 - 220) / 250.0);
	glEnd();

}










void drawProject1_ppnguye2() {

	glBegin(GL_LINE_LOOP);
	glVertex2f(2.00f, -2.00f); glVertex2f(-5.50f, 5.50f);
	glVertex2f(-8.50f, 2.50f); glVertex2f(-3.50f, -2.50f);
	glVertex2f(-2.50f, -1.50f); glVertex2f(-6.50f, 2.50f);
	glVertex2f(-5.50f, 3.50f); glVertex2f(1.00f, -3.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-6.00f, 0.00f); glVertex2f(-8.50f, -2.50f);
	glVertex2f(-5.00f, -6.00f); glVertex2f(-0.50f, -1.50f);
	glVertex2f(-1.50f, -0.50f); glVertex2f(-5.00f, -4.00f);
	glVertex2f(-6.50f, -2.50f); glVertex2f(-5.00f, -1.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-4.00f, 0.00f); glVertex2f(-5.00f, 1.00f);
	glVertex2f(-4.00f, 2.00f); glVertex2f(-3.00f, 1.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-2.00f, 2.00f); glVertex2f(-3.00f, 3.00f);
	glVertex2f(-1.00f, 5.00f); glVertex2f(0.00f, 4.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.50f, -2.50f); glVertex2f(-2.50f, -3.50f);
	glVertex2f(1.50f, -7.50f); glVertex2f(0.00f, -9.00f);
	glVertex2f(-1.50f, -7.50f); glVertex2f(0.00f, -6.00f);
	glVertex2f(-1.00f, -5.00f); glVertex2f(-3.50f, -7.50f);
	glVertex2f(0.00f, -11.00f); glVertex2f(3.50f, -7.50f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.00f, -4.00f); glVertex2f(1.00f, -5.00f);
	glVertex2f(5.00f, -1.00f); glVertex2f(4.00f, 0.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(2.00f, -4.00f); glVertex2f(4.50f, -6.50f);
	glVertex2f(8.50f, -2.50f); glVertex2f(3.50f, 2.50f);
	glVertex2f(2.50f, 1.50f); glVertex2f(6.50f, -2.50f);
	glVertex2f(4.50f, -4.50f); glVertex2f(3.00f, -3.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.50f, -0.50f); glVertex2f(-0.50f, 0.50f);
	glVertex2f(5.00f, 6.00f); glVertex2f(8.50f, 2.50f);
	glVertex2f(6.00f, 0.00f); glVertex2f(5.00f, 1.00f);
	glVertex2f(6.50f, 2.50f); glVertex2f(5.00f, 4.00f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(1.50f, 2.50f); glVertex2f(2.50f, 3.50f);
	glVertex2f(-1.50f, 7.50f); glVertex2f(0.00f, 9.00f);
	glVertex2f(1.50f, 7.50f); glVertex2f(0.00f, 6.00f);
	glVertex2f(1.00f, 5.00f); glVertex2f(3.50f, 7.50f);
	glVertex2f(0.00f, 11.00f); glVertex2f(-3.50f, 7.50f);
	glEnd();
}












void drawProject1_tlhawley() {

	GLfloat obX = 0.0f, obY = 0.0f, gemR = 0.65f, gemB = 0.0f, gemG = 0.0f;

	glShadeModel(GL_SMOOTH);

	glTranslatef(obX, obY, 0.0f); //Middle
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.1f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.0f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.1f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.1f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.1f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.1f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.2f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.1f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.2f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.2f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.2f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.2f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.3f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.2f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.3f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.3f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.3f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.3f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.4f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.3f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.4f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.4f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.4f);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(-0.05f, 0.4f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(-0.05f, 0.5f);
	glEnd();

	//Middle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f); glVertex2f(0.05f, 0.4f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(-0.05f, 0.5f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(0.05f, 0.5f);
	glEnd();

	//Edge
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(-0.1f, 0.0f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(-0.05f, 0.0f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(-0.05f, 0.5f);
	glEnd();

	//Edge
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(0.1f, 0.0f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(0.05f, 0.0f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(0.05f, 0.5f);
	glEnd();

	//Tip
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(0.0f, 0.6f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(-0.05f, 0.5f);
	glColor3f(0.75f, 0.75f, 0.75f); glVertex2f(0.05f, 0.5f);
	glEnd();

	//Guard
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.2f, 0.0f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.2f, -0.03f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.2f, 0.0f);
	glEnd();

	//Guard
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.2f, 0.0f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.2f, -0.03f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.2f, -0.03f);
	glEnd();

	//Bauble
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.2f, 0.0f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.21f, 0.01);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.24f, 0.01);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.25f, 0.0f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.25f, -0.03f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.24f, -0.04f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.21f, -0.04f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.2f, -0.03f);
	glEnd();

	//Bauble
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.2f, 0.0f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.21f, 0.01f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.24f, 0.01f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.25f, 0.0f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.25f, -0.03f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.24f, -0.04f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.21f, -0.04f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.2f, -0.03f);
	glEnd();

	//Gem
	glTranslatef(obX, obY, 0.0f);
	glTranslatef(.225f, -.015f, 0.0f);
	glScaled(0.6f, 0.6f, 1.0f);
	glTranslatef(-.225f, .015f, 0.0f);

	glTranslatef(0.0f, 0.0, -0.001f);

	glBegin(GL_POLYGON);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.2f, 0.0f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.21f, 0.01);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.24f, 0.01);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.25f, 0.0f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.25f, -0.03f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.24f, -0.04f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.21f, -0.04f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.2f, -0.03f);
	glEnd();

	glTranslatef(0.0f, 0.0, 0.001f);
	glScaled(1 / 0.6f, 1 / 0.6f, 1.0f);

	//Gem
	glTranslatef(obX, obY, 0.0f);
	glTranslatef(-.225f, -.015f, 0.0f);
	glScaled(0.6f, 0.6f, 1.0f);
	glTranslatef(.225f, .015f, 0.0f);

	glTranslatef(-0.15f, 0.01f, -0.001f);

	glBegin(GL_POLYGON);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.2f, 0.0f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.21f, 0.01f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.24f, 0.01f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.25f, 0.0f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.25f, -0.03f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.24f, -0.04f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.21f, -0.04f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.2f, -0.03f);
	glEnd();

	glTranslatef(0.15f, 0.01f, 0.002f);
	//glScaled(1.5f, 1.5f, 1.5f);
	//glTranslatef(-0.05f, 0.0f, 0.001f);

	//Handle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.3633f, 0.1806f, 0.050f); glVertex2f(0.03f, -0.33f);
	glColor3f(0.3633f, 0.1806f, 0.050f); glVertex2f(-0.03f, -0.03f);
	glColor3f(0.3633f, 0.1806f, 0.050f); glVertex2f(0.03f, -0.03f);
	glEnd();

	//Handle
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.3633f, 0.1806f, 0.050f); glVertex2f(0.03f, -0.33f);
	glColor3f(0.3633f, 0.1806f, 0.050f); glVertex2f(-0.03f, -0.33f);
	glColor3f(0.3633f, 0.1806f, 0.050f); glVertex2f(-0.03f, -0.03f);
	glEnd();

	//Handle Bauble
	glTranslatef(obX, obY, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.03f, -0.33f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.05f, -0.35f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.05f, -0.41f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(0.03f, -0.43f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.03f, -0.43f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.05f, -0.41f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.05f, -0.35f);
	glColor3f(0.25f, 0.25f, 0.25f); glVertex2f(-0.03f, -0.33f);
	glEnd();

	//Handle Gem
	glTranslatef(obX, obY, 0.0f);
	glTranslatef(0.0f, -.38f, 0.0f);
	glScaled(0.6f, 0.6f, 1.0f);
	glTranslatef(0.0f, .38f, -0.001f);
	glBegin(GL_POLYGON);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.03f, -0.33f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.05f, -0.35f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.05f, -0.41f);
	glColor3f(gemR, gemG, gemB); glVertex2f(0.03f, -0.43f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.03f, -0.43f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.05f, -0.41f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.05f, -0.35f);
	glColor3f(gemR, gemG, gemB); glVertex2f(-0.03f, -0.33f);
	glEnd();

	/*
	glLoadIdentity();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
	glRotatef(camAngX, 1.0, 0.0, 0.0);
	*/


	glTranslatef(0.0f, -.38f, 0.001f);
	glTranslatef(0.0f, .38f, 0.0f);
	glScaled(1 / 0.6f, 1 / 0.6f, 1.0f);

	//glTranslatef(-obX * 4, -obY * 4, 0.0f);

	glTranslatef(-0.15f, -0.01f, -0.002f);

	glTranslatef(0.15f, -0.01f, 0.001f);
	glTranslatef(-.225f, -.015f, 0.0f);
	glScaled(1 / 0.6f, 1 / 0.6f, 1.0f);
	glTranslatef(.225f, .015f, 0.0f);
	//glTranslatef(-obX, -obY, 0.0f);
	glScaled(0.6f, 0.6f, 1.0f);
	glTranslatef(0.0f, 0.0, -0.001f);

	glTranslatef(0.0f, 0.0, 0.001f);
	glTranslatef(.225f, -.015f, 0.0f);
	glScaled(1 / 0.6f, 1 / 0.6f, 1.0f);
	glTranslatef(-.225f, .015f, 0.0f);
	glTranslatef(-obX * 18, -obY * 18 + 0.1, 0.0f);


}



