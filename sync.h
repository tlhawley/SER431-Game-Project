
// This function sync the framerate to roughly 60 frames per second
// It also updates mouse movement input

void sync();

void sync() {

	glutSwapBuffers();

	if (lockMouse == true) {
		mouseMoveX = width / 2 - mouseX;
		mouseMoveY = height / 2 - mouseY;

		glutWarpPointer(width / 2, height / 2);
	}
	else {
		mouseMoveX = 0;
		mouseMoveY = 0;
	}

	if (mouseDown == true) { // the mouse is being held down
		mouseWait = true;
	}
	if (mouseWait == true && mouseDown == false) { // the mouse has been released

		//if ((float)mouseX / (float)width < 1.0f && (float)mouseX / (float)width > 0.8f && (float)mouseY / (float)width < 0.25f && (float)mouseY / (float)width > 0.2f) {
		if ((float)mouseX / (float)width < 1.0f && (float)mouseX / (float)width > 0.8f && (float)mouseY / (float)height - mouseY - width * 0.04 - width * 0.2 < 0.0 && height - mouseY - width * 0.2 > 0.0) {
			if (sprint) { //SmoothingSetting == 1) {
				sprint = false; //SmoothingSetting = 0;
			}
			else {
				sprint = true; //SmoothingSetting = 1;
			}
		}
		else {

			if (lockMouse == true) {
				lockMouse = false;
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
				mouseOX = width / 2;
				mouseOY = height / 2;
				mouseX = mouseOX;
				mouseY = mouseOY;
				glutWarpPointer(width / 2, height / 2);
			}
			else {
				glutSetCursor(GLUT_CURSOR_NONE);
				mouseOX = width / 2;
				mouseOY = height / 2;
				mouseX = mouseOX;
				mouseY = mouseOY;
				glutWarpPointer(width / 2, height / 2);
				lockMouse = true;
			}
		}
		mouseWait = false;
	}

	// Roughly syncs the framerate to 60 fps
	fps = 62;
	while (fps > 61) {
		delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
		if (delta_ticks > 0)
			fps = CLOCKS_PER_SEC / delta_ticks;
	}

	mouseOX = mouseX;
	mouseOY = mouseY;

	current_ticks = clock(); // clock used to sync the frame rate

}