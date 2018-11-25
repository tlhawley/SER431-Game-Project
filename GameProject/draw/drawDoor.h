
void drawDoor();
void drawDoorLeft();
void drawDoorRight();

void drawDoor() {
	//glCallList(drawList5);
	//setmaterial2(0.1f, 0.7f, 0.5f, 0.1f, 0.9f); //gold
	//setmaterial2(0.1f, 0.5f, 0.5f, 0.5f, 0.9f);
	setMaterialAdvanced(materialChrome);
	glCallList(meshDoorFrame.l1);
}

void drawDoorLeft() {
	//setmaterial2(0.1f, 0.2f, 0.2f, 0.2f, 0.5f);
	setMaterialAdvanced(materialChrome);
	glCallList(meshDoorLeft.l1);
}

void drawDoorRight() {
	//setmaterial2(0.1f, 0.2f, 0.2f, 0.2f, 0.5f);
	setMaterialAdvanced(materialChrome);
	glCallList(meshDoorRight.l1);
}

void drawDoorLock() {
	//setmaterial2(0.1f, 0.7f, 0.5f, 0.1f, 0.9f); //gold
	//setmaterial2(0.1f, 0.5f, 0.5f, 0.5f, 0.9f);
	//setMaterialAdvanced(materialObsidian);
	setMaterialAdvanced(materialGold);
	glCallList(meshDoorLock.l1);
}

	/*
	glBegin(GL_TRIANGLES);
	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(-0.05, 3.0, 0.5);
	glVertex3f(-0.05, 3.0, -0.5);
	glVertex3f(-1.5, 3.0, -0.5);

	glColor3f(0.0875, 0.0875, 0.0875);
	glVertex3f(-1.5, 3.0, 0.5);
	glVertex3f(-1.5, 0.0, -0.5);
	glVertex3f(-1.5, 0.0, 0.5);

	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.05, 0.0, -0.5);
	glVertex3f(-1.5, 3.0, -0.5);
	glVertex3f(-0.05, 3.0, -0.5);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(-0.05, 0.0, -0.5);
	glVertex3f(-0.05, 0.0, 0.5);
	glVertex3f(-1.5, 0.0, 0.5);

	glColor3f(0.125, 0.125, 0.125);
	glVertex3f(-0.05, 0.0, 0.5);
	glVertex3f(-1.5, 3.0, 0.5);
	glVertex3f(-1.5, 0.0, 0.5);

	glColor3f(0.12133875, 0.12133875, 0.12133875);
	glVertex3f(-0.0, 0.0, -0.45);
	glVertex3f(-0.05, 3.0, -0.5);
	glVertex3f(-0.0, 3.0, -0.45);

	glColor3f(0.13901626, 0.13901626, 0.13901626);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(-0.05, 0.0, 0.5);
	glVertex3f(0.0, 0.0, 0.45);

	glColor3f(0.1375, 0.1375, 0.1375);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(0.0, 0.0, 0.45);
	glVertex3f(-0.0, 0.0, -0.45);

	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(-1.5, 3.0, -0.5);
	glVertex3f(-1.5, 3.0, 0.5);
	glVertex3f(-0.05, 3.0, 0.5);

	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(-0.05, 3.0, 0.5);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(-0.0, 3.0, -0.45);

	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(-0.05, 3.0, -0.5);
	glVertex3f(-0.05, 3.0, 0.5);

	glColor3f(0.0875, 0.0875, 0.0875);
	glVertex3f(-1.5, 3.0, 0.5);
	glVertex3f(-1.5, 3.0, -0.5);
	glVertex3f(-1.5, 0.0, -0.5);

	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-0.05, 0.0, -0.5);
	glVertex3f(-1.5, 0.0, -0.5);
	glVertex3f(-1.5, 3.0, -0.5);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(-1.5, 0.0, 0.5);
	glVertex3f(-1.5, 0.0, -0.5);
	glVertex3f(-0.05, 0.0, -0.5);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(-0.05, 0.0, -0.5);
	glVertex3f(-0.0, 0.0, -0.45);
	glVertex3f(0.0, 0.0, 0.45);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(0.0, 0.0, 0.45);
	glVertex3f(-0.05, 0.0, 0.5);
	glVertex3f(-0.05, 0.0, -0.5);

	glColor3f(0.125, 0.125, 0.125);
	glVertex3f(-0.05, 0.0, 0.5);
	glVertex3f(-0.05, 3.0, 0.5);
	glVertex3f(-1.5, 3.0, 0.5);

	glColor3f(0.12133875, 0.12133875, 0.12133875);
	glVertex3f(-0.0, 0.0, -0.45);
	glVertex3f(-0.05, 0.0, -0.5);
	glVertex3f(-0.05, 3.0, -0.5);

	glColor3f(0.13901626, 0.13901626, 0.13901626);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(-0.05, 3.0, 0.5);
	glVertex3f(-0.05, 0.0, 0.5);

	glColor3f(0.1375, 0.1375, 0.1375);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(0.0, 0.0, 0.45);

	glEnd();
	*/
//}


/*
void drawDoorRight() {
	glBegin(GL_TRIANGLES);
	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(0.05, 3.0, -0.5);
	glVertex3f(0.05, 3.0, 0.5);
	glVertex3f(1.5, 3.0, 0.5);

	glColor3f(0.1375, 0.1375, 0.1375);
	glVertex3f(1.5, 3.0, -0.5);
	glVertex3f(1.5, 0.0, 0.5);
	glVertex3f(1.5, 0.0, -0.5);

	glColor3f(0.125, 0.125, 0.125);
	glVertex3f(0.05, 0.0, 0.5);
	glVertex3f(1.5, 3.0, 0.5);
	glVertex3f(0.05, 3.0, 0.5);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(0.05, 0.0, 0.5);
	glVertex3f(0.05, 0.0, -0.5);
	glVertex3f(1.5, 0.0, -0.5);

	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.05, 0.0, -0.5);
	glVertex3f(1.5, 3.0, -0.5);
	glVertex3f(1.5, 0.0, -0.5);

	glColor3f(0.103661254, 0.103661254, 0.103661254);
	glVertex3f(0.0, 0.0, 0.45);
	glVertex3f(0.05, 3.0, 0.5);
	glVertex3f(0.0, 3.0, 0.45);

	glColor3f(0.08598375, 0.08598375, 0.08598375);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(0.05, 0.0, -0.5);
	glVertex3f(-0.0, 0.0, -0.45);

	glColor3f(0.0875, 0.0875, 0.0875);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(-0.0, 0.0, -0.45);
	glVertex3f(0.0, 0.0, 0.45);

	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(1.5, 3.0, 0.5);
	glVertex3f(1.5, 3.0, -0.5);
	glVertex3f(0.05, 3.0, -0.5);

	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(0.05, 3.0, -0.5);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(0.0, 3.0, 0.45);

	glColor3f(0.16250001, 0.16250001, 0.16250001);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(0.05, 3.0, 0.5);
	glVertex3f(0.05, 3.0, -0.5);

	glColor3f(0.1375, 0.1375, 0.1375);
	glVertex3f(1.5, 3.0, -0.5);
	glVertex3f(1.5, 3.0, 0.5);
	glVertex3f(1.5, 0.0, 0.5);

	glColor3f(0.125, 0.125, 0.125);
	glVertex3f(0.05, 0.0, 0.5);
	glVertex3f(1.5, 0.0, 0.5);
	glVertex3f(1.5, 3.0, 0.5);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(1.5, 0.0, -0.5);
	glVertex3f(1.5, 0.0, 0.5);
	glVertex3f(0.05, 0.0, 0.5);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(0.05, 0.0, 0.5);
	glVertex3f(0.0, 0.0, 0.45);
	glVertex3f(-0.0, 0.0, -0.45);

	glColor3f(0.0625, 0.0625, 0.0625);
	glVertex3f(-0.0, 0.0, -0.45);
	glVertex3f(0.05, 0.0, -0.5);
	glVertex3f(0.05, 0.0, 0.5);

	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(0.05, 0.0, -0.5);
	glVertex3f(0.05, 3.0, -0.5);
	glVertex3f(1.5, 3.0, -0.5);

	glColor3f(0.103661254, 0.103661254, 0.103661254);
	glVertex3f(0.0, 0.0, 0.45);
	glVertex3f(0.05, 0.0, 0.5);
	glVertex3f(0.05, 3.0, 0.5);

	glColor3f(0.08598375, 0.08598375, 0.08598375);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(0.05, 3.0, -0.5);
	glVertex3f(0.05, 0.0, -0.5);

	glColor3f(0.0875, 0.0875, 0.0875);
	glVertex3f(0.0, 3.0, 0.45);
	glVertex3f(-0.0, 3.0, -0.45);
	glVertex3f(-0.0, 0.0, -0.45);
	glEnd();
}
*/