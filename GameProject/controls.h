void Update();

// NOTE: sync.h is used for some mouse click controls

// Control Movement and Collision
void Update() {

	timer = timer + 0.01;

	if (takingDamage > 0) {
		takingDamage = takingDamage - 1;
	}

	ox = camx;
	oy = camy;
	oz = camz;

	camxv = camxv * 0.8f;
	camzv = camzv * 0.8f;
	camyv = camyv - 0.01f;
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
		camyv = 0.2f;
		canJump = false;
	}

	camx = camx + camxv;
	camy = camy + camyv;
	camz = camz + camzv;

	

	if (mouseMoveX != 0) {
		camAngY -= mouseMoveX * 0.001f;
		orientMe(camAngY);
	}
	if (mouseMoveY != 0) {
		camAngX = camAngX + mouseMoveY * 0.001f;
		if (camAngX > 1.5) camAngX = 1.5;
		if (camAngX < -1.5)camAngX =-1.5;
		orientMe2(camAngX);
	}

	
	if (upPressed == true) {
		rockz = rockz + 1.1f;
	}
	if (downPressed == true) {
		rockz = rockz - 1.1f;
	}
	if (leftPressed == true) {
		rockx = rockx - 1.1f;
	}
	if (rightPressed == true) {
		rockx = rockx + 1.1f;
	}

	if (aKey == true) {
		moveMeFlatStrafe(-1.1f);
	}
	if (dKey == true) {
		moveMeFlatStrafe(1.1f);
	}
	if (wKey == true) {
		
		if (sprint == false) {
			moveMeFlat(1.1f);
		}
		else {
			moveMeFlat(2.0f);
		}

		//y = y + 0.1;
	}
	if (sKey == true) {
		moveMeFlat(-1.1f);
		//y = y - 0.1;
	}

	//checkCollision(); // collision is now detected using collision boxes
	if (camy < -200 || health == 0) {
		objInit();
	}

	if (upPressed == true) {
		rockz = rockz + 1.1f;
	}
	if (downPressed == true) {
		rockz = rockz - 1.1f;
	}
	if (leftPressed == true) {
		rockx = rockx - 1.1f;
	}
	if (rightPressed == true) {
		rockx = rockx + 1.1f;
	}

	glutPostRedisplay();
}