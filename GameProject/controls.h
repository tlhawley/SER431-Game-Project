void Update();
void UpdateCam();
float crateX = 0;
float crateY = 100;

// NOTE: sync.h is used for some mouse click controls

void UpdateCam() {

	Geometry[0][0] = box1X;
	Geometry[0][1] = box1Y;
	Geometry[0][2] = box1Z;
	Geometry[1][0] = box2X;
	Geometry[1][1] = box2Y;
	Geometry[1][2] = box2Z;

	// use the parametric time value 0 to 1
	//for (int i = 0; i != N - 1; i++) {
		float t = (float)frameTimer / (N - 1);
		// calculate blending functions
		float b0 = 2 * t*t*t - 3 * t*t + 1;
		float b1 = -2 * t*t*t + 3 * t*t;
		float b2 = t * t*t - 2 * t*t + t;
		float b3 = t * t*t - t * t;
		// calculate the x, y and z of the curve point
		float x = b0 * Geometry[0][0] + b1 * Geometry[1][0] + b2 * Geometry[2][0] + b3 * Geometry[3][0];
		float y = b0 * Geometry[0][1] + b1 * Geometry[1][1] + b2 * Geometry[2][1] + b3 * Geometry[3][1];
		float z = b0 * Geometry[0][2] + b1 * Geometry[1][2] + b2 * Geometry[2][2] + b3 * Geometry[3][2];


		float t2 = (float)(frameTimer + 1) / (N - 1);
		// calculate blending functions
		float b02 = 2 * t2*t2*t2 - 3 * t2*t2 + 1;
		float b12 = -2 * t2*t2*t2 + 3 * t2*t2;
		float b22 = t2 * t2*t2 - 2 * t2*t2 + t2;
		float b32 = t2 * t2*t2 - t2 * t2;
		// calculate the x, y and z of the curve point
		float x2 = b02 * Geometry[0][0] + b12 * Geometry[1][0] + b22 * Geometry[2][0] + b32 * Geometry[3][0];
		float y2 = b02 * Geometry[0][1] + b12 * Geometry[1][1] + b22 * Geometry[2][1] + b32 * Geometry[3][1];
		float z2 = b02 * Geometry[0][2] + b12 * Geometry[1][2] + b22 * Geometry[2][2] + b32 * Geometry[3][2];

		/*
		// specify the points
		glVertex3f(x, y - 0.1f, z);
		glVertex3f(x2, y2 - 0.1f, z2);
		glVertex3f(x, y + 0.1f, z);

		glVertex3f(x, y + 0.1f, z);
		glVertex3f(x2, y2 - 0.1f, z2);
		glVertex3f(x2, y2 + 0.1f, z2);
		*/
	//}

	camAngY = -atan2f(x - x2, z - z2);
	orientMe(camAngY);
	orientMe2(camAngX);
	camx = x;
	camy = y;
	camz = z;

	glutPostRedisplay();

}

