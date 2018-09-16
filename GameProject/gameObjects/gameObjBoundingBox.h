
// Displays green wireframe boxes
// May be used to view collision boxes

struct boundingBox
{
	float xOffset;
	float yOffset;
	float zOffset;
	float xScale;
	float yScale;
	float zScale;
};

boundingBox newBoundingBox(float xOffset, float yOffset, float zOffset, float xScale, float yScale, float zScale);
void initBoundingBoxes();
void actionBoundingBoxes();


#define maxBoundingBoxes 1000
boundingBox boundingBoxes[maxBoundingBoxes];
int boundingBoxAmount;

//#define playerSize 0.5f
//#define playerHeight 1.0f

boundingBox newBoundingBox(float xOffset, float yOffset, float zOffset, float xScale, float yScale, float zScale) {
	boundingBoxAmount++;
	boundingBox theBox;
	theBox.xOffset = xOffset;
	theBox.yOffset = yOffset;
	theBox.zOffset = zOffset;
	theBox.xScale = xScale;
	theBox.yScale = yScale;
	theBox.zScale = zScale;
	return theBox;
}

void initBoundingBoxes() {


	boundingBoxAmount = 0;

	for (int i = 0; i < CboxAmount; i++) {
		boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(Cboxes[i].x, Cboxes[i].y, Cboxes[i].z, Cboxes[i].sx, Cboxes[i].sy, Cboxes[i].sz);
	}

	/*
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(0, 5, 31, 20, 10, 2); // white back wall


														   //Cboxes[CboxAmount - 1] = newCBox(0, 5, -31, 20, 10, 2); // yellow back wall
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(6, 5, -30.25, 0.5, 10, 8); // green back wall
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(-6, 5, -30.25, 0.5, 10, 8); // green back wall
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(0, 7, -30.25, 0.5, 6, 4); // green back wall


	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(31, 5, 0, 2, 10, 20); // red back wall

														   //Cboxes[CboxAmount - 1] = newCBox(-31, 5, 0, 2, 10, 20); // blue back wall solid
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(-30.25, 5, 6, 0.5, 10, 8); // blue back wall
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(-30.25, 5, -6, 0.5, 10, 8); // blue back wall
	boundingBoxes[boundingBoxAmount - 1] = newBoundingBox(-30.25, 7, 0, 0.5, 6, 4); // blue back wall

	*/
}



void actionBoundingBoxes()
{

	// Set the color of the bounding box lines
	glBegin(GL_LINES);
	glColor3f(0.3f, 0.5f, 0.1f);
	glEnd();

	for (int i = 0; i < boundingBoxAmount; i++) {
		glBegin(GL_LINES);
		//glColor3f(0.0f, 1.0f, 0.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f); // c1

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			//glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			//glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f); // r1

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f); // c2

			//glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			//glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f); // r2

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f); // c3

			//glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			//glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f); // r3

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f); // c4

			//glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f); // 111

		glEnd();
	}

}