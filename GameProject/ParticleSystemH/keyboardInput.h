
// Arrow key input for toggling the different particle systems
bool upPressed = false;
bool downPressed = false;
bool rightPressed = false;
bool leftPressed = false;

int particleSystemType = 0;

void mySpecial(int key, int x, int y);
void mySpecialUp(int key, int x, int y);

// Special Keyboard Input
void mySpecial(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
		upPressed = true;
		break;
	case GLUT_KEY_DOWN:
		downPressed = true;
		break;
	case GLUT_KEY_LEFT:
		leftPressed = true;
		particleSystemType++;
		if (particleSystemType > 9) {
			particleSystemType = 0;
		}
		break;
	case GLUT_KEY_RIGHT:
		rightPressed = true;
		particleSystemType--;
		if (particleSystemType < 0) {
			particleSystemType = 9;
		}
		break;
	}
}

void mySpecialUp(int key, int x, int y) {

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
	}
}