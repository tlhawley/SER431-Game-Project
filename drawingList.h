
#include "lists/listBox.h"
#include "lists/listBoxBounds.h"
#include "lists/listHealthPack.h"
#include "lists/listSpinSpikes.h"
#include "lists/listClockFrame.h"
#include "lists/listDoor.h"
#include "lists/listCheckerFloor.h"

void drawingList();

GLuint drawList;
GLuint drawList2;
GLuint drawList3;
GLuint drawList4;
GLuint drawList5;
GLuint drawList6;

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// DDDD   RRRR   AAAAA  W   W         L      IIIII  SSSSS  TTTTT
// D   D  R   R  A   A  W W W         L        I    S        T  
// D   D  RRRR   AAAAA  W W W         L        I    SSSSS    T  
// D   D  R   R  A   A  W W W         L        I        S    T  
// DDDD   R   R  A   A   W W          LLLLL  IIIII  SSSSS    T  

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX



// drawingList
void drawingList() {

	GLuint boxBounds = listBoxBounds(2);
	GLuint spinSpikes = listSpinSpikes(3);
	GLuint clockFrame = listClockFrame(4);
	GLuint healthPack = listHealthPack(5);
	GLuint box = listBox(6);
	GLuint door = listDoor(7);
	GLuint checkerFloor = listCheckerFloor(8);

	// Matrix of list thingy
	GLuint worldDL = glGenLists(1);
	glNewList(worldDL, GL_COMPILE);

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glCallList(boxBounds);

	glTranslatef(-29.9, 7.25, 0);
	glScalef(2.8, 2.8, 2.8);
	glCallList(clockFrame);
	glScalef(1/2.8, 1/2.8, 1/2.8);
	glTranslatef(29.9, -7.25, 0);

	glTranslatef(-30.1, 7.25, 0);
	glScalef(2.8, 2.8, 2.8);
	glRotatef(180, 0, 1, 0);
	glCallList(clockFrame);

	glPopMatrix();

	glEndList();

	drawList = worldDL;


	GLuint worldDL2 = glGenLists(1);
	glNewList(worldDL2, GL_COMPILE);

	glPushMatrix();
	glTranslatef(0.0, 0.65, 0.0);
	glCallList(spinSpikes);
	glPopMatrix();

	glEndList();

	drawList2 = worldDL2;







	GLuint worldDL3 = glGenLists(1);
	glNewList(worldDL3, GL_COMPILE);

	glPushMatrix();

	glTranslatef(0.0, 0.35, 0.0);
	glScalef(0.25, 0.25, 0.25);
	glCallList(healthPack);
	glPopMatrix();

	glEndList();

	drawList3 = worldDL3;




	GLuint worldDL4 = glGenLists(1);
	glNewList(worldDL4, GL_COMPILE);

	glPushMatrix();
	glCallList(box);
	glPopMatrix();

	glEndList();

	drawList4 = worldDL4;





	GLuint worldDL5 = glGenLists(1);
	glNewList(worldDL5, GL_COMPILE);

	glPushMatrix();
	glCallList(door);
	glPopMatrix();

	glEndList();
	drawList5 = worldDL5;






	GLuint worldDL6 = glGenLists(1);
	glNewList(worldDL6, GL_COMPILE);

	glPushMatrix();
	glCallList(checkerFloor);
	glPopMatrix();

	glEndList();
	drawList6 = worldDL6;




}