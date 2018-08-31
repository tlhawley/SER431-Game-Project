
GLuint listBoxBounds();

GLuint listBoxBounds(int num){
	// Creates the room
	GLuint boxBounds = glGenLists(num);

	glNewList(boxBounds, GL_COMPILE);
	glBegin(GL_TRIANGLES);

	//Center Base
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-10, 0, 10);
	glVertex3f(10, 0, -10);
	glVertex3f(10, 0, 10);

	glVertex3f(10, 0, -10);
	glVertex3f(-10, 0, -10);
	glVertex3f(-10, 0, 10);

	//Center Roof
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-10, 10, 10);
	glVertex3f(10, 10, -10);
	glVertex3f(10, 10, 10);

	glVertex3f(10, 10, -10);
	glVertex3f(-10, 10, -10);
	glVertex3f(-10, 10, 10);






	//Front
	glColor3f(0.7, 0.7, 0.3);
	glVertex3f(-10, 10, -30);
	glVertex3f(10, 10, -30);
	glVertex3f(10, 0, -30);

	glVertex3f(10, 0, -30);
	glVertex3f(-10, 0, -30);
	glVertex3f(-10, 10, -30);

	//Front Base
	glColor3f(0.9, 0.9, 0.4);
	glVertex3f(-10, 0, -10);
	glVertex3f(10, 0, -30);
	glVertex3f(10, 0, -10);

	glVertex3f(10, 0, -30);
	glVertex3f(-10, 0, -30);
	glVertex3f(-10, 0, -10);

	//Front Roof
	glColor3f(0.5, 0.5, 0.2);
	glVertex3f(-10, 10, -10);
	glVertex3f(10, 10, -30);
	glVertex3f(10, 10, -10);

	glVertex3f(10, 10, -30);
	glVertex3f(-10, 10, -30);
	glVertex3f(-10, 10, -10);


	//Front Left
	glColor3f(0.75, 0.75, 0.3);
	glVertex3f(-10, 10, -30);
	glVertex3f(-10, 10, -10);
	glVertex3f(-10, 0, -10);

	glVertex3f(-10, 0, -10);
	glVertex3f(-10, 0, -30);
	glVertex3f(-10, 10, -30);


	//Front Right
	glColor3f(0.6, 0.6, 0.2);
	glVertex3f(10, 10, -30);
	glVertex3f(10, 10, -10);
	glVertex3f(10, 0, -10);

	glVertex3f(10, 0, -10);
	glVertex3f(10, 0, -30);
	glVertex3f(10, 10, -30);











	// Back
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-10, 10, 30);
	glVertex3f(10, 10, 30);
	glVertex3f(10, 0, 30);

	glVertex3f(10, 0, 30);
	glVertex3f(-10, 0, 30);
	glVertex3f(-10, 10, 30);


	//Back Base
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-10, 0, 10);
	glVertex3f(10, 0, 30);
	glVertex3f(10, 0, 10);

	glVertex3f(10, 0, 30);
	glVertex3f(-10, 0, 30);
	glVertex3f(-10, 0, 10);

	//Back Roof
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-10, 10, 10);
	glVertex3f(10, 10, 30);
	glVertex3f(10, 10, 10);

	glVertex3f(10, 10, 30);
	glVertex3f(-10, 10, 30);
	glVertex3f(-10, 10, 10);



	//Back Left
	glColor3f(0.75, 0.75, 0.75);
	glVertex3f(-10, 10, 30);
	glVertex3f(-10, 10, 10);
	glVertex3f(-10, 0, 10);

	glVertex3f(-10, 0, 10);
	glVertex3f(-10, 0, 30);
	glVertex3f(-10, 10, 30);


	//Back Right
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(10, 10, 30);
	glVertex3f(10, 10, 10);
	glVertex3f(10, 0, 10);

	glVertex3f(10, 0, 10);
	glVertex3f(10, 0, 30);
	glVertex3f(10, 10, 30);











	//Left
	/*
	glColor3f(0.3, 0.3, 0.75);
	glVertex3f(-30, 10, -10);
	glVertex3f(-30, 10, 10);
	glVertex3f(-30, 0, 10);

	glVertex3f(-30, 0, 10);
	glVertex3f(-30, 0, -10);
	glVertex3f(-30, 10, -10);
	*/

	/*
	Cboxes[CboxAmount - 1] = newCBox(-31, 5, 6, 2, 10, 8); // blue back wall
	Cboxes[CboxAmount - 1] = newCBox(-31, 5, -6, 2, 10, 8); // blue back wall
	Cboxes[CboxAmount - 1] = newCBox(-31, 7, 0, 2, 6, 4); // blue back wall
	*/

	glColor3f(0.3, 0.3, 0.75);
	glVertex3f(-30, 10, 2);
	glVertex3f(-30, 10, 10);
	glVertex3f(-30, 0, 10);

	glVertex3f(-30, 0, 10);
	glVertex3f(-30, 0, 2);
	glVertex3f(-30, 10, 2);

	glVertex3f(-30, 10, -2);
	glVertex3f(-30, 10, -10);
	glVertex3f(-30, 0, -10);
	glVertex3f(-30, 0, -10);
	glVertex3f(-30, 0, -2);
	glVertex3f(-30, 10, -2);

	glVertex3f(-30, 10, -2);
	glVertex3f(-30, 10, 2);
	glVertex3f(-30, 4, 2);
	glVertex3f(-30, 4, 2);
	glVertex3f(-30, 4, -2);
	glVertex3f(-30, 10, -2);



	//Left Base
	glColor3f(0.4, 0.4, 0.9);
	glVertex3f(-30, 0, 10);
	glVertex3f(-10, 0, -10);
	glVertex3f(-10, 0, 10);

	glVertex3f(-10, 0, -10);
	glVertex3f(-30, 0, -10);
	glVertex3f(-30, 0, 10);

	//Left Roof
	glColor3f(0.2, 0.2, 0.5);
	glVertex3f(-30, 10, 10);
	glVertex3f(-10, 10, -10);
	glVertex3f(-10, 10, 10);

	glVertex3f(-10, 10, -10);
	glVertex3f(-30, 10, -10);
	glVertex3f(-30, 10, 10);

	//Left Front
	glColor3f(0.3, 0.3, 0.7);
	glVertex3f(-30, 10, -10);
	glVertex3f(-10, 10, -10);
	glVertex3f(-10, 0, -10);

	glVertex3f(-10, 0, -10);
	glVertex3f(-30, 0, -10);
	glVertex3f(-30, 10, -10);


	//Left Back
	glColor3f(0.3, 0.3, 0.8);
	glVertex3f(-30, 10, 10);
	glVertex3f(-10, 10, 10);
	glVertex3f(-10, 0, 10);

	glVertex3f(-10, 0, 10);
	glVertex3f(-30, 0, 10);
	glVertex3f(-30, 10, 10);









	// Right
	glColor3f(0.6, 0.3, 0.3);
	glVertex3f(30, 10, -10);
	glVertex3f(30, 10, 10);
	glVertex3f(30, 0, 10);

	glVertex3f(30, 0, 10);
	glVertex3f(30, 0, -10);
	glVertex3f(30, 10, -10);


	//Right Base
	glColor3f(0.9, 0.4, 0.4);
	glVertex3f(30, 0, 10);
	glVertex3f(10, 0, -10);
	glVertex3f(10, 0, 10);

	glVertex3f(10, 0, -10);
	glVertex3f(30, 0, -10);
	glVertex3f(30, 0, 10);

	//Right Roof
	glColor3f(0.5, 0.2, 0.2);
	glVertex3f(30, 10, 10);
	glVertex3f(10, 10, -10);
	glVertex3f(10, 10, 10);

	glVertex3f(10, 10, -10);
	glVertex3f(30, 10, -10);
	glVertex3f(30, 10, 10);

	//Left Front
	glColor3f(0.7, 0.3, 0.3);
	glVertex3f(30, 10, -10);
	glVertex3f(10, 10, -10);
	glVertex3f(10, 0, -10);

	glVertex3f(10, 0, -10);
	glVertex3f(30, 0, -10);
	glVertex3f(30, 10, -10);


	//Left Back
	glColor3f(0.8, 0.3, 0.3);
	glVertex3f(30, 10, 10);
	glVertex3f(10, 10, 10);
	glVertex3f(10, 0, 10);

	glVertex3f(10, 0, 10);
	glVertex3f(30, 0, 10);
	glVertex3f(30, 10, 10);




	glEnd();
	glEndList();
	return boxBounds;
}