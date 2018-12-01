
#define mpScale 1.0
#define mpSpace 0.1

struct movingPlatform {

	float mpGeometry[4][3];

	/*
	= {
		{ b1X, b1Y, b1Z },  //  Point 1
	{ b2X,  b2Y, b2Z },	  //	Point2
	{ 0,  0, 0 },	  //	Tangent1
	{ 0,  0, 0 }		//	Tangent2
	};
	*/

	float velocity;

	int timerDirection = 1;


	int mpTimer;

	unsigned int N; // = 800;

};

movingPlatform newMovingPlatform(float x, float y, float z, float sx, float sy, float sz);
void initMovingPlatforms();
void actionMovingPlatforms();

#define maxMovingPlatforms 1000
movingPlatform movingPlatforms[maxMovingPlatforms];
int movingPlatformAmount;

#define playerSize 0.5f
#define playerHeight 1.0f

movingPlatform newMovingPlatform(float x1, float y1, float z1, float x2, float y2, float z2, float vx1, float vy1, float vz1, float vx2, float vy2, float vz2, int direction, int offset, int N) {
	movingPlatformAmount++;
	movingPlatform theBox;

	theBox.mpGeometry[0][0] = x1;
	theBox.mpGeometry[0][1] = y1;
	theBox.mpGeometry[0][2] = z1;

	theBox.mpGeometry[1][0] = x2;
	theBox.mpGeometry[1][1] = y2;
	theBox.mpGeometry[1][2] = z2;

	theBox.mpGeometry[2][0] = vx1;
	theBox.mpGeometry[2][1] = vy1;
	theBox.mpGeometry[2][2] = vz1;

	theBox.mpGeometry[3][0] = vx2;
	theBox.mpGeometry[3][1] = vy2;
	theBox.mpGeometry[3][2] = vz2;

	/*
	theBox.mpGeometry[4][3] = {
		{ x1, y1, z1 },  //  Point 1
		{ x2, y2, z2 },	  //	Point2
		{ vx1,  vy1, vz1 },	  //	Tangent1
		{ vx2,  vy2, vz2 }		//	Tangent2
	};
	*/


	theBox.timerDirection = direction;

	theBox.mpTimer = offset;

	theBox.N = N;

	return theBox;
}

void initMovingPlatforms() {

	movingPlatformAmount = 0;

	/*
	// Quiz 4 map
	Cboxes[CboxAmount - 1] = newCBox(0.0, -10.0, 0.0, 200.0, 20.0, 200.0);
	Cboxes[CboxAmount - 1] = newCBox(0.0, 0.0, 11.0, 60.0, 40.0, 2.0);
	*/


	// LV -1 intro Map
	if (currentLevel == -1) {


		movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(20, 0, 0, 20, 0, 50, 0, 5, 0, 0, -5, 0, 1, 50, 1000);

		//movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(-89.314995, -40.0, -24.910002, 218.39, 80.0, 80.0);

	}


	// LV 0 Hub world
	if (currentLevel == 0) {
		//movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(129, 0.0, 0.0, 2, 20, 300);

	}


	// LV 3 Platforms
	if (currentLevel == 3) {

		// portal collider
		movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(-54, -1.5, 0, -10, -1.5, 0, 0, 5, 0, 0, -5, 0, 1, 50, 1000);

		movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(-64, -1.5, -10, -64, 18.5, -54, 0, 5, 0, 0, -5, 0, 1, 50, 1000);

		movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(-74, 18.5, -64, -118, 46.5, -64, 0, 5, 0, 0, -5, 0, 1, 50, 1000);

		movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(-128, 46.5, -54, -128, 46.5, -10, 0, 5, 0, 0, -5, 0, 1, 50, 1000);

		movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform(-138, 46.5, -0, -182, 46.5, 0, 0, 5, 0, 0, -5, 0, 1, 50, 1000);

	}


}


