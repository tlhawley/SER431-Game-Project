void Update();
float crateX = 0;
float crateY = 100;

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
		pxv = pxv - 0.4f;
		if (pxv < -1.5f) {
			pxv = -1.5f;
		}
		//moveMeFlatStrafe(-2.1f);
	}
	if (dKey == true) {
		pxv = pxv + 0.4f;
		if (pxv > 1.5f) {
			pxv = 1.5f;
		}
		//moveMeFlatStrafe(2.1f);
	}
	if (wKey == true || upPressed == true) {
		pzv = pzv + 0.4f;
		if (pzv > 2.2f) {
			pzv = 2.2f;
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
		pzv = pzv - 0.4f;
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

	moveMeFlatStrafe(pxv);
	moveMeFlat(pzv);


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