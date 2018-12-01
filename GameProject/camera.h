// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// CCCCC  AAAAA  MMMMM  EEEEE  RRRR   AAAAA
// C      A   A  M M M  E      R   R  A   A
// C      AAAAA  M M M  EEEE   RRRR   AAAAA
// C      A   A  M M M  E      R   R  A   A
// CCCCC  A   A  M M M  EEEEE  R   R  A   A

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void orientMe(float ang);
void orientMe2(float ang);
void moveMeFlat(float i);
void moveMeFlatStrafe(float i);

// Camera Angles
void orientMe(float ang) {

	float number = cos(camAngX);
	lx = sin(ang)*number;
	lz = -cos(ang)*number;
	ly = sin(camAngX);

}

void orientMe2(float ang) {
	
	float number = cos(ang);
	lx = sin(camAngY)*number;
	lz = -cos(camAngY)*number;

	ly = sin(ang);
}

// Movement Forwards & Backwards
void moveMeFlat(float i) {


	camx = camx + i * (sin(camAngY))*0.1;
	camz = camz + i * (-cos(camAngY))*0.1;
}

// Movement Side to Side
void moveMeFlatStrafe(float i) {

	camx = camx + i * (cos(camAngY))*0.1;
	camz = camz + i * (sin(camAngY))*0.1;
}