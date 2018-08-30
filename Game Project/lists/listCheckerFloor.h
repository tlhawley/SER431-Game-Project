

GLuint listCheckerFloor();

GLuint listCheckerFloor(int num) {

	GLuint checkerFloor = glGenLists(num);

	glNewList(checkerFloor, GL_COMPILE);

	int num2 = 0;
	setmaterial3(0.1f, 0.7f, 0.7f, 0.7f, 0.75f, 0.0f);
	for (int z = 0; z < 31; z++) {
		for (int x = 0; x < 31; x++) {
			num2++;
			if (num2 == 2) { num2 = 0; }

			if (num2 == 0) {
				setmaterial3(0.1f, 0.7f, 0.7f, 0.7f, 0.5f, 0.0f);

				glTranslatef(x * 2 - 30, 0, z * 2 - 30);
				glBegin(GL_TRIANGLES);
				glNormal3f(0, -1.0f, 0);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-1.0, 0.0, 1.0);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.0, 0.0, 1.0);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0, 0.0, -1.0);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-1.0, 0.0, 1.0);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0, 0.0, -1.0);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-1.0, 0.0, -1.0);
				glEnd();
				glTranslatef(-x * 2 + 30, 0, -z * 2 + 30);
			}

		}
	}

	num2 = 0;
	setmaterial3(0.1f, 0.1f, 0.1f, 0.1f, 0.75f, 0.0f);
	for (int z = 0; z < 31; z++) {
		for (int x = 0; x < 31; x++) {
			num2++;
			if (num2 == 2) { num2 = 0; }

			if (num2 != 0) {
				glTranslatef(x * 2 - 30, 0, z * 2 - 30);
				glBegin(GL_TRIANGLES);
				glNormal3f(0, -1.0f, 0);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-1.0, 0.0, 1.0);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(1.0, 0.0, 1.0);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0, 0.0, -1.0);

				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(-1.0, 0.0, 1.0);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(1.0, 0.0, -1.0);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(-1.0, 0.0, -1.0);
				glEnd();
				glTranslatef(-x * 2 + 30, 0, -z * 2 + 30);
			}
		}
	}

	glEnd();

	glEndList();

	return checkerFloor;

}