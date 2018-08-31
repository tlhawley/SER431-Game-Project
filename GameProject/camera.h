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
	//lx = sin(ang); lz = -cos(ang);

	//ly = sin(camAngX);
	//lx = sin(camAngY); lz = -cos(camAngY);
	//lx = sin(ang); lz = -cos(ang);
	//float number = sqrt(lx * lx + lz * lz);
	//lx = lx * ly / 2.0;
	//lz = lz * ly / 2.0;

	float number = cos(camAngX);
	lx = sin(ang)*number;
	lz = -cos(ang)*number;
	ly = sin(camAngX);

}

void orientMe2(float ang) {
	
	//lx = sin(camAngY); lz = -cos(camAngY);
	//float number = sqrt(lx * lx + lz * lz);
	float number = cos(ang);
	//lx = sin(camAngY)*number;
	//lz = -cos(camAngY)*number;

	lx = sin(camAngY)*number;
	lz = -cos(camAngY)*number;

	ly = sin(ang);
	//lx = lx * ly / 2.0;
	//lz = lz * ly / 2.0;
}

// Movement Forwards & Backwards
void moveMeFlat(float i) {


	camx = camx + i * (sin(camAngY))*0.1;
	camz = camz + i * (-cos(camAngY))*0.1;

	/*
	lx = sin(camAngY);
	lz = -cos(camAngY);
	*/

	/*
	x = x + i * (lx)*0.1;
	z = z + i * (lz)*0.1;
	*/
}

// Movement Side to Side
void moveMeFlatStrafe(float i) {

	camx = camx + i * (cos(camAngY))*0.1;
	camz = camz + i * (sin(camAngY))*0.1;

	/*
	x = x + i * (-lz)*0.1;
	z = z + i * (lx)*0.1;
	*/
}