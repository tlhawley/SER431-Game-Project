

struct pointLight {
	//int motion;
	//float offset;
	float x;
	float y;
	float z;
	float range;
	float r;
	float g;
	float b;
};

pointLight newPointLight(float x, float y, float z, float range, float r, float g, float b);
void initPointLights();
void actionPointLights();
void displayPointLights();
void enablePointLights();

//#define PI 3.1415926535
#define maxPointLights 6
pointLight pointLights[maxPointLights];
int pointLightAmount;

pointLight newPointLight(float x, float y, float z, float range, float r, float g, float b) {
	pointLightAmount++;
	pointLight thePointLight;
	thePointLight.x = x;
	thePointLight.y = y;
	thePointLight.z = z;
	thePointLight.range = range;
	thePointLight.r = r;
	thePointLight.g = g;
	thePointLight.b = b;
	return thePointLight;
}

void initPointLights() {
	pointLightAmount = 0;

	//pointLights[pointLightAmount - 1] = newPointLight(2, 2, 0, 1, 0.5, 0.4f, 0.3);

}

void actionPointLights() {

	for (int i = 0; i < pointLightAmount; i++) {
		float LightDiffuse[] = { pointLights[i].r*pointLights[i].range, pointLights[i].g*pointLights[i].range, pointLights[i].b*pointLights[i].range, 1.0f*pointLights[i].range };
		float LightSpecular[] = { pointLights[i].r*pointLights[i].range, pointLights[i].g*pointLights[i].range, pointLights[i].b*pointLights[i].range, 1.0f*pointLights[i].range };
		float LightPosition[] = { pointLights[i].x, pointLights[i].y, pointLights[i].z, 1 };
		float LightAmbient[] = { 0.003f, 0.0035f, 0.004f, 1.0f };

		switch (i) {
		case 0:
			glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
			glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);
			glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
			break;
		case 1:
			glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse);
			glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular);
			glLightfv(GL_LIGHT2, GL_POSITION, LightPosition);
			break;
		case 2:
			glLightfv(GL_LIGHT3, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiffuse);
			glLightfv(GL_LIGHT3, GL_SPECULAR, LightSpecular);
			glLightfv(GL_LIGHT3, GL_POSITION, LightPosition);
			break;
		case 3:
			glLightfv(GL_LIGHT4, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT4, GL_DIFFUSE, LightDiffuse);
			glLightfv(GL_LIGHT4, GL_SPECULAR, LightSpecular);
			glLightfv(GL_LIGHT4, GL_POSITION, LightPosition);
			break;
		case 4:
			glLightfv(GL_LIGHT5, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT5, GL_DIFFUSE, LightDiffuse);
			glLightfv(GL_LIGHT5, GL_SPECULAR, LightSpecular);
			glLightfv(GL_LIGHT5, GL_POSITION, LightPosition);
			break;
		case 5:
			glLightfv(GL_LIGHT6, GL_AMBIENT, LightAmbient);
			glLightfv(GL_LIGHT6, GL_DIFFUSE, LightDiffuse);
			glLightfv(GL_LIGHT6, GL_SPECULAR, LightSpecular);
			glLightfv(GL_LIGHT6, GL_POSITION, LightPosition);
			break;
		}
	}
}


void enablePointLights() {
	for (int i = 0; i < pointLightAmount; i++) {
		switch (i) {
		case 0:
			glEnable(GL_LIGHT1);
			break;
		case 1:
			glEnable(GL_LIGHT2);
			break;
		case 2:
			glEnable(GL_LIGHT3);
			break;
		case 3:
			glEnable(GL_LIGHT4);
			break;
		case 4:
			glEnable(GL_LIGHT5);
			break;
		case 5:
			glEnable(GL_LIGHT6);
			break;
		}
	}
}





void displayPointLights() {

	for (int i = 0; i < pointLightAmount; i++) {

		glTranslatef(pointLights[i].x, pointLights[i].y, pointLights[i].z);
		glCallList(meshLightBulb);
		glTranslatef(-pointLights[i].x, -pointLights[i].y, -pointLights[i].z);

	}
}