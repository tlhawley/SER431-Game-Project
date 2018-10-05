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

buttonsUI newButtonUI(float x, float y, bool active, int toggle, const char *text1, const char *text2);
void initButtonUI();
void actionButtonUI();
void displayButtonUI();




#define maxButtons 20
buttonsUI buttons[maxButtons];

buttonsUI newButtonUI(float x, float y, bool active, int toggle, const char *text1, const char *text2) {
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

	buttons[buttonAmount - 1] = newButtonUI(0,0,true,0,"Boundbox ON","Boundbox OFF");

}

void actionButtonUI() {
	//for (int i = 0; i < buttonAmount; i++) { /// ?????????????????????? NOT WORKING WHEN IN LOOP???? WHY
		//if (buttons[i].active == true) {

		//if ((float)mouseX / (float)width < 1.0f && (float)mouseX / (float)width > 0.8f && (float)mouseY / (float)width < 0.25f && (float)mouseY / (float)width > 0.2f) {
			if ((float)mouseX / (float)width < 1.0f && (float)mouseX / (float)width > 0.8f && (float)mouseY / (float)height - mouseY - width * 0.04 - width * 0.2 < 0.0 && height - mouseY - width * 0.2 > 0.0) {
				if (sprint) { //SmoothingSetting == 1) {
					sprint = false; //SmoothingSetting = 0;
				}
				else {
					sprint = true; //SmoothingSetting = 1;
				}
				buttonMouseActive = 1;
			}
			//buttonMouseActive = 1;
		//}


		//}
	//}
}


void displayButtonUI() {
	for (int i = 0; i < buttonAmount; i++) {
		if (buttons[i].active == true) {



		}
	}
}