// Control Movement and Collision
void Update() {

	timer = timer + 0.01;

	if (takingDamage > 0) {
		takingDamage = takingDamage - 1;
	}

	ox = camx;
	oy = camy;
	oz = camz;

	if (buttons[15].toggle == false) {
		camxv = camxv * 0.8f;
		camzv = camzv * 0.8f;
		camyv = camyv - 0.01f;
	}
	else { // view mode
		camxv = camxv * 0.8f;
		camzv = camzv * 0.8f;
		camyv = camyv * 0.8f;
	}
	/*
	if (creativeMode >= 1) {
		canJump = true;
		//yv = -0.02f;
	}
	else {
		yv = yv - 0.01f;
	}
	*/

	//canJump = true; // infinite jump
	if (canJump == true && spaceKey == true) {
		if (buttons[15].toggle == false) {
			camyv = 0.25f;
			canJump = false;
		}
	}

	if (abs(camyv) > 0.04f) {
		canJump = false;
	}

	// jump attack animation frame counter
	if (jumpFrame > 0) {
		jumpFrame = jumpFrame + 1;
	}

	// jump attack input
	if (camyv > -0.15f && canJump == false && jumpFrame == 0 && eKey == true) { // if the player is in the air with a positive velocity and presses e (attack button) then start a jump attack animation
		jumpFrame = 1;
	}


	camx = camx + camxv - collisionVelocityX;
	camy = camy + camyv - collisionVelocityY;
	camz = camz + camzv - collisionVelocityZ;

	collisionVelocityX = 0;
	collisionVelocityY = 0;
	collisionVelocityZ = 0;
	

	if (mouseMoveX != 0) {
		camAngY -= mouseMoveX * 0.001f;
		playerAngle -= mouseMoveX * 0.001f;
		orientMe(camAngY);
	}
	if (mouseMoveY != 0) {
		camAngX = camAngX + mouseMoveY * 0.001f;
		if (camAngX > 0.7) camAngX = 0.7;
		if (camAngX < -1.5)camAngX =-1.5;
		orientMe2(camAngX);
	}

	/*
	if (upPressed == true) {
		//moveMeFlat(1.1f);
		crateY = crateY + 1.1f;
	}
	if (downPressed == true) {
		//moveMeFlat(-1.1f);
		crateY = crateY - 1.1f;
	}
	*/
	
	if (leftPressed == true) {
		camAngY -= 0.03f;
		orientMe(camAngY);
		//crateX = crateX + 1.1f;
	}
	if (rightPressed == true) {
		camAngY += 0.03f;
		orientMe(camAngY);
		//crateX = crateX - 1.1f;
	}
	if (aKey == true) {
		pxv = pxv - 0.2f;
		if (pxv < -1.5f) {
			pxv = -1.5f;
		}
		//moveMeFlatStrafe(-2.1f);
	}
	if (dKey == true) {
		pxv = pxv + 0.2f;
		if (pxv > 1.5f) {
			pxv = 1.5f;
		}
		//moveMeFlatStrafe(2.1f);
	}
	if (wKey == true || upPressed == true) {
		pzv = pzv + 0.2f;
		if (pzv > 1.5f) {
			pzv = 1.5f;
		}
		/*
		if (sprint == false) {
			moveMeFlat(2.1f);
		}
		else {
			moveMeFlat(2.0f);
		}
		*/

		//y = y + 0.1;
	}
	if (sKey == true || downPressed == true) {
		pzv = pzv - 0.2f;
		if (pzv < -1.5f) {
			pzv = -1.5f;
		}
		//moveMeFlat(-2.1f);
		//y = y - 0.1;
	}
	if (aKey == false && dKey == false && wKey == false && sKey == false) {
		pxv = pxv * 0.95f;
		pzv = pzv * 0.95f;
		if (pxv < 0.04f && pxv > -0.04f) {
			pxv = 0.0f;
		}
		if (pzv < 0.04f && pzv > -0.04f) {
			pzv = 0.0f;
		}
	}

	pxv = pxv * 0.92f;
	pzv = pzv * 0.92f;

	float maxVelocity = abs(pxv) + abs(pzv);
	if (maxVelocity > 1.5f) {
		maxVelocity = 1.5f;
	}
	//moveMeFlatStrafe(pxv);
	//moveMeFlat(pzv);
	moveMeFlatStrafe(cos(atan2(pzv, pxv))*maxVelocity);
	moveMeFlat(sin(atan2(pzv, pxv))*maxVelocity);
	
	if (buttons[15].toggle == true) {
		camyv = sin(atan2(pzv, pxv))*maxVelocity*sin(camAngX)/8.0f;
	}

	//checkCollision(); // collision is now detected using collision boxes
	if (camy < -200 || health == 0) {
		objInit();
	}

	if (pzv == 0 && pxv == 0) {
		
	}
	else {
		playerAngle = atan2(pzv, pxv);
	}

	glutPostRedisplay();
}