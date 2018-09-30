
// This function translates, rotates, and scales an obj function to be displayed
// TRS (Translate, Rotate, Scale)

//void objPlacementTRS(void objFunction(), float scaleX, float scaleY, float scaleZ, float translateX, float translateY, float translateZ, float rotateX, float rotateY, float rotateZ) ;
void objPlacementTRS(void(*objFunction)(), float translateX, float translateY, float translateZ, float rotateX, float rotateY, float rotateZ, float scaleX, float scaleY, float scaleZ);

void objPlacementTRS(void(*objFunction)(), float translateX, float translateY, float translateZ, float rotateX, float rotateY, float rotateZ, float scaleX, float scaleY, float scaleZ) {
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotatef(rotateX, 1.0, 0.0, 0.0);
	glRotatef(rotateY, 0.0, 1.0, 0.0);
	glRotatef(rotateZ, 0.0, 0.0, 1.0);
	glScalef(scaleX, scaleY, scaleZ);
	objFunction();
	glScalef(1.0 / scaleX, 1.0 / scaleY, 1.0 / scaleZ);
	glRotatef(-rotateZ, 0.0, 0.0, 1.0);
	glRotatef(-rotateY, 0.0, 1.0, 0.0);
	glRotatef(-rotateX, 1.0, 0.0, 0.0);
	glTranslatef(-translateX, -translateY, -translateZ);
	glPopMatrix();
}