void setCharacterMBVelocity(float x, float y, float z, float x2, float y2, float z2, int direction) {
	if (direction > 0) {
		collisionVelocityX = x - x2;
		collisionVelocityY = y - y2;
		collisionVelocityZ = z - z2;
	}
	else {
		collisionVelocityX = x2 - x;
		collisionVelocityY = y2 - y;
		collisionVelocityZ = z2 - z;
	}
}


void actionMovingPlatforms() {


	float t;
	// calculate blending functions
	float b0;
	float b1;
	float b2;
	float b3;
	// calculate the x, y and z of the curve point
	float x;
	float y;
	float z;
	float x2;
	float y2;
	float z2;
	float direction;
	float magnitude;

	float t2;
	// calculate blending functions
	float b02;
	float b12;
	float b22;
	float b32;

	/*
	movingPlatforms[i].mpGeometry[0][0] = b1X;
	movingPlatforms[i].mpGeometry[0][1] = b1Y;
	movingPlatforms[i].mpGeometry[0][2] = b1Z;
	movingPlatforms[i].mpGeometry[1][0] = b2X;
	movingPlatforms[i].mpGeometry[1][1] = b2Y;
	movingPlatforms[i].mpGeometry[1][2] = b2Z;
	*/

	// use the parametric time value 0 to 1
	//for (int i = 0; i != N - 1; i++) {

	/*
	if (movingPlatforms[i].mpTimer == movingPlatforms[i].N) {
		movingPlatforms[i].timerDirection = -1;
	}
	if (movingPlatforms[i].mpTimer == 0) {
		movingPlatforms[i].timerDirection = 1;
	}

	movingPlatforms[i].mpTimer = movingPlatforms[i].mpTimer + movingPlatforms[i].timerDirection;

	t = (float)(movingPlatforms[i].mpTimer) / (movingPlatforms[i].N - 1);
	// calculate blending functions
	b0 = 2 * t*t*t - 3 * t*t + 1;
	b1 = -2 * t*t*t + 3 * t*t;
	b2 = t * t*t - 2 * t*t + t;
	b3 = t * t*t - t * t;
	// calculate the x, y and z of the curve point
	x = b0 * movingPlatforms[i].mpGeometry[0][0] + b1 * movingPlatforms[i].mpGeometry[1][0] + b2 * movingPlatforms[i].mpGeometry[2][0] + b3 * movingPlatforms[i].mpGeometry[3][0];
	y = b0 * movingPlatforms[i].mpGeometry[0][1] + b1 * movingPlatforms[i].mpGeometry[1][1] + b2 * movingPlatforms[i].mpGeometry[2][1] + b3 * movingPlatforms[i].mpGeometry[3][1];
	z = b0 * movingPlatforms[i].mpGeometry[0][2] + b1 * movingPlatforms[i].mpGeometry[1][2] + b2 * movingPlatforms[i].mpGeometry[2][2] + b3 * movingPlatforms[i].mpGeometry[3][2];


	t2 = (float)(frameTimer + 1 + movingPlatforms[i].offset) / (movingPlatforms[i].N - 1);
	// calculate blending functions
	b02 = 2 * t2*t2*t2 - 3 * t2*t2 + 1;
	b12 = -2 * t2*t2*t2 + 3 * t2*t2;
	b22 = t2 * t2*t2 - 2 * t2*t2 + t2;
	b32 = t2 * t2*t2 - t2 * t2;
	// calculate the x, y and z of the curve point
	x2 = b02 * movingPlatforms[i].mpGeometry[0][0] + b12 * movingPlatforms[i].mpGeometry[1][0] + b22 * movingPlatforms[i].mpGeometry[2][0] + b32 * movingPlatforms[i].mpGeometry[3][0];
	y2 = b02 * movingPlatforms[i].mpGeometry[0][1] + b12 * movingPlatforms[i].mpGeometry[1][1] + b22 * movingPlatforms[i].mpGeometry[2][1] + b32 * movingPlatforms[i].mpGeometry[3][1];
	z2 = b02 * movingPlatforms[i].mpGeometry[0][2] + b12 * movingPlatforms[i].mpGeometry[1][2] + b22 * movingPlatforms[i].mpGeometry[2][2] + b32 * movingPlatforms[i].mpGeometry[3][2];

	//mpx = x;
	//mpy = y;
	//mpz = z;

	movingPlatforms[i].velocity = -atan2f(x - x2, z - z2)*sqrt((x - x2)*(x - x2) + (z - z2)*(z - z2));

	*/







	if (creativeMode == 2) {
		//movingPlatforms[movingPlatformAmount - 1].x = (int)((camx + sin(camAngY) * 3) * 4) / 4.0;
		//movingPlatforms[movingPlatformAmount - 1].y = (int)((camy + sin(camAngX) * 3) * 8) / 8.0;
		//movingPlatforms[movingPlatformAmount - 1].z = (int)((camz - cos(camAngY) * 3) * 4) / 4.0;

		/*
		if (mouseRDown == true && mouseRWait == false) {
			movingPlatforms[movingPlatformAmount - 1] = newMovingPlatform((int)((camx + sin(camAngY) * 3) * 4) / 4.0, (int)((camy + sin(camAngX) * 3) * 8) / 8.0, (int)((camz - cos(camAngY) * 3) * 4) / 4.0, 1, 1, 1);
			mouseRWait = true;
		}
		if (mouseRDown == false) {
			mouseRWait = false;
		}
		*/
	}
	else {
		/*
		Cboxes[CboxAmount - 1].x = 0.0;
		Cboxes[CboxAmount - 1].y = -10000.0;
		Cboxes[CboxAmount - 1].z = 0.0;
		*/
	}

	glPushMatrix();

	setMaterialAdvanced(materialPlayer);

	//setMaterialAdvanced(materialCollisionBox);
	for (int i = 0; i < movingPlatformAmount; i++) {

		


		if (movingPlatforms[i].mpTimer == movingPlatforms[i].N) {
			movingPlatforms[i].timerDirection = -1;
		}
		if (movingPlatforms[i].mpTimer == 0) {
			movingPlatforms[i].timerDirection = 1;
		}

		movingPlatforms[i].mpTimer = movingPlatforms[i].mpTimer + movingPlatforms[i].timerDirection;

		t = (float)(movingPlatforms[i].mpTimer) / (movingPlatforms[i].N - 1);

		// calculate blending functions
		b0 = 2 * t*t*t - 3 * t*t + 1;
		b1 = -2 * t*t*t + 3 * t*t;
		b2 = t * t*t - 2 * t*t + t;
		b3 = t * t*t - t * t;
		// calculate the x, y and z of the curve point
		x = b0 * movingPlatforms[i].mpGeometry[0][0] + b1 * movingPlatforms[i].mpGeometry[1][0] + b2 * movingPlatforms[i].mpGeometry[2][0] + b3 * movingPlatforms[i].mpGeometry[3][0];
		y = b0 * movingPlatforms[i].mpGeometry[0][1] + b1 * movingPlatforms[i].mpGeometry[1][1] + b2 * movingPlatforms[i].mpGeometry[2][1] + b3 * movingPlatforms[i].mpGeometry[3][1];
		z = b0 * movingPlatforms[i].mpGeometry[0][2] + b1 * movingPlatforms[i].mpGeometry[1][2] + b2 * movingPlatforms[i].mpGeometry[2][2] + b3 * movingPlatforms[i].mpGeometry[3][2];


		t2 = (float)(movingPlatforms[i].mpTimer + 1) / (movingPlatforms[i].N - 1);
		// calculate blending functions
		b02 = 2 * t2*t2*t2 - 3 * t2*t2 + 1;
		b12 = -2 * t2*t2*t2 + 3 * t2*t2;
		b22 = t2 * t2*t2 - 2 * t2*t2 + t2;
		b32 = t2 * t2*t2 - t2 * t2;
		// calculate the x, y and z of the curve point
		x2 = b02 * movingPlatforms[i].mpGeometry[0][0] + b12 * movingPlatforms[i].mpGeometry[1][0] + b22 * movingPlatforms[i].mpGeometry[2][0] + b32 * movingPlatforms[i].mpGeometry[3][0];
		y2 = b02 * movingPlatforms[i].mpGeometry[0][1] + b12 * movingPlatforms[i].mpGeometry[1][1] + b22 * movingPlatforms[i].mpGeometry[2][1] + b32 * movingPlatforms[i].mpGeometry[3][1];
		z2 = b02 * movingPlatforms[i].mpGeometry[0][2] + b12 * movingPlatforms[i].mpGeometry[1][2] + b22 * movingPlatforms[i].mpGeometry[2][2] + b32 * movingPlatforms[i].mpGeometry[3][2];

		//mpx = x;
		//mpy = y;
		//mpz = z;

		//movingPlatforms[i].velocity = -atan2f(x - x2, z - z2)*sqrt((x - x2)*(x - x2) + (z - z2)*(z - z2));


		glTranslatef(x, y, z);
		glCallList(meshMovingPlatform.l1);
		glTranslatef(-x, -y, -z);



		// Do not render collision boxes
		//objPlacementTRS(drawBox, Cboxes[i].x, Cboxes[i].y, Cboxes[i].z, 0.0, 0.0, 0.0, Cboxes[i].sx, Cboxes[i].sy, Cboxes[i].sz);
		if (camx > x - playerSize - mpScale && camx < x + playerSize + mpScale) {
			if (camy > y - playerSize - mpScale && camy < y + playerHeight + mpScale) {
				if (camz > z - playerSize - mpScale && camz < z + playerSize + mpScale) {

					if (ox+ mpSpace >= x - playerSize - mpScale || ox- mpSpace <= x + playerSize + mpScale) {
						if (oz+ mpSpace >= z - playerSize - mpScale || oz- mpSpace <= z + playerSize + mpScale) {
							if (oy- mpSpace <= y - playerSize + 0.2 - mpScale) {

								setCharacterMBVelocity(x, y, z, x2, y2, z2, movingPlatforms[i].timerDirection);

								camy = y - playerSize - mpScale;
								//oy = y;
							}
							if (oy+ mpSpace >= y + playerHeight - 0.2 + mpScale) {

								setCharacterMBVelocity(x, y, z, x2, y2, z2, movingPlatforms[i].timerDirection);

								camy = y + playerHeight + mpScale;
								//oy = y;
								camyv = 0.0f;
								jumpFrame = 0;
								canJump = true;
							}
						}
					}

					if (ox+ mpSpace >= x - playerSize - mpScale || ox- mpSpace <= x + playerSize + mpScale) {
						if (oy+ mpSpace >= y - playerSize - mpScale && oy- mpSpace <= y + playerHeight - 0.2 + mpScale) {
							if (oz- mpSpace <= z - playerSize - mpScale) {

								setCharacterMBVelocity(x, y, z, x2, y2, z2, movingPlatforms[i].timerDirection);

								camz = z - playerSize - mpScale;
								//oz = z;
							}
							if (oz+ mpSpace >= z + playerSize + mpScale) {

								setCharacterMBVelocity(x, y, z, x2, y2, z2, movingPlatforms[i].timerDirection);

								camz = z + playerSize + mpScale;
								//oz = z;
							}
						}
					}


					if (oz+ mpSpace >= z - playerSize - mpScale || oz- mpSpace <= z + playerSize + mpScale) {
						if (oy+ mpSpace >= y - playerSize - mpScale && oy- mpSpace <= y + playerHeight - 0.2 + mpScale) {
							if (ox- mpSpace <= x - playerSize - mpScale) {

								setCharacterMBVelocity(x, y, z, x2, y2, z2, movingPlatforms[i].timerDirection);

								camx = x - playerSize - mpScale;
								//ox = x;
							}
							if (ox+ mpSpace >= x + playerSize + mpScale) {

								setCharacterMBVelocity(x, y, z, x2, y2, z2, movingPlatforms[i].timerDirection);

								camx = x + playerSize + mpScale;
								//ox = x;
							}
						}
					}



				}
			}
		}
	}

	glPopMatrix();



}









void displayMovingPlatform() {
	for (int i = 0; i < movingPlatformAmount; i++) {


		
	}
}