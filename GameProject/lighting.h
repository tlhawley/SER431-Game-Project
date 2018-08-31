void setlight();
void setmaterial();
void setmaterial2(float ambient, float r, float g, float b, float shine);
void setmaterial3(float ambient, float r, float g, float b, float a, float shine);

// Source: https://stackoverflow.com/questions/9450978/material-property-help-in-open-gl-using-glut-c#9474261

float getDistanceFromCam(float pointX, float pointY, float pointZ) {
	double num = sqrt((camx - pointX)*(camx - pointX) + (camy - pointY)*(camy - pointY) + (camz - pointZ)*(camz - pointZ))*0.05f;
	if (num < 1) {
		num = 1;
	}
	return num;
}

void setlight() {
	//here you set the lights and parameters, example with one light
	float distance = getDistanceFromCam(0.125f, 0.7f, 0);
	//printf("%f",distance);

	float LightAmbient[] = { 0.05f, 0.05f, 0.025f, 1.0f };
	float LightEmission[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float LightDiffuse[] = { 1.0f / distance, 1.1f / distance, 1.2f / distance, 1.0f };
	float LightSpecular[] = { 1.0f / distance, 1.0f / distance, 1.0f / distance, 1.0f };
	float LightDirection[] = { 0.125f, 0.7f,0, 1 };
	//float LightDirection[] = { x, y,z, 0.01f, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightDirection);

	distance = getDistanceFromCam(sin(timer) * 15, 60.0f, cos(timer) * 15);

	float LightDiffuse1[] = { 1.3f / distance, 1.0f / distance, 0.5f / distance, 1.0f };
	float LightDirection1[] = { sin(timer)*15, 60.0f, cos(timer) * 15, 1 };
	float LightSpecular1[] = { 1.0f / distance, 1.0f / distance, 1.0f / distance, 1.0f };
	//float LightAmbient1[] = { 0.1f / distance, 0.1f / distance, 0.05f / distance, 1.0f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular1);
	glLightfv(GL_LIGHT1, GL_POSITION, LightDirection1);

	distance = getDistanceFromCam(-sin(timer) * 15, 10.0f, -cos(timer) * 15);
	//float LightAmbient2[] = { 0.1f / distance, 0.1f / distance, 0.05f / distance, 1.0f };
	float LightDiffuse2[] = { 0.3f / distance, 0.3f / distance, 0.2f / distance, 1.0f };
	float LightDirection2[] = { -sin(timer) * 15, 10.0f, -cos(timer) * 15, 1 };
	float LightSpecular2[] = { 0.1f / distance, 0.1f / distance, 0.1f / distance, 0.1f };

	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular2);
	glLightfv(GL_LIGHT2, GL_POSITION, LightDirection2);


	distance = getDistanceFromCam(0.5f, 0.1f, 0.0f);
	//float LightAmbient3[] = { 0.1f / distance, 0.1f / distance, 0.05f / distance, 1.0f };
	float LightSpecular3[] = { 0.1f / distance, 0.1f / distance, 0.1f / distance, 0.1f };
	float LightDiffuse3[] = { 0.5f, 0.1f, 0.0f, 1.0f };
	float LightDirection3[] = { 0, 15, -20, 1};
	//float LightSpecular3[] = { 0.1f, 0.1f, 0.1f, 0.1f };

	glLightfv(GL_LIGHT3, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, LightDiffuse3);
	glLightfv(GL_LIGHT3, GL_SPECULAR, LightSpecular3);
	glLightfv(GL_LIGHT3, GL_POSITION, LightDirection3);


	distance = getDistanceFromCam(0, 15, 20);
	//float LightAmbient4[] = { 0.1f / distance, 0.1f / distance, 0.05f / distance, 1.0f };
	float LightSpecular4[] = { 0.1f / distance, 0.1f / distance, 0.1f / distance, 0.1f };
	float LightDiffuse4[] = { 0.0f, 0.5f / distance, 0.1f / distance, 1.0f };
	float LightDirection4[] = { 0, 15, 20, 1};
	//float LightSpecular2[] = { 0.1f, 0.1f, 0.1f, 0.1f };

	glLightfv(GL_LIGHT4, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, LightDiffuse4);
	glLightfv(GL_LIGHT4, GL_SPECULAR, LightSpecular4);
	glLightfv(GL_LIGHT4, GL_POSITION, LightDirection4);



	distance = getDistanceFromCam(-90.0f, 5.0f, -sin(timer*3.0)*5.0);
	//float LightSpecular5[] = { 0.9f, 0.8f, 0.5f, 1.0f };
	//float LightAmbient5[] = { 9.0f, 8.0f, 5.0f, 1.0f };
	//float LightAmbient5[] = { 0.1f / distance, 0.1f / distance, 0.05f / distance, 1.0f };
	float LightSpecular5[] = { 0.5f / distance, 0.5f / distance, 0.20f / distance, 1.0f };
	float LightDiffuse5[] = { 0.5f / distance, 0.5f / distance, 0.20f / distance, 1.0f };
	float LightDirection5[] = { -90.0f, 5.0f, -sin(timer*3.0)*5.0, 1};
	//float LightSpecular2[] = { 0.1f, 0.1f, 0.1f, 0.1f };

	glLightfv(GL_LIGHT5, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, LightDiffuse5);
	glLightfv(GL_LIGHT5, GL_SPECULAR, LightSpecular5);
	glLightfv(GL_LIGHT5, GL_POSITION, LightDirection5);






	distance = getDistanceFromCam(0, 5.0f, -120);
	//float LightSpecular5[] = { 0.9f, 0.8f, 0.5f, 1.0f };
	//float LightAmbient5[] = { 9.0f, 8.0f, 5.0f, 1.0f };
	//float LightAmbient5[] = { 0.1f / distance, 0.1f / distance, 0.05f / distance, 1.0f };
	float LightSpecular6[] = { 1.5f / distance, 0.0f / distance, 0.0f / distance, 1.0f };
	float LightDiffuse6[] = { 1.5f / distance, 0.0f / distance, 0.0f / distance, 1.0f };
	float LightDirection6[] = { 0, 5.0f, -120, 1 };
	//float LightSpecular2[] = { 0.1f, 0.1f, 0.1f, 0.1f };

	glLightfv(GL_LIGHT6, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, LightDiffuse6);
	glLightfv(GL_LIGHT6, GL_SPECULAR, LightSpecular6);
	glLightfv(GL_LIGHT6, GL_POSITION, LightDirection6);


	/*
	distance = getDistanceFromCam(-90.0f, 5.0f, -sin(timer*3.0)*5.0);
	float LightSpecular6[] = { 2.0f / distance, 2.0f / distance, 1.0f / distance, 1.0f };
	float LightDiffuse6[] = { 2.0f / distance, 2.0f / distance, 1.0f / distance, 1.0f };
	float LightDirection6[] = { camx, camy, camz, 1 };

	glLightfv(GL_LIGHT5, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, LightDiffuse6);
	glLightfv(GL_LIGHT5, GL_SPECULAR, LightSpecular6);
	glLightfv(GL_LIGHT5, GL_POSITION, LightDirection6);
	*/


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);


	/*
	float LightAmbient1[] = { 0.1f, 0.1f, 0.05f, 1.0f };
	float LightEmission1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float LightDiffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float LightSpecular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float LightDirection1[] = { -1.0f, 0.5f,0, 1.0f, 0.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular1);
	glLightfv(GL_LIGHT1, GL_POSITION, LightDirection1);
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	*/
}

void disableLights() {
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glDisable(GL_LIGHT5);
	glDisable(GL_LIGHT6);
}


void setmaterial() {
	//here you set materials, you must declare each one of the colors global or locally like this:
	float MatAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float MatDiffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float MatSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float MatShininess = 1;
	float black[] = { 0.02f,0.02f,0.02f,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}


void setmaterialGold() {
	//here you set materials, you must declare each one of the colors global or locally like this:
	float MatAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float MatDiffuse[] = { 0.9f, 0.7f, 0.1f, 1.0f };
	float MatSpecular[] = { 0.95f, 0.95f, 0.95f, 0.9f };
	float MatShininess = 98;
	float black[] = { 0.02f,0.02f,0.02f,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}

void setmaterial2(float ambient, float r, float g, float b, float shine) {
	//here you set materials, you must declare each one of the colors global or locally like this:
	float MatAmbient[] = { ambient, ambient, ambient, 1.0f };
	float MatDiffuse[] = { r, g, b, 1.0f };
	float MatSpecular[] = { r*shine, g*shine, b*shine, 1.0f };
	float MatShininess = shine*100.0f;
	float black[] = { r,g,b,1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}

void setmaterial3(float ambient, float r, float g, float b, float a, float shine) {
	//here you set materials, you must declare each one of the colors global or locally like this:
	float MatAmbient[] = { ambient, ambient, ambient, a };
	float MatDiffuse[] = { r, g, b, a };
	float MatSpecular[] = { r*shine, g*shine, b*shine, a*shine };
	float MatShininess = shine * 100.0f;
	float black[] = { r,g,b,a };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatShininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);
}



void setMaterialAdvanced(float MatData[17]) {
	// Makes a Material
	float MatAmbient[] = { MatData[0], MatData[1], MatData[2], MatData[3] };
	float MatDiffuse[] = { MatData[4], MatData[5], MatData[6], MatData[7] };
	float MatSpecular[] = { MatData[8], MatData[9], MatData[10], MatData[11] };
	float MatEmission[] = { MatData[12], MatData[13], MatData[14], MatData[15] };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MatSpecular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MatData[16]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, MatEmission);
}

