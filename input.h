// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// IIIII  N   N  PPPPP  U   U  TTTTT
//   I    NN  N  P   P  U   U    T  
//   I    N N N  PPPPP  U   U    T  
//   I    N  NN  P      U   U    T  
// IIIII  N   N  P      UUUUU    T  

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void mySpecial(int key, int x, int y);
void mySpecialUp(int key, int x, int y);
void keyboardInput(unsigned char key, int x2, int y2);
void keyboardInputUp(unsigned char key, int x2, int y2);

// Special Keyboard Input
void mySpecial(int key, int x, int y) {

	/*
	if ((glutGetModifiers() & GLUT_ACTIVE_SHIFT) || (glutGetModifiers() & GLUT_ACTIVE_ALT)) { sprint = true; }
	else { sprint = false; }
	*/

	switch (key) {
	case GLUT_KEY_UP:
		upPressed = true;
		break;
	case GLUT_KEY_DOWN:
		downPressed = true;
		break;
	case GLUT_KEY_LEFT:
		leftPressed = true;
		break;
	case GLUT_KEY_RIGHT:
		rightPressed = true;
		break;
	//case GLUT_ACTIVE_SHIFT:
		//sprint = true;
		//break;
	case GLUT_KEY_F11:
		if (windowed == true) {
			windowed = false;
			glutFullScreen();
		}
		else {
			glutReshapeWindow(800, 600);
			glutPositionWindow(64, 64);
			windowed = true;
		}
		break;
	}
}

void mySpecialUp(int key, int x, int y) {

	/*
	if ((glutGetModifiers() & GLUT_ACTIVE_SHIFT) || (glutGetModifiers() & GLUT_ACTIVE_ALT)) { sprint = true; }
	else { sprint = false; }
	*/
	
	switch (key) {
	case GLUT_KEY_UP:
		upPressed = false;
		break;
	case GLUT_KEY_DOWN:
		downPressed = false;
		break;
	case GLUT_KEY_LEFT:
		leftPressed = false;
		break;
	case GLUT_KEY_RIGHT:
		rightPressed = false;
		break;
	case GLUT_KEY_F11:
		//f11Pressed = false;
		break;
	}
}

// Keyboard Input
void keyboardInput(unsigned char key, int x2, int y2)
{

	/*
	if ((glutGetModifiers() & GLUT_ACTIVE_SHIFT) || (glutGetModifiers() & GLUT_ACTIVE_ALT)) { sprint = true; }
	else { sprint = false; }
	*/

	switch (key) {
	case 49:
		if (creativeMode == 0) {
			creativeMode = 1;
		}
		else {
			creativeMode = 0;
		}
		break;
	case 32:
		spaceKey = true;
		break;


	case 68:
		dKey = true;
		break;
	case 65:
		aKey = true;
		break;
	case 87:
		wKey = true;
		break;
	case 83:
		sKey = true;
		break;

	case 100:
		dKey = true;
		break;
	case 97:
		aKey = true;
		break;
	case 119:
		wKey = true;
		break;
	case 115:
		sKey = true;
		break;
	case 27:
		exit(0);
		break;
	}

	glutPostRedisplay();

}


void keyboardInputUp(unsigned char key, int x2, int y2)
{

	//if ((glutGetModifiers() & GLUT_ACTIVE_SHIFT) || (glutGetModifiers() & GLUT_ACTIVE_ALT)) { sprint = true; } else { sprint = false; }

	switch (key) {
	case 32:
		spaceKey = false;
		break;

	case 68:
		dKey = false;
		break;
	case 65:
		aKey = false;
		break;
	case 87:
		wKey = false;
		break;
	case 83:
		sKey = false;
		break;


	case 100:
		dKey = false;
		break;
	case 97:
		aKey = false;
		break;
	case 119:
		wKey = false;
		break;
	case 115:
		sKey = false;
		break;
	}


	glutPostRedisplay();
}

void myMouseMotion(int x, int y) {

	mouseX = x;
	mouseY = y;
}

void mouseClicks(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseDown = true;
	}
	else {
		mouseDown = false;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		mouseRDown = true;
	}
	else {
		mouseRDown = false;
	}
}