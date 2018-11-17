// This is used for menu buttons

struct buttonsUI {
	bool active;
	bool toggle;
	const char *text1;
	const char *text2;
	float x;
	float y;
	//GLuint buttonImg;
};

int buttonAmount;
int buttonMouseActive = 0; // used with buttonUI.h to detect if the mouse is available to click on the button

buttonsUI newButtonUI(float x, float y, bool active, bool toggle, const char *text1, const char *text2);
void initButtonUI();
void actionButtonUI();
void displayButtonUI();




#define maxButtons 20
buttonsUI buttons[maxButtons];

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

	buttons[buttonAmount - 1] = newButtonUI(0, 980, true, false, "Menu OFF", "Menu ON");
	buttons[buttonAmount - 1] = newButtonUI(0, 880,false,false,"Boundbox OFF","Boundbox ON");
	buttons[buttonAmount - 1] = newButtonUI(0, 780, false, true, "Particles OFF", "Particles ON");
	buttons[buttonAmount - 1] = newButtonUI(0, 680, false, false, "Info ON", "Info OFF");
	buttons[buttonAmount - 1] = newButtonUI(0, 580, false, true, "Sky OFF", "Sky ON");
	buttons[buttonAmount - 1] = newButtonUI(0, 480, false, true, "Fog OFF", "Fog ON");
	buttons[buttonAmount - 1] = newButtonUI(0, 380, false, true, "Reflections OFF", "Reflections ON");

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
				}
				else {
					buttons[i].toggle = true;
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
	//glViewport(width - width * 0.2, height - width * 0.25, width*0.2, width*0.04);

	glViewport(0, 0, width, height);

	//glViewport(width - width * 0.2, width * 0.2, width*0.2, width*0.04);
	gluPerspective(0, 0, 0.1, 1000);

	//glOrtho(-10, 10, -10, 10, -10, 10);

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




			//glColor3f(0.0, 0.0, 0.0);
			//renderBitmapString(buttons[i].x + 6, buttons[i].y + 4, 0.0, GLUT_BITMAP_HELVETICA_18, msgXYZ); // uses "graphicsFunctions.h"


		}
	}
}