
// Displays heart sprites to indicate player health

void draw2DHealthBar();

void draw2DHealthBar(){


	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, height - width * 0.5, width*0.5, width*0.5);
	gluPerspective(0, 0, 0.1, 1000);


	glRotatef(90, 1, 0, 0);
	glScalef(0.08, 0.08, 0.08);

	setlight();
	setMaterialAdvanced(materialSkyBox);

	glTranslatef(-10.9f, 0, -11.2);
	
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

	glScalef(1/ 0.08, 1 / 0.08, 1 / 0.08);
	
	glRotatef(-90, 1, 0, 0);


}