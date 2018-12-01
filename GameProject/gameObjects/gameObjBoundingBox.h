
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

}



void actionBoundingBoxes()
{

	// Set the color of the bounding box lines
	glBegin(GL_LINES);
	glColor3f(0.3f, 0.5f, 0.1f);
	glEnd();

	for (int i = 0; i < boundingBoxAmount; i++) {
		glBegin(GL_LINES);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset + boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset - boundingBoxes[i].zScale / 2.0f);

			glVertex3f(boundingBoxes[i].xOffset - boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);
			glVertex3f(boundingBoxes[i].xOffset + boundingBoxes[i].xScale / 2.0f, boundingBoxes[i].yOffset - boundingBoxes[i].yScale / 2.0f, boundingBoxes[i].zOffset + boundingBoxes[i].zScale / 2.0f);


		glEnd();
	}

}