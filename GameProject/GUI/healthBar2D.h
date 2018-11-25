
void draw2DHealthBar();

void draw2DHealthBar(){


	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glViewport(width * 0.01, height - width * 0.03, width*0.25, width*0.02);
	//glViewport(0, height, width*0.5, width*0.5);
	glViewport(0, height - width * 0.5, width*0.5, width*0.5);
	gluPerspective(0, 0, 0.1, 1000);

	/*
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
	/*
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
	*/


	// TODO: hearts need to update based on the players health
	glRotatef(90, 1, 0, 0);

	glScalef(0.08, 0.08, 0.08);

	setlight();
	setMaterialAdvanced(materialSkyBox);

	glTranslatef(-10.9f, 0, -11.2);

	//glTranslatef(-10.9f, 0, -11.2);
	//glCallList(meshHeartUI[0]);

	
	if (health > 0) {

		if(health <= 4) {
			glCallList(meshHeartUI[4 - health].l1);
			glTranslatef(2.25, 0, 0); glCallList(meshHeartUI[4].l1);
			glTranslatef(2.25, 0, 0); glCallList(meshHeartUI[4].l1);
			glTranslatef(2.25, 0, 0); glCallList(meshHeartUI[4].l1);
			glTranslatef(2.25, 0, 0); glCallList(meshHeartUI[4].l1);
		} else {
		 glCallList(meshHeartUI[0].l1);
		 if(health <= 8) {
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[8 - health].l1);
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[4].l1);
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[4].l1);
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[4].l1);
		 } else {
		 glTranslatef(2.25, 0, 0); glCallList(meshHeartUI[0].l1);
		 if(health <= 12) {
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[12 - health].l1);
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[4].l1);
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[4].l1);
		 } else {
		 glTranslatef(2.25, 0, 0);
		 glCallList(meshHeartUI[0].l1);
		 if(health <= 16) {
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[16 - health].l1);
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[4].l1);
		 } else {
		 glTranslatef(2.25, 0, 0);
		 glCallList(meshHeartUI[0].l1);
		 if(health <= 20) {
			 glTranslatef(2.25, 0, 0);
			 glCallList(meshHeartUI[20 - health].l1);
		 }
		}
	 }
	}
	}
	}
	
	//glTranslatef(10.9f, 0, 11.2);
	//glTranslatef(10.9f - 9.0f, 0, 11.2);

	/*
	//glRotatef(180, 0, 1, 0);
	glScalef(0.08, 0.08, 0.08);

	setlight();
	setMaterialAdvanced(materialSkyBox);

	glTranslatef(-10.9f, 0, -11.2);
	glCallList(meshHeartUI[0]);

	glTranslatef(2.25, 0, 0);
	glCallList(meshHeartUI[0]);
	glTranslatef(2.25, 0, 0);
	glCallList(meshHeartUI[0]);
	glTranslatef(2.25, 0, 0);
	glCallList(meshHeartUI[0]);
	glTranslatef(2.25, 0, 0);
	glCallList(meshHeartUI[0]);
	glTranslatef(-2.5, 0, 0);
	glTranslatef(-2.5, 0, 0);
	glTranslatef(-2.5, 0, 0);

	glTranslatef(10.9f, 0, 11.2);

	*/

	glScalef(1/ 0.08, 1 / 0.08, 1 / 0.08);
	
	//glRotatef(-180, 0, 1, 0);
	glRotatef(-90, 1, 0, 0);


}