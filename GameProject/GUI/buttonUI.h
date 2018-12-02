// This is used for menu buttons

void CreateTreeLists(void);

int buttonAmount;
int buttonMouseActive = 0; // used with buttonUI.h to detect if the mouse is available to click on the button

buttonsUI newButtonUI(float x, float y, bool active, bool toggle, const char *text1, const char *text2);
void initButtonUI();
void actionButtonUI();
void displayButtonUI();

struct GLuint2 {
	GLuint l1;
	GLuint l2;
};

void swapLists();
GLuint2 swapGLuint2(GLuint2 list);



buttonsUI newButtonUI(float x, float y, bool active, bool toggle, const char *text1, const char *text2) {
	buttonAmount++;
	buttonsUI theButton;
	theButton.active = active;
	theButton.toggle = toggle;
	theButton.text1 = text1;
	theButton.text2 = text2;
	theButton.x = x;
	theButton.y = y;
	return theButton;
}

void initButtonUI() {
	buttonAmount = 0;

	buttons[buttonAmount - 1] = newButtonUI(0, 980, true, false, "Menu OFF", "Menu ON");				// 0 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 890,false,false,"Boundbox OFF","Boundbox ON");			// 1 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 800, false, true, "Particles OFF", "Particles ON");		// 2 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 710, false, true, "Info OFF", "Info ON");				// 3 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 620, false, true, "Sky OFF", "Sky ON");					// 4 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 530, false, true, "Fog OFF", "Fog ON");					// 5 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 440, false, true, "Reflections OFF", "Reflections ON");	// 6 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(0, 350, false, true, "Shadows OFF", "Shadows ON");			// 7 -- Complete

	buttons[buttonAmount - 1] = newButtonUI(300, 980, false, true, "Fractals OFF", "Fractals ON");		// 8 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 890, false, true, "Lights OFF", "Lights ON");			// 9 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 800, false, true, "Textures OFF", "Textures ON");		// 10 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 710, false, true, "Procedural OFF", "Procedural ON");	// 11 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 620, false, true, "Materials OFF", "Materials ON");	// 12 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 530, false, true, "Collision OFF", "Collision ON");	// 13 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 440, false, true, "Terrain OFF", "Terrain ON");		// 14 -- Complete
	buttons[buttonAmount - 1] = newButtonUI(300, 350, false, false, "View Mode OFF", "View Mode ON");	// 15 -- Complete

}

void actionButtonUI() {
	for (int i = 0; i < buttonAmount; i++) {

		if (i > 0) {
			if (buttons[0].toggle) {
				buttons[i].active = true;
			}
			else {
				buttons[i].active = false;
			}
		}

		if (buttons[i].active == true) {


			if (1920 * (float)mouseX / (float)width > buttons[i].x && 1920 * (float)mouseX / (float)width < buttons[i].x + 220 && 1080 * (float)mouseY / (float)height > buttons[i].y && 1080 * (float)mouseY / (float)height < buttons[i].y + 64) {
				if (buttons[i].toggle) {
					buttons[i].toggle = false;
					if (i == 10) {
						swapLists();
					}
					if (i == 12) {
						if (currentLevel == -1) {
							CreateTreeLists();
						}
					}
				}
				else {
					buttons[i].toggle = true;
					if (i == 10) {
						swapLists();
					}
					if (i == 12) {
						if (currentLevel == -1) {
							CreateTreeLists();
						}
					}
				}
				buttonMouseActive = 1;
			}

		}
	}
}


void displayButtonUI() {

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, width, height);
	gluPerspective(0, 0, 0.1, 1000);
	glOrtho(0, 1920, 1080, 0, -10, 10);

	for (int i = 0; i < buttonAmount; i++) {
		if (buttons[i].active == true) {


			char msgXYZ[100];

			if (buttons[i].toggle) {
				sprintf_s(msgXYZ, buttons[i].text2);
			}
			else {
				sprintf_s(msgXYZ, buttons[i].text1);
			}

			glColor3f(1, 1, 1);
			renderBitmapString(buttons[i].x + 31, buttons[i].y + 38, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses graphicsFunctions.h

			glBegin(GL_POLYGON);

			if (i > 0) {
				glColor4f(.0, .0, .0, 0.5);
			}
			else {
				glColor4f(.1, .2, .4, 0.5);
			}
			glVertex3f(buttons[i].x, buttons[i].y, 0);
			glVertex3f(buttons[i].x + 220, buttons[i].y, 0);
			glVertex3f(buttons[i].x + 220, buttons[i].y+64, 0);
			glVertex3f(buttons[i].x, buttons[i].y+64, 0);


			glEnd();

			glBegin(GL_POLYGON);
			glColor4f(1, 1, 1, 0.5);
			glVertex3f(buttons[i].x - 5, buttons[i].y - 5, 0);
			glVertex3f(buttons[i].x + 5 + 220, buttons[i].y - 5, 0);
			glVertex3f(buttons[i].x + 5 + 220, buttons[i].y + 5 + 64, 0);
			glVertex3f(buttons[i].x - 5, buttons[i].y + 5 + 64, 0);
			glEnd();


		}
	}